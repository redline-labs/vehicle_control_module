#include "task_adc.h"

extern "C"
{
#include "afec.h"
}

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

constexpr const char* kAdcTaskName = "ADC";
constexpr uint32_t kAdcTaskStackSize = 1024U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kAdcTaskPriority = tskIDLE_PRIORITY;

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

    uint32_t ul_value = afec_channel_get_value(AFEC0, AFEC_TEMPERATURE_SENSOR);

    /* Post the byte. */
    xQueueSendFromISR(queue_adc_sample, &ul_value, &xHigherPriorityTaskWoken);

    /* Now the buffer is empty we can switch context if necessary. */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/**
 * \brief Interrupt handler for AFEC1.
 */
void AFEC1_Handler(void)
{
    traceISR_ENTER();
    //afec_process_callback(AFEC1);
    traceISR_EXIT();
}

static void task_adc(void* /*pvParameters*/)
{
    uint32_t rx_adc_sample = 0U;

    while (true)
    {
        if( xQueueReceive(queue_adc_sample, &rx_adc_sample, portMAX_DELAY) == pdPASS )
        {
            int32_t ul_vol = (rx_adc_sample * kVoltRef) / kMaxDigital;
            int32_t ul_temp = (ul_vol - 720)  * 100 / 233 + 27;
            SEGGER_SYSVIEW_PrintfTarget("Temperature is: %4d\r", ul_temp);
        }
    }
}

bool create_task_adc()
{
    queue_adc_sample = xQueueCreate(2U, sizeof(uint32_t));




    afec_enable(AFEC0);

    struct afec_config afec_cfg;

    afec_get_config_defaults(&afec_cfg);

    afec_init(AFEC0, &afec_cfg);

    afec_set_trigger(AFEC0, AFEC_TRIG_SW);

    struct afec_ch_config afec_ch_cfg;
    afec_ch_get_config_defaults(&afec_ch_cfg);

    afec_ch_cfg.gain = AFEC_GAINVALUE_0;
    afec_ch_set_config(AFEC0, AFEC_TEMPERATURE_SENSOR, &afec_ch_cfg);

    /*
     * Because the internal ADC offset is 0x200, it should cancel it and shift
     * down to 0.
     */
    afec_channel_set_analog_offset(AFEC0, AFEC_TEMPERATURE_SENSOR, 0x200);

    struct afec_temp_sensor_config afec_temp_sensor_cfg;

    afec_temp_sensor_get_config_defaults(&afec_temp_sensor_cfg);
    afec_temp_sensor_cfg.rctc = true;
    afec_temp_sensor_set_config(AFEC0, &afec_temp_sensor_cfg);

    irq_register_handler(AFEC0_IRQn, configAFEC_INTERRUPT_PRIORITY);
    irq_register_handler(AFEC1_IRQn, configAFEC_INTERRUPT_PRIORITY);
    afec_enable_interrupt(AFEC0, AFEC_INTERRUPT_EOC_11);

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
