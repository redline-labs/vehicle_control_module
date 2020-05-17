include_directories(
    .
    config

    # FreeRTOS.
    FreeRTOS/include
    FreeRTOS/portable/GCC/ARM_CM7/r0p1

    # CMSIS.
    CMSIS/Core/Include
    samv71b/include

    hal/include
    hal/utils/include
    hpl/core
    hpl/pio
    hpl/pmc
    hri
)


add_executable(${PROJECT_NAME}
    main.cpp

    # FreeRTOS
    FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.c
    FreeRTOS/portable/MemMang/heap_4.c

    FreeRTOS/croutine.c
    FreeRTOS/event_groups.c
    FreeRTOS/list.c
    FreeRTOS/queue.c
    FreeRTOS/stream_buffer.c
    FreeRTOS/tasks.c
    FreeRTOS/timers.c

    driver_init.c
    #rtos_port.c

    hal/src/hal_atomic.c
    hal/src/hal_delay.c
    hal/src/hal_gpio.c
    hal/src/hal_init.c
    hal/src/hal_io.c
    hal/src/hal_sleep.c
    hpl/core/hpl_core_m7_base.c
    hpl/core/hpl_init.c
    hpl/pmc/hpl_pmc.c
    hpl/pmc/hpl_sleep.c

    samv71b/gcc/startup_samv71q21b.c
)

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
