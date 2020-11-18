/*
 * FreeRTOS+TCP V2.3.1
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/* Standard includes. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_IP_Private.h"
#include "FreeRTOS_ARP.h"
#include "NetworkBufferManagement.h"
#include "NetworkInterface.h"

/* Some files from the Atmel Software Framework */
/* gmac_SAM.[ch] is a combination of the gmac.[ch] for both SAM4E and SAME70. */
#include "conf_clock.h"
#include "gmac_handler.h"
#include <sysclk.h>
//#include "phyhandling.h"
#include "ethernet_phy.h"

/* This file is included to see if 'CONF_BOARD_ENABLE_CACHE' is defined. */
//#include "conf_board.h"
#include "conf_eth.h"

#include "ioport.h"


/* Interrupt events to process.  Currently only the Rx event is processed
 * although code for other events is included to allow for possible future
 * expansion. */
#define EMAC_IF_RX_EVENT     1UL
#define EMAC_IF_TX_EVENT     2UL
#define EMAC_IF_ERR_EVENT    4UL
#define EMAC_IF_ALL_EVENT    ( EMAC_IF_RX_EVENT | EMAC_IF_TX_EVENT | EMAC_IF_ERR_EVENT )


#if ( ipconfigZERO_COPY_RX_DRIVER == 0 )
    #error This driver works optimal if ipconfigZERO_COPY_RX_DRIVER is defined as 1
#endif

#if ( ipconfigZERO_COPY_TX_DRIVER == 0 )
    #error This driver works optimal if ipconfigZERO_COPY_TX_DRIVER is defined as 1
#endif


constexpr const char* kEMACTaskName = "EMAC";
constexpr uint32_t kEMACTaskStackSize = 1024U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kEMACTaskPriority = configMAX_PRIORITIES - 1;
constexpr TickType_t kEMACMaxBlockTimeTicks = pdMS_TO_TICKS(100);

static StackType_t emac_task_stack[kEMACTaskStackSize] = {};
static StaticTask_t emac_task_buffer = {};

static TaskHandle_t emac_task_handle = nullptr;


__attribute__( ( aligned( 32 ) ) )
//__attribute__( ( section( ".first_data" ) ) )
uint8_t ucNetworkPackets[ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS * NETWORK_BUFFER_SIZE] = {};

// Queue Buffers
uint8_t g_queue_buffers[GMAC_TX_BUFFERS * sizeof(void *)] = {};
StaticQueue_t g_queue_buffer = {};

StaticSemaphore_t g_buffer_semaphore = {};


#if ( __DCACHE_PRESENT != 0 ) && defined( CONF_BOARD_ENABLE_CACHE )
    #include "core_cm7.h"
    // #warning This driver assumes the presence of DCACHE
    #define     NETWORK_BUFFERS_CACHED        1
    #define     CACHE_LINE_SIZE               32
    #define     NETWORK_BUFFER_HEADER_SIZE    (ipconfigPACKET_FILLER_SIZE + 8)

    static void cache_clean_invalidate()
    {
        /* If you application crashes here, make sure that SCB_EnableDCache() has been called. */
        SCB_CleanInvalidateDCache();
    }
    /*-----------------------------------------------------------*/

    static void cache_clean_invalidate_by_addr(uint32_t /*addr*/, uint32_t /*size*/)
    {
        /* SAME70 does not have clean/invalidate per area. */
        /* SCB_CleanInvalidateDCache_by_Addr( ( uint32_t * )addr, size); */
        SCB_CleanInvalidateDCache();
    }
    /*-----------------------------------------------------------*/

    static void cache_invalidate_by_addr(uint32_t /*addr*/, uint32_t /*size*/) \
    {
        /* SAME70 does not have clean/invalidate per area. */
        /* SCB_InvalidateDCache_by_Addr( ( uint32_t * )addr, size); */
        SCB_InvalidateDCache();
    }
    /*-----------------------------------------------------------*/

#else /* if ( __DCACHE_PRESENT != 0 ) && defined( CONF_BOARD_ENABLE_CACHE ) */
    //#warning Sure there is no caching?
    #define     cache_clean_invalidate()                        do {} while( 0 )
    #define     cache_clean_invalidate_by_addr( addr, size )    do {} while( 0 )
    #define     cache_invalidate_by_addr( addr, size )          do {} while( 0 )
#endif /* if ( __DCACHE_PRESENT != 0 ) && defined( CONF_BOARD_ENABLE_CACHE ) */

/*
 * Called from the ASF GMAC driver.
 */
