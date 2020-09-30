#ifndef CONF_BOARD_H_
#define CONF_BOARD_H_

#include <cstdbool>

namespace board
{

/* Configure UART pins */
constexpr bool kEnableUartConsole = true;
constexpr bool kDisableWatchdogAtInit = true;
constexpr bool kConfigureMpuAtInit = false;
constexpr bool kEnableCacheAtInit = false;
constexpr bool kEnableTcmAtInit = false;

}  // namespace board

#endif  // CONF_BOARD_H_
