/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMV71 has 4 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3

#define PA21 GPIO(GPIO_PORTA, 21)

#define LED0 GPIO(GPIO_PORTC, 19)
#define LED1 GPIO(GPIO_PORTA, 30)
#define LED2 GPIO(GPIO_PORTA, 28)
#define LED3 GPIO(GPIO_PORTC, 18)

#define PB4 GPIO(GPIO_PORTB, 4)

#endif // ATMEL_START_PINS_H_INCLUDED
