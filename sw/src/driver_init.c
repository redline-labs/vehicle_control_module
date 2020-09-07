/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hpl_pwm_base.h>

#include <hpl_spi_base.h>

/* The priority of the peripheral should be between the low and high interrupt priority set by chosen RTOS,
 * Otherwise, some of the RTOS APIs may fail to work inside interrupts
 * In case of FreeRTOS,the Lowest Interrupt priority is set by configLIBRARY_LOWEST_INTERRUPT_PRIORITY and
 * Maximum interrupt priority by configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY, So Interrupt Priority of the peripheral
 * should be between configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY and configLIBRARY_LOWEST_INTERRUPT_PRIORITY
 */
#define PERIPHERAL_INTERRUPT_PRIORITY (configLIBRARY_LOWEST_INTERRUPT_PRIORITY - 1)

struct aes_sync_descriptor   CRYPTOGRAPHY_0;
struct spi_m_sync_descriptor SPI_0;
struct can_async_descriptor  CAN_0;
struct can_async_descriptor  CAN_1;

struct adc_sync_descriptor ADC_0;

struct adc_sync_descriptor ADC_1;

struct pwm_descriptor PWM_0;

struct pwm_descriptor PWM_1;

struct qspi_sync_descriptor QUAD_SPI_0;

struct calendar_descriptor CALENDAR_0;

struct rand_sync_desc RAND_0;

struct i2c_m_sync_desc I2C_0;

struct usart_sync_descriptor USART_0;

struct usart_sync_descriptor USART_1;

struct usart_sync_descriptor USART_2;

struct usart_sync_descriptor USART_3;

struct wdt_descriptor WDT_0;

struct mac_async_descriptor ETHERNET_MAC_0;

void CRYPTOGRAPHY_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_AES);
}

/**
 * \brief AES initialization function
 *
 * Enables AES peripheral, clocks and initializes AES driver
 */
void CRYPTOGRAPHY_0_init(void)
{
	CRYPTOGRAPHY_0_CLOCK_init();
	aes_sync_init(&CRYPTOGRAPHY_0, AES);
}

void ADC_0_PORT_init(void)
{

	gpio_set_pin_function(PD30, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PA21, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PE5, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PE4, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PA17, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PA18, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PA19, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PA20, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PB0, GPIO_PIN_FUNCTION_OFF);
}

void ADC_0_CLOCK_init(void)
{

	_pmc_enable_periph_clock(ID_AFEC0);
}

void ADC_0_init(void)
{
	ADC_0_CLOCK_init();
	ADC_0_PORT_init();
	adc_sync_init(&ADC_0, AFEC0, (void *)NULL);
}

void ADC_1_PORT_init(void)
{

	gpio_set_pin_function(PB1, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PC13, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PC15, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PC29, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PC30, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PC31, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PC26, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PC27, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PC0, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PE3, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_function(PE0, GPIO_PIN_FUNCTION_OFF);
}

void ADC_1_CLOCK_init(void)
{

	_pmc_enable_periph_clock(ID_AFEC1);
}

void ADC_1_init(void)
{
	ADC_1_CLOCK_init();
	ADC_1_PORT_init();
	adc_sync_init(&ADC_1, AFEC1, (void *)NULL);
}

void EXTERNAL_IRQ_0_init(void)
{

	// Set pin direction to input
	gpio_set_pin_direction(PA0, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA0,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA0, GPIO_PIN_FUNCTION_OFF);
}

void PWM_0_PORT_init(void)
{

	gpio_set_pin_function(PD11, MUX_PD11B_PWM0_PWMH0);

	gpio_set_pin_function(PA2, MUX_PA2A_PWM0_PWMH1);

	gpio_set_pin_function(PA25, MUX_PA25B_PWM0_PWMH2);

	gpio_set_pin_function(PA7, MUX_PA7B_PWM0_PWMH3);
}

void PWM_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_PWM0);
}

void PWM_0_init(void)
{
	PWM_0_CLOCK_init();
	PWM_0_PORT_init();
	pwm_init(&PWM_0, PWM0, _pwm_get_pwm());
}

void PWM_1_PORT_init(void)
{

	gpio_set_pin_function(PA31, MUX_PA31D_PWM1_PWMH2);

	gpio_set_pin_function(PA8, MUX_PA8A_PWM1_PWMH3);

	gpio_set_pin_function(PA23, MUX_PA23D_PWM1_PWML2);
}

void PWM_1_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_PWM1);
}

void PWM_1_init(void)
{
	PWM_1_CLOCK_init();
	PWM_1_PORT_init();
	pwm_init(&PWM_1, PWM1, _pwm_get_pwm());
}

