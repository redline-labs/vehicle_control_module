/* Auto-generated config file peripheral_clk_config.h */
#ifndef PERIPHERAL_CLK_CONFIG_H
#define PERIPHERAL_CLK_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <h> AFEC Clock Settings
// <y> AFEC Clock source
// <CONF_SRC_MCK"> Master Clock (MCK)
// <i> This defines the clock source for the AFEC
// <id> afec_clock_source
#ifndef CONF_AFEC0_SRC
#define CONF_AFEC0_SRC CONF_SRC_MCK
#endif
// </h>

/**
 * \def AFEC FREQUENCY
 * \brief AFEC's Clock frequency
 */
#ifndef CONF_AFEC0_FREQUENCY
#define CONF_AFEC0_FREQUENCY 150000000
#endif

// <h> AFEC Clock Settings
// <y> AFEC Clock source
// <CONF_SRC_MCK"> Master Clock (MCK)
// <i> This defines the clock source for the AFEC
// <id> afec_clock_source
#ifndef CONF_AFEC1_SRC
#define CONF_AFEC1_SRC CONF_SRC_MCK
#endif
// </h>

/**
 * \def AFEC FREQUENCY
 * \brief AFEC's Clock frequency
 */
#ifndef CONF_AFEC1_FREQUENCY
#define CONF_AFEC1_FREQUENCY 150000000
#endif

/**
 * \def CONF_HCLK_FREQUENCY
 * \brief HCLK's Clock frequency
 */
#ifndef CONF_HCLK_FREQUENCY
#define CONF_HCLK_FREQUENCY 300000000
#endif

/**
 * \def CONF_FCLK_FREQUENCY
 * \brief FCLK's Clock frequency
 */
#ifndef CONF_FCLK_FREQUENCY
#define CONF_FCLK_FREQUENCY 300000000
#endif

/**
 * \def CONF_CPU_FREQUENCY
 * \brief CPU's Clock frequency
 */
#ifndef CONF_CPU_FREQUENCY
#define CONF_CPU_FREQUENCY 300000000
#endif

/**
 * \def CONF_SLCK_FREQUENCY
 * \brief Slow Clock frequency
 */
#define CONF_SLCK_FREQUENCY 32000

/**
 * \def CONF_MCK_FREQUENCY
 * \brief Master Clock frequency
 */
#define CONF_MCK_FREQUENCY 150000000

/**
 * \def CONF_PCK6_FREQUENCY
 * \brief Programmable Clock Controller 6 frequency
 */
#define CONF_PCK6_FREQUENCY 12000000

// <h> PWM Clock Settings
// <y> PWM Clock source
// <CONF_SRC_MCK"> Master Clock (MCK)
// <i> This defines the clock source for the PWM
// <id> pwm_clock_source
#ifndef CONF_PWM0_SRC
#define CONF_PWM0_SRC CONF_SRC_MCK
#endif
// </h>

/**
 * \def PWM FREQUENCY
 * \brief PWM's Clock frequency
 */
#ifndef CONF_PWM0_FREQUENCY
#define CONF_PWM0_FREQUENCY 150000000
#endif

// <h> PWM Clock Settings
// <y> PWM Clock source
// <CONF_SRC_MCK"> Master Clock (MCK)
// <i> This defines the clock source for the PWM
// <id> pwm_clock_source
#ifndef CONF_PWM1_SRC
#define CONF_PWM1_SRC CONF_SRC_MCK
#endif
// </h>

/**
 * \def PWM FREQUENCY
 * \brief PWM's Clock frequency
 */
#ifndef CONF_PWM1_FREQUENCY
#define CONF_PWM1_FREQUENCY 150000000
#endif

// <h> QSPI Clock Settings
// <y> QSPI Clock source
// <CONF_SRC_MCK"> Master Clock (MCK)
// <i> This defines the clock source for the QSPI
// <id> qspi_clock_source
#ifndef CONF_QSPI_SRC
#define CONF_QSPI_SRC CONF_SRC_MCK
#endif
// </h>

