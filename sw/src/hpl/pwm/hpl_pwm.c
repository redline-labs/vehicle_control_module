/**
 * \file
 *
 * \brief SAM PWM
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

#include <utils_assert.h>
#include <utils.h>
#include <hpl_pwm_base.h>
#include <hpl_pwm.h>
#include <hpl_pwm_config.h>

/**
 * \brief PWM channel configuration type
 */
struct _pwm_ch_cfg {
	uint8_t  index;
	uint32_t mode;
	uint32_t period;
	uint32_t duty_cycle;
};

/**
 * \brief PWM comparison channel configuration type
 */
struct _pwm_comp_cfg {
	uint8_t  index;
	uint32_t comp_cmpm;
	uint32_t comp_cmpv;
};

/**
 * \brief PWM configuration type
 */
struct _pwm_cfg {
	void *                      hw;      /*!< Hardware instance */
	IRQn_Type                   irq;     /*!< IRQ handler */
	uint32_t                    pwm_clk; /*!< CLKA/CLKB source select */
	uint32_t                    pwm_elmr0;
	uint32_t                    pwm_elmr1;
	uint32_t                    pwm_fmr;
	uint32_t                    pwm_fpv1;
	uint32_t                    pwm_fpv2;
	uint32_t                    pwm_fpe;
	uint32_t                    pwm_etrg1;
	uint32_t                    pwm_etrg2;
	uint32_t                    ch_num;
	const struct _pwm_ch_cfg *  ch; /*!< Enabled Channel number */
	uint32_t                    comp_num;
	const struct _pwm_comp_cfg *comp; /*!< Enabled Channel number */
};

/**
 * \brief Macro is used to fill pwm configuration structure based on its
 * number
 *
 * \param[in] n The index of structures
 */