void QUAD_SPI_0_PORT_init(void)
{

	// Set pin direction to input
	gpio_set_pin_direction(PA11, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA11,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA11, MUX_PA11A_QSPI_QCS);

	gpio_set_pin_direction(PA13,
	                       // <y> Pin direction
	                       // <id> pad_direction
	                       // <GPIO_DIRECTION_OFF"> Off
	                       // <GPIO_DIRECTION_IN"> In
	                       // <GPIO_DIRECTION_OUT"> Out
	                       GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PA13,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_pull_mode(PA13,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA13,
	                      // <y> Pin function
	                      // <id> pad_function
	                      // <i> Auto : use driver pinmux if signal is imported by driver, else turn off function
	                      // <MUX_PA13A_QSPI_QIO0"> Auto
	                      // <GPIO_PIN_FUNCTION_OFF"> Off
	                      // <GPIO_PIN_FUNCTION_A"> A
	                      // <GPIO_PIN_FUNCTION_B"> B
	                      // <GPIO_PIN_FUNCTION_C"> C
	                      // <GPIO_PIN_FUNCTION_D"> D
	                      MUX_PA13A_QSPI_QIO0);

	gpio_set_pin_direction(PA12,
	                       // <y> Pin direction
	                       // <id> pad_direction
	                       // <GPIO_DIRECTION_OFF"> Off
	                       // <GPIO_DIRECTION_IN"> In
	                       // <GPIO_DIRECTION_OUT"> Out
	                       GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PA12,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_pull_mode(PA12,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA12,
	                      // <y> Pin function
	                      // <id> pad_function
	                      // <i> Auto : use driver pinmux if signal is imported by driver, else turn off function
	                      // <MUX_PA12A_QSPI_QIO1"> Auto
	                      // <GPIO_PIN_FUNCTION_OFF"> Off
	                      // <GPIO_PIN_FUNCTION_A"> A
	                      // <GPIO_PIN_FUNCTION_B"> B
	                      // <GPIO_PIN_FUNCTION_C"> C
	                      // <GPIO_PIN_FUNCTION_D"> D
	                      MUX_PA12A_QSPI_QIO1);

	// Set pin direction to input
	gpio_set_pin_direction(PA14, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA14,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA14, MUX_PA14A_QSPI_QSCK);
}

void QUAD_SPI_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_QSPI);
}

void QUAD_SPI_0_init(void)
{
	QUAD_SPI_0_CLOCK_init();
	qspi_sync_init(&QUAD_SPI_0, QSPI);
	QUAD_SPI_0_PORT_init();
}

void CALENDAR_0_CLOCK_init(void)
{
}

void CALENDAR_0_init(void)
{
	CALENDAR_0_CLOCK_init();
	calendar_init(&CALENDAR_0, RTC);
}

void SPI_0_PORT_init(void)
{

	gpio_set_pin_function(PD20, MUX_PD20B_SPI0_MISO);

	gpio_set_pin_function(PD21, MUX_PD21B_SPI0_MOSI);

	gpio_set_pin_function(PD22, MUX_PD22B_SPI0_SPCK);
}

void SPI_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_SPI0);
}

void SPI_0_init(void)
{
	SPI_0_CLOCK_init();
	spi_m_sync_set_func_ptr(&SPI_0, _spi_get_spi_m_sync());
	spi_m_sync_init(&SPI_0, SPI0);
	SPI_0_PORT_init();
}

void RAND_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_TRNG);
}

void RAND_0_init(void)
{
	RAND_0_CLOCK_init();
	rand_sync_init(&RAND_0, TRNG);
}

void I2C_0_PORT_init(void)
{

	gpio_set_pin_function(PA4, MUX_PA4A_TWIHS0_TWCK0);

	gpio_set_pin_function(PA3, MUX_PA3A_TWIHS0_TWD0);
}

void I2C_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_TWIHS0);
}

void I2C_0_init(void)
{
	I2C_0_CLOCK_init();

	i2c_m_sync_init(&I2C_0, TWIHS0);

	I2C_0_PORT_init();
}

void USART_0_PORT_init(void)
{

	gpio_set_pin_function(PA9, MUX_PA9A_UART0_URXD0);

	gpio_set_pin_function(PA10, MUX_PA10A_UART0_UTXD0);
}

void USART_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_UART0);
}

void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_sync_init(&USART_0, UART0, _uart_get_usart_sync());
	USART_0_PORT_init();
}

void USART_1_PORT_init(void)
{

	gpio_set_pin_function(PA5, MUX_PA5C_UART1_URXD1);

	gpio_set_pin_function(PA6, MUX_PA6C_UART1_UTXD1);
}

void USART_1_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_UART1);
}

void USART_1_init(void)
{
	USART_1_CLOCK_init();
	usart_sync_init(&USART_1, UART1, _uart_get_usart_sync());
	USART_1_PORT_init();
}

void USART_2_PORT_init(void)
{

	gpio_set_pin_function(PD25, MUX_PD25C_UART2_URXD2);

	gpio_set_pin_function(PD26, MUX_PD26C_UART2_UTXD2);
}

void USART_2_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_UART2);
}

void USART_2_init(void)
{
	USART_2_CLOCK_init();
	usart_sync_init(&USART_2, UART2, _uart_get_usart_sync());
	USART_2_PORT_init();
}

void USART_3_PORT_init(void)
{

	gpio_set_pin_function(PD28, MUX_PD28A_UART3_URXD3);

	gpio_set_pin_function(PD31, MUX_PD31B_UART3_UTXD3);
}