/**
 * \def QSPI FREQUENCY
 * \brief QSPI's Clock frequency
 */
#ifndef CONF_QSPI_FREQUENCY
#define CONF_QSPI_FREQUENCY 150000000
#endif

// <o> RTC Clock source
// <0=> SLCK for Peripheral
// <i> This defines the clock source for the RTC
// <id> rtc_clock_source
#ifndef CONF_RTC_SRC
#define CONF_RTC_SRC 0
#endif

/**
 * \def CONF_CLK_RTC_FREQUENCY
 * \brief RTC's Clock frequency
 */
#ifndef CONF_CLK_RTC_FREQUENCY
#define CONF_CLK_RTC_FREQUENCY 32000
#endif

// <h> SPI0 Clock Settings
// <y> SPI0 Clock source
// <CONF_SRC_MCK"> Master Clock (MCK)
// <i> This defines the clock source for the SPI0
// <id> spi_clock_source
#ifndef CONF_SPI0_SRC
#define CONF_SPI0_SRC CONF_SRC_MCK
#endif
// </h>

/**
 * \def SPI0 FREQUENCY
 * \brief SPI0's Clock frequency
 */
#ifndef CONF_SPI0_FREQUENCY
#define CONF_SPI0_FREQUENCY 150000000
#endif

// <h> TWIHS Clock Settings
// <y> TWIHS Clock source
// <CONF_SRC_MCK"> Master Clock (MCK)
// <i> This defines the clock source for the TWIHS
// <id> twihs_clock_source
#ifndef CONF_TWIHS0_SRC
#define CONF_TWIHS0_SRC CONF_SRC_MCK
#endif
// </h>

/**
 * \def TWIHS FREQUENCY
 * \brief TWIHS's Clock frequency
 */
#ifndef CONF_TWIHS0_FREQUENCY
#define CONF_TWIHS0_FREQUENCY 150000000
#endif

// <h> UART Clock Settings
// <o> UART Clock source
// <0=> Master Clock (MCK)
// <1=> Programmable Clock Controller 4 (PMC_PCK4)
// <i> This defines the clock source for the UART
// <id> uart_clock_source
#ifndef CONF_UART0_CK_SRC
#define CONF_UART0_CK_SRC 0
#endif
// </h>

/**
 * \def UART FREQUENCY
 * \brief UART's Clock frequency
 */
#ifndef CONF_UART0_FREQUENCY
#define CONF_UART0_FREQUENCY 150000000
#endif

// <h> UART Clock Settings
// <o> UART Clock source
// <0=> Master Clock (MCK)
// <1=> Programmable Clock Controller 4 (PMC_PCK4)
// <i> This defines the clock source for the UART
// <id> uart_clock_source
#ifndef CONF_UART1_CK_SRC
#define CONF_UART1_CK_SRC 0
#endif
// </h>

/**
 * \def UART FREQUENCY
 * \brief UART's Clock frequency
 */
#ifndef CONF_UART1_FREQUENCY
#define CONF_UART1_FREQUENCY 150000000
#endif

// <h> UART Clock Settings
// <o> UART Clock source
// <0=> Master Clock (MCK)
// <1=> Programmable Clock Controller 4 (PMC_PCK4)
// <i> This defines the clock source for the UART
// <id> uart_clock_source
#ifndef CONF_UART2_CK_SRC
#define CONF_UART2_CK_SRC 0
#endif
// </h>

/**
 * \def UART FREQUENCY
 * \brief UART's Clock frequency
 */
#ifndef CONF_UART2_FREQUENCY
#define CONF_UART2_FREQUENCY 150000000
#endif

// <h> UART Clock Settings
// <o> UART Clock source
// <0=> Master Clock (MCK)
// <1=> Programmable Clock Controller 4 (PMC_PCK4)
// <i> This defines the clock source for the UART
// <id> uart_clock_source
#ifndef CONF_UART3_CK_SRC
#define CONF_UART3_CK_SRC 0
#endif
// </h>