void xRxCallback(uint32_t ulStatus);
void xTxCallback(uint8_t* puc_buffer, BaseType_t* task_switch_required);

/*
 * A deferred interrupt handler task that processes GMAC interrupts.
 */
static void prvEMACHandlerTask(void* pvParameters);

/*
 * Initialise the ASF GMAC driver.
 */
static BaseType_t prvGMACInit();

/*
 * Try to obtain an Rx packet from the hardware.
 */
static uint32_t prvEMACRxPoll();

/*
 * Handle transmission errors.
 */
static void hand_tx_errors();

/*-----------------------------------------------------------*/

/* Bit map of outstanding ETH interrupt events for processing.  Currently only
 * the Rx interrupt is handled, although code is included for other events to
 * enable future expansion. */
static volatile uint32_t ulISREvents = 0U;

/* The GMAC object as defined by the ASF drivers. */
static gmac_device_t gs_gmac_dev = {};

/* Holds the handle of the task used as a deferred interrupt processor.  The
 * handle is used so direct notifications can be sent to the task for all EMAC/DMA
 * related interrupts. */
TaskHandle_t xEMACTaskHandle = nullptr;

static QueueHandle_t xTxBufferQueue;

/* xTXDescriptorSemaphore is a counting semaphore with
 * a maximum count of GMAC_TX_BUFFERS, which is the number of
 * DMA TX descriptors. */
static SemaphoreHandle_t xTXDescriptorSemaphore = nullptr;

/*-----------------------------------------------------------*/

/*
 * GMAC interrupt handler.
 */
void GMAC_Handler()
{
    BaseType_t xGMACSwitchRequired = pdFALSE;

    /* gmac_handler() may call xRxCallback() which may change
     * the value of xGMACSwitchRequired. */
    gmac_handler(&gs_gmac_dev, &xGMACSwitchRequired);

    portEND_SWITCHING_ISR(xGMACSwitchRequired);
}
/*-----------------------------------------------------------*/

void xRxCallback(uint32_t ulStatus, BaseType_t* task_switch_required)
{
    if (((ulStatus & GMAC_RSR_REC) != 0U) && (xEMACTaskHandle != nullptr))
    {
        /* let the prvEMACHandlerTask know that there was an RX event. */
        ulISREvents |= EMAC_IF_RX_EVENT;
        /* Only an RX interrupt can wakeup prvEMACHandlerTask. */
        vTaskNotifyGiveFromISR(xEMACTaskHandle, task_switch_required);
    }
}
/*-----------------------------------------------------------*/

void returnTxBuffer(uint8_t* puc_buffer)
{
    /* Called from a non-ISR context. */
    if (xTxBufferQueue != nullptr)
    {
        xQueueSend(xTxBufferQueue, &puc_buffer, 0U);
        xTaskNotifyGive(xEMACTaskHandle);
        ulISREvents |= EMAC_IF_TX_EVENT;
    }
}

void xTxCallback(uint8_t* puc_buffer, BaseType_t* task_switch_required)
{
    if ((xTxBufferQueue != nullptr) && (xEMACTaskHandle != nullptr))
    {
        /* let the prvEMACHandlerTask know that there was an TX event. */
        ulISREvents |= EMAC_IF_TX_EVENT;
        /* Wakeup prvEMACHandlerTask. */
        vTaskNotifyGiveFromISR(xEMACTaskHandle, task_switch_required);
        xQueueSendFromISR(xTxBufferQueue, &puc_buffer, task_switch_required);
        //tx_release_count[2]++;
    }
}
/*-----------------------------------------------------------*/

BaseType_t xNetworkInterfaceInitialise()
{
    const TickType_t x5_Seconds = 5000UL;

    if (xEMACTaskHandle == nullptr)
    {
        prvGMACInit();

        cache_clean_invalidate();

        /* The handler task is created at the highest possible priority to
         * ensure the interrupt handler can return directly to it. */
        xTaskCreate(prvEMACHandlerTask, "EMAC", kEMACTaskStackSize, nullptr, kEMACTaskPriority,
            &xEMACTaskHandle);
        configASSERT(xEMACTaskHandle);
    }

    if (xTxBufferQueue == nullptr)
    {
        xTxBufferQueue = xQueueCreate(GMAC_TX_BUFFERS, sizeof(void *));
        configASSERT(xTxBufferQueue);
    }

    if (xTXDescriptorSemaphore == nullptr)
    {
        xTXDescriptorSemaphore = xSemaphoreCreateCounting((UBaseType_t)GMAC_TX_BUFFERS, (UBaseType_t)GMAC_TX_BUFFERS);
        configASSERT(xTXDescriptorSemaphore);
    }

    /* When returning non-zero, the stack will become active and
     * start DHCP (in configured) */
    return xGetPhyLinkStatus();
}
/*-----------------------------------------------------------*/

