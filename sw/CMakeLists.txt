# Based on https://github.com/cortexm/baremetal/blob/master/CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

# project name
project(vehicle_control_module)

# Default to `Release` build type.
if(NOT CMAKE_BUILD_TYPE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY VALUE "Release")
endif()

add_compile_options(
    -mthumb -mcpu=cortex-m7
    -mfloat-abi=hard
    -mfpu=fpv5-d16

    $<$<COMPILE_LANGUAGE:C>:-std=c11>
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
    $<$<COMPILE_LANGUAGE:CXX>:-fms-extensions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
    -fstrict-volatile-bitfields
    -ffunction-sections
    -fno-threadsafe-statics

    -Werror
    -Wall
    -Wextra
    -Wcast-align
    -Wconversion
    -Wsign-conversion
    -Wold-style-cast
    -Wshadow
    -Wlogical-op
    -Wsuggest-override
    -Wsuggest-final-types
    -Wsuggest-final-methods
    -pedantic
)