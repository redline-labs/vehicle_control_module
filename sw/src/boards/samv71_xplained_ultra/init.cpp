/**
 * \file
 *
 * \brief SAMV71-XULTRA board init.
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "board.h"
#include "conf_board.h"
#include "ioport.h"
#include "pio.h"
#include "mpu.h"
#include "twihs.h"

/**
 * \brief Set peripheral mode for IOPORT pins.
 * It will configure port mode and disable pin mode (but enable peripheral).
 * \param port IOPORT port to configure
 * \param masks IOPORT pin masks to configure
 * \param mode Mode masks to configure for the specified pin (\ref ioport_modes)
 */
#define ioport_set_port_peripheral_mode(port, masks, mode) \
    do {\
        ioport_set_port_mode(port, masks, mode);\
        ioport_disable_port(port, masks);\
    } while (0)

/**
 * \brief Set peripheral mode for one single IOPORT pin.
 * It will configure port mode and disable pin mode (but enable peripheral).
 * \param pin IOPORT pin to configure
 * \param mode Mode masks to configure for the specified pin (\ref ioport_modes)
 */
#define ioport_set_pin_peripheral_mode(pin, mode) \
    do {\
        ioport_set_pin_mode(pin, mode);\
        ioport_disable_pin(pin);\
    } while (0)

/**
 * \brief Set input mode for one single IOPORT pin.
 * It will configure port mode and disable pin mode (but enable peripheral).
 * \param pin IOPORT pin to configure
 * \param mode Mode masks to configure for the specified pin (\ref ioport_modes)
 * \param sense Sense for interrupt detection (\ref ioport_sense)
 */
#define ioport_set_pin_input_mode(pin, mode, sense) \
    do {\
        ioport_set_pin_dir(pin, IOPORT_DIR_INPUT);\
        ioport_set_pin_mode(pin, mode);\
        ioport_set_pin_sense_mode(pin, sense);\
    } while (0)

/**
 *  Default memory map
 *  Address range        Memory region      Memory type   Shareability  Cache policy
 *  0x00000000- 0x1FFFFFFF Code             Normal        Non-shareable  WT
 *  0x20000000- 0x3FFFFFFF SRAM             Normal        Non-shareable  WBWA
 *  0x40000000- 0x5FFFFFFF Peripheral       Device        Non-shareable  -
 *  0x60000000- 0x7FFFFFFF RAM              Normal        Non-shareable  WBWA
 *  0x80000000- 0x9FFFFFFF RAM              Normal        Non-shareable  WT
 *  0xA0000000- 0xBFFFFFFF Device           Device        Shareable
 *  0xC0000000- 0xDFFFFFFF Device           Device        Non Shareable
 *  0xE0000000- 0xFFFFFFFF System           -                  -
 */

/**
 * \brief Set up a memory region.
 */
static void _setup_memory_region()
{

    uint32_t dw_region_base_addr;
    uint32_t dw_region_attr;

    __DMB();

/**
 *  ITCM memory region --- Normal
 *  START_Addr:-  0x00000000UL
 *  END_Addr:-    0x00400000UL
 */
    dw_region_base_addr =
        ITCM_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_DEFAULT_ITCM_REGION;

    dw_region_attr =
        MPU_AP_PRIVILEGED_READ_WRITE |
        mpu_cal_mpu_region_size(ITCM_END_ADDRESS - ITCM_START_ADDRESS) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);

/**
 *  Internal flash memory region --- Normal read-only
 *  (update to Strongly ordered in write accesses)
 *  START_Addr:-  0x00400000UL
 *  END_Addr:-    0x00600000UL
 */

    dw_region_base_addr =
        IFLASH_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_DEFAULT_IFLASH_REGION;

    dw_region_attr =
        MPU_AP_READONLY |
        INNER_NORMAL_WB_NWA_TYPE( NON_SHAREABLE ) |
        mpu_cal_mpu_region_size(IFLASH_END_ADDRESS - IFLASH_START_ADDRESS) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);

/**
 *  DTCM memory region --- Normal
 *  START_Addr:-  0x20000000L
 *  END_Addr:-    0x20400000UL
 */

    /* DTCM memory region */
    dw_region_base_addr =
        DTCM_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_DEFAULT_DTCM_REGION;

    dw_region_attr =
        MPU_AP_PRIVILEGED_READ_WRITE |
        mpu_cal_mpu_region_size(DTCM_END_ADDRESS - DTCM_START_ADDRESS) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);