BaseType_t xGetPhyLinkStatus()
{
    // Port PA29 on the SAMV71 Explained Ultra board is SIGDET from the PHY.
    // return ioport_get_pin_level(PIN_GMAC_SIDET_GPIO);
    return true;
}
/*-----------------------------------------------------------*/

/** The GMAC TX errors to handle */
#define GMAC_TX_ERRORS    ( GMAC_TSR_TFC | GMAC_TSR_HRESP )

static void hand_tx_errors()
{
/* Handle GMAC underrun or AHB errors. */
    if (gmac_get_tx_status(GMAC) & GMAC_TX_ERRORS)
    {
        gmac_enable_transmit(GMAC, false);

        /* Reinit TX descriptors. */
/*		gmac_tx_init(ps_gmac_dev); */
        gmac_reset_tx_mem(&gs_gmac_dev);
        /* Clear error status. */
        gmac_clear_tx_status(GMAC, GMAC_TX_ERRORS);

        gmac_enable_transmit(GMAC, true );
    }
}

BaseType_t xNetworkInterfaceOutput(NetworkBufferDescriptor_t* const pxDescriptor, BaseType_t bReleaseAfterSend)
{
/* Do not wait too long for a free TX DMA buffer. */
    constexpr TickType_t xBlockTimeTicks = pdMS_TO_TICKS(50u);
    uint32_t ulTransmitSize = pxDescriptor->xDataLength;

    if( ulTransmitSize > NETWORK_BUFFER_SIZE)
    {
        ulTransmitSize = NETWORK_BUFFER_SIZE;
    }

    /* A do{}while(0) loop is introduced to allow the use of multiple break
     * statement. */
    do
    {
        if( xTXDescriptorSemaphore == nullptr )
        {
            /* Semaphore has not been created yet? */
            break;
        }

        hand_tx_errors();

        if (xSemaphoreTake(xTXDescriptorSemaphore, xBlockTimeTicks) != pdPASS)
        {
            /* Time-out waiting for a free TX descriptor. */
            //tx_release_count[ 3 ]++;
            break;
        }

        #if ( NETWORK_BUFFERS_CACHED != 0 )
            {
                uint32_t xlength = CACHE_LINE_SIZE * ( ( ulTransmitSize + NETWORK_BUFFER_HEADER_SIZE + CACHE_LINE_SIZE - 1 ) / CACHE_LINE_SIZE );
                uint32_t xAddress = ( uint32_t ) ( pxDescriptor->pucEthernetBuffer - NETWORK_BUFFER_HEADER_SIZE );
                cache_clean_invalidate_by_addr( xAddress, xlength );
            }
        #endif

        gmac_dev_write(&gs_gmac_dev, ( void * )pxDescriptor->pucEthernetBuffer, pxDescriptor->xDataLength);

        /* Not interested in a call-back after TX. */
        iptraceNETWORK_INTERFACE_TRANSMIT();
    } while(ipFALSE_BOOL);

    configASSERT( bReleaseAfterSend != pdFALSE );
    /*
    if( bReleaseAfterSend != pdFALSE )
    {
        vReleaseNetworkBufferAndDescriptor( pxDescriptor );
    }*/

    return pdTRUE;
}
/*-----------------------------------------------------------*/

static BaseType_t prvGMACInit()
{
    gmac_enable_management(GMAC, true);

    gs_gmac_dev.p_hw = GMAC;
    gmac_dev_init(GMAC, &gs_gmac_dev);

    NVIC_SetPriority(GMAC_IRQn, configMAC_INTERRUPT_PRIORITY);
    NVIC_EnableIRQ(GMAC_IRQn);

    /* Init MAC PHY driver */
    if (ethernet_phy_init(GMAC, BOARD_GMAC_PHY_ADDR, sysclk_get_peripheral_hz()) != GMAC_OK)
    {
        puts("PHY Initialize ERROR!\r");
        return false;
    }

    /* Auto Negotiate, work in RMII mode */
    if (ethernet_phy_auto_negotiate(GMAC, BOARD_GMAC_PHY_ADDR) != GMAC_OK)
    {
        puts("Auto Negotiate ERROR!\r");
        return false;
    }

    /* Establish ethernet link */
    if (ethernet_phy_set_link(GMAC, BOARD_GMAC_PHY_ADDR, 1) != GMAC_OK)
    {
        puts("Set link ERROR!\r");
        return false;
    }

    /* Select Media Independent Interface type */
    /* Selecting RMII mode. */
    gmac_select_mii_mode(GMAC, GMAC_PHY_RMII);

    gmac_enable_transmit(GMAC, true);
    gmac_enable_receive(GMAC, true);

    gmac_enable_management(GMAC, false);

    return 1;
}