void USART_3_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_UART3);
}

void USART_3_init(void)
{
	USART_3_CLOCK_init();
	usart_sync_init(&USART_3, UART3, _uart_get_usart_sync());
	USART_3_PORT_init();
}

/* The USB module requires a GCLK_USB of 48 MHz ~ 0.25% clock
 * for low speed and full speed operation. */
#if (CONF_USBHS_SRC == CONF_SRC_USB_48M)
#if (CONF_USBHS_FREQUENCY > (48000000 + 48000000 / 400)) || (CONF_USBHS_FREQUENCY < (48000000 - 48000000 / 400))
#warning USB clock should be 48MHz ~ 0.25% clock, check your configuration!
#endif
#endif

void USB_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_USBHS);
}

void USB_0_init(void)
{
	USB_0_CLOCK_init();
	usb_d_init();
}

void WDT_0_init(void)
{
	wdt_init(&WDT_0, WDT);
}

void ETHERNET_MAC_0_PORT_init(void)
{

	gpio_set_pin_function(PD8, MUX_PD8A_GMAC_GMDC);

	gpio_set_pin_function(PD9, MUX_PD9A_GMAC_GMDIO);

	gpio_set_pin_function(PD5, MUX_PD5A_GMAC_GRX0);

	gpio_set_pin_function(PD6, MUX_PD6A_GMAC_GRX1);

	gpio_set_pin_function(PD4, MUX_PD4A_GMAC_GRXDV);

	gpio_set_pin_function(PD7, MUX_PD7A_GMAC_GRXER);

	gpio_set_pin_function(PD2, MUX_PD2A_GMAC_GTX0);

	gpio_set_pin_function(PD3, MUX_PD3A_GMAC_GTX1);

	gpio_set_pin_function(PD0, MUX_PD0A_GMAC_GTXCK);

	gpio_set_pin_function(PD1, MUX_PD1A_GMAC_GTXEN);
}

void ETHERNET_MAC_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_GMAC);
}

void ETHERNET_MAC_0_init(void)
{
	ETHERNET_MAC_0_CLOCK_init();
	mac_async_init(&ETHERNET_MAC_0, GMAC);
	ETHERNET_MAC_0_PORT_init();
}

/**
 * \brief MCAN Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void CAN_0_CLOCK_init()
{
	_pmc_enable_periph_clock(ID_MCAN0);
}

/**
 * \brief MCAN pinmux initialization function
 *
 * Set each required pin to MCAN functionality
 */
void CAN_0_PORT_init(void)
{

	gpio_set_pin_function(PB3, MUX_PB3A_MCAN0_CANRX0);

	gpio_set_pin_function(PB2, MUX_PB2A_MCAN0_CANTX0);
}
/**
 * \brief CAN initialization function
 *
 * Enables CAN peripheral, clocks and initializes CAN driver
 */
void CAN_0_init(void)
{
	CAN_0_CLOCK_init();
	CAN_0_PORT_init();
	int32_t ret = can_async_init(&CAN_0, MCAN0);
}

/**
 * \brief MCAN Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void CAN_1_CLOCK_init()
{
	_pmc_enable_periph_clock(ID_MCAN1);
}

/**
 * \brief MCAN pinmux initialization function
 *
 * Set each required pin to MCAN functionality
 */
void CAN_1_PORT_init(void)
{

	gpio_set_pin_function(PC12, MUX_PC12C_MCAN1_CANRX1);

	gpio_set_pin_function(PD12, MUX_PD12B_MCAN1_CANTX1);
}
/**
 * \brief CAN initialization function
 *
 * Enables CAN peripheral, clocks and initializes CAN driver
 */
void CAN_1_init(void)
{
	CAN_1_CLOCK_init();
	CAN_1_PORT_init();
	can_async_init(&CAN_1, MCAN1);
}

void system_init(void)
{
	init_mcu();

	_pmc_enable_periph_clock(ID_PIOA);

	/* Disable Watchdog */
	hri_wdt_set_MR_WDDIS_bit(WDT);

	/* GPIO on PA23 */

	gpio_set_pin_level(LED0, false);
	gpio_set_pin_level(LED1, false);
	gpio_set_pin_level(LED2, false);
	gpio_set_pin_level(LED3, false);

	// Set pin direction to output
	gpio_set_pin_direction(LED0, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(LED1, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(LED2, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(LED3, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED0, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_function(LED1, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_function(LED2, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_function(LED3, GPIO_PIN_FUNCTION_OFF);

	CAN_0_init();
	CAN_1_init();

/*
	CRYPTOGRAPHY_0_init();

	ADC_0_init();

	ADC_1_init();
	EXTERNAL_IRQ_0_init();

	PWM_0_init();

	PWM_1_init();

	QUAD_SPI_0_init();

	CALENDAR_0_init();

	SPI_0_init();

	RAND_0_init();

	I2C_0_init();

	USART_0_init();

	USART_1_init();

	USART_2_init();

	USART_3_init();

	USB_0_init();

	WDT_0_init();

	ETHERNET_MAC_0_init();

	ext_irq_init();
	*/
}
