
/**
 * \file
 *
 * \brief SAM PIO External Interrupt
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#include <utils.h>
#include <utils_assert.h>
#include <hal_ext_irq.h>
#include <hpl_pio_config.h>

#ifndef CONF_EXTIRQ_0_ENABLE
#define CONF_EXTIRQ_0_ENABLE 0
#endif
#ifndef CONF_EXTIRQ_1_ENABLE
#define CONF_EXTIRQ_1_ENABLE 0
#endif
#ifndef CONF_EXTIRQ_2_ENABLE
#define CONF_EXTIRQ_2_ENABLE 0
#endif
#ifndef CONF_EXTIRQ_3_ENABLE
#define CONF_EXTIRQ_3_ENABLE 0
#endif
#ifndef CONF_EXTIRQ_4_ENABLE
#define CONF_EXTIRQ_4_ENABLE 0
#endif

#define EXT_IRQ_AMOUNT (0 + 1)

struct ext_irq_configuration {
	uint8_t  number;
	uint32_t irq_enable;
	/* Write 1 to enable addition interrupt modes */
	uint32_t add_irq_enable;
	/* Write 1 to set edge select */
	uint32_t esr;
	/* Write 1 to set level select */
	uint32_t lsr;
	/* Write 1 to set Rising Edge/High-Level Select */
	uint32_t rehlsr;
	/* Write 1 to set Falling Edge/Low-Level Select */
	uint32_t fellsr;
};

/** IRQ number lookup for PIO instances
 */
static const int8_t _pio_irq_n[] = {

#if defined(PIOA)
    PIOA_IRQn,
#endif

#if defined(PIOB)
    PIOB_IRQn,
#endif

#if defined(PIOC)
    PIOC_IRQn,
#endif

#if defined(PIOD)
    PIOD_IRQn,
#endif

#if defined(PIOE)
    PIOE_IRQn,
#endif
};

#if EXT_IRQ_AMOUNT < 1
/** Dummy array to pass compiling. */
static const struct ext_irq_configuration _ext_irq[1] = {{0}};
#else
static const struct ext_irq_configuration _ext_irq[] = {

#if CONF_EXTIRQ_0_ENABLE == 1
    {0,
     CONF_EXTIRQ_0_IRQ_ENABLE,
     CONF_EXTIRQ_0_ADD_IRQ_ENABLE,
     CONF_EXTIRQ_0_ESR,
     CONF_EXTIRQ_0_LSR,
     CONF_EXTIRQ_0_REHLSR,
     CONF_EXTIRQ_0_FELLSR},
#endif

#if CONF_EXTIRQ_1_ENABLE == 1
    {1,
     CONF_EXTIRQ_1_IRQ_ENABLE,
     CONF_EXTIRQ_1_ADD_IRQ_ENABLE,
     CONF_EXTIRQ_1_ESR,
     CONF_EXTIRQ_1_LSR,
     CONF_EXTIRQ_1_REHLSR,
     CONF_EXTIRQ_1_FELLSR},
#endif

#if CONF_EXTIRQ_2_ENABLE == 1
    {2,
     CONF_EXTIRQ_2_IRQ_ENABLE,
     CONF_EXTIRQ_2_ADD_IRQ_ENABLE,
     CONF_EXTIRQ_2_ESR,
     CONF_EXTIRQ_2_LSR,
     CONF_EXTIRQ_2_REHLSR,
     CONF_EXTIRQ_2_FELLSR},
#endif

#if CONF_EXTIRQ_3_ENABLE == 1
    {3,
     CONF_EXTIRQ_3_IRQ_ENABLE,
     CONF_EXTIRQ_3_ADD_IRQ_ENABLE,
     CONF_EXTIRQ_3_ESR,
     CONF_EXTIRQ_3_LSR,
     CONF_EXTIRQ_3_REHLSR,
     CONF_EXTIRQ_3_FELLSR},
#endif

#if CONF_EXTIRQ_4_ENABLE == 1
    {4,
     CONF_EXTIRQ_4_IRQ_ENABLE,
     CONF_EXTIRQ_4_ADD_IRQ_ENABLE,
     CONF_EXTIRQ_4_ESR,
     CONF_EXTIRQ_4_LSR,
     CONF_EXTIRQ_4_REHLSR,
     CONF_EXTIRQ_4_FELLSR},
#endif

};
#endif