static uint32_t prvEMACRxPoll()
{
    unsigned char * pucUseBuffer;
    uint32_t ulReceiveCount, ulResult, ulReturnValue = 0;
    static NetworkBufferDescriptor_t * pxNextNetworkBufferDescriptor = nullptr;
    const UBaseType_t xMinDescriptorsToLeave = 2UL;
    const TickType_t xBlockTime = pdMS_TO_TICKS( 100UL );
    static IPStackEvent_t xRxEvent = { eNetworkRxEvent, nullptr };
    uint8_t * pucDMABuffer = nullptr;

    while (true)
    {
        /* If pxNextNetworkBufferDescriptor was not left pointing at a valid
         * descriptor then allocate one now. */
        if ( ( pxNextNetworkBufferDescriptor == nullptr ) && ( uxGetNumberOfFreeNetworkBuffers() > xMinDescriptorsToLeave ) )
        {
            pxNextNetworkBufferDescriptor = pxGetNetworkBufferWithDescriptor( ipTOTAL_ETHERNET_FRAME_SIZE, xBlockTime );
        }

        if ( pxNextNetworkBufferDescriptor != nullptr )
        {
            /* Point pucUseBuffer to the buffer pointed to by the descriptor. */
            pucUseBuffer = ( unsigned char * ) ( pxNextNetworkBufferDescriptor->pucEthernetBuffer - ipconfigPACKET_FILLER_SIZE );
        }
        else
        {
            /* As long as pxNextNetworkBufferDescriptor is nullptr, the incoming
             * messages will be flushed and ignored. */
            pucUseBuffer = nullptr;
        }

        /* Read the next packet from the hardware into pucUseBuffer. */
        ulResult = gmac_dev_read(&gs_gmac_dev, pucUseBuffer, ipTOTAL_ETHERNET_FRAME_SIZE, &ulReceiveCount, &pucDMABuffer);

        if( ( ulResult != GMAC_OK ) || ( ulReceiveCount == 0 ) )
        {
            /* No data from the hardware. */
            break;
        }

        if( pxNextNetworkBufferDescriptor == nullptr)
        {
            /* Data was read from the hardware, but no descriptor was available
             * for it, so it will be dropped. */
            iptraceETHERNET_RX_EVENT_LOST();
            continue;
        }

        iptraceNETWORK_INTERFACE_RECEIVE();

        pxNextNetworkBufferDescriptor = pxPacketBuffer_to_NetworkBuffer(pucDMABuffer);

        if( pxNextNetworkBufferDescriptor == nullptr)
        {
            /* STrange: can not translate from a DMA buffer to a Network Buffer. */
            break;
        }

        pxNextNetworkBufferDescriptor->xDataLength = ( size_t ) ulReceiveCount;
        xRxEvent.pvData = ( void * ) pxNextNetworkBufferDescriptor;

        /* Send the descriptor to the IP task for processing. */
        if (xSendEventStructToIPTask( &xRxEvent, xBlockTime ) != pdTRUE)
        {
            /* The buffer could not be sent to the stack so must be released
             * again. */
            vReleaseNetworkBufferAndDescriptor( pxNextNetworkBufferDescriptor );
            iptraceETHERNET_RX_EVENT_LOST();
            FreeRTOS_printf( ( "prvEMACRxPoll: Can not queue return packet!\n" ) );
        }

        /* Now the buffer has either been passed to the IP-task,
         * or it has been released in the code above. */
        pxNextNetworkBufferDescriptor = nullptr;
        ulReturnValue++;
    }

    return ulReturnValue;
}
/*-----------------------------------------------------------*/

volatile UBaseType_t uxLastMinBufferCount = 0;
#if ( ipconfigCHECK_IP_QUEUE_SPACE != 0 )
    volatile UBaseType_t uxLastMinQueueSpace;
#endif
volatile UBaseType_t uxCurrentSemCount;
volatile UBaseType_t uxLowestSemCount;

