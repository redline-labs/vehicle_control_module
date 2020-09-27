#include "board.h"
#include "core_cm7.h"

#include <cstdint>

extern "C"
{
    void configure_debug_cycle_counter();
    uint32_t read_debug_cycle_counter();
}

// https://www.avrfreaks.net/comment/1884261#comment-1884261

void configure_debug_cycle_counter()
{
    CoreDebug->DEMCR = CoreDebug_DEMCR_TRCENA_Msk;
    __DSB(); DWT->LAR = 0xC5ACCE55; __DSB();
    DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
    DWT->CYCCNT = 0;
    DWT->CTRL = DWT_CTRL_CYCCNTENA_Msk;
}

uint32_t read_debug_cycle_counter()
{
    // We are running at 300MHz, so by shifting right by 14, we nock our rate down to ~18kHz
    return DWT->CYCCNT >> 14;
}
