#include "task_monitor.h"
#include "FreeRTOS.h"
#include "task.h"

#include <array>

constexpr const char* kTaskMonitorTaskName = "Monitor";
constexpr uint32_t kTaskMonitorTaskStackSize = 2048U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kTaskMonitorTaskPriority = tskIDLE_PRIORITY;
constexpr TickType_t kTaskRateTicks = pdMS_TO_TICKS(5000);

static StackType_t task_monitor_task_stack[kTaskMonitorTaskStackSize] = {};
static StaticTask_t task_monitor_task_buffer = {};

static TaskHandle_t monitor_task_handle = nullptr;

constexpr uint32_t kMaxNumTasks = 10U;

static void task_monitor(void* /*pvParameters*/)
{
    std::array<TaskStatus_t, kMaxNumTasks> task_statuses = {};
    unsigned long total_run_time = 0;

    TickType_t last_wake_time_ticks = xTaskGetTickCount();

    while (true)
    {
        uint8_t num_tasks = uxTaskGetSystemState(&(task_statuses[0]),
            kMaxNumTasks,
            &total_run_time);

        printf("Num tasks = %u\n\r", num_tasks);
        printf(" ~~ Total run time = %lu ~~ \n\r", total_run_time);

        for (uint8_t i = 0; i < num_tasks; ++i)
        {
            const auto& task = task_statuses[i];
            printf(" :: %s\t%lu\n\r", task.pcTaskName, task.ulRunTimeCounter);
        }

        vTaskDelayUntil(&last_wake_time_ticks, kTaskRateTicks);
    }
}

bool create_task_monitor()
{
    monitor_task_handle = xTaskCreateStatic(
        &task_monitor,
        kTaskMonitorTaskName,
        kTaskMonitorTaskStackSize,
        nullptr,
        kTaskMonitorTaskPriority,
        &task_monitor_task_stack[0],
        &task_monitor_task_buffer
    );

    return monitor_task_handle != nullptr;
}
