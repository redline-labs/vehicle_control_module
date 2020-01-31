include_directories(
    include/

    FreeRTOS/include/
    FreeRTOS/portable/GCC/ARM_CM7/r0p1/
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