/**
 *  SRAM Cacheable memory region --- Normal
 *  START_Addr:-  0x20400000UL
 *  END_Addr:-    0x2043FFFFUL
 */
    /* SRAM memory  region */
    dw_region_base_addr =
        SRAM_FIRST_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_DEFAULT_SRAM_REGION_1;

    dw_region_attr =
        MPU_AP_FULL_ACCESS    |
        INNER_NORMAL_WB_NWA_TYPE( NON_SHAREABLE ) |
        mpu_cal_mpu_region_size(SRAM_FIRST_END_ADDRESS - SRAM_FIRST_START_ADDRESS)
        | MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);


/**
 *  Internal SRAM second partition memory region --- Normal
 *  START_Addr:-  0x20440000UL
 *  END_Addr:-    0x2045FFFFUL
 */
    /* SRAM memory region */
    dw_region_base_addr =
        SRAM_SECOND_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_DEFAULT_SRAM_REGION_2;

    dw_region_attr =
        MPU_AP_FULL_ACCESS    |
        INNER_NORMAL_WB_NWA_TYPE( NON_SHAREABLE ) |
        mpu_cal_mpu_region_size(SRAM_SECOND_END_ADDRESS - SRAM_SECOND_START_ADDRESS) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);

#ifdef MPU_HAS_NOCACHE_REGION
    dw_region_base_addr =
        SRAM_NOCACHE_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_NOCACHE_SRAM_REGION;

    dw_region_attr =
        MPU_AP_FULL_ACCESS    |
        INNER_OUTER_NORMAL_NOCACHE_TYPE( SHAREABLE ) |
        mpu_cal_mpu_region_size(NOCACHE_SRAM_REGION_SIZE) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);
#endif

/**
 *  Peripheral memory region --- DEVICE Shareable
 *  START_Addr:-  0x40000000UL
 *  END_Addr:-    0x5FFFFFFFUL
 */
    dw_region_base_addr =
        PERIPHERALS_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_PERIPHERALS_REGION;

    dw_region_attr = MPU_AP_FULL_ACCESS |
        MPU_REGION_EXECUTE_NEVER |
        SHAREABLE_DEVICE_TYPE |
        mpu_cal_mpu_region_size(PERIPHERALS_END_ADDRESS - PERIPHERALS_START_ADDRESS)
        |MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);


/**
 *  External EBI memory  memory region --- Strongly Ordered
 *  START_Addr:-  0x60000000UL
 *  END_Addr:-    0x6FFFFFFFUL
 */
    dw_region_base_addr =
        EXT_EBI_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_EXT_EBI_REGION;

    dw_region_attr =
        MPU_AP_FULL_ACCESS |
        /* External memory Must be defined with 'Device' or 'Strongly Ordered' attribute for write accesses (AXI) */
        STRONGLY_ORDERED_SHAREABLE_TYPE |
        mpu_cal_mpu_region_size(EXT_EBI_END_ADDRESS - EXT_EBI_START_ADDRESS) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);

/**
 *  SDRAM cacheable memory region --- Normal
 *  START_Addr:-  0x70000000UL
 *  END_Addr:-    0x7FFFFFFFUL
 */
    dw_region_base_addr =
        SDRAM_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_DEFAULT_SDRAM_REGION;

    dw_region_attr =
        MPU_AP_FULL_ACCESS    |
        INNER_NORMAL_WB_RWA_TYPE( SHAREABLE ) |
        mpu_cal_mpu_region_size(SDRAM_END_ADDRESS - SDRAM_START_ADDRESS) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);

/**
 *  QSPI memory region --- Strongly ordered
 *  START_Addr:-  0x80000000UL
 *  END_Addr:-    0x9FFFFFFFUL
 */
    dw_region_base_addr =
        QSPI_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_QSPIMEM_REGION;

    dw_region_attr =
        MPU_AP_FULL_ACCESS |
        STRONGLY_ORDERED_SHAREABLE_TYPE |
        mpu_cal_mpu_region_size(QSPI_END_ADDRESS - QSPI_START_ADDRESS) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);


