include_directories(
    include
    config
)

include_directories(SYSTEM
    # FreeRTOS.
    FreeRTOS/include
    FreeRTOS/portable/GCC/ARM_CM7/r0p1

    # Boards.
    boards

    # CMSIS.
    CMSIS/Core/Include

    # Lua.
    lua/src

    # ASF.
    ASF/common/services/clock
    ASF/common/services/clock/samv71
    ASF/common/services/delay
    ASF/common/services/delay/sam
    ASF/common/services/gpio
    ASF/common/services/gpio/sam_gpio
    ASF/common/services/ioport
    ASF/common/services/ioport/sam
    ASF/common/services/serial
    ASF/common/services/serial/sam_uart
    ASF/common/services/sleepmgr
    ASF/common/services/sleepmgr/sam
    ASF/common/services/twi
    ASF/common/services/twi/sam_twihs
    ASF/common/utils
    ASF/common/utils/interrupt
    ASF/common/utils/stdio/stdio_serial
    ASF/sam/components/ethernet_phy
    ASF/sam/components/ethernet_phy/ksz8061rnb
    ASF/sam/drivers/aes
    ASF/sam/drivers/aes/example
    ASF/sam/drivers/afec
    ASF/sam/drivers/chipid
    ASF/sam/drivers/efc
    ASF/sam/drivers/gmac
    ASF/sam/drivers/mcan
    ASF/sam/drivers/mpu
    ASF/sam/drivers/pio
    ASF/sam/drivers/pmc
    ASF/sam/drivers/pwm
    ASF/sam/drivers/qspi
    ASF/sam/drivers/rstc
    ASF/sam/drivers/spi
    ASF/sam/drivers/tc
    ASF/sam/drivers/trng
    ASF/sam/drivers/twihs
    ASF/sam/drivers/uart
    ASF/sam/drivers/usart
    ASF/sam/drivers/wdt
    ASF/sam/utils
    ASF/sam/utils/cmsis/samv71/include
    ASF/sam/utils/cmsis/samv71/include/component
    ASF/sam/utils/cmsis/samv71/include/instance
    ASF/sam/utils/cmsis/samv71/include/pio
    ASF/sam/utils/cmsis/samv71/source/templates
    ASF/sam/utils/fpu
    ASF/sam/utils/header_files
    ASF/sam/utils/preprocessor
)

add_executable(${PROJECT_NAME}
    main.cpp
    freertos_hooks.cpp
    debug_cycle_counter.cpp

    task_ethernet.cpp
    task_led.cpp
    task_lua.cpp
    task_monitor.cpp

    boards/samv71_xplained_ultra/init.cpp

    # FreeRTOS
    FreeRTOS/croutine.c
    FreeRTOS/event_groups.c
    FreeRTOS/list.c
    FreeRTOS/queue.c
    FreeRTOS/stream_buffer.c
    FreeRTOS/tasks.c
    FreeRTOS/timers.c

    FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.c
    FreeRTOS/portable/MemMang/heap_4.c

    # Lua
    lua/src/lapi.c
    lua/src/lauxlib.c
    lua/src/lbaselib.c
    lua/src/lcode.c
    lua/src/lcorolib.c
    lua/src/lctype.c
    lua/src/ldblib.c
    lua/src/ldebug.c
    lua/src/ldo.c
    lua/src/ldump.c
    lua/src/lfunc.c
    lua/src/lgc.c
    lua/src/linit.c
    lua/src/liolib.c
    lua/src/llex.c
    lua/src/lmathlib.c
    lua/src/lmem.c
    lua/src/loadlib.c
    lua/src/lobject.c
    lua/src/lopcodes.c
    lua/src/loslib.c
    lua/src/lparser.c
    lua/src/lstate.c
    lua/src/lstring.c
    lua/src/lstrlib.c
    lua/src/ltable.c
    lua/src/ltablib.c
    lua/src/ltm.c
    lua/src/lundump.c
    lua/src/lutf8lib.c
    lua/src/lvm.c
    lua/src/lzio.c

    # ASF
    ASF/common/services/clock/samv71/sysclk.c
    ASF/common/services/delay/sam/cycle_counter.c
    ASF/common/services/serial/usart_serial.c
    ASF/common/services/sleepmgr/sam/sleepmgr.c
    ASF/common/utils/interrupt/interrupt_sam_nvic.c
    ASF/common/utils/stdio/read.c
    ASF/common/utils/stdio/write.c
    ASF/sam/components/ethernet_phy/ksz8061rnb/ethernet_phy.c
    ASF/sam/drivers/aes/aes.c
    ASF/sam/drivers/afec/afec.c
    ASF/sam/drivers/chipid/chipid.c
    ASF/sam/drivers/efc/efc.c
    ASF/sam/drivers/gmac/gmac_phy.c
    ASF/sam/drivers/gmac/gmac_raw_2.c
    ASF/sam/drivers/mcan/mcan.c
    ASF/sam/drivers/mpu/mpu.c
    ASF/sam/drivers/pio/pio.c
    ASF/sam/drivers/pio/pio_handler.c
    ASF/sam/drivers/pmc/pmc.c
    ASF/sam/drivers/pmc/sleep.c
    ASF/sam/drivers/pwm/pwm.c
    ASF/sam/drivers/qspi/qspi.c
    ASF/sam/drivers/rstc/rstc.c
    ASF/sam/drivers/spi/spi.c
    ASF/sam/drivers/tc/tc.c
    ASF/sam/drivers/trng/trng.c
    ASF/sam/drivers/twihs/twihs.c
    ASF/sam/drivers/uart/uart.c
    ASF/sam/drivers/usart/usart.c
    ASF/sam/drivers/wdt/wdt.c
    ASF/sam/utils/cmsis/samv71/source/templates/gcc/startup_samv71.c
    ASF/sam/utils/cmsis/samv71/source/templates/system_samv71.c
    ASF/sam/utils/syscalls/gcc/syscalls.c
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    BUILD_TYPE="${CMAKE_BUILD_TYPE}")

set_target_properties(${PROJECT_NAME}
    # Force a .elf extension on the output file.
    PROPERTIES
        SUFFIX .elf

    # Place the resultant Elf into the top level directory.
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Shortcut for printing out the text/data/bss usage.
add_custom_target(size
    arm-none-eabi-size $<TARGET_FILE:${PROJECT_NAME}>
    DEPENDS ${PROJECT_NAME}
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND arm-none-eabi-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature $<TARGET_FILE:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>/$<TARGET_FILE_BASE_NAME:${PROJECT_NAME}>.hex
)
