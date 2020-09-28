#include "task_lua.h"

#include "ioport.h"

#include "FreeRTOS.h"
#include "task.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

constexpr const char* kLuaTaskName = "Lua";
constexpr uint32_t kLuaTaskStackSize = (10U * 1024U) / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kLuaTaskPriority = tskIDLE_PRIORITY;
constexpr TickType_t kTaskRateTicks = pdMS_TO_TICKS(1000);

static StackType_t lua_task_stack[kLuaTaskStackSize] = {};
static StaticTask_t lua_task_buffer = {};

static TaskHandle_t lua_task_handle = nullptr;

static lua_State* L = nullptr;

static int toggle_led(lua_State* /*L*/)
{
    ioport_toggle_pin_level(LED1_GPIO);

    return 0;
}

static void task_lua(void* /*pvParameters*/)
{
    TickType_t last_wake_time_ticks = xTaskGetTickCount();

    while (true)
    {
        //ioport_toggle_pin_level(LED1_GPIO);
        luaL_dostring(L, "toggle_led()");
        vTaskDelayUntil(&last_wake_time_ticks, kTaskRateTicks);
    }
}

bool create_task_lua()
{
    L = luaL_newstate();
    luaL_openlibs(L);
    lua_pushcfunction(L, toggle_led);
    lua_setglobal(L, "toggle_led");

    lua_task_handle = xTaskCreateStatic(
        &task_lua,
        kLuaTaskName,
        kLuaTaskStackSize,
        nullptr,
        kLuaTaskPriority,
        &lua_task_stack[0],
        &lua_task_buffer
    );

    return lua_task_handle != nullptr;
}