/**
 *  USB RAM Memory region --- Device
 *  START_Addr:-  0xA0100000UL
 *  END_Addr:-    0xA01FFFFFUL
 */
    dw_region_base_addr =
        USBHSRAM_START_ADDRESS |
        MPU_REGION_VALID |
        MPU_USBHSRAM_REGION;

    dw_region_attr =
        MPU_AP_FULL_ACCESS |
        MPU_REGION_EXECUTE_NEVER |
        SHAREABLE_DEVICE_TYPE |
        mpu_cal_mpu_region_size(USBHSRAM_END_ADDRESS - USBHSRAM_START_ADDRESS) |
        MPU_REGION_ENABLE;

    mpu_set_region( dw_region_base_addr, dw_region_attr);


    /* Enable the memory management fault , Bus Fault, Usage Fault exception */
    SCB->SHCSR |= (SCB_SHCSR_MEMFAULTENA_Msk | SCB_SHCSR_BUSFAULTENA_Msk
                    | SCB_SHCSR_USGFAULTENA_Msk);

    /* Enable the MPU region */
    mpu_enable( MPU_ENABLE | MPU_PRIVDEFENA);

    __DSB();
    __ISB();
}

#if defined(__GNUC__)
extern char _itcm_lma, _sitcm, _eitcm;
#endif

/** \brief  TCM memory enable
* The function enables TCM memories
*/
static inline void tcm_enable()
{

    __DSB();
    __ISB();

    SCB->ITCMCR = (SCB_ITCMCR_EN_Msk  | SCB_ITCMCR_RMW_Msk | SCB_ITCMCR_RETEN_Msk);
    SCB->DTCMCR = ( SCB_DTCMCR_EN_Msk | SCB_DTCMCR_RMW_Msk | SCB_DTCMCR_RETEN_Msk);

    __DSB();
    __ISB();
}

/** \brief  TCM memory Disable

    The function enables TCM memories
 */
static inline void tcm_disable()
{

    __DSB();
    __ISB();
    SCB->ITCMCR &= ~(uint32_t)(1UL);
    SCB->DTCMCR &= ~(uint32_t)SCB_DTCMCR_EN_Msk;
    __DSB();
    __ISB();
}

void board_init()
{
    if constexpr (board::kDisableWatchdogAtInit)
    {
        // Disable the watchdog.
        WDT->WDT_MR = WDT_MR_WDDIS;
    }

    if constexpr (board::kConfigureMpuAtInit)
    {
        _setup_memory_region();
    }

    if constexpr (board::kEnableCacheAtInit)
    {
        /* Enabling the Cache */
        SCB_EnableICache();
        SCB_EnableDCache();
    }

    /* TCM Configuration */
    if constexpr (board::kEnableTcmAtInit)
    {
        EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(8));
        EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB | EEFC_FCR_FARG(7));
        tcm_enable();

#       if defined(__GNUC__)
        volatile char *dst = &_sitcm;
        volatile char *src = &_itcm_lma;
        /* copy code_TCM from flash to ITCM */
        while(dst < &_eitcm)
        {
            *dst++ = *src++;
        }