/* Find the first bit set */
static int _ffs(uint32_t *v, uint8_t len)
{
	uint32_t i, j, bit;

	for (i = 0; i < len; i++) {
		bit = 1;
		for (j = 0; j < sizeof(uint32_t) * 8; j++) {
			if (v[i] & bit) {
				return i * 32 + j;
			}
			bit <<= 1;
		}
	}

	return -1;
}

/**
 * \brief Invalid external interrupt and pin numbers
 */
#define INVALID_EXTINT_NUMBER 0xFF
#define INVALID_PIN_NUMBER 0xFFFFFFFF

/**
 * \brief The callback to upper layer's interrupt processing routine
 */
static void (*callback)(const uint32_t pin);

/**
 * \internal Get the PIO hardware instance
 *
 * \param[in] pin The PIO pin
 *
 * \return The instance of PIO hardware
 */
static inline void *_get_hardware_instance(const uint8_t pin)
{
	ASSERT(pin < 160);

	/* PIO instance offset is 0x200 */
	return (void *)((uint32_t)PIOA + (pin >> 5) * 0x200);
}

/**
 * \internal Retrieve ordinal number of the given PIO hardware instance
 *
 * \param[in] hw The pointer to hardware instance
 *
 * \return The index of hardware instance
 */
static uint8_t _pio_get_hardware_index(const void *const hw)
{
	ASSERT(hw);

	return ((uint32_t)hw - (uint32_t)PIOA) >> 9;
}

/**
 * \internal Retrieve ordinal number of the given PIO hardware instance
 *
 * \param[in] hw The pointer to hardware instance
 *
 * \return The ordinal number of the given PIO hardware instance
 */
static int8_t _pio_get_index(const void *const hw)
{
	ASSERT(hw);

	uint8_t offset = _pio_get_hardware_index(hw);
	uint8_t i;

	for (i = 0; i < ARRAY_SIZE(_ext_irq); i++) {
		if (_ext_irq[i].number == offset) {
			return i;
		}
	}

	return ERR_INVALID_DATA;
}

/**
 * \brief External interrupt handler
 */
static void _ext_irq_handler(void)
{
	uint32_t flag_total = 0, flags[5] = {
	                             0,
	                         };
	int pos;

	ASSERT(callback);

#if CONF_EXTIRQ_0_ENABLE == 1 && defined(PIOA)
	flags[0] = hri_pio_read_ISR_reg(PIOA);
	flags[0] &= hri_pio_read_IMR_reg(PIOA);
	flag_total |= flags[0];
#endif

#if CONF_EXTIRQ_1_ENABLE == 1 && defined(PIOB)
	flags[1] = hri_pio_read_ISR_reg(PIOB);
	flags[1] &= hri_pio_read_IMR_reg(PIOB);
	flag_total |= flags[1];
#endif

#if CONF_EXTIRQ_2_ENABLE == 1 && defined(PIOC)
	flags[2] = hri_pio_read_ISR_reg(PIOC);
	flags[2] &= hri_pio_read_IMR_reg(PIOC);
	flag_total |= flags[2];
#endif

#if CONF_EXTIRQ_3_ENABLE == 1 && defined(PIOD)
	flags[3] = hri_pio_read_ISR_reg(PIOD);
	flags[3] &= hri_pio_read_IMR_reg(PIOD);
	flag_total |= flags[3];
#endif

#if CONF_EXTIRQ_4_ENABLE == 1 && defined(PIOE)
	flags[4] = hri_pio_read_ISR_reg(PIOE);
	flags[4] &= hri_pio_read_IMR_reg(PIOE);
	flag_total |= flags[4];
#endif

	while (flag_total) {
		pos = _ffs(flags, 5);
		while (-1 != pos) {
			callback(pos);

			flags[pos >> 5] &= ~(1 << (pos & 31));
			pos = _ffs(flags, 5);
		}
		flag_total = 0;

#if CONF_EXTIRQ_0_ENABLE == 1 && defined(PIOA)
		flags[0] = hri_pio_read_ISR_reg(PIOA);
		flags[0] &= hri_pio_read_IMR_reg(PIOA);
		flag_total |= flags[0];
#endif

#if CONF_EXTIRQ_1_ENABLE == 1 && defined(PIOB)
		flags[1] = hri_pio_read_ISR_reg(PIOB);
		flags[1] &= hri_pio_read_IMR_reg(PIOB);
		flag_total |= flags[1];
#endif

#if CONF_EXTIRQ_2_ENABLE == 1 && defined(PIOC)
		flags[2] = hri_pio_read_ISR_reg(PIOC);
		flags[2] &= hri_pio_read_IMR_reg(PIOC);
		flag_total |= flags[2];
#endif

#if CONF_EXTIRQ_3_ENABLE == 1 && defined(PIOD)
		flags[3] = hri_pio_read_ISR_reg(PIOD);
		flags[3] &= hri_pio_read_IMR_reg(PIOD);
		flag_total |= flags[3];
#endif

#if CONF_EXTIRQ_4_ENABLE == 1 && defined(PIOE)
		flags[4] = hri_pio_read_ISR_reg(PIOE);
		flags[4] &= hri_pio_read_IMR_reg(PIOE);
		flag_total |= flags[4];
#endif
	}
}

