#include <FreeRTOS.h>
#include <task.h>

#include <FreeRTOS_IP.h>
#include <FreeRTOS_Sockets.h>

#include <cstdint>

extern "C"
{
BaseType_t xApplicationGetRandomNumber(uint32_t *pulNumber);

uint32_t ulApplicationGetNextSequenceNumber(uint32_t ulSourceAddress,
     uint16_t usSourcePort,
     uint32_t ulDestinationAddress,
     uint16_t usDestinationPort);
}

/**
 * \brief Called if stack overflow during execution
 */

/* configSUPPORT_STATIC_ALLOCATION is set to 1, so the application must provide an
implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
used by the Idle task. */
void vApplicationGetIdleTaskMemory( StaticTask_t** ppxIdleTaskTCBBuffer,
                                    StackType_t** ppxIdleTaskStackBuffer,
                                    uint32_t* pulIdleTaskStackSize )
{
    /* If the buffers to be provided to the Idle task are declared inside this
    function then they must be declared static – otherwise they will be allocated on
    the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task’s
    state will be stored. */
    if (ppxIdleTaskTCBBuffer != nullptr)
    {
        *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    }

    /* Pass out the array that will be used as the Idle task’s stack. */
    if (ppxIdleTaskStackBuffer != nullptr)
    {
        *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    }

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    if (pulIdleTaskStackSize != nullptr)
    {
        *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
    }
}
/*———————————————————–*/

/* configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory( StaticTask_t** ppxTimerTaskTCBBuffer,
                                     StackType_t** ppxTimerTaskStackBuffer,
                                     uint32_t* pulTimerTaskStackSize)
{
    /* If the buffers to be provided to the Timer task are declared inside this
    function then they must be declared static – otherwise they will be allocated on
    the stack and so not exists after this function exits. */
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task’s state will be stored. */
    if (ppxTimerTaskTCBBuffer != nullptr)
    {
        *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
    }

    /* Pass out the array that will be used as the Timer task’s stack. */
    if (ppxTimerTaskStackBuffer != nullptr)
    {
        *ppxTimerTaskStackBuffer = uxTimerTaskStack;
    }

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
    if (pulTimerTaskStackSize != nullptr)
    {
        *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
    }
}

BaseType_t xApplicationGetRandomNumber(uint32_t *pulNumber)
{
    static UBaseType_t ulNextRand;

    BaseType_t ret = pdFAIL;

    if (nullptr != pulNumber)
    {
        const uint32_t ulMultiplier = 0x015a4e35UL, ulIncrement = 1UL;

        /* Utility function to generate a pseudo random number. */

        ulNextRand = ( ulMultiplier * ulNextRand ) + ulIncrement;
        *pulNumber = ( int ) ( ulNextRand >> 16UL ) & 0x7fffUL;
        ret = pdPASS;
    }

    return ret;
}


uint32_t ulApplicationGetNextSequenceNumber(uint32_t ulSourceAddress,
     uint16_t usSourcePort,
     uint32_t ulDestinationAddress,
     uint16_t usDestinationPort)
{
    static uint32_t seq = 0U;

    return ++seq;
}
