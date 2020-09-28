#include "conf_board.h"
#include "conf_features.h"

#include "chip_id_helper.h"
#include "task_monitor.h"
#include "task_led.h"
#include "task_lua.h"
#include "lua.h"

#include <FreeRTOS.h>
#include <task.h>

#include <chipid.h>
#include <fpu.h>
#include <serial.h>
#include <stdio_serial.h>

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

int main()
{
    /* Initialize the SAM system */
    sysclk_init();
    board_init();

    /* Initialize the console uart */
    configure_console();

    chipid_data_t chipid_data;
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

    printf("-- Compiled: " __DATE__ " " __TIME__ " --\n\r");
    printf("-- FreeRTOS " tskKERNEL_VERSION_NUMBER "\n\r");
    printf("-- " LUA_VERSION "\n\r");

    if (false == create_task_monitor())
    {
        printf("Failed to create Monitor task\r\n");
    }

    if (false == create_task_led())
    {
        printf("Failed to create LED task\r\n");
    }

    if constexpr (kFeaturesEnableLua)
    {
        if (false == create_task_lua())
        {
            printf("Failed to create Lua task\r\n");
        }
    }

    /* Start the scheduler. */
    vTaskStartScheduler();

    /* Will only get here if there was insufficient memory to create the idle task. */
    return 0;
}
