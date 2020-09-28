#include "task_led.h"

#include "ioport.h"

#include "FreeRTOS.h"
#include "task.h"

constexpr const char* kLedTaskName = "LED";
constexpr uint32_t kLedTaskStackSize = 1024U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kLedTaskPriority = tskIDLE_PRIORITY;
constexpr TickType_t kTaskRateTicks = pdMS_TO_TICKS(500);

static StackType_t led_task_stack[kLedTaskStackSize] = {};
static StaticTask_t led_task_buffer = {};

static TaskHandle_t led_task_handle = nullptr;

static void task_led(void* /*pvParameters*/)
{
    TickType_t last_wake_time_ticks = xTaskGetTickCount();

    while (true)
    {
        ioport_toggle_pin_level(LED0_GPIO);
        vTaskDelayUntil(&last_wake_time_ticks, kTaskRateTicks);
    }
}

bool create_task_led()
{
    led_task_handle = xTaskCreateStatic(
        &task_led,
        kLedTaskName,
        kLedTaskStackSize,
        nullptr,
        kLedTaskPriority,
        &led_task_stack[0],
        &led_task_buffer
    );

    return led_task_handle != nullptr;
}
