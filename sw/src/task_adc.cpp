#include "task_adc.h"

extern "C"
{
#include "afec.h"
}

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

#include "board.h"

constexpr const char* kAdcTaskName = "ADC";
constexpr uint32_t kAdcTaskStackSize = 1024U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kAdcTaskPriority = tskIDLE_PRIORITY;
constexpr TickType_t kAdcTaskRateTicks = pdMS_TO_TICKS(20);

static StackType_t adc_task_stack[kAdcTaskStackSize] = {};
static StaticTask_t adc_task_buffer = {};

static TaskHandle_t adc_task_handle = nullptr;

static QueueHandle_t queue_adc_sample = {};

/** Reference voltage for AFEC,in mv. */
constexpr uint32_t kVoltRef = 3300UL;

/** The maximal digital value */
constexpr uint32_t kMaxDigital = 4095UL;

void AFEC0_Handler(void)
{
    traceISR_ENTER();

    //volatile uint32_t status;
    //uint32_t cnt, inst_num;

    //status = afec_get_interrupt_status(afec) & afec_get_interrupt_mask(afec);
    //inst_num = afec_find_inst_num(afec);

    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //uint32_t ul_value = afec_channel_get_value(AFEC0, PIN_HIGHSIDE1_ADC_CHANNEL);

    /* Post the byte. */
    ///xQueueSendFromISR(queue_adc_sample, &ul_value, &xHigherPriorityTaskWoken);

    /* Now the buffer is empty we can switch context if necessary. */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/**
 * \brief Interrupt handler for AFEC1.
 */
void AFEC1_Handler(void)
{
    traceISR_ENTER();
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    uint32_t ul_value = afec_channel_get_value(AFEC1, PIN_HIGHSIDE12_ADC_CHANNEL);

    /* Post the byte. */
    xQueueSendFromISR(queue_adc_sample, &ul_value, &xHigherPriorityTaskWoken);

    /* Now the buffer is empty we can switch context if necessary. */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

static void task_adc(void* /*pvParameters*/)
{
    uint32_t rx_adc_sample = 0U;
    TickType_t last_wake_time_ticks = xTaskGetTickCount();

    while (true)
    {
        afec_start_software_conversion(AFEC1);
        if (xQueueReceive(queue_adc_sample, &rx_adc_sample, portMAX_DELAY) == pdPASS)
        {
            SEGGER_SYSVIEW_PrintfTarget("ADC is: %d", rx_adc_sample);
        }

        vTaskDelayUntil(&last_wake_time_ticks, kAdcTaskRateTicks);
    }
}

bool create_task_adc()
{
    queue_adc_sample = xQueueCreate(2U, sizeof(uint32_t));

    adc_task_handle = xTaskCreateStatic(
        &task_adc,
        kAdcTaskName,
        kAdcTaskStackSize,
        nullptr,
        kAdcTaskPriority,
        &adc_task_stack[0],
        &adc_task_buffer
    );

    return adc_task_handle != nullptr;
}
