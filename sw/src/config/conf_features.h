#ifndef CONF_FEATURES_H_
#define CONF_FEATURES_H_

#include <cstdbool>

namespace features
{

// Enable the Lua interpreter.
constexpr bool kEnableLua = true;
constexpr bool kEnableEthernet = true;

// Enable reading the unique ID from Flash.
constexpr bool kReadFlashUniqueId = true;
constexpr bool kReadMacFromEeprom = true;

constexpr bool kEnableICache = true;
constexpr bool kEnableDCache = false;

}  // namespace features

#endif  //CONF_FEATURES_H_
