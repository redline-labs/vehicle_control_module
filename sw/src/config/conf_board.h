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

constexpr bool kEnableTwi = true;

constexpr bool kEnableCan0 = false;
constexpr bool kEnableCan1 = false;

constexpr bool kEnableSpi = false;
constexpr bool kEnableQspi = false;

constexpr bool kEnablePwmLed0 = false;
constexpr bool kEnablePwmLed1 = false;

constexpr bool kConfigureUsartRxd = false;
constexpr bool kConfigureUsartTxd = false;
constexpr bool kConfigureUsartSck = false;
constexpr bool kConfigureUsartCts = false;
constexpr bool kConfigureUsartRts = false;

constexpr bool kEnableSdMmc = false;
constexpr bool kEnableLcd = false;

constexpr bool kEnableUsb = false;
constexpr bool kConfigureUsbVbusDetect = false;
constexpr bool kConfigureUsbIdDetect = false;

constexpr bool kEnableSdram = false;

constexpr bool kEnableIsi = false;

}  // namespace board

#endif  // CONF_BOARD_H_
