#include <board.h>
#include <conf_features.h>

#include <chip_id_helper.h>
#include <mac_address.h>

#include <task_ethernet.h>
#include <task_led.h>
#include <task_lua.h>
#include <task_monitor.h>

#include <lua.h>

#include <FreeRTOS.h>
#include <task.h>

#include <FreeRTOS_IP.h>

#include <chipid.h>
#include <efc.h>
#include <ethernet_phy.h>
#include <fpu.h>
#include <rstc.h>
#include <serial.h>
#include <stdio_serial.h>
#include <twihs.h>

#include <array>
#include <cstring>

static void configure_console()
{
    constexpr usart_serial_options_t uart_serial_options = {
        .baudrate = CONF_UART_BAUDRATE,
        .charlength = CONF_UART_CHAR_LENGTH,
        .paritytype = CONF_UART_PARITY,
        .stopbits = CONF_UART_STOP_BITS,
    };

    /* Configure console UART. */
    stdio_serial_init(CONF_UART, &uart_serial_options);

    /* Specify that stdout should not be buffered. */
    setbuf(stdout, NULL);
}

static Eui48MacAddress at24mac_get_mac_address()
{
    Eui48MacAddress mac_addr = {};

    /* MAC address */
    twihs_packet_t packet_mac_addr = {};

    packet_mac_addr.chip = BOARD_AT24MAC_EXTENDED_ADDRESS;
    packet_mac_addr.addr[0] = 0x9A;
    packet_mac_addr.addr_length = 1;
    packet_mac_addr.buffer = &(mac_addr[0]);
    packet_mac_addr.length = mac_addr.size();

    if (TWIHS_SUCCESS != twihs_master_read(BOARD_AT24MAC_TWIHS, &packet_mac_addr))
    {
        printf("Failed twihs_master_read init.\n\r");
    }

    if ((mac_addr[0] == 0xFC) || (mac_addr[1] == 0xC2) || (mac_addr[2] == 0x3D))
    {
        mac_addr.unique = true;
    }

    return mac_addr;
}

static const char* get_reset_reason()
{
    uint32_t cause = rstc_get_reset_cause(RSTC);
    //! [reset_get_status]

    /* Decode the reset reason. */
    switch (cause)
    {
        case RSTC_GENERAL_RESET:
            return "General Reset";
            break;

        case RSTC_BACKUP_RESET:
            return "Backup Reset";
            break;

        case RSTC_WATCHDOG_RESET:
            return "Watchdog Reset";
            break;

        case RSTC_SOFTWARE_RESET:
            return "Software Reset";
            break;

        case RSTC_USER_RESET:
            return "User Reset";
            break;

        default:
            return "Invalid reset reason!";
    }
}

int main()
{
    /* Initialize the SAM system */
    sysclk_init();
    board_init();

    /* Initialize the console uart */
    configure_console();

    chipid_data_t chipid_data = {};
    chipid_read(CHIPID, &chipid_data);

    /* Output demo information. */
    printf("Board: " BOARD_NAME "\n\r");
    printf("%s (%s)\n\r", get_chip_id_arch_str(chipid_data.ul_arch),
        get_chip_id_embedded_processor_type_str(chipid_data.ul_eproc));
    printf("%s (NVM: %s, NVM2: %s)\n\r", get_chip_id_nvp_type_str(chipid_data.ul_nvptyp),
        get_chip_id_nvm_size_str(chipid_data.ul_nvpsiz), get_chip_id_nvm2_size_str(chipid_data.ul_nvpsiz2));
    printf("SRAM: %s\n\r", get_chip_id_sram_size_str(chipid_data.ul_sramsiz));
    printf("Sysclock: %ld MHz\n\r", sysclk_get_cpu_hz() / 1000000UL);
    printf("FPU enabled: %s\n\r", fpu_is_enabled() ? "true" : "false");
    printf("Reset cause: %s\n\r", get_reset_reason());

    if constexpr (features::kReadFlashUniqueId)
    {
        // Purposedly keep around another byte to null terminate.
        uint32_t unique_id[5] = {};

        if (EFC_RC_OK != efc_perform_read_sequence(EFC, EFC_FCMD_STUI, EFC_FCMD_SPUI, &(unique_id[0]), 4))
        {
            printf("Failed Read the unique identifier!\n\r");
            return 0;
        }

        printf("Unique ID: %s\n\r", reinterpret_cast<char*>(&(unique_id[0])) + 1U);
    }

    Eui48MacAddress mac_addr = {};
    if constexpr (features::kReadMacFromEeprom)
    {
        mac_addr = at24mac_get_mac_address();
    }

    printf("MAC Address (%s): %02X:%02X:%02X:%02X:%02X:%02X\n\r", mac_addr.unique ? "Unique" : "Hardcoded",
        mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    printf("IP Address: %d.%d.%d.%d\n\r", ETHERNET_CONF_IPADDR0, ETHERNET_CONF_IPADDR1, ETHERNET_CONF_IPADDR2,
        ETHERNET_CONF_IPADDR3);


    printf("-- Compiled (" BUILD_TYPE "): " __DATE__ " " __TIME__ "\n\r");
    printf("-- FreeRTOS " tskKERNEL_VERSION_NUMBER "\n\r");
    printf("-- " LUA_VERSION "\n\r");

    if (false == create_task_monitor())
    {
        printf("Failed to create Monitor task.\r\n");
    }

    if (false == create_task_led())
    {
        printf("Failed to create LED task.\r\n");
    }

    if constexpr (features::kEnableLua)
    {
        if (false == create_task_lua())
        {
            printf("Failed to create Lua task.\r\n");
        }
    }

    if constexpr (features::kEnableEthernet)
    {
        if (false == create_task_ethernet(mac_addr))
        {
            printf("Failed to create Ethernet task.\n\r\n");
        }
    }

    if constexpr (features::kEnableICache)
    {
        SCB_EnableICache();
    }

    if constexpr (features::kEnableDCache)
    {
        SCB_EnableDCache();
    }

    /* Start the scheduler. */
    vTaskStartScheduler();

    /* Will only get here if there was insufficient memory to create the idle task. */
    return 0;
}