void PIOA_Handler(void)
{
	_ext_irq_handler();
}

/**
 * \internal Initialize PIO instance
 *
 * \param[in] hw The pointer to hardware instance
 *
 * \return The status of instance initial
 * \retval ERR_NONE Initial status OK
 * \retval ERR_DENIED No need to initial
 */
static int32_t _pio_init(void *const hw)
{
	int8_t i;

	ASSERT(hw);

	i = _pio_get_index(hw);
	if (i < 0) {
		return ERR_DENIED;
	}

	hri_pio_set_AIMMR_reg(hw, _ext_irq[i].add_irq_enable);
	hri_pio_clear_ELSR_reg(hw, _ext_irq[i].esr);
	hri_pio_set_ELSR_reg(hw, _ext_irq[i].lsr);
	hri_pio_clear_FRLHSR_reg(hw, _ext_irq[i].fellsr);
	hri_pio_set_FRLHSR_reg(hw, _ext_irq[i].rehlsr);

	i = _pio_irq_n[_pio_get_hardware_index(hw)];
	NVIC_DisableIRQ((IRQn_Type)i);
	NVIC_ClearPendingIRQ((IRQn_Type)i);
	NVIC_EnableIRQ((IRQn_Type)i);

	return ERR_NONE;
}

int32_t _ext_irq_init(void (*cb)(const uint32_t pin))
{

#if CONF_EXTIRQ_0_ENABLE == 1 && defined(PIOA)
	_pio_init(PIOA);
#endif

#if CONF_EXTIRQ_1_ENABLE == 1 && defined(PIOB)
	_pio_init(PIOB);
#endif

#if CONF_EXTIRQ_2_ENABLE == 1 && defined(PIOC)
	_pio_init(PIOC);
#endif

#if CONF_EXTIRQ_3_ENABLE == 1 && defined(PIOD)
	_pio_init(PIOD);
#endif

#if CONF_EXTIRQ_4_ENABLE == 1 && defined(PIOE)
	_pio_init(PIOE);
#endif

	callback = cb;

	return ERR_NONE;
}

int32_t _ext_irq_deinit(void)
{
#if CONF_EXTIRQ_0_ENABLE == 1 && defined(PIOA)
	NVIC_DisableIRQ(PIOA_IRQn);
#endif
#if CONF_EXTIRQ_1_ENABLE == 1 && defined(PIOB)
	NVIC_DisableIRQ(PIOB_IRQn);
#endif
#if CONF_EXTIRQ_2_ENABLE == 1 && defined(PIOC)
	NVIC_DisableIRQ(PIOC_IRQn);
#endif
#if CONF_EXTIRQ_3_ENABLE == 1 && defined(PIOD)
	NVIC_DisableIRQ(PIOD_IRQn);
#endif
#if CONF_EXTIRQ_4_ENABLE == 1 && defined(PIOE)
	NVIC_DisableIRQ(PIOE_IRQn);
#endif

	callback = NULL;

	return ERR_NONE;
}

int32_t _ext_irq_enable(const uint32_t pin, const bool enable)
{
	void *   hw   = PIOA;
	uint32_t temp = 0;

	ASSERT(pin < 160);

	hw   = _get_hardware_instance(pin);
	temp = pin & 31;

	if (enable) {
		hri_pio_set_IMR_reg(hw, 1ul << temp);
	} else {
		hri_pio_clear_IMR_reg(hw, 1ul << temp);
	}

	return ERR_NONE;
}