void vCheckBuffersAndQueue()
{
    static UBaseType_t uxCurrentCount;

    #if ( ipconfigCHECK_IP_QUEUE_SPACE != 0 )
        {
            uxCurrentCount = uxGetMinimumIPQueueSpace();

            if( uxLastMinQueueSpace != uxCurrentCount )
            {
                /* The logging produced below may be helpful
                 * while tuning +TCP: see how many buffers are in use. */
                uxLastMinQueueSpace = uxCurrentCount;
                //FreeRTOS_printf( ( "Queue space: lowest %lu\n", uxCurrentCount ) );
            }
        }
    #endif /* ipconfigCHECK_IP_QUEUE_SPACE */
    uxCurrentCount = uxGetMinimumFreeNetworkBuffers();

    if( uxLastMinBufferCount != uxCurrentCount )
    {
        /* The logging produced below may be helpful
         * while tuning +TCP: see how many buffers are in use. */
        uxLastMinBufferCount = uxCurrentCount;
        //FreeRTOS_printf( ( "Network buffers: %lu lowest %lu\n", uxGetNumberOfFreeNetworkBuffers(), uxCurrentCount ) );
    }

    if( xTXDescriptorSemaphore != nullptr )
    {
        uxCurrentSemCount = uxSemaphoreGetCount( xTXDescriptorSemaphore );

        if( uxLowestSemCount > uxCurrentSemCount )
        {
            uxLowestSemCount = uxCurrentSemCount;
            //FreeRTOS_printf( ( "TX DMA buffers: lowest %lu\n", uxLowestSemCount ) );
        }
    }
}
/*-----------------------------------------------------------*/

void vNetworkInterfaceAllocateRAMToBuffers(NetworkBufferDescriptor_t pxNetworkBuffers[ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS])
{
    uint8_t* ucRAMBuffer = &ucNetworkPackets[0];

    for(uint32_t ulIndex = 0; ulIndex < ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS; ulIndex++ )
    {
        pxNetworkBuffers[ ulIndex ].pucEthernetBuffer = ucRAMBuffer + ipBUFFER_PADDING;
        *( ( unsigned * ) ucRAMBuffer ) = ( unsigned ) ( &( pxNetworkBuffers[ ulIndex ] ) );
        ucRAMBuffer += NETWORK_BUFFER_SIZE;
    }

    cache_clean_invalidate();
}
/*-----------------------------------------------------------*/

static void prvEMACHandlerTask(void* /*pvParameters*/)
{
    UBaseType_t uxCount = 0U;

    NetworkBufferDescriptor_t* pxBuffer = nullptr;

    uint8_t* pucBuffer = nullptr;

    configASSERT(xEMACTaskHandle);

    while (true)
    {
        vCheckBuffersAndQueue();

        if ((ulISREvents & EMAC_IF_ALL_EVENT) == 0)
        {
            /* No events to process now, wait for the next. */
            ulTaskNotifyTake(pdFALSE, kEMACMaxBlockTimeTicks);
        }

        if ((ulISREvents & EMAC_IF_RX_EVENT) != 0)
        {
            ulISREvents &= ~EMAC_IF_RX_EVENT;

            /* Wait for the EMAC interrupt to indicate that another packet has been
             * received. */
            prvEMACRxPoll();
        }

        if ( ( ulISREvents & EMAC_IF_TX_EVENT ) != 0 )
        {
            /* Future extension: code to release TX buffers if zero-copy is used. */
            ulISREvents &= ~EMAC_IF_TX_EVENT;

            while (xQueueReceive(xTxBufferQueue, &pucBuffer, 0) != pdFALSE)
            {
                pxBuffer = pxPacketBuffer_to_NetworkBuffer(pucBuffer);

                if( pxBuffer != nullptr )
                {
                    vReleaseNetworkBufferAndDescriptor(pxBuffer);
                    //tx_release_count[ 0 ]++;
                }
                else
                {
                    //tx_release_count[ 1 ]++;
                }

                uxCount = uxQueueMessagesWaiting( ( QueueHandle_t ) xTXDescriptorSemaphore );

                if(uxCount < GMAC_TX_BUFFERS)
                {
                    /* Tell the counting semaphore that one more TX descriptor is available. */
                    xSemaphoreGive( xTXDescriptorSemaphore );
                }
            }
        }

        if( ( ulISREvents & EMAC_IF_ERR_EVENT ) != 0 )
        {
            /* Future extension: logging about errors that occurred. */
            ulISREvents &= ~EMAC_IF_ERR_EVENT;
        }
    }
}
/*-----------------------------------------------------------*/