/**
 * \def UART FREQUENCY
 * \brief UART's Clock frequency
 */
#ifndef CONF_UART3_FREQUENCY
#define CONF_UART3_FREQUENCY 150000000
#endif

#ifndef CONF_SRC_USB_480M
#define CONF_SRC_USB_480M 0
#endif

#ifndef CONF_SRC_USB_48M
#define CONF_SRC_USB_48M 1
#endif

// <y> USB Full/Low Speed Clock
// <CONF_SRC_USB_48M"> USB Clock Controller (USB_48M)
// <id> usb_fsls_clock_source
// <i> 48MHz clock source for low speed and full speed.
// <i> It must be available when low speed is supported by host driver.
// <i> It must be available when low power mode is selected.
#ifndef CONF_USBHS_FSLS_SRC
#define CONF_USBHS_FSLS_SRC CONF_SRC_USB_48M
#endif

// <y> USB Clock Source(Normal/Low-power Mode Selection)
// <CONF_SRC_USB_480M"> USB High Speed Clock (USB_480M)
// <CONF_SRC_USB_48M"> USB Clock Controller (USB_48M)
// <id> usb_clock_source
// <i> Select the clock source for USB.
// <i> In normal mode, use "USB High Speed Clock (USB_480M)".
// <i> In low-power mode, use "USB Clock Controller (USB_48M)".
#ifndef CONF_USBHS_SRC
#define CONF_USBHS_SRC CONF_SRC_USB_480M
#endif

/**
 * \def CONF_USBHS_FSLS_FREQUENCY
 * \brief USBHS's Full/Low Speed Clock Source frequency
 */
#ifndef CONF_USBHS_FSLS_FREQUENCY
#define CONF_USBHS_FSLS_FREQUENCY 300000000
#endif

/**
 * \def CONF_USBHS_FREQUENCY
 * \brief USBHS's Selected Clock Source frequency
 */
#ifndef CONF_USBHS_FREQUENCY
#define CONF_USBHS_FREQUENCY 480000000
#endif

// <h> GMAC Clock Settings
// <y> GMAC Clock source
// <CONF_SRC_MCK"> Master Clock (MCK)
// <i> Select the clock source for GMAC
// <id> gmac_clock_source
#ifndef CONF_GMAC_SRC
#define CONF_GMAC_SRC CONF_SRC_MCK
#endif
// </h>

/**
 * \def GMAC FREQUENCY
 * \brief GMAC Clock frequency
 */
#ifndef CONF_GMAC_FREQUENCY
#define CONF_GMAC_FREQUENCY 150000000
#endif

// <h> MCAN Clock Settings
// <y> MCAN Clock source
// <CONF_SRC_PCK5"> Programmable Clock Controller 5 (PMC_PCK5)
// <i> This defines the clock source for the MCAN
// <id> mcan_clock_source
#ifndef CONF_MCAN0_SRC
#define CONF_MCAN0_SRC CONF_SRC_PCK5
#endif
// </h>

/**
 * \def MCAN FREQUENCY
 * \brief MCAN's Clock frequency
 */
#ifndef CONF_MCAN0_FREQUENCY
#define CONF_MCAN0_FREQUENCY 12000000
#endif

// <h> MCAN Clock Settings
// <y> MCAN Clock source
// <CONF_SRC_PCK5"> Programmable Clock Controller 5 (PMC_PCK5)
// <i> This defines the clock source for the MCAN
// <id> mcan_clock_source
#ifndef CONF_MCAN1_SRC
#define CONF_MCAN1_SRC CONF_SRC_PCK5
#endif
// </h>

/**
 * \def MCAN FREQUENCY
 * \brief MCAN's Clock frequency
 */
#ifndef CONF_MCAN1_FREQUENCY
#define CONF_MCAN1_FREQUENCY 12000000
#endif

// <<< end of configuration section >>>

#endif // PERIPHERAL_CLK_CONFIG_H
