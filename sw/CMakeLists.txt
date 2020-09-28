# Based on https://github.com/cortexm/baremetal/blob/master/CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

# https://github.com/cortexm/baremetal
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_C_COMPILER_ID GNU)
set(CMAKE_CXX_COMPILER_ID GNU)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

set(CMAKE_C_FLAGS_DEBUG "" CACHE STRING "")
set(CMAKE_CXX_FLAGS_DEBUG "" CACHE STRING "")
set(CMAKE_C_FLAGS_RELEASE "" CACHE STRING "")
set(CMAKE_CXX_FLAGS_RELEASE "" CACHE STRING "")

# project name
project(vehicle_control_module)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_link_options(
    -T${CMAKE_SOURCE_DIR}/src/ASF/sam/utils/linker_scripts/samv71/samv71q21/gcc/flash.ld

    -Wl,--gc-sections

    -specs=nano.specs

    -mthumb
    -mcpu=cortex-m7
    -mfloat-abi=hard
    -mfpu=fpv5-d16
)

add_compile_options(
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>

    $<$<COMPILE_LANGUAGE:CXX>:-Wold-style-cast>
    $<$<COMPILE_LANGUAGE:CXX>:-Wsuggest-override>

    #-Werror
    -Wall
    -Wextra
    #-Wcast-align
    #-Wconversion
    #-Wsign-conversion

    -Wshadow
    -Wlogical-op

    -Wsuggest-final-types
    -Wsuggest-final-methods

    -Wno-expansion-to-defined

    -D__SAMV71Q21B__
    -DBOARD=SAMV71_XPLAINED_ULTRA
    -DLUA_32BITS

    # Debugging.
    -g3
    -DNDEBUG

    # Optimization
    -O0
    -ffunction-sections
    -fdata-sections
    -mlong-calls
    -fno-math-errno

    -mthumb
    -mcpu=cortex-m7
    -mfloat-abi=hard
    -mfpu=fpv5-d16
)

add_subdirectory(src)
