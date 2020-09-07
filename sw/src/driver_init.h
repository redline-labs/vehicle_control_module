/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_H_INCLUDED
#define DRIVER_INIT_H_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_aes_sync.h>

#include <hal_adc_sync.h>

#include <hal_adc_sync.h>
#include <hal_ext_irq.h>

#include <hal_pwm.h>

#include <hal_pwm.h>

#include <hal_qspi_sync.h>

#include <hal_calendar.h>
#include <hal_spi_m_sync.h>

#include <hal_rand_sync.h>

#include <hal_i2c_m_sync.h>

#include <hal_usart_sync.h>
#include <hpl_uart_base.h>

#include <hal_usart_sync.h>
#include <hpl_uart_base.h>

#include <hal_usart_sync.h>
#include <hpl_uart_base.h>

#include <hal_usart_sync.h>
#include <hpl_uart_base.h>

#include "hal_usb_device.h"

#include <hal_wdt.h>

#include <hal_mac_async.h>
#include <hal_can_async.h>
#include <hal_can_async.h>

extern struct aes_sync_descriptor CRYPTOGRAPHY_0;

extern struct adc_sync_descriptor ADC_0;

extern struct adc_sync_descriptor ADC_1;

extern struct pwm_descriptor PWM_0;

extern struct pwm_descriptor PWM_1;

extern struct qspi_sync_descriptor QUAD_SPI_0;

extern struct calendar_descriptor   CALENDAR_0;
extern struct spi_m_sync_descriptor SPI_0;

extern struct rand_sync_desc RAND_0;

extern struct i2c_m_sync_desc I2C_0;

extern struct usart_sync_descriptor USART_0;

extern struct usart_sync_descriptor USART_1;

extern struct usart_sync_descriptor USART_2;

extern struct usart_sync_descriptor USART_3;

extern struct wdt_descriptor WDT_0;

extern struct mac_async_descriptor ETHERNET_MAC_0;
extern struct can_async_descriptor CAN_0;
extern struct can_async_descriptor CAN_1;

void ADC_0_PORT_init(void);
void ADC_0_CLOCK_init(void);
void ADC_0_init(void);

void ADC_1_PORT_init(void);
void ADC_1_CLOCK_init(void);
void ADC_1_init(void);

void PWM_0_PORT_init(void);
void PWM_0_CLOCK_init(void);
void PWM_0_init(void);

void PWM_1_PORT_init(void);
void PWM_1_CLOCK_init(void);
void PWM_1_init(void);

void QUAD_SPI_0_PORT_init(void);
void QUAD_SPI_0_CLOCK_init(void);
void QUAD_SPI_0_init(void);

void CALENDAR_0_CLOCK_init(void);
void CALENDAR_0_init(void);

void SPI_0_PORT_init(void);
void SPI_0_CLOCK_init(void);
void SPI_0_init(void);

void RAND_0_CLOCK_init(void);
void RAND_0_init(void);

void I2C_0_CLOCK_init(void);
void I2C_0_init(void);
void I2C_0_PORT_init(void);

void USART_0_PORT_init(void);
void USART_0_CLOCK_init(void);
void USART_0_init(void);
void USART_0_example(void);

void USART_1_PORT_init(void);
void USART_1_CLOCK_init(void);
void USART_1_init(void);
void USART_1_example(void);

void USART_2_PORT_init(void);
void USART_2_CLOCK_init(void);
void USART_2_init(void);
void USART_2_example(void);

void USART_3_PORT_init(void);
void USART_3_CLOCK_init(void);
void USART_3_init(void);
void USART_3_example(void);

void USB_0_CLOCK_init(void);
void USB_0_init(void);

void WDT_0_init(void);

void ETHERNET_MAC_0_CLOCK_init(void);
void ETHERNET_MAC_0_init(void);
void ETHERNET_MAC_0_PORT_init(void);

void CAN_0_PORT_init(void);
void CAN_0_CLOCK_init(void);
void CAN_0_init(void);
void CAN_0_example(void);

void CAN_1_PORT_init(void);
void CAN_1_CLOCK_init(void);
void CAN_1_init(void);
void CAN_1_example(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_H_INCLUDED
