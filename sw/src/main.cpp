#include <cstdint>

#include <FreeRTOS.h>
#include <task.h>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    vTaskStartScheduler();
}
