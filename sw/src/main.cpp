#include <cstdint>

#include <FreeRTOS.h>
#include <task.h>

#include "atmel_start_pins.h"
#include "driver_init.h"

#define TASK_LED_STACK_SIZE (256 / sizeof(portSTACK_TYPE))
#define TASK_LED_STACK_PRIORITY (tskIDLE_PRIORITY + 1)

#define TASK_CAN_STACK_SIZE (256 / sizeof(portSTACK_TYPE))
#define TASK_CAN_STACK_PRIORITY (tskIDLE_PRIORITY + 1)


static TaskHandle_t xCreatedLedTask;
static TaskHandle_t xCreatedCanTask;

static void task_led(void *p)
{
    (void)p;
    while (true)
    {
        gpio_toggle_pin_level(LED0);
        vTaskDelay(500);
    }
}

static void task_can(void* p)
{
    (void)p;

    struct can_message msg;
    struct can_filter  filter;
    uint8_t            send_data[4];
    send_data[0] = 0x00;
    send_data[1] = 0x01;
    send_data[2] = 0x02;
    send_data[3] = 0x03;

    msg.id   = 0x45A;
    msg.type = CAN_TYPE_DATA;
    msg.data = send_data;
    msg.len  = 4;
    msg.fmt  = CAN_FMT_STDID;

    while (true)
    {
        int32_t ret = can_async_write(&CAN_0, &msg);

        gpio_toggle_pin_level(LED1);
        vTaskDelay(1000);
    }
}

int main()
{
    system_init();

    xTaskCreate(task_led, "Led", TASK_LED_STACK_SIZE, NULL, TASK_LED_STACK_PRIORITY, &xCreatedLedTask);
    xTaskCreate(task_can, "CAN", TASK_CAN_STACK_SIZE, NULL, TASK_CAN_STACK_PRIORITY, &xCreatedCanTask);

    //can_async_register_callback(&CAN_1, CAN_ASYNC_RX_CB, (FUNC_PTR)CAN_1_rx_callback);
    //can_async_enable(&CAN_1);
    can_async_enable(&CAN_0);

    vTaskStartScheduler();

    return -1;
}
