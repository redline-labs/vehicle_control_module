#ifndef CONF_FEATURES_H_
#define CONF_FEATURES_H_

#include <cstdbool>

namespace features
{

// Enable the Lua interpreter.
constexpr bool kEnableLua = false;

// Enable reading the unique ID from Flash.
constexpr bool kReadFlashUniqueId = true;

constexpr bool kEnableICache = true;
constexpr bool kEnableDCache = true;

}  // namespace features

#endif  //CONF_FEATURES_H_
