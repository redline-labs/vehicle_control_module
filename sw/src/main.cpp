#include <asf.h>
#include "conf_board.h"

constexpr const char* kTaskMonitorTaskName = "Monitor";
constexpr uint32_t kTaskMonitorTaskStackSize = 2048U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kTaskMonitorTaskPriority = tskIDLE_PRIORITY;
static StackType_t task_monitor_task_stack[kTaskMonitorTaskStackSize] = {};
static StaticTask_t task_monitor_task_buffer = {};

constexpr const char* kLedTaskName = "LED";
constexpr uint32_t kLedTaskStackSize = 1024U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kLedTaskPriority = tskIDLE_PRIORITY;
static StackType_t led_task_stack[kLedTaskStackSize] = {};
static StaticTask_t led_task_buffer = {};

static void task_monitor(void* /*pvParameters*/)
{
	constexpr uint32_t kMaxNumTasks = 10U;
    TaskStatus_t task_statuses[kMaxNumTasks] = {};
    unsigned long total_run_time = 0;

    TickType_t last_wake_time_ticks = xTaskGetTickCount();
    constexpr TickType_t kTaskRateTicks = pdMS_TO_TICKS(5000);

    while (true)
    {
        uint8_t num_tasks = uxTaskGetSystemState(&(task_statuses[0]),
        	kMaxNumTasks,
        	&total_run_time);

        printf("Num tasks = %u\n\r", num_tasks);
        printf(" ~~ Total run time = %u ~~ \n\r", total_run_time);

        for (uint8_t i = 0U; i < num_tasks; ++i)
        {
        	printf(" :: %s\t%u\n\r", task_statuses[i].pcTaskName, task_statuses[i].ulRunTimeCounter);
        }

        vTaskDelayUntil(&last_wake_time_ticks, kTaskRateTicks);
    }
}

static void task_led(void *pvParameters)
{
    UNUSED(pvParameters);

    TickType_t last_wake_time_ticks = xTaskGetTickCount();
    constexpr TickType_t kTaskRateTicks = pdMS_TO_TICKS(500);

    for (;;)
    {
        LED_Toggle(LED0);
        vTaskDelayUntil(&last_wake_time_ticks, kTaskRateTicks);
    }
}

static void configure_console(void)
{
    const usart_serial_options_t uart_serial_options = {
        .baudrate = CONF_UART_BAUDRATE,
#if (defined CONF_UART_CHAR_LENGTH)
        .charlength = CONF_UART_CHAR_LENGTH,
#endif
        .paritytype = CONF_UART_PARITY,
#if (defined CONF_UART_STOP_BITS)
        .stopbits = CONF_UART_STOP_BITS,
#endif
    };

    /* Configure console UART. */
    stdio_serial_init(CONF_UART, &uart_serial_options);

    /* Specify that stdout should not be buffered. */
    setbuf(stdout, NULL);
}

/**
 *  \brief FreeRTOS Real Time Kernel example entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */
int main(void)
{
	TaskHandle_t monitor_task_handle = nullptr;
	TaskHandle_t led_task_handle = nullptr;

    /* Initialize the SAM system */
    sysclk_init();
    board_init();

    /* Initialize the console uart */
    configure_console();

    /* Output demo information. */
    printf("-- FreeRTOS " tskKERNEL_VERSION_NUMBER "\n\r");
    printf("-- %s\n\r", BOARD_NAME);
    printf("-- Compiled: %s %s --\n\r", __DATE__, __TIME__);
    printf("-- FPU enabled: %s\n\r", fpu_is_enabled() ? "true" : "false");
    printf("-- SYSCLCK %d\n\r", sysclk_get_cpu_hz());

    monitor_task_handle = xTaskCreateStatic(
    	&task_monitor,
    	kTaskMonitorTaskName,
    	kTaskMonitorTaskStackSize,
    	nullptr,
    	kTaskMonitorTaskPriority,
    	&task_monitor_task_stack[0],
    	&task_monitor_task_buffer
    );

    if (monitor_task_handle  == nullptr)
    {
    	printf("Failed to create Monitor task\r\n");
    }

    led_task_handle = xTaskCreateStatic(
    	&task_led,
    	kLedTaskName,
    	kLedTaskStackSize,
    	nullptr,
    	kLedTaskPriority,
    	&led_task_stack[0],
    	&led_task_buffer
    );

    if (led_task_handle  == nullptr)
    {
    	printf("Failed to create LED task\r\n");
    }

    /* Start the scheduler. */
    vTaskStartScheduler();

    /* Will only get here if there was insufficient memory to create the idle task. */
    return 0;
}