#       endif
    }
    else
    {
        /* TCM Configuration */
        EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(8));
        EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(7));

        tcm_disable();
    }

    /* Initialize IOPORTs */
    ioport_init();

    /* Configure the pins connected to LED as output and set their
     * default initial state to high (LED off).
     */
    ioport_set_pin_dir(LED0_GPIO, IOPORT_DIR_OUTPUT);
    ioport_set_pin_level(LED0_GPIO, LED0_INACTIVE_LEVEL);
    ioport_set_pin_dir(LED1_GPIO, IOPORT_DIR_OUTPUT);
    ioport_set_pin_level(LED1_GPIO, LED0_INACTIVE_LEVEL);

    /* Configure Push Button pins */
    ioport_set_pin_input_mode(GPIO_PUSH_BUTTON_1, GPIO_PUSH_BUTTON_1_FLAGS,
            GPIO_PUSH_BUTTON_1_SENSE);

    if constexpr (board::kEnableUartConsole)
    {
        /* Configure UART pins */
        ioport_set_pin_peripheral_mode(USART1_RXD_GPIO, USART1_RXD_FLAGS);
        MATRIX->CCFG_SYSIO |= CCFG_SYSIO_SYSIO4;
        ioport_set_pin_peripheral_mode(USART1_TXD_GPIO, USART1_TXD_FLAGS);
    }

    if constexpr (board::kEnableTwi)
    {
        ioport_set_pin_peripheral_mode(TWIHS0_DATA_GPIO, TWIHS0_DATA_FLAGS);
        ioport_set_pin_peripheral_mode(TWIHS0_CLK_GPIO, TWIHS0_CLK_FLAGS);

        /* Enable TWI peripheral */
        if (0U != pmc_enable_periph_clk(ID_TWIHS0))
        {
            // printf("Failed to init PMC.\n\r");
        }

        /* Init TWI peripheral */
        twihs_options_t opt = {};
        opt.master_clk = sysclk_get_cpu_hz();
        opt.speed = BOARD_AT24MAC_TWIHS_CLK;
        if (TWIHS_SUCCESS != twihs_master_init(BOARD_AT24MAC_TWIHS, &opt))
        {
            // printf("Failed master init.\n\r");
        }
    }

    if constexpr (board::kEnableEthernet)
    {
        pmc_enable_periph_clk(ID_GMAC);

        // Allow reading the Link status via DIO.
        //ioport_set_pin_input_mode(PIN_GMAC_SIDET_GPIO, 0U /*IOPORT_MODE_PULLUP*/, IOPORT_SENSE_BOTHEDGES);
    }

    if constexpr (board::kEnableCan0)
    {
        /* Configure the CAN0 TX and RX pins. */
        ioport_set_pin_peripheral_mode(PIN_CAN0_RX_IDX, PIN_CAN0_RX_FLAGS);
        ioport_set_pin_peripheral_mode(PIN_CAN0_TX_IDX, PIN_CAN0_TX_FLAGS);
        /* Configure the transiver0 RS & EN pins. */
        ioport_set_pin_dir(PIN_CAN0_TR_RS_IDX, IOPORT_DIR_OUTPUT);
        ioport_set_pin_dir(PIN_CAN0_TR_EN_IDX, IOPORT_DIR_OUTPUT);
    }

    if constexpr (board::kEnableCan1)
    {
        /* Configure the CAN1 TX and RX pin. */
        ioport_set_pin_peripheral_mode(PIN_CAN1_RX_IDX, PIN_CAN1_RX_FLAGS);
        ioport_set_pin_peripheral_mode(PIN_CAN1_TX_IDX, PIN_CAN1_TX_FLAGS);
    }

    if constexpr (board::kEnableSpi)
    {
        ioport_set_pin_peripheral_mode(SPI0_MISO_GPIO, SPI0_MISO_FLAGS);
        ioport_set_pin_peripheral_mode(SPI0_MOSI_GPIO, SPI0_MOSI_FLAGS);
        ioport_set_pin_peripheral_mode(SPI0_NPCS0_GPIO, SPI0_NPCS0_FLAGS);
        ioport_set_pin_peripheral_mode(SPI0_SPCK_GPIO, SPI0_SPCK_FLAGS);
    }

    if constexpr (board::kEnableQspi)
    {
        ioport_set_pin_peripheral_mode(QSPI_QSCK_GPIO, QSPI_QSCK_FLAGS);
        ioport_set_pin_peripheral_mode(QSPI_QCS_GPIO, QSPI_QCS_FLAGS);
        ioport_set_pin_peripheral_mode(QSPI_QIO0_GPIO, QSPI_QIO0_FLAGS);
        ioport_set_pin_peripheral_mode(QSPI_QIO1_GPIO, QSPI_QIO1_FLAGS);
        ioport_set_pin_peripheral_mode(QSPI_QIO2_GPIO, QSPI_QIO2_FLAGS);
        ioport_set_pin_peripheral_mode(QSPI_QIO3_GPIO, QSPI_QIO3_FLAGS);
    }

    if constexpr (board::kEnablePwmLed0)
    {
        /* Configure PWM LED0 pin */
        ioport_set_pin_peripheral_mode(PIN_PWM_LED0_GPIO, PIN_PWM_LED0_FLAGS);
    }

    if constexpr (board::kEnablePwmLed1)
    {
        /* Configure PWM LED1 pin */
        ioport_set_pin_peripheral_mode(PIN_PWM_LED1_GPIO, PIN_PWM_LED1_FLAGS);
    }


    if constexpr (board::kConfigureUsartRxd)
    {
        /* Configure USART RXD pin */
        ioport_set_pin_peripheral_mode(USART0_RXD_GPIO, USART0_RXD_FLAGS);
    }

    if constexpr (board::kConfigureUsartTxd)
    {
        /* Configure USART TXD pin */
        ioport_set_pin_peripheral_mode(USART0_TXD_GPIO, USART0_TXD_FLAGS);
    }

    if constexpr (board::kConfigureUsartSck)
    {
        /* Configure USART synchronous communication SCK pin */
        ioport_set_pin_peripheral_mode(PIN_USART0_SCK_IDX,PIN_USART0_SCK_FLAGS);
    }

    if constexpr (board::kConfigureUsartCts)
    {
        /* Configure USART synchronous communication CTS pin */
        ioport_set_pin_peripheral_mode(PIN_USART0_CTS_IDX,PIN_USART0_CTS_FLAGS);
    }

    if constexpr (board::kConfigureUsartRts)
    {
        /* Configure USART RTS pin */
        ioport_set_pin_peripheral_mode(PIN_USART0_RTS_IDX, PIN_USART0_RTS_FLAGS);
    }

    if constexpr (board::kEnableSdMmc)
    {
        /* Configure HSMCI pins */
        ioport_set_pin_peripheral_mode(PIN_HSMCI_MCCDA_GPIO, PIN_HSMCI_MCCDA_FLAGS);
        ioport_set_pin_peripheral_mode(PIN_HSMCI_MCCK_GPIO, PIN_HSMCI_MCCK_FLAGS);
        ioport_set_pin_peripheral_mode(PIN_HSMCI_MCDA0_GPIO, PIN_HSMCI_MCDA0_FLAGS);
        ioport_set_pin_peripheral_mode(PIN_HSMCI_MCDA1_GPIO, PIN_HSMCI_MCDA1_FLAGS);
        ioport_set_pin_peripheral_mode(PIN_HSMCI_MCDA2_GPIO, PIN_HSMCI_MCDA2_FLAGS);
        ioport_set_pin_peripheral_mode(PIN_HSMCI_MCDA3_GPIO, PIN_HSMCI_MCDA3_FLAGS);

        /* Configure SD/MMC card detect pin */
        ioport_set_pin_dir(SD_MMC_0_CD_GPIO, IOPORT_DIR_INPUT);
        ioport_set_pin_mode(SD_MMC_0_CD_GPIO, SD_MMC_0_CD_FLAGS);
    }

    if constexpr (board::kEnableLcd)
    {
        /**LCD pin configure on EBI*/
        pio_configure(PIN_EBI_RESET_PIO, PIN_EBI_RESET_TYPE, PIN_EBI_RESET_MASK, PIN_EBI_RESET_ATTRI);
        pio_configure(PIN_EBI_CDS_PIO, PIN_EBI_CDS_TYPE, PIN_EBI_CDS_MASK, PIN_EBI_CDS_ATTRI);
        pio_configure(PIN_EBI_DATAL_PIO, PIN_EBI_DATAL_TYPE, PIN_EBI_DATAL_MASK, PIN_EBI_DATAL_ATTRI);
        pio_configure(PIN_EBI_DATAH_0_PIO, PIN_EBI_DATAH_0_TYPE, PIN_EBI_DATAH_0_MASK, PIN_EBI_DATAH_0_ATTRI);
        pio_configure(PIN_EBI_DATAH_1_PIO, PIN_EBI_DATAH_1_TYPE, PIN_EBI_DATAH_1_MASK, PIN_EBI_DATAH_1_ATTRI);
        pio_configure(PIN_EBI_NWE_PIO, PIN_EBI_NWE_TYPE, PIN_EBI_NWE_MASK, PIN_EBI_NWE_ATTRI);
        pio_configure(PIN_EBI_NRD_PIO, PIN_EBI_NRD_TYPE, PIN_EBI_NRD_MASK, PIN_EBI_NRD_ATTRI);
        pio_configure(PIN_EBI_CS_PIO, PIN_EBI_CS_TYPE, PIN_EBI_CS_MASK, PIN_EBI_CS_ATTRI);
        pio_configure(PIN_EBI_BACKLIGHT_PIO, PIN_EBI_BACKLIGHT_TYPE, PIN_EBI_BACKLIGHT_MASK, PIN_EBI_BACKLIGHT_ATTRI);
        pio_set(PIN_EBI_BACKLIGHT_PIO, PIN_EBI_BACKLIGHT_MASK);
    }

    if constexpr (board::kEnableUsb && board::kConfigureUsbVbusDetect)
    {
        ioport_set_pin_dir(USB_VBUS_PIN, IOPORT_DIR_INPUT);
    }

    if constexpr (board::kEnableUsb && board::kConfigureUsbIdDetect)
    {
        ioport_set_pin_dir(USB_ID_PIN, IOPORT_DIR_INPUT);
    }

    if constexpr (board::kEnableSdram)
    {
        pio_configure_pin(SDRAM_BA0_PIO, SDRAM_BA0_FLAGS);
        pio_configure_pin(SDRAM_SDCK_PIO, SDRAM_SDCK_FLAGS);
        pio_configure_pin(SDRAM_SDCKE_PIO, SDRAM_SDCKE_FLAGS);
        pio_configure_pin(SDRAM_SDCS_PIO, SDRAM_SDCS_FLAGS);
        pio_configure_pin(SDRAM_RAS_PIO, SDRAM_RAS_FLAGS);
        pio_configure_pin(SDRAM_CAS_PIO, SDRAM_CAS_FLAGS);
        pio_configure_pin(SDRAM_SDWE_PIO, SDRAM_SDWE_FLAGS);
        pio_configure_pin(SDRAM_NBS0_PIO, SDRAM_NBS0_FLAGS);
        pio_configure_pin(SDRAM_NBS1_PIO, SDRAM_NBS1_FLAGS);
        pio_configure_pin(SDRAM_A2_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A3_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A4_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A5_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A6_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A7_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A8_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A9_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A10_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_A11_PIO, SDRAM_A_FLAGS);
        pio_configure_pin(SDRAM_SDA10_PIO, SDRAM_SDA10_FLAGS);
        pio_configure_pin(SDRAM_D0_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D1_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D2_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D3_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D4_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D5_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D6_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D7_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D8_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D9_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D10_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D11_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D12_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D13_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D14_PIO, SDRAM_D_FLAGS);
        pio_configure_pin(SDRAM_D15_PIO, SDRAM_D_FLAGS);

        MATRIX->CCFG_SMCNFCS = CCFG_SMCNFCS_SDRAMEN;
    }

    if constexpr (board::kEnableIsi)
    {
        pio_configure_pin(ISI_D0_PIO, ISI_D0_FLAGS);
        pio_configure_pin(ISI_D1_PIO, ISI_D1_FLAGS);
        pio_configure_pin(ISI_D2_PIO, ISI_D2_FLAGS);
        pio_configure_pin(ISI_D3_PIO, ISI_D3_FLAGS);
        pio_configure_pin(ISI_D4_PIO, ISI_D4_FLAGS);
        pio_configure_pin(ISI_D5_PIO, ISI_D5_FLAGS);
        pio_configure_pin(ISI_D6_PIO, ISI_D6_FLAGS);
        pio_configure_pin(ISI_D7_PIO, ISI_D7_FLAGS);
        pio_configure_pin(ISI_D8_PIO, ISI_D8_FLAGS);
        pio_configure_pin(ISI_D9_PIO, ISI_D9_FLAGS);
        pio_configure_pin(ISI_D10_PIO, ISI_D10_FLAGS);
        pio_configure_pin(ISI_D11_PIO, ISI_D11_FLAGS);
        pio_configure_pin(ISI_HSYNC_PIO, ISI_HSYNC_FLAGS);
        pio_configure_pin(ISI_VSYNC_PIO, ISI_VSYNC_FLAGS);
        pio_configure_pin(ISI_PCK_PIO, ISI_PCK_FLAGS);
        pio_configure_pin(ISI_PCK0_PIO, ISI_PCK0_FLAGS);
        pio_configure_pin(OV_PWD_GPIO, OV_PWD_FLAGS);
        pio_configure_pin(OV_RST_GPIO, OV_RST_FLAGS);
    }
}