#define PWM_CONFIGURATION(n)                                                                                           \
	{                                                                                                                  \
		PWM##n, PWM##n##_IRQn,                                                                                         \
		    PWM_CLK_PREA(CONF_PWM_##n##_PREA) | PWM_CLK_DIVA(CONF_PWM_##n##_DIVA) | PWM_CLK_PREB(CONF_PWM_##n##_PREB)  \
		        | PWM_CLK_DIVB(CONF_PWM_##n##_DIVB),                                                                   \
		    CONF_PWM_##n##_ELMR0_REGVAL, CONF_PWM_##n##_ELMR1_REGVAL, CONF_PWM_##n##_FMR_REGVAL,                       \
		    CONF_PWM_##n##_FPV1_REGVAL, CONF_PWM_##n##_FPV2_REGVAL, CONF_PWM_##n##_FPE_REGVAL,                         \
		    CONF_PWM_##n##_ETRG1_REGVAL, CONF_PWM_##n##_ETRG2_REGVAL, CONF_PWM_##n##_CH_NUM, _ch_cfg##n,               \
		    CONF_PWM_##n##_COMP_NUM, _comp_cfg##n                                                                      \
	}

/**
 * \brief Macro is used to fill pwm channel configuration structure based on its
 * number
 *
 * \param[in] m The index of pwm instance, start from 0
 * \param[in] n The index of channel, start from 0
 */
#define PWM_CH_CONFIGURATION(m, n)                                                                                     \
	{                                                                                                                  \
		n,                                                                                                             \
		    PWM_CMR_CPRE(CONF_PWM_##m##_CHANNEL##n##_CPRE) | (CONF_PWM_##m##_CHANNEL##n##_CPOL << PWM_CMR_CPOL_Pos)    \
		        | (CONF_PWM_##m##_CHANNEL##n##_DPOLI << PWM_CMR_DPOLI_Pos)                                             \
		        | (CONF_PWM_##m##_CHANNEL##n##_CALG << PWM_CMR_CALG_Pos),                                              \
		    CONF_PWM_##m##_CHANNEL##n##_CPRD, CONF_PWM_##m##_CHANNEL##n##_CDTY                                         \
	}

/**
 * \brief Macro is used to fill pwm comparison configuration structure based on its
 * number
 *
 * \param[in] m The index of peripheral
 * \param[in] n The index of comparison channel
 */
#define PWM_COMP_CONFIGURATION(m, n)                                                                                   \
	{                                                                                                                  \
		n,                                                                                                             \
		    (uint32_t)(PWM_CMPM_CTR(CONF_PWM_##m##_CTR##n) | PWM_CMPM_CPR(CONF_PWM_##m##_CPR##n)                       \
		               | PWM_CMPM_CUPR(CONF_PWM_##m##_CUPR##n)),                                                       \
		    (uint32_t)(PWM_CMPV_CV(CONF_PWM_##m##_CV##n) | (CONF_PWM_##m##_CVM##n << PWM_CMPV_CV_Pos))                 \
	}

#ifndef CONF_PWM_0_ENABLE
#define CONF_PWM_0_ENABLE 0
#endif
#ifndef CONF_PWM_1_ENABLE
#define CONF_PWM_1_ENABLE 0
#endif

/** Amount of PWM. */
#define PWM_AMOUNT (CONF_PWM_0_ENABLE + CONF_PWM_1_ENABLE)

/**
 * \brief Array of Channel configurations
 */
#if CONF_PWM_0_ENABLE
#if (CONF_PWM_0_CH_NUM < 1)
/** Dummy array to pass compiling. */
static const struct _pwm_ch_cfg _ch_cfg0[] = {{0}};
#else
static const struct _pwm_ch_cfg _ch_cfg0[] = {

#if CONF_PWM_0_CHANNEL0_ENABLE == 1
    PWM_CH_CONFIGURATION(0, 0),
#endif

#if CONF_PWM_0_CHANNEL1_ENABLE == 1
    PWM_CH_CONFIGURATION(0, 1),
#endif

#if CONF_PWM_0_CHANNEL2_ENABLE == 1
    PWM_CH_CONFIGURATION(0, 2),
#endif

#if CONF_PWM_0_CHANNEL3_ENABLE == 1
    PWM_CH_CONFIGURATION(0, 3),
#endif

};
#endif
#endif /* CONF_PWM_0_ENABLE */

#if CONF_PWM_1_ENABLE
#if (CONF_PWM_1_CH_NUM < 1)
/** Dummy array to pass compiling. */
static const struct _pwm_ch_cfg _ch_cfg1[] = {{0}};
#else
static const struct _pwm_ch_cfg _ch_cfg1[] = {

#if CONF_PWM_1_CHANNEL0_ENABLE == 1
    PWM_CH_CONFIGURATION(1, 0),
#endif

#if CONF_PWM_1_CHANNEL1_ENABLE == 1
    PWM_CH_CONFIGURATION(1, 1),
#endif

#if CONF_PWM_1_CHANNEL2_ENABLE == 1
    PWM_CH_CONFIGURATION(1, 2),
#endif

#if CONF_PWM_1_CHANNEL3_ENABLE == 1
    PWM_CH_CONFIGURATION(1, 3),
#endif

};
#endif
#endif /* CONF_PWM_1_ENABLE */

/**
 * \brief Array of Comparison configurations
 */
#if CONF_PWM_0_ENABLE
#if (CONF_PWM_0_COMP_AMOUNT < 1)
/** Dummy array to pass compiling. */
static struct _pwm_comp_cfg _comp_cfg0[] = {{0}};
#else
static struct _pwm_comp_cfg _comp_cfg0[] = {

#if CONF_PWM_0_COMP_ENABLE0 == 1
    PWM_COMP_CONFIGURATION(0, 0),
#endif

#if CONF_PWM_0_COMP_ENABLE1 == 1
    PWM_COMP_CONFIGURATION(0, 1),
#endif

#if CONF_PWM_0_COMP_ENABLE2 == 1
    PWM_COMP_CONFIGURATION(0, 2),
#endif

#if CONF_PWM_0_COMP_ENABLE3 == 1
    PWM_COMP_CONFIGURATION(0, 3),
#endif

#if CONF_PWM_0_COMP_ENABLE4 == 1
    PWM_COMP_CONFIGURATION(0, 4),
#endif

#if CONF_PWM_0_COMP_ENABLE5 == 1
    PWM_COMP_CONFIGURATION(0, 5),
#endif

#if CONF_PWM_0_COMP_ENABLE6 == 1
    PWM_COMP_CONFIGURATION(0, 6),
#endif

#if CONF_PWM_0_COMP_ENABLE7 == 1
    PWM_COMP_CONFIGURATION(0, 7),
#endif

};
#endif
#endif /*CONF_PWM_0_ENABLE */

#if CONF_PWM_1_ENABLE
#if (CONF_PWM_1_COMP_AMOUNT < 1)
/** Dummy array to pass compiling. */
static struct _pwm_comp_cfg _comp_cfg1[] = {{0}};
#else
static struct _pwm_comp_cfg _comp_cfg1[] = {

#if CONF_PWM_1_COMP_ENABLE0 == 1
    PWM_COMP_CONFIGURATION(1, 0),
#endif

#if CONF_PWM_1_COMP_ENABLE1 == 1
    PWM_COMP_CONFIGURATION(1, 1),
#endif

#if CONF_PWM_1_COMP_ENABLE2 == 1
    PWM_COMP_CONFIGURATION(1, 2),
#endif

#if CONF_PWM_1_COMP_ENABLE3 == 1
    PWM_COMP_CONFIGURATION(1, 3),
#endif

#if CONF_PWM_1_COMP_ENABLE4 == 1
    PWM_COMP_CONFIGURATION(1, 4),
#endif

#if CONF_PWM_1_COMP_ENABLE5 == 1
    PWM_COMP_CONFIGURATION(1, 5),
#endif

#if CONF_PWM_1_COMP_ENABLE6 == 1
    PWM_COMP_CONFIGURATION(1, 6),
#endif

#if CONF_PWM_1_COMP_ENABLE7 == 1
    PWM_COMP_CONFIGURATION(1, 7),
#endif

};
#endif
#endif /*CONF_PWM_1_ENABLE */

#if PWM_AMOUNT < 1
/** Dummy array to pass compiling. */
static const struct _pwm_cfg _pwms[] = {{0}};
#else
/**
 * \brief Array of PWM configurations
 */
static const struct _pwm_cfg _pwms[] = {
#if CONF_PWM_0_ENABLE == 1
    PWM_CONFIGURATION(0),
#endif
#if CONF_PWM_1_ENABLE == 1
    PWM_CONFIGURATION(1),
#endif
};
#endif

static struct _pwm_device *_pwm0_dev = NULL;

static struct _pwm_device *_pwm1_dev = NULL;

/** \brief Return the pointer to register settings of specific SPI
 *  \param[in] hw_addr The hardware register base address.
 *  \return Pointer to register settings of specific SERCOM.
 */
static const struct _pwm_cfg *_pwm_get_cfg(void *const hw)
{
	uint8_t i;

	for (i = 0; i < ARRAY_SIZE(_pwms); i++) {
		if (_pwms[i].hw == hw) {
			return (_pwms + i);
		}
	}

	return NULL;
}

/**
 * \brief Retrieve ordinal number of the given afec hardware instance
 */
static uint8_t _pwm_get_hardware_index(const void *const hw)
{
	if (hw == PWM0) {
		return 0;
	} else if (hw == PWM1) {
		return 1;
	}

	ASSERT(false);
	return 0;
}

/**
 * \brief Init irq param with the given pwm hardware instance
 */
static void _pwm_init_irq_param(const void *const hw, struct _pwm_device *dev)
{
	if (hw == PWM0) {
		_pwm0_dev = dev;
	}
	if (hw == PWM1) {
		_pwm1_dev = dev;
	}
}

/**
 * \internal interrupt handler for PWM
 *
 * \param[in] instance PWM instance number
 */
static void _pwm_interrupt_handler(struct _pwm_device *device)
{
	if (hri_pwm_read_ISR1_reg(device->hw)) {
		if (NULL != device->callback.pwm_period_cb) {
			device->callback.pwm_period_cb(device);
		}
	}
}

/**
 * \internal PWM interrupt handler
 */
void PWM0_Handler(void)
{
	_pwm_interrupt_handler(_pwm0_dev);
}

/**
 * \internal PWM interrupt handler
 */
void PWM1_Handler(void)
{
	_pwm_interrupt_handler(_pwm1_dev);
}

int32_t _pwm_init(struct _pwm_device *const device, void *const hw)
{
	ASSERT(hw);

	int8_t                      i;
	const struct _pwm_cfg *     cfg;
	const struct _pwm_ch_cfg *  ch;
	const struct _pwm_comp_cfg *comp;

	cfg = _pwm_get_cfg(hw);

	device->hw = hw;
	/* Init PMW */
	hri_pwm_write_CLK_reg(hw, cfg->pwm_clk);
	hri_pwm_write_ELMR_reg(hw, 0, cfg->pwm_elmr0);
	hri_pwm_write_ELMR_reg(hw, 1, cfg->pwm_elmr1);
	hri_pwm_write_FMR_reg(hw, cfg->pwm_fmr);
	hri_pwm_write_FPV1_reg(hw, cfg->pwm_fpv1);
	hri_pwm_write_FPV2_reg(hw, cfg->pwm_fpv2);
	hri_pwm_write_FPE_reg(hw, cfg->pwm_fpe);
	hri_pwm_write_ETRG1_reg(hw, cfg->pwm_etrg1);
	hri_pwm_write_ETRG2_reg(hw, cfg->pwm_etrg2);

	/* Init Channel */
	for (i = 0; i < cfg->ch_num; i++) {
		ch = cfg->ch + i;
		hri_pwm_write_CMR_reg(hw, ch->index, ch->mode);
		hri_pwm_write_CDTY_reg(hw, ch->index, ch->duty_cycle);
		hri_pwm_write_CPRD_reg(hw, ch->index, ch->period);
	}
	/* Init comparison */
	for (i = 0; i < cfg->comp_num; i++) {
		comp = cfg->comp + i;
		hri_pwm_write_CMPM_reg(hw, comp->index, comp->comp_cmpm);
		hri_pwm_write_CMPV_reg(hw, comp->index, comp->comp_cmpv);
	}

	_pwm_init_irq_param(hw, device);
	NVIC_DisableIRQ(cfg->irq);
	NVIC_ClearPendingIRQ(cfg->irq);
	NVIC_EnableIRQ(cfg->irq);

	return ERR_NONE;
}

void _pwm_deinit(struct _pwm_device *const device)
{
	const struct _pwm_cfg *cfg;

	cfg = _pwm_get_cfg(device->hw);
	NVIC_DisableIRQ(cfg->irq);

	hri_pwm_write_DIS_reg(device->hw, PWM_DIS_MASK);
}

void _pwm_enable(struct _pwm_device *const device)
{
	ASSERT(device);
	int8_t                 i;
	const struct _pwm_cfg *cfg;

	cfg = _pwm_get_cfg(device->hw);

	for (i = 0; i < cfg->ch_num; i++) {
		hri_pwm_write_ENA_reg(device->hw, 0x1u << cfg->ch[i].index);
	}
}

void _pwm_disable(struct _pwm_device *const device)
{
	ASSERT(device);
	int8_t                 i;
	const struct _pwm_cfg *cfg;

	cfg = _pwm_get_cfg(device->hw);

	for (i = 0; i < cfg->ch_num; i++) {
		hri_pwm_write_DIS_reg(device->hw, 0x1u << cfg->ch[i].index);
	}
}

void _pwm_set_param(struct _pwm_device *const device, const pwm_period_t period, const pwm_period_t duty_cycle)
{
	uint8_t                i;
	const struct _pwm_cfg *cfg;

	ASSERT(device && (duty_cycle < period));

	cfg = _pwm_get_cfg(device->hw);

	for (i = 0; i < cfg->ch_num; i++) {
		hri_pwm_write_CDTYUPD_reg(device->hw, cfg->ch[i].index, duty_cycle);
		hri_pwm_write_CPRDUPD_reg(device->hw, cfg->ch[i].index, period);
	}
}

bool _pwm_is_enabled(const struct _pwm_device *const device)
{
	ASSERT(device);
	uint8_t status = hri_pwm_get_SR_reg(device->hw, 0x0F);
	if (status == 0) {
		return false;
	} else {
		return true;
	}
}

pwm_period_t _pwm_get_period(const struct _pwm_device *const device)
{
	ASSERT(device);
	const struct _pwm_cfg *cfg;

	cfg = _pwm_get_cfg(device->hw);

	return hri_pwm_read_CPRD_reg(device->hw, cfg->ch[0].index);
}

uint32_t _pwm_get_duty(const struct _pwm_device *const device)
{
	ASSERT(device);
	const struct _pwm_cfg *cfg;

	cfg = _pwm_get_cfg(device->hw);

	return hri_pwm_read_CDTY_reg(device->hw, cfg->ch[0].index);
}

void _pwm_set_irq_state(struct _pwm_device *const device, const enum _pwm_callback_type type, const bool disable)
{
	uint8_t                i;
	const struct _pwm_cfg *cfg;

	ASSERT(device);

	cfg = _pwm_get_cfg(device->hw);

	if (PWM_DEVICE_PERIOD_CB == type) {
		for (i = 0; i < cfg->ch_num; i++) {
			hri_pwm_write_IMR1_reg(device->hw, 0x1u << cfg->ch[i].index);
		}
	} else if (PWM_DEVICE_ERROR_CB == type) {
		ASSERT(false);
	}
}

/**
 * \brief Retrieve pwm helper functions
 */
struct _pwm_hpl_interface *_pwm_get_pwm(void)
{
	return NULL;
}
