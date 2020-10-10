#include <task_ethernet.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <FreeRTOS_IP.h>
#include <FreeRTOS_IP_Private.h>
#include <NetworkBufferManagement.h>

#include <ethernet_phy.h>
#include <gmac.h>
#include <gmac_raw_2.h>
#include <sysclk.h>

#include <conf_eth.h>
#include <mini_ip.h>

#include <array>
#include <cstring>

constexpr const char* kEthernetTaskName = "Ethernet";
constexpr uint32_t kEthernetTaskStackSize = 1024U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kEthernetTaskPriority = tskIDLE_PRIORITY;

static StackType_t ethernet_task_stack[kEthernetTaskStackSize] = {};
static StaticTask_t ethernet_task_buffer = {};

static TaskHandle_t ethernet_task_handle = nullptr;

/** The GMAC driver instance */
static gmac_device_t gs_gmac_dev;

// Hacky hack hack.
extern SemaphoreHandle_t netif_notification_semaphore;


#ifdef __cplusplus
extern "C" {
#endif
/**
 * \brief GMAC interrupt handler.
 */
void GMAC_Handler(void)
{
    gmac_handler(&gs_gmac_dev, GMAC_QUE_0);
}



BaseType_t xNetworkInterfaceInitialise(void)
{
    /* Wait for PHY to be ready (CAT811: Max400ms) */
    //volatile uint32_t ul_delay = sysclk_get_cpu_hz() / 1000 / 3 * 400;
    //while (ul_delay--);

    /* Enable GMAC clock */
    pmc_enable_periph_clk(ID_GMAC);

    /* Fill in GMAC options */
    gmac_options_t gmac_option = {};
    gmac_option.uc_copy_all_frame = 0;
    gmac_option.uc_no_boardcast = 0;

    memcpy(gmac_option.uc_mac_addr, FreeRTOS_GetMACAddress(), sizeof(gmac_option.uc_mac_addr));

    gs_gmac_dev.p_hw = GMAC;

    /* Init GMAC driver structure */
    gmac_dev_init(GMAC, &gs_gmac_dev, &gmac_option);

    /* Enable Interrupt */
    NVIC_SetPriority(GMAC_IRQn, configMAC_INTERRUPT_PRIORITY);
    NVIC_EnableIRQ(GMAC_IRQn);

    /* Init MAC PHY driver */
    if (ethernet_phy_init(GMAC, BOARD_GMAC_PHY_ADDR, sysclk_get_cpu_hz())
                    != GMAC_OK) {
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

    return pdPASS;
}

BaseType_t xNetworkInterfaceOutput(NetworkBufferDescriptor_t * const pxDescriptor, BaseType_t xReleaseAfterSend)
{
    /* Simple network interfaces (as opposed to more efficient zero copy network
    interfaces) just use Ethernet peripheral driver library functions to copy
    data from the FreeRTOS+TCP buffer into the peripheral driver’s own buffer.
    This example assumes SendData() is a peripheral driver library function that
    takes a pointer to the start of the data to be sent and the length of the
    data to be sent as two separate parameters.  The start of the data is located
    by pxDescriptor->pucEthernetBuffer.  The length of the data is located
    by pxDescriptor->xDataLength. */
    uint32_t ul_rc = gmac_dev_write(&gs_gmac_dev, GMAC_QUE_0, pxDescriptor->pucEthernetBuffer,
        pxDescriptor->xDataLength, NULL);

    /* Call the standard trace macro to log the send event. */
    iptraceNETWORK_INTERFACE_TRANSMIT();

    if (xReleaseAfterSend != pdFALSE)
    {
        /* It is assumed SendData() copies the data out of the FreeRTOS+TCP Ethernet
        buffer.  The Ethernet buffer is therefore no longer needed, and must be
        freed for re-use. */
        vReleaseNetworkBufferAndDescriptor(pxDescriptor);
    }

    return ul_rc == GMAC_OK ? pdTRUE : pdFALSE;
}

#ifdef __cplusplus
}
#endif


static void task_ethernet(void* /*pvParameters*/)
{
    constexpr size_t kBufferSizeBytes = 1500U;

    NetworkBufferDescriptor_t *pxBufferDescriptor = nullptr;
    uint32_t receive_size = 0u;
    IPStackEvent_t xRxEvent = {};

    while (true)
    {
        if( xSemaphoreTake(netif_notification_semaphore, portMAX_DELAY) == pdFALSE)
        {
            continue;
        }

        pxBufferDescriptor = pxGetNetworkBufferWithDescriptor(kBufferSizeBytes, 0);
        if (nullptr == pxBufferDescriptor)
        {
            continue;
        }

        /* Process packets */
        if (GMAC_OK != gmac_dev_read(&gs_gmac_dev, GMAC_QUE_0, pxBufferDescriptor->pucEthernetBuffer,
            kBufferSizeBytes, &receive_size))
        {
            vReleaseNetworkBufferAndDescriptor(pxBufferDescriptor);
            continue;
        }

        /* Handle input frame */
        //gmac_process_eth_packet((uint8_t *) gs_uc_eth_buffer, ul_frm_size);
        if (eConsiderFrameForProcessing(pxBufferDescriptor->pucEthernetBuffer) == eProcessBuffer)
        {
            /* The event about to be sent to the TCP/IP is an Rx event. */
            xRxEvent.eEventType = eNetworkRxEvent;

            /* pvData is used to point to the network buffer descriptor that
            now references the received data. */
            xRxEvent.pvData = ( void * ) pxBufferDescriptor;

            /* Send the data to the TCP/IP stack. */
            if( xSendEventStructToIPTask( &xRxEvent, 0 ) == pdFALSE )
            {
                /* The buffer could not be sent to the IP task so the buffer
                must be released. */
                vReleaseNetworkBufferAndDescriptor(pxBufferDescriptor);

                /* Make a call to the standard trace macro to log the
                occurrence. */
                iptraceETHERNET_RX_EVENT_LOST();
            }
            else
            {
                /* The message was successfully sent to the TCP/IP stack.
                Call the standard trace macro to log the occurrence. */
                iptraceNETWORK_INTERFACE_RECEIVE();
            }
        }
        else
        {
            /* The Ethernet frame can be dropped, but the Ethernet buffer
            must be released. */
            vReleaseNetworkBufferAndDescriptor(pxBufferDescriptor);
        }
    }
}

bool create_task_ethernet(const Eui48MacAddress& mac_addr)
{
    constexpr std::array<uint8_t, 4> ip_addr = {ETHERNET_CONF_IPADDR0, ETHERNET_CONF_IPADDR1, ETHERNET_CONF_IPADDR2,
        ETHERNET_CONF_IPADDR3};
    constexpr std::array<uint8_t, 4> net_mask = {255, 255, 255, 0};
    constexpr std::array<uint8_t, 4> gw_addr = ip_addr;
    constexpr std::array<uint8_t, 4> dns_addr = ip_addr;

    FreeRTOS_IPInit(&(ip_addr[0]), &(net_mask[0]), &(gw_addr[0]), &(dns_addr[0]), &(mac_addr[0]));

    ethernet_task_handle = xTaskCreateStatic(
        &task_ethernet,
        kEthernetTaskName,
        kEthernetTaskStackSize,
        nullptr,
        kEthernetTaskPriority,
        &ethernet_task_stack[0],
        &ethernet_task_buffer
    );

    return ethernet_task_handle != nullptr;
}
