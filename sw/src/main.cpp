#include <cstdint>

#include <FreeRTOS.h>
#include <task.h>

#include "atmel_start_pins.h"
#include "driver_init.h"

#define TASK_LED_STACK_SIZE (108 / sizeof(portSTACK_TYPE))
#define TASK_LED_STACK_PRIORITY (tskIDLE_PRIORITY + 1)


static TaskHandle_t      xCreatedLedTask;


static void task_led(void *p)
{
    (void)p;
    for (;;) {
        gpio_set_pin_level(LED0, true);
        gpio_set_pin_level(LED2, false);
        vTaskDelay(500);

        //gpio_toggle_pin_level(LED1);
        //vTaskDelay(500);

        gpio_set_pin_level(LED0, false);
        gpio_set_pin_level(LED2, true);
        vTaskDelay(500);

        //gpio_toggle_pin_level(LED3);
        //vTaskDelay(500);
    }
}

int main()
{
    system_init();

    xTaskCreate(task_led, "Led", TASK_LED_STACK_SIZE, NULL, TASK_LED_STACK_PRIORITY, &xCreatedLedTask);

    vTaskStartScheduler();

    return -1;
}
