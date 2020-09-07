/* Auto-generated config file hpl_pwm_config.h */
#ifndef HPL_PWM_CONFIG_H
#define HPL_PWM_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <peripheral_clk_config.h>

#ifndef CONF_PWM_0_ENABLE
#define CONF_PWM_0_ENABLE 1
#endif

// <h> Basic settings

// <o> CLKA Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <i> This defines the clka source clock.
// <id> pwm_prea
#ifndef CONF_PWM_0_PREA
#define CONF_PWM_0_PREA 0
#endif

// <o> CLKA Divide Factor<0-255>
// <i> Defines the clka divided by DIVA factor
// <id> pwm_diva
#ifndef CONF_PWM_0_DIVA
#define CONF_PWM_0_DIVA 1
#endif

// <o> CLKB Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <i> This defines the clkb source clock.
// <id> pwm_preb
#ifndef CONF_PWM_0_PREB
#define CONF_PWM_0_PREB 0
#endif

// <o> CLKB Divide Factor<0-255>
// <i> Defines the clka divided by DIVB factor
// <id> pwm_divb
#ifndef CONF_PWM_0_DIVB
#define CONF_PWM_0_DIVB 1
#endif

// </h>

// <h> Channel configuration
// <e> Channel0 Settings
// <id> channel0_settings
#ifndef CONF_PWM_0_CHANNEL0_ENABLE
#define CONF_PWM_0_CHANNEL0_ENABLE 1
#endif

// <o> Channel Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <11=> CLKA
// <12=> CLKB
// <i> This defines the channel source clock
// <id> pwm_channel0_clk_src
#ifndef CONF_PWM_0_CHANNEL0_CPRE
#define CONF_PWM_0_CHANNEL0_CPRE 0
#endif

// <o> Channel Period Value <1-65535>
// <i> Channel Period Value
// <id> pwm_channel0_CPRD
#ifndef CONF_PWM_0_CHANNEL0_CPRD
#define CONF_PWM_0_CHANNEL0_CPRD 1024
#endif

// <o> Channel Duty Cycle Value <1-65535>
// <i> Channel Duty Cycle Value, this value must be defined between 0 and CPRD
// <id> pwm_channel0_CDTY
#ifndef CONF_PWM_0_CHANNEL0_CDTY
#define CONF_PWM_0_CHANNEL0_CDTY 512
#endif

// <o> Channel Polarity
// <0=> The OCx output waveform starts at a low level
// <1=> The OCx output waveform starts at a high level
// <i> Indicates whether OCx output start at high level or not
// <id> pwm_channel0_output_polarity
#ifndef CONF_PWM_0_CHANNEL0_CPOL
#define CONF_PWM_0_CHANNEL0_CPOL 0
#endif

// <q> Channel Disabled status Polarity Inverted
// <i> When the PWM channel x is disabled, whether OCx output is
// <i> inverted compared to the one defined by the CPOL bit
// <id> pwm_channel0_disabled_polarity_inverted
#ifndef CONF_PWM_0_CHANNEL0_DPOLI
#define CONF_PWM_0_CHANNEL0_DPOLI 0
#endif

// <o> Channel Alignment
// <0=> The period is left-aligned
// <1=> The period is center-aligned
// <i> Channel period Channel Alignment
// <id> pwm_channel0_alignment
#ifndef CONF_PWM_0_CHANNEL0_CALG
#define CONF_PWM_0_CHANNEL0_CALG 0
#endif

// </e>

// <e> Channel1 Settings
// <id> channel1_settings
#ifndef CONF_PWM_0_CHANNEL1_ENABLE
#define CONF_PWM_0_CHANNEL1_ENABLE 1
#endif

// <o> Channel Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <11=> CLKA
// <12=> CLKB
// <i> This defines the channel source clock
// <id> pwm_channel1_clk_src
#ifndef CONF_PWM_0_CHANNEL1_CPRE
#define CONF_PWM_0_CHANNEL1_CPRE 0
#endif

// <o> Channel Period Value <1-65535>
// <i> Channel Period Value
// <id> pwm_channel1_CPRD
#ifndef CONF_PWM_0_CHANNEL1_CPRD
#define CONF_PWM_0_CHANNEL1_CPRD 1024
#endif

// <o> Channel Duty Cycle Value <1-65535>
// <i> Channel Duty Cycle Value, this value must be defined between 0 and CPRD
// <id> pwm_channel1_CDTY
#ifndef CONF_PWM_0_CHANNEL1_CDTY
#define CONF_PWM_0_CHANNEL1_CDTY 512
#endif

// <o> Channel Polarity
// <0=> The OCx output waveform starts at a low level
// <1=> The OCx output waveform starts at a high level
// <i> Indicates whether OCx output start at high level or not
// <id> pwm_channel1_output_polarity
#ifndef CONF_PWM_0_CHANNEL1_CPOL
#define CONF_PWM_0_CHANNEL1_CPOL 0
#endif

// <q> Channel Disabled status Polarity Inverted
// <i> When the PWM channel x is disabled, whether OCx output
// <i> is inverted compared to the one defined by the CPOL bit
// <id> pwm_channel1_disabled_polarity_inverted
#ifndef CONF_PWM_0_CHANNEL1_DPOLI
#define CONF_PWM_0_CHANNEL1_DPOLI 0
#endif

// <o> Channel Alignment
// <0=> The period is left-aligned
// <1=> The period is center-aligned
// <i> Channel period Channel Alignment
// <id> pwm_channel1_alignment
#ifndef CONF_PWM_0_CHANNEL1_CALG
#define CONF_PWM_0_CHANNEL1_CALG 0
#endif

// <e> Channel 1 External Trigger Enable
// <id> pwm_channel1_trigger_enable
#ifndef CONF_PWM_0_CHANNEL1_TRIGGER_ENABLE
#define CONF_PWM_0_CHANNEL1_TRIGGER_ENABLE 0
#endif

// <o> Channel 1 External Trigger Mode
// <0x0=> External trigger is not enabled.
// <0x1=> External PWM Reset Mode
// <0x2=> External PWM Start Mode
// <0x3=> Cycle-by-cycle Duty Mode
// <i> This defines external trigger mode.
// <id> pwm_channel1_trgmode
#ifndef CONF_PWM_0_CHANNEL1_TRGMODE
#define CONF_PWM_0_CHANNEL1_TRGMODE 0
#endif

// <o> Channel 1 Trigger Source Selection
// <0x0=> By the PWMTRG input
// <0x1=> By the Analog Comparator Controller
// <i> This defines trigger source selection.
// <id> pwm_channel1_trgsrc
#ifndef CONF_PWM_0_CHANNEL1_TRGSRC
#define CONF_PWM_0_CHANNEL1_TRGSRC 0
#endif

// <o> Channel 1 Edge Selection
// <0x0=> Falling edge or level 0
// <0x1=> Rising edge or level 1
// <i> If trigger mode is Reset Mode, trigger edge is falling edge or rising edge.
// <i> If trigger mode is Start Mode or Cycle-by-cycle Duty Mode, trigger edge is level 0 or 1.
// <id> pwm_channel1_trgedge
#ifndef CONF_PWM_0_CHANNEL1_TRGEDGE
#define CONF_PWM_0_CHANNEL1_TRGEDGE 0
#endif

// <q> Channel 1 Recoverable Fault Enable
// <i> This defines whether the TRGINx signal generate a recoverable fault in place of the fault input.
// <id> pwm_channel1_rfen
#ifndef CONF_PWM_0_CHANNEL1_RFEN
#define CONF_PWM_0_CHANNEL1_RFEN 0
#endif

// <q> Channel 1 Filtered Input
// <i> This defines whether the external trigger input is filtered.
// <id> pwm_channel1_trgfilt
#ifndef CONF_PWM_0_CHANNEL1_TRGFILT
#define CONF_PWM_0_CHANNEL1_TRGFILT 0
#endif

// </e>

// </e>

// <e> Channel2 Settings
// <id> channel2_settings
#ifndef CONF_PWM_0_CHANNEL2_ENABLE
#define CONF_PWM_0_CHANNEL2_ENABLE 1
#endif

// <o> Channel Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <11=> CLKA
// <12=> CLKB
// <i> This defines the channel source clock
// <id> pwm_channel2_clk_src
#ifndef CONF_PWM_0_CHANNEL2_CPRE
#define CONF_PWM_0_CHANNEL2_CPRE 0
#endif

// <o> Channel Period Value <1-65535>
// <i> Channel Period Value
// <id> pwm_channel2_CPRD
#ifndef CONF_PWM_0_CHANNEL2_CPRD
#define CONF_PWM_0_CHANNEL2_CPRD 1024
#endif

// <o> Channel Duty Cycle Value <1-65535>
// <i> Channel Duty Cycle Value, this value must be defined between 0 and CPRD
// <id> pwm_channel2_CDTY
#ifndef CONF_PWM_0_CHANNEL2_CDTY
#define CONF_PWM_0_CHANNEL2_CDTY 512
#endif

// <o> Channel Polarity
// <0=> The OCx output waveform starts at a low level
// <1=> The OCx output waveform starts at a high level
// <i> Indicates whether OCx output start at high level or not
// <id> pwm_channel2_output_polarity
#ifndef CONF_PWM_0_CHANNEL2_CPOL
#define CONF_PWM_0_CHANNEL2_CPOL 0
#endif

// <q> Channel Disabled status Polarity Inverted
// <i> When the PWM channel x is disabled, whether OCx output
// <i> is inverted compared to the one defined by the CPOL bit
// <id> pwm_channel2_disabled_polarity_inverted
#ifndef CONF_PWM_0_CHANNEL2_DPOLI
#define CONF_PWM_0_CHANNEL2_DPOLI 0
#endif

// <o> Channel Alignment
// <0=> The period is left-aligned
// <1=> The period is center-aligned
// <i> Channel period Channel Alignment
// <id> pwm_channel2_alignment
#ifndef CONF_PWM_0_CHANNEL2_CALG
#define CONF_PWM_0_CHANNEL2_CALG 0
#endif

// <e> Channel 2 External Trigger Enable
// <id> pwm_channel2_trigger_enable
#ifndef CONF_PWM_0_CHANNEL2_TRIGGER_ENABLE
#define CONF_PWM_0_CHANNEL2_TRIGGER_ENABLE 0
#endif

// <o> Channel 2 External Trigger Mode
// <0x0=> External trigger is not enabled.
// <0x1=> External PWM Reset Mode
// <0x2=> External PWM Start Mode
// <0x3=> Cycle-by-cycle Duty Mode
// <i> This defines external trigger mode.
// <id> pwm_channel2_trgmode
#ifndef CONF_PWM_0_CHANNEL2_TRGMODE
#define CONF_PWM_0_CHANNEL2_TRGMODE 0
#endif

// <o> Channel 2 Trigger Source Selection
// <0x0=> By the PWMTRG input
// <0x1=> By the Analog Comparator Controller
// <i> This defines trigger source selection.
// <id> pwm_channel2_trgsrc
#ifndef CONF_PWM_0_CHANNEL2_TRGSRC
#define CONF_PWM_0_CHANNEL2_TRGSRC 0
#endif

// <o> Channel 2 Edge Selection
// <0x0=> Falling edge or level 0
// <0x1=> Rising edge or level 1
// <i> If trigger mode is Reset Mode, trigger edge is falling edge or rising edge.
// <i> If trigger mode is Start Mode or Cycle-by-cycle Duty Mode, trigger edge is level 0 or 1.
// <id> pwm_channel2_trgedge
#ifndef CONF_PWM_0_CHANNEL2_TRGEDGE
#define CONF_PWM_0_CHANNEL2_TRGEDGE 0
#endif

// <q> Channel 2 Recoverable Fault Enable
// <i> This defines whether the TRGINx signal generate a recoverable fault in place of the fault input.
// <id> pwm_channel2_rfen
#ifndef CONF_PWM_0_CHANNEL2_RFEN
#define CONF_PWM_0_CHANNEL2_RFEN 0
#endif

// <q> Channel 2 Filtered Input
// <i> This defines whether the external trigger input is filtered.
// <id> pwm_channel2_trgfilt
#ifndef CONF_PWM_0_CHANNEL2_TRGFILT
#define CONF_PWM_0_CHANNEL2_TRGFILT 0
#endif

// </e>

// </e>

// <e> Channel3 Settings
// <id> channel3_settings
#ifndef CONF_PWM_0_CHANNEL3_ENABLE
#define CONF_PWM_0_CHANNEL3_ENABLE 1
#endif

// <o> Channel Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <11=> CLKA
// <12=> CLKB
// <i> This defines the channel source clock
// <id> pwm_channel3_clk_src
#ifndef CONF_PWM_0_CHANNEL3_CPRE
#define CONF_PWM_0_CHANNEL3_CPRE 0
#endif

// <o> Channel Period Value <1-65535>
// <i> Channel Period Value
// <id> pwm_channel3_CPRD
#ifndef CONF_PWM_0_CHANNEL3_CPRD
#define CONF_PWM_0_CHANNEL3_CPRD 1024
#endif

// <o> Channel Duty Cycle Value <1-65535>
// <i> Channel Duty Cycle Value, this value must be defined between 0 and CPRD
// <id> pwm_channel3_CDTY
#ifndef CONF_PWM_0_CHANNEL3_CDTY
#define CONF_PWM_0_CHANNEL3_CDTY 512
#endif

// <o> Channel Polarity
// <0=> The OCx output waveform starts at a low level
// <1=> The OCx output waveform starts at a high level
// <i> Indicates whether OCx output start at high level or not
// <id> pwm_channel3_output_polarity
#ifndef CONF_PWM_0_CHANNEL3_CPOL
#define CONF_PWM_0_CHANNEL3_CPOL 0
#endif

// <q> Channel Disabled status Polarity Inverted
// <i> When the PWM channel x is disabled, whether OCx output
// <i> is inverted compared to the one defined by the CPOL bit
// <id> pwm_channel3_disabled_polarity_inverted
#ifndef CONF_PWM_0_CHANNEL3_DPOLI
#define CONF_PWM_0_CHANNEL3_DPOLI 0
#endif

// <o> Channel Alignment
// <0=> The period is left-aligned
// <1=> The period is center-aligned
// <i> Channel period Channel Alignment
// <id> pwm_channel3_alignment
#ifndef CONF_PWM_0_CHANNEL3_CALG
#define CONF_PWM_0_CHANNEL3_CALG 0
#endif
// </e>
// </h>

// <h> Comparison Configuration

// <e> Comparison 0 ENABLE
// <i> This defines the comparison 0 is enabled and can match.
// <id> pwm_comp_enable0
#ifndef CONF_PWM_0_COMP_ENABLE0
#define CONF_PWM_0_COMP_ENABLE0 0
#endif

// <q> Event Lines 0 Comparison 0 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel0_enable
#ifndef CONF_PWM_0_ELMR0_CSEL0
#define CONF_PWM_0_ELMR0_CSEL0 0
#endif

// <q> Event Lines 1 Comparison 0 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel0_enable
#ifndef CONF_PWM_0_ELMR1_CSEL0
#define CONF_PWM_0_ELMR1_CSEL0 0
#endif

// <o> Comparison 0 Value <0-65535>
// <i> Define the comparison 0 value to be compared with the counter of the channel 0.
// <id> pwm_cv0
#ifndef CONF_PWM_0_CV0
#define CONF_PWM_0_CV0 0
#endif

// <o> Comparison 0 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm0
#ifndef CONF_PWM_0_CVM0
#define CONF_PWM_0_CVM0 0
#endif

// <o> Comparison 0 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr0
#ifndef CONF_PWM_0_CTR0
#define CONF_PWM_0_CTR0 0
#endif

// <o> Comparison 0 Period <0-15>
// <i> This defines the maximum value of the comparison 0 period counter.
// <id> pwm_cpr0
#ifndef CONF_PWM_0_CPR0
#define CONF_PWM_0_CPR0 0
#endif

// <o> Comparison 0 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 0 value.
// <id> pwm_cupr0
#ifndef CONF_PWM_0_CUPR0
#define CONF_PWM_0_CUPR0 0
#endif

// </e>

// <e> Comparison 1 ENABLE
// <i> This defines the comparison 1 is enabled and can match.
// <id> pwm_comp_enable1
#ifndef CONF_PWM_0_COMP_ENABLE1
#define CONF_PWM_0_COMP_ENABLE1 0
#endif

// <q> Event Lines 0 Comparison 1 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel1_enable
#ifndef CONF_PWM_0_ELMR0_CSEL1
#define CONF_PWM_0_ELMR0_CSEL1 0
#endif

// <q> Event Lines 1 Comparison 1 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel1_enable
#ifndef CONF_PWM_0_ELMR1_CSEL1
#define CONF_PWM_0_ELMR1_CSEL1 0
#endif

// <o> Comparison 1 Value <0-65535>
// <i> Define the comparison 1 value to be compared with the counter of the channel 0.
// <id> pwm_cv1
#ifndef CONF_PWM_0_CV1
#define CONF_PWM_0_CV1 0
#endif

// <o> Comparison 1 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm1
#ifndef CONF_PWM_0_CVM1
#define CONF_PWM_0_CVM1 0
#endif

// <o> Comparison 1 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr1
#ifndef CONF_PWM_0_CTR1
#define CONF_PWM_0_CTR1 0
#endif

// <o> Comparison 1 Period <0-15>
// <i> This defines the maximum value of the comparison 1 period counter.
// <id> pwm_cpr1
#ifndef CONF_PWM_0_CPR1
#define CONF_PWM_0_CPR1 0
#endif

// <o> Comparison 1 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 1 value.
// <id> pwm_cupr1
#ifndef CONF_PWM_0_CUPR1
#define CONF_PWM_0_CUPR1 0
#endif

// </e>

// <e> Comparison 2 ENABLE
// <i> This defines the comparison 2 is enabled and can match.
// <id> pwm_comp_enable2
#ifndef CONF_PWM_0_COMP_ENABLE2
#define CONF_PWM_0_COMP_ENABLE2 0
#endif

// <q> Event Lines 0 Comparison 2 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel2_enable
#ifndef CONF_PWM_0_ELMR0_CSEL2
#define CONF_PWM_0_ELMR0_CSEL2 0
#endif

// <q> Event Lines 1 Comparison 2 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel2_enable
#ifndef CONF_PWM_0_ELMR1_CSEL2
#define CONF_PWM_0_ELMR1_CSEL2 0
#endif

// <o> Comparison 2 Value <0-65535>
// <i> Define the comparison 2 value to be compared with the counter of the channel 0.
// <id> pwm_cv2
#ifndef CONF_PWM_0_CV2
#define CONF_PWM_0_CV2 0
#endif

// <o> Comparison 2 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm2
#ifndef CONF_PWM_0_CVM2
#define CONF_PWM_0_CVM2 0
#endif

// <o> Comparison 2 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr2
#ifndef CONF_PWM_0_CTR2
#define CONF_PWM_0_CTR2 0
#endif

// <o> Comparison 2 Period <0-15>
// <i> This defines the maximum value of the comparison 2 period counter.
// <id> pwm_cpr2
#ifndef CONF_PWM_0_CPR2
#define CONF_PWM_0_CPR2 0
#endif

// <o> Comparison 2 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 2 value.
// <id> pwm_cupr2
#ifndef CONF_PWM_0_CUPR2
#define CONF_PWM_0_CUPR2 0
#endif

// </e>

// <e> Comparison 3 ENABLE
// <i> This defines the comparison 3 is enabled and can match.
// <id> pwm_comp_enable3
#ifndef CONF_PWM_0_COMP_ENABLE3
#define CONF_PWM_0_COMP_ENABLE3 0
#endif

// <q> Event Lines 0 Comparison 3 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel3_enable
#ifndef CONF_PWM_0_ELMR0_CSEL3
#define CONF_PWM_0_ELMR0_CSEL3 0
#endif

// <q> Event Lines 1 Comparison 3 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel3_enable
#ifndef CONF_PWM_0_ELMR1_CSEL3
#define CONF_PWM_0_ELMR1_CSEL3 0
#endif

// <o> Comparison 3 Value <0-65535>
// <i> Define the comparison 3 value to be compared with the counter of the channel 0.
// <id> pwm_cv3
#ifndef CONF_PWM_0_CV3
#define CONF_PWM_0_CV3 0
#endif

// <o> Comparison 3 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm3
#ifndef CONF_PWM_0_CVM3
#define CONF_PWM_0_CVM3 0
#endif

// <o> Comparison 3 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr3
#ifndef CONF_PWM_0_CTR3
#define CONF_PWM_0_CTR3 0
#endif

// <o> Comparison 3 Period <0-15>
// <i> This defines the maximum value of the comparison 3 period counter.
// <id> pwm_cpr3
#ifndef CONF_PWM_0_CPR3
#define CONF_PWM_0_CPR3 0
#endif

// <o> Comparison 3 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 3 value.
// <id> pwm_cupr3
#ifndef CONF_PWM_0_CUPR3
#define CONF_PWM_0_CUPR3 0
#endif

// </e>

// <e> Comparison 4 ENABLE
// <i> This defines the comparison 4 is enabled and can match.
// <id> pwm_comp_enable4
#ifndef CONF_PWM_0_COMP_ENABLE4
#define CONF_PWM_0_COMP_ENABLE4 0
#endif

// <q> Event Lines 0 Comparison 4 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel4_enable
#ifndef CONF_PWM_0_ELMR0_CSEL4
#define CONF_PWM_0_ELMR0_CSEL4 0
#endif

// <q> Event Lines 1 Comparison 4 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel4_enable
#ifndef CONF_PWM_0_ELMR1_CSEL4
#define CONF_PWM_0_ELMR1_CSEL4 0
#endif

// <o> Comparison 4 Value <0-65535>
// <i> Define the comparison 4 value to be compared with the counter of the channel 0.
// <id> pwm_cv4
#ifndef CONF_PWM_0_CV4
#define CONF_PWM_0_CV4 0
#endif

// <o> Comparison 4 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm4
#ifndef CONF_PWM_0_CVM4
#define CONF_PWM_0_CVM4 0
#endif

// <o> Comparison 4 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr4
#ifndef CONF_PWM_0_CTR4
#define CONF_PWM_0_CTR4 0
#endif

// <o> Comparison 4 Period <0-15>
// <i> This defines the maximum value of the comparison 4 period counter.
// <id> pwm_cpr4
#ifndef CONF_PWM_0_CPR4
#define CONF_PWM_0_CPR4 0
#endif

// <o> Comparison 4 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 4 value.
// <id> pwm_cupr4
#ifndef CONF_PWM_0_CUPR4
#define CONF_PWM_0_CUPR4 0
#endif

// </e>

// <e> Comparison 5 ENABLE
// <i> This defines the comparison 5 is enabled and can match.
// <id> pwm_comp_enable5
#ifndef CONF_PWM_0_COMP_ENABLE5
#define CONF_PWM_0_COMP_ENABLE5 0
#endif

// <q> Event Lines 0 Comparison 5 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel5_enable
#ifndef CONF_PWM_0_ELMR0_CSEL5
#define CONF_PWM_0_ELMR0_CSEL5 0
#endif

// <q> Event Lines 1 Comparison 5 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel5_enable
#ifndef CONF_PWM_0_ELMR1_CSEL5
#define CONF_PWM_0_ELMR1_CSEL5 0
#endif

// <o> Comparison 5 Value <0-65535>
// <i> Define the comparison 5 value to be compared with the counter of the channel 0.
// <id> pwm_cv5
#ifndef CONF_PWM_0_CV5
#define CONF_PWM_0_CV5 0
#endif

// <o> Comparison 5 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm5
#ifndef CONF_PWM_0_CVM5
#define CONF_PWM_0_CVM5 0
#endif

// <o> Comparison 5 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr5
#ifndef CONF_PWM_0_CTR5
#define CONF_PWM_0_CTR5 0
#endif

// <o> Comparison 5 Period <0-15>
// <i> This defines the maximum value of the comparison 5 period counter.
// <id> pwm_cpr5
#ifndef CONF_PWM_0_CPR5
#define CONF_PWM_0_CPR5 0
#endif

// <o> Comparison 5 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 5 value.
// <id> pwm_cupr5
#ifndef CONF_PWM_0_CUPR5
#define CONF_PWM_0_CUPR5 0
#endif

// </e>

// <e> Comparison 6 ENABLE
// <i> This defines the comparison 6 is enabled and can match.
// <id> pwm_comp_enable6
#ifndef CONF_PWM_0_COMP_ENABLE6
#define CONF_PWM_0_COMP_ENABLE6 0
#endif

// <q> Event Lines 0 Comparison 6 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel6_enable
#ifndef CONF_PWM_0_ELMR0_CSEL6
#define CONF_PWM_0_ELMR0_CSEL6 0
#endif

// <q> Event Lines 1 Comparison 6 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel6_enable
#ifndef CONF_PWM_0_ELMR1_CSEL6
#define CONF_PWM_0_ELMR1_CSEL6 0
#endif

// <o> Comparison 6 Value <0-65535>
// <i> Define the comparison 6 value to be compared with the counter of the channel 0.
// <id> pwm_cv6
#ifndef CONF_PWM_0_CV6
#define CONF_PWM_0_CV6 0
#endif

// <o> Comparison 6 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm6
#ifndef CONF_PWM_0_CVM6
#define CONF_PWM_0_CVM6 0
#endif

// <o> Comparison 6 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr6
#ifndef CONF_PWM_0_CTR6
#define CONF_PWM_0_CTR6 0
#endif

// <o> Comparison 6 Period <0-15>
// <i> This defines the maximum value of the comparison 6 period counter.
// <id> pwm_cpr6
#ifndef CONF_PWM_0_CPR6
#define CONF_PWM_0_CPR6 0
#endif

// <o> Comparison 6 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 6 value.
// <id> pwm_cupr6
#ifndef CONF_PWM_0_CUPR6
#define CONF_PWM_0_CUPR6 0
#endif

// </e>

// <e> Comparison 7 ENABLE
// <i> This defines the comparison 7 is enabled and can match.
// <id> pwm_comp_enable7
#ifndef CONF_PWM_0_COMP_ENABLE7
#define CONF_PWM_0_COMP_ENABLE7 0
#endif

// <q> Event Lines 0 Comparison 7 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel7_enable
#ifndef CONF_PWM_0_ELMR0_CSEL7
#define CONF_PWM_0_ELMR0_CSEL7 0
#endif

// <q> Event Lines 1 Comparison 7 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel7_enable
#ifndef CONF_PWM_0_ELMR1_CSEL7
#define CONF_PWM_0_ELMR1_CSEL7 0
#endif

// <o> Comparison 7 Value <0-65535>
// <i> Define the comparison 7 value to be compared with the counter of the channel 0.
// <id> pwm_cv7
#ifndef CONF_PWM_0_CV7
#define CONF_PWM_0_CV7 0
#endif

// <o> Comparison 7 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm7
#ifndef CONF_PWM_0_CVM7
#define CONF_PWM_0_CVM7 0
#endif

// <o> Comparison 7 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr7
#ifndef CONF_PWM_0_CTR7
#define CONF_PWM_0_CTR7 0
#endif

// <o> Comparison 7 Period <0-15>
// <i> This defines the maximum value of the comparison 7 period counter.
// <id> pwm_cpr7
#ifndef CONF_PWM_0_CPR7
#define CONF_PWM_0_CPR7 0
#endif

// <o> Comparison 7 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 7 value.
// <id> pwm_cupr7
#ifndef CONF_PWM_0_CUPR7
#define CONF_PWM_0_CUPR7 0
#endif

// </e>

// </h>

// <h> Fault Configuration

// <e> Fault 0 Configuration
// <i> This defines fault 0 configuration enable
// <id> pwm_fault0_enable
#ifndef CONF_PWM_0_FAULT0_ENABLE
#define CONF_PWM_0_FAULT0_ENABLE 0
#endif

// <q> Fault 0 Polarity
// <i> If true, the fault 0 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault0
#ifndef CONF_PWM_0_FMR_FPOL_FAULT0
#define CONF_PWM_0_FMR_FPOL_FAULT0 1
#endif

// <q> Fault 0 Filtering
// <i> If true, the fault 0 is filtered.
// <id> pwm_fmr_ffil_fault0
#ifndef CONF_PWM_0_FMR_FFIL_FAULT0
#define CONF_PWM_0_FMR_FFIL_FAULT0 0
#endif

// <o> Fault 0 Activation Mode
// <0x0=> The fault 0 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 0 activation mode.
// <id> pwm_fmr_fmod_fault0
#ifndef CONF_PWM_0_FMR_FMOD_FAULT0
#define CONF_PWM_0_FMR_FMOD_FAULT0 0
#endif

// </e>

// <e> Fault 1 Configuration
// <i> This defines fault 1 configuration enable
// <id> pwm_fault1_enable
#ifndef CONF_PWM_0_FAULT1_ENABLE
#define CONF_PWM_0_FAULT1_ENABLE 0
#endif

// <q> Fault 1 Polarity
// <i> If true, the fault 1 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault1
#ifndef CONF_PWM_0_FMR_FPOL_FAULT1
#define CONF_PWM_0_FMR_FPOL_FAULT1 1
#endif

// <q> Fault 1 Filtering
// <i> If true, the fault 1 is filtered.
// <id> pwm_fmr_ffil_fault1
#ifndef CONF_PWM_0_FMR_FFIL_FAULT1
#define CONF_PWM_0_FMR_FFIL_FAULT1 0
#endif

// <o> Fault 1 Activation Mode
// <0x0=> The fault 1 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 1 activation mode.
// <id> pwm_fmr_fmod_fault1
#ifndef CONF_PWM_0_FMR_FMOD_FAULT1
#define CONF_PWM_0_FMR_FMOD_FAULT1 0
#endif

// </e>

// <e> Fault 2 Configuration
// <i> This defines fault 2 configuration enable
// <id> pwm_fault2_enable
#ifndef CONF_PWM_0_FAULT2_ENABLE
#define CONF_PWM_0_FAULT2_ENABLE 0
#endif

// <q> Fault 2 Polarity
// <i> If true, the fault 2 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault2
#ifndef CONF_PWM_0_FMR_FPOL_FAULT2
#define CONF_PWM_0_FMR_FPOL_FAULT2 1
#endif

// <q> Fault 2 Filtering
// <i> If true, the fault 2 is filtered.
// <id> pwm_fmr_ffil_fault2
#ifndef CONF_PWM_0_FMR_FFIL_FAULT2
#define CONF_PWM_0_FMR_FFIL_FAULT2 0
#endif

// <o> Fault 2 Activation Mode
// <0x0=> The fault 2 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 2 activation mode.
// <id> pwm_fmr_fmod_fault2
#ifndef CONF_PWM_0_FMR_FMOD_FAULT2
#define CONF_PWM_0_FMR_FMOD_FAULT2 0
#endif

// </e>

// <e> Fault 3 Configuration
// <i> This defines fault 3 configuration enable
// <id> pwm_fault3_enable
#ifndef CONF_PWM_0_FAULT3_ENABLE
#define CONF_PWM_0_FAULT3_ENABLE 0
#endif

// <q> Fault 3 Polarity
// <i> If true, the fault 3 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault3
#ifndef CONF_PWM_0_FMR_FPOL_FAULT3
#define CONF_PWM_0_FMR_FPOL_FAULT3 1
#endif

// <q> Fault 3 Filtering
// <i> If true, the fault 3 is filtered.
// <id> pwm_fmr_ffil_fault3
#ifndef CONF_PWM_0_FMR_FFIL_FAULT3
#define CONF_PWM_0_FMR_FFIL_FAULT3 0
#endif

// <o> Fault 3 Activation Mode
// <0x0=> The fault 3 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 3 activation mode.
// <id> pwm_fmr_fmod_fault3
#ifndef CONF_PWM_0_FMR_FMOD_FAULT3
#define CONF_PWM_0_FMR_FMOD_FAULT3 0
#endif

// </e>

// <e> Fault 4 Configuration
// <i> This defines fault 4 configuration enable
// <id> pwm_fault4_enable
#ifndef CONF_PWM_0_FAULT4_ENABLE
#define CONF_PWM_0_FAULT4_ENABLE 0
#endif

// <q> Fault 4 Polarity
// <i> If true, the fault 4 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault4
#ifndef CONF_PWM_0_FMR_FPOL_FAULT4
#define CONF_PWM_0_FMR_FPOL_FAULT4 1
#endif

// <q> Fault 4 Filtering
// <i> If true, the fault 4 is filtered.
// <id> pwm_fmr_ffil_fault4
#ifndef CONF_PWM_0_FMR_FFIL_FAULT4
#define CONF_PWM_0_FMR_FFIL_FAULT4 0
#endif

// <o> Fault 4 Activation Mode
// <0x0=> The fault 4 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 4 activation mode.
// <id> pwm_fmr_fmod_fault4
#ifndef CONF_PWM_0_FMR_FMOD_FAULT4
#define CONF_PWM_0_FMR_FMOD_FAULT4 0
#endif

// </e>

// <e> Fault 5 Configuration
// <i> This defines fault 5 configuration enable
// <id> pwm_fault5_enable
#ifndef CONF_PWM_0_FAULT5_ENABLE
#define CONF_PWM_0_FAULT5_ENABLE 0
#endif

// <q> Fault 5 Polarity
// <i> If true, the fault 5 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault5
#ifndef CONF_PWM_0_FMR_FPOL_FAULT5
#define CONF_PWM_0_FMR_FPOL_FAULT5 1
#endif

// <q> Fault 5 Filtering
// <i> If true, the fault 5 is filtered.
// <id> pwm_fmr_ffil_fault5
#ifndef CONF_PWM_0_FMR_FFIL_FAULT5
#define CONF_PWM_0_FMR_FFIL_FAULT5 0
#endif

// <o> Fault 5 Activation Mode
// <0x0=> The fault 5 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 5 activation mode.
// <id> pwm_fmr_fmod_fault5
#ifndef CONF_PWM_0_FMR_FMOD_FAULT5
#define CONF_PWM_0_FMR_FMOD_FAULT5 0
#endif

// </e>

// <e> Fault 6 Configuration
// <i> This defines fault 6 configuration enable
// <id> pwm_fault6_enable
#ifndef CONF_PWM_0_FAULT6_ENABLE
#define CONF_PWM_0_FAULT6_ENABLE 0
#endif

// <q> Fault 6 Polarity
// <i> If true, the fault 6 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault6
#ifndef CONF_PWM_0_FMR_FPOL_FAULT6
#define CONF_PWM_0_FMR_FPOL_FAULT6 1
#endif

// <q> Fault 6 Filtering
// <i> If true, the fault 6 is filtered.
// <id> pwm_fmr_ffil_fault6
#ifndef CONF_PWM_0_FMR_FFIL_FAULT6
#define CONF_PWM_0_FMR_FFIL_FAULT6 0
#endif

// <o> Fault 6 Activation Mode
// <0x0=> The fault 6 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 6 activation mode.
// <id> pwm_fmr_fmod_fault6
#ifndef CONF_PWM_0_FMR_FMOD_FAULT6
#define CONF_PWM_0_FMR_FMOD_FAULT6 0
#endif

// </e>

// <e> Fault 7 Configuration
// <i> This defines fault 7 configuration enable
// <id> pwm_fault7_enable
#ifndef CONF_PWM_0_FAULT7_ENABLE
#define CONF_PWM_0_FAULT7_ENABLE 0
#endif

// <q> Fault 7 Polarity
// <i> If true, the fault 7 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault7
#ifndef CONF_PWM_0_FMR_FPOL_FAULT7
#define CONF_PWM_0_FMR_FPOL_FAULT7 1
#endif

// <q> Fault 7 Filtering
// <i> If true, the fault 7 is filtered.
// <id> pwm_fmr_ffil_fault7
#ifndef CONF_PWM_0_FMR_FFIL_FAULT7
#define CONF_PWM_0_FMR_FFIL_FAULT7 0
#endif

// <o> Fault 7 Activation Mode
// <0x0=> The fault 7 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 7 activation mode.
// <id> pwm_fmr_fmod_fault7
#ifndef CONF_PWM_0_FMR_FMOD_FAULT7
#define CONF_PWM_0_FMR_FMOD_FAULT7 0
#endif

// </e>

// <e> Fault Configuration for Channel 0
// <id> pwm_channel0_fault_config
#ifndef CONF_PWM_0_CHANNEL0_FAULT_CONFIG
#define CONF_PWM_0_CHANNEL0_FAULT_CONFIG 0
#endif

// <q> Fault 0 Protection Enable for channel 0
// <i> This defines fault 0 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault0_enable
#ifndef CONF_PWM_0_FPE0_FAULT0_ENABLE
#define CONF_PWM_0_FPE0_FAULT0_ENABLE 0
#endif

// <q> Fault 1 Protection Enable for channel 0
// <i> This defines fault 1 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault1_enable
#ifndef CONF_PWM_0_FPE0_FAULT1_ENABLE
#define CONF_PWM_0_FPE0_FAULT1_ENABLE 0
#endif

// <q> Fault 2 Protection Enable for channel 0
// <i> This defines fault 2 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault2_enable
#ifndef CONF_PWM_0_FPE0_FAULT2_ENABLE
#define CONF_PWM_0_FPE0_FAULT2_ENABLE 0
#endif

// <q> Fault 3 Protection Enable for channel 0
// <i> This defines fault 3 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault3_enable
#ifndef CONF_PWM_0_FPE0_FAULT3_ENABLE
#define CONF_PWM_0_FPE0_FAULT3_ENABLE 0
#endif

// <q> Fault 4 Protection Enable for channel 0
// <i> This defines fault 4 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault4_enable
#ifndef CONF_PWM_0_FPE0_FAULT4_ENABLE
#define CONF_PWM_0_FPE0_FAULT4_ENABLE 0
#endif

// <q> Fault 5 Protection Enable for channel 0
// <i> This defines fault 5 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault5_enable
#ifndef CONF_PWM_0_FPE0_FAULT5_ENABLE
#define CONF_PWM_0_FPE0_FAULT5_ENABLE 0
#endif

// <q> Fault 6 Protection Enable for channel 0
// <i> This defines fault 6 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault6_enable
#ifndef CONF_PWM_0_FPE0_FAULT6_ENABLE
#define CONF_PWM_0_FPE0_FAULT6_ENABLE 0
#endif

// <q> Fault 7 Protection Enable for channel 0
// <i> This defines fault 7 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault7_enable
#ifndef CONF_PWM_0_FPE0_FAULT7_ENABLE
#define CONF_PWM_0_FPE0_FAULT7_ENABLE 0
#endif

// <o> Fault Protection Value for PWMH output on channel0
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWMH output on channel 0 when fault occurs.
// <id> pwm_fpv1_fpvh0
#ifndef CONF_PWM_0_FPV1_FPVH0
#define CONF_PWM_0_FPV1_FPVH0 2
#endif

// <o> Fault Protection Value for PWML output on channel0
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWML output on channel 0 when fault occurs.
// <id> pwm_fpv1_fpvl0
#ifndef CONF_PWM_0_FPV1_FPVL0
#define CONF_PWM_0_FPV1_FPVL0 2
#endif
// </e>

// <e> Fault Configuration for Channel 1
// <id> pwm_channel1_fault_config
#ifndef CONF_PWM_0_CHANNEL1_FAULT_CONFIG
#define CONF_PWM_0_CHANNEL1_FAULT_CONFIG 0
#endif

// <q> Fault 0 Protection Enable for channel 1
// <i> This defines fault 0 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault0_enable
#ifndef CONF_PWM_0_FPE1_FAULT0_ENABLE
#define CONF_PWM_0_FPE1_FAULT0_ENABLE 0
#endif

// <q> Fault 1 Protection Enable for channel 1
// <i> This defines fault 1 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault1_enable
#ifndef CONF_PWM_0_FPE1_FAULT1_ENABLE
#define CONF_PWM_0_FPE1_FAULT1_ENABLE 0
#endif

// <q> Fault 2 Protection Enable for channel 1
// <i> This defines fault 2 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault2_enable
#ifndef CONF_PWM_0_FPE1_FAULT2_ENABLE
#define CONF_PWM_0_FPE1_FAULT2_ENABLE 0
#endif

// <q> Fault 3 Protection Enable for channel 1
// <i> This defines fault 3 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault3_enable
#ifndef CONF_PWM_0_FPE1_FAULT3_ENABLE
#define CONF_PWM_0_FPE1_FAULT3_ENABLE 0
#endif

// <q> Fault 4 Protection Enable for channel 1
// <i> This defines fault 4 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault4_enable
#ifndef CONF_PWM_0_FPE1_FAULT4_ENABLE
#define CONF_PWM_0_FPE1_FAULT4_ENABLE 0
#endif

// <q> Fault 5 Protection Enable for channel 1
// <i> This defines fault 5 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault5_enable
#ifndef CONF_PWM_0_FPE1_FAULT5_ENABLE
#define CONF_PWM_0_FPE1_FAULT5_ENABLE 0
#endif

// <q> Fault 6 Protection Enable for channel 1
// <i> This defines fault 6 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault6_enable
#ifndef CONF_PWM_0_FPE1_FAULT6_ENABLE
#define CONF_PWM_0_FPE1_FAULT6_ENABLE 0
#endif

// <q> Fault 7 Protection Enable for channel 1
// <i> This defines fault 7 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault7_enable
#ifndef CONF_PWM_0_FPE1_FAULT7_ENABLE
#define CONF_PWM_0_FPE1_FAULT7_ENABLE 0
#endif

// <o> Fault Protection Value for PWMH output on channel1
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWMH output on channel 1 when fault occurs.
// <id> pwm_fpv1_fpvh1
#ifndef CONF_PWM_0_FPV1_FPVH1
#define CONF_PWM_0_FPV1_FPVH1 2
#endif

// <o> Fault Protection Value for PWML output on channel1
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWML output on channel 1 when fault occurs.
// <id> pwm_fpv1_fpvl1
#ifndef CONF_PWM_0_FPV1_FPVL1
#define CONF_PWM_0_FPV1_FPVL1 2
#endif
// </e>

// <e> Fault Configuration for Channel 2
// <id> pwm_channel2_fault_config
#ifndef CONF_PWM_0_CHANNEL2_FAULT_CONFIG
#define CONF_PWM_0_CHANNEL2_FAULT_CONFIG 0
#endif

// <q> Fault 0 Protection Enable for channel 2
// <i> This defines fault 0 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault0_enable
#ifndef CONF_PWM_0_FPE2_FAULT0_ENABLE
#define CONF_PWM_0_FPE2_FAULT0_ENABLE 0
#endif

// <q> Fault 1 Protection Enable for channel 2
// <i> This defines fault 1 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault1_enable
#ifndef CONF_PWM_0_FPE2_FAULT1_ENABLE
#define CONF_PWM_0_FPE2_FAULT1_ENABLE 0
#endif

// <q> Fault 2 Protection Enable for channel 2
// <i> This defines fault 2 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault2_enable
#ifndef CONF_PWM_0_FPE2_FAULT2_ENABLE
#define CONF_PWM_0_FPE2_FAULT2_ENABLE 0
#endif

// <q> Fault 3 Protection Enable for channel 2
// <i> This defines fault 3 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault3_enable
#ifndef CONF_PWM_0_FPE2_FAULT3_ENABLE
#define CONF_PWM_0_FPE2_FAULT3_ENABLE 0
#endif

// <q> Fault 4 Protection Enable for channel 2
// <i> This defines fault 4 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault4_enable
#ifndef CONF_PWM_0_FPE2_FAULT4_ENABLE
#define CONF_PWM_0_FPE2_FAULT4_ENABLE 0
#endif

// <q> Fault 5 Protection Enable for channel 2
// <i> This defines fault 5 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault5_enable
#ifndef CONF_PWM_0_FPE2_FAULT5_ENABLE
#define CONF_PWM_0_FPE2_FAULT5_ENABLE 0
#endif

// <q> Fault 6 Protection Enable for channel 2
// <i> This defines fault 6 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault6_enable
#ifndef CONF_PWM_0_FPE2_FAULT6_ENABLE
#define CONF_PWM_0_FPE2_FAULT6_ENABLE 0
#endif

// <q> Fault 7 Protection Enable for channel 2
// <i> This defines fault 7 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault7_enable
#ifndef CONF_PWM_0_FPE2_FAULT7_ENABLE
#define CONF_PWM_0_FPE2_FAULT7_ENABLE 0
#endif

// <o> Fault Protection Value for PWMH output on channel2
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWMH output on channel 2 when fault occurs.
// <id> pwm_fpv1_fpvh2
#ifndef CONF_PWM_0_FPV1_FPVH2
#define CONF_PWM_0_FPV1_FPVH2 2
#endif

// <o> Fault Protection Value for PWML output on channel2
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWML output on channel 2 when fault occurs.
// <id> pwm_fpv1_fpvl2
#ifndef CONF_PWM_0_FPV1_FPVL2
#define CONF_PWM_0_FPV1_FPVL2 2
#endif
// </e>

// <e> Fault Configuration for Channel 3
// <id> pwm_channel3_fault_config
#ifndef CONF_PWM_0_CHANNEL3_FAULT_CONFIG
#define CONF_PWM_0_CHANNEL3_FAULT_CONFIG 0
#endif

// <q> Fault 0 Protection Enable for channel 3
// <i> This defines fault 0 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault0_enable
#ifndef CONF_PWM_0_FPE3_FAULT0_ENABLE
#define CONF_PWM_0_FPE3_FAULT0_ENABLE 0
#endif

// <q> Fault 1 Protection Enable for channel 3
// <i> This defines fault 1 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault1_enable
#ifndef CONF_PWM_0_FPE3_FAULT1_ENABLE
#define CONF_PWM_0_FPE3_FAULT1_ENABLE 0
#endif

// <q> Fault 2 Protection Enable for channel 3
// <i> This defines fault 2 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault2_enable
#ifndef CONF_PWM_0_FPE3_FAULT2_ENABLE
#define CONF_PWM_0_FPE3_FAULT2_ENABLE 0
#endif

// <q> Fault 3 Protection Enable for channel 3
// <i> This defines fault 3 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault3_enable
#ifndef CONF_PWM_0_FPE3_FAULT3_ENABLE
#define CONF_PWM_0_FPE3_FAULT3_ENABLE 0
#endif

// <q> Fault 4 Protection Enable for channel 3
// <i> This defines fault 4 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault4_enable
#ifndef CONF_PWM_0_FPE3_FAULT4_ENABLE
#define CONF_PWM_0_FPE3_FAULT4_ENABLE 0
#endif

// <q> Fault 5 Protection Enable for channel 3
// <i> This defines fault 5 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault5_enable
#ifndef CONF_PWM_0_FPE3_FAULT5_ENABLE
#define CONF_PWM_0_FPE3_FAULT5_ENABLE 0
#endif

// <q> Fault 6 Protection Enable for channel 3
// <i> This defines fault 6 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault6_enable
#ifndef CONF_PWM_0_FPE3_FAULT6_ENABLE
#define CONF_PWM_0_FPE3_FAULT6_ENABLE 0
#endif

// <q> Fault 7 Protection Enable for channel 3
// <i> This defines fault 7 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault7_enable
#ifndef CONF_PWM_0_FPE3_FAULT7_ENABLE
#define CONF_PWM_0_FPE3_FAULT7_ENABLE 0
#endif

// <o> Fault Protection Value for PWMH output on channel3
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWMH output on channel 3 when fault occurs.
// <id> pwm_fpv1_fpvh3
#ifndef CONF_PWM_0_FPV1_FPVH3
#define CONF_PWM_0_FPV1_FPVH3 2
#endif

// <o> Fault Protection Value for PWML output on channel3
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWML output on channel 3 when fault occurs.
// <id> pwm_fpv1_fpvl3
#ifndef CONF_PWM_0_FPV1_FPVL3
#define CONF_PWM_0_FPV1_FPVL3 2
#endif
// </e>

// </h>

/** Amount of Channel. */
#define CONF_PWM_0_CH_NUM                                                                                              \
	(CONF_PWM_0_CHANNEL0_ENABLE + CONF_PWM_0_CHANNEL1_ENABLE + CONF_PWM_0_CHANNEL2_ENABLE + CONF_PWM_0_CHANNEL3_ENABLE)

/** Amount of Comparison. */
#define CONF_PWM_0_COMP_NUM                                                                                            \
	(0 + CONF_PWM_0_COMP_ENABLE0 + CONF_PWM_0_COMP_ENABLE1 + CONF_PWM_0_COMP_ENABLE2 + CONF_PWM_0_COMP_ENABLE3         \
	 + CONF_PWM_0_COMP_ENABLE4 + CONF_PWM_0_COMP_ENABLE5 + CONF_PWM_0_COMP_ENABLE6 + CONF_PWM_0_COMP_ENABLE7)

/** Amount of Trigger. */
#define CONF_PWM_0_TRIGGER_NUM (CONF_PWM_0_CHANNEL1_TRIGGER_ENABLE + CONF_PWM_0_CHANNEL2_TRIGGER_ENABLE)

#ifndef CONF_PWM_0_FPV1_REGVAL
#define CONF_PWM_0_FPV1_REGVAL                                                                                         \
	(((CONF_PWM_0_FPV1_FPVH0 == 0x02) ? 0 : (CONF_PWM_0_FPV1_FPVH0 << PWM_FPV1_FPVH0_Pos))                             \
	 | ((CONF_PWM_0_FPV1_FPVL0 == 0x02) ? 0 : (CONF_PWM_0_FPV1_FPVH0 << PWM_FPV1_FPVL0_Pos))                           \
	 | ((CONF_PWM_0_FPV1_FPVH1 == 0x02) ? 0 : (CONF_PWM_0_FPV1_FPVH1 << PWM_FPV1_FPVH1_Pos))                           \
	 | ((CONF_PWM_0_FPV1_FPVL1 == 0x02) ? 0 : (CONF_PWM_0_FPV1_FPVH1 << PWM_FPV1_FPVL1_Pos))                           \
	 | ((CONF_PWM_0_FPV1_FPVH2 == 0x02) ? 0 : (CONF_PWM_0_FPV1_FPVH2 << PWM_FPV1_FPVH2_Pos))                           \
	 | ((CONF_PWM_0_FPV1_FPVL2 == 0x02) ? 0 : (CONF_PWM_0_FPV1_FPVH2 << PWM_FPV1_FPVL2_Pos))                           \
	 | ((CONF_PWM_0_FPV1_FPVH3 == 0x02) ? 0 : (CONF_PWM_0_FPV1_FPVH3 << PWM_FPV1_FPVH3_Pos))                           \
	 | ((CONF_PWM_0_FPV1_FPVL3 == 0x02) ? 0 : (CONF_PWM_0_FPV1_FPVH3 << PWM_FPV1_FPVL3_Pos)) | 0)
#endif

#ifndef CONF_PWM_0_FPV2_REGVAL
#define CONF_PWM_0_FPV2_REGVAL                                                                                         \
	(((CONF_PWM_0_FPV1_FPVH0 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                        \
	 | ((CONF_PWM_0_FPV1_FPVL0 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_0_FPV1_FPVH1 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_0_FPV1_FPVL1 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_0_FPV1_FPVH2 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_0_FPV1_FPVL2 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_0_FPV1_FPVH3 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_0_FPV1_FPVL3 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0) | 0)
#endif

#ifndef CONF_PWM_0_FPE_REGVAL
#define CONF_PWM_0_FPE_REGVAL                                                                                          \
	((CONF_PWM_0_FPE0_FAULT0_ENABLE << (PWM_FPE_FPE0_Pos + 0))                                                         \
	 | (CONF_PWM_0_FPE0_FAULT1_ENABLE << (PWM_FPE_FPE0_Pos + 1))                                                       \
	 | (CONF_PWM_0_FPE0_FAULT2_ENABLE << (PWM_FPE_FPE0_Pos + 2))                                                       \
	 | (CONF_PWM_0_FPE0_FAULT3_ENABLE << (PWM_FPE_FPE0_Pos + 3))                                                       \
	 | (CONF_PWM_0_FPE0_FAULT4_ENABLE << (PWM_FPE_FPE0_Pos + 4))                                                       \
	 | (CONF_PWM_0_FPE0_FAULT5_ENABLE << (PWM_FPE_FPE0_Pos + 5))                                                       \
	 | (CONF_PWM_0_FPE0_FAULT6_ENABLE << (PWM_FPE_FPE0_Pos + 6))                                                       \
	 | (CONF_PWM_0_FPE0_FAULT7_ENABLE << (PWM_FPE_FPE0_Pos + 7))                                                       \
	 | (CONF_PWM_0_FPE1_FAULT0_ENABLE << (PWM_FPE_FPE1_Pos + 0))                                                       \
	 | (CONF_PWM_0_FPE1_FAULT1_ENABLE << (PWM_FPE_FPE1_Pos + 1))                                                       \
	 | (CONF_PWM_0_FPE1_FAULT2_ENABLE << (PWM_FPE_FPE1_Pos + 2))                                                       \
	 | (CONF_PWM_0_FPE1_FAULT3_ENABLE << (PWM_FPE_FPE1_Pos + 3))                                                       \
	 | (CONF_PWM_0_FPE1_FAULT4_ENABLE << (PWM_FPE_FPE1_Pos + 4))                                                       \
	 | (CONF_PWM_0_FPE1_FAULT5_ENABLE << (PWM_FPE_FPE1_Pos + 5))                                                       \
	 | (CONF_PWM_0_FPE1_FAULT6_ENABLE << (PWM_FPE_FPE1_Pos + 6))                                                       \
	 | (CONF_PWM_0_FPE1_FAULT7_ENABLE << (PWM_FPE_FPE1_Pos + 7))                                                       \
	 | (CONF_PWM_0_FPE2_FAULT0_ENABLE << (PWM_FPE_FPE2_Pos + 0))                                                       \
	 | (CONF_PWM_0_FPE2_FAULT1_ENABLE << (PWM_FPE_FPE2_Pos + 1))                                                       \
	 | (CONF_PWM_0_FPE2_FAULT2_ENABLE << (PWM_FPE_FPE2_Pos + 2))                                                       \
	 | (CONF_PWM_0_FPE2_FAULT3_ENABLE << (PWM_FPE_FPE2_Pos + 3))                                                       \
	 | (CONF_PWM_0_FPE2_FAULT4_ENABLE << (PWM_FPE_FPE2_Pos + 4))                                                       \
	 | (CONF_PWM_0_FPE2_FAULT5_ENABLE << (PWM_FPE_FPE2_Pos + 5))                                                       \
	 | (CONF_PWM_0_FPE2_FAULT6_ENABLE << (PWM_FPE_FPE2_Pos + 6))                                                       \
	 | (CONF_PWM_0_FPE2_FAULT7_ENABLE << (PWM_FPE_FPE2_Pos + 7))                                                       \
	 | (CONF_PWM_0_FPE3_FAULT0_ENABLE << (PWM_FPE_FPE3_Pos + 0))                                                       \
	 | (CONF_PWM_0_FPE3_FAULT1_ENABLE << (PWM_FPE_FPE3_Pos + 1))                                                       \
	 | (CONF_PWM_0_FPE3_FAULT2_ENABLE << (PWM_FPE_FPE3_Pos + 2))                                                       \
	 | (CONF_PWM_0_FPE3_FAULT3_ENABLE << (PWM_FPE_FPE3_Pos + 3))                                                       \
	 | (CONF_PWM_0_FPE3_FAULT4_ENABLE << (PWM_FPE_FPE3_Pos + 4))                                                       \
	 | (CONF_PWM_0_FPE3_FAULT5_ENABLE << (PWM_FPE_FPE3_Pos + 5))                                                       \
	 | (CONF_PWM_0_FPE3_FAULT6_ENABLE << (PWM_FPE_FPE3_Pos + 6))                                                       \
	 | (CONF_PWM_0_FPE3_FAULT7_ENABLE << (PWM_FPE_FPE3_Pos + 7)) | 0)
#endif

#ifndef CONF_PWM_0_ELMR0_REGVAL
#define CONF_PWM_0_ELMR0_REGVAL                                                                                        \
	((CONF_PWM_0_ELMR0_CSEL0 < PWM_ELMR_CSEL0_Pos) | (CONF_PWM_0_ELMR0_CSEL1 < PWM_ELMR_CSEL1_Pos)                     \
	 | (CONF_PWM_0_ELMR0_CSEL2 < PWM_ELMR_CSEL2_Pos) | (CONF_PWM_0_ELMR0_CSEL3 < PWM_ELMR_CSEL3_Pos)                   \
	 | (CONF_PWM_0_ELMR0_CSEL4 < PWM_ELMR_CSEL4_Pos) | (CONF_PWM_0_ELMR0_CSEL5 < PWM_ELMR_CSEL5_Pos)                   \
	 | (CONF_PWM_0_ELMR0_CSEL6 < PWM_ELMR_CSEL6_Pos) | (CONF_PWM_0_ELMR0_CSEL7 < PWM_ELMR_CSEL7_Pos) | 0)
#endif

#ifndef CONF_PWM_0_ELMR1_REGVAL
#define CONF_PWM_0_ELMR1_REGVAL                                                                                        \
	((CONF_PWM_0_ELMR1_CSEL0 < PWM_ELMR_CSEL0_Pos) | (CONF_PWM_0_ELMR1_CSEL1 < PWM_ELMR_CSEL1_Pos)                     \
	 | (CONF_PWM_0_ELMR1_CSEL2 < PWM_ELMR_CSEL2_Pos) | (CONF_PWM_0_ELMR1_CSEL3 < PWM_ELMR_CSEL3_Pos)                   \
	 | (CONF_PWM_0_ELMR1_CSEL4 < PWM_ELMR_CSEL4_Pos) | (CONF_PWM_0_ELMR1_CSEL5 < PWM_ELMR_CSEL5_Pos)                   \
	 | (CONF_PWM_0_ELMR1_CSEL6 < PWM_ELMR_CSEL6_Pos) | (CONF_PWM_0_ELMR1_CSEL7 < PWM_ELMR_CSEL7_Pos) | 0)
#endif

#ifndef CONF_PWM_0_FMR_REGVAL
#define CONF_PWM_0_FMR_REGVAL                                                                                          \
	((CONF_PWM_0_FMR_FPOL_FAULT0 << (PWM_FMR_FPOL_Pos + 0)) | (CONF_PWM_0_FMR_FFIL_FAULT0 << (PWM_FMR_FFIL_Pos + 0))   \
	 | (CONF_PWM_0_FMR_FMOD_FAULT0 << (PWM_FMR_FMOD_Pos + 0)) | (CONF_PWM_0_FMR_FPOL_FAULT1 << (PWM_FMR_FPOL_Pos + 1)) \
	 | (CONF_PWM_0_FMR_FFIL_FAULT1 << (PWM_FMR_FFIL_Pos + 1)) | (CONF_PWM_0_FMR_FMOD_FAULT1 << (PWM_FMR_FMOD_Pos + 1)) \
	 | (CONF_PWM_0_FMR_FPOL_FAULT2 << (PWM_FMR_FPOL_Pos + 2)) | (CONF_PWM_0_FMR_FFIL_FAULT2 << (PWM_FMR_FFIL_Pos + 2)) \
	 | (CONF_PWM_0_FMR_FMOD_FAULT2 << (PWM_FMR_FMOD_Pos + 2)) | (CONF_PWM_0_FMR_FPOL_FAULT3 << (PWM_FMR_FPOL_Pos + 3)) \
	 | (CONF_PWM_0_FMR_FFIL_FAULT3 << (PWM_FMR_FFIL_Pos + 3)) | (CONF_PWM_0_FMR_FMOD_FAULT3 << (PWM_FMR_FMOD_Pos + 3)) \
	 | (CONF_PWM_0_FMR_FPOL_FAULT4 << (PWM_FMR_FPOL_Pos + 4)) | (CONF_PWM_0_FMR_FFIL_FAULT4 << (PWM_FMR_FFIL_Pos + 4)) \
	 | (CONF_PWM_0_FMR_FMOD_FAULT4 << (PWM_FMR_FMOD_Pos + 4)) | (CONF_PWM_0_FMR_FPOL_FAULT5 << (PWM_FMR_FPOL_Pos + 5)) \
	 | (CONF_PWM_0_FMR_FFIL_FAULT5 << (PWM_FMR_FFIL_Pos + 5)) | (CONF_PWM_0_FMR_FMOD_FAULT5 << (PWM_FMR_FMOD_Pos + 5)) \
	 | (CONF_PWM_0_FMR_FPOL_FAULT6 << (PWM_FMR_FPOL_Pos + 6)) | (CONF_PWM_0_FMR_FFIL_FAULT6 << (PWM_FMR_FFIL_Pos + 6)) \
	 | (CONF_PWM_0_FMR_FMOD_FAULT6 << (PWM_FMR_FMOD_Pos + 6)) | (CONF_PWM_0_FMR_FPOL_FAULT7 << (PWM_FMR_FPOL_Pos + 7)) \
	 | (CONF_PWM_0_FMR_FFIL_FAULT7 << (PWM_FMR_FFIL_Pos + 7)) | (CONF_PWM_0_FMR_FMOD_FAULT7 << (PWM_FMR_FMOD_Pos + 7)) \
	 | 0)
#endif

#ifndef CONF_PWM_0_ETRG1_REGVAL
#define CONF_PWM_0_ETRG1_REGVAL                                                                                        \
	(PWM_ETRG1_TRGMODE(CONF_PWM_0_CHANNEL1_TRGMODE) | (CONF_PWM_0_CHANNEL1_TRGEDGE << PWM_ETRG1_TRGEDGE_Pos)           \
	 | (CONF_PWM_0_CHANNEL1_TRGFILT << PWM_ETRG1_TRGFILT_Pos) | (CONF_PWM_0_CHANNEL1_TRGSRC << PWM_ETRG1_TRGSRC_Pos)   \
	 | (CONF_PWM_0_CHANNEL1_RFEN << PWM_ETRG1_RFEN_Pos))
#endif

#ifndef CONF_PWM_0_ETRG2_REGVAL
#define CONF_PWM_0_ETRG2_REGVAL                                                                                        \
	(PWM_ETRG2_TRGMODE(CONF_PWM_0_CHANNEL2_TRGMODE) | (CONF_PWM_0_CHANNEL2_TRGEDGE << PWM_ETRG2_TRGEDGE_Pos)           \
	 | (CONF_PWM_0_CHANNEL2_TRGFILT << PWM_ETRG2_TRGFILT_Pos) | (CONF_PWM_0_CHANNEL2_TRGSRC << PWM_ETRG2_TRGSRC_Pos)   \
	 | (CONF_PWM_0_CHANNEL2_RFEN << PWM_ETRG2_RFEN_Pos))
#endif

#include <peripheral_clk_config.h>

#ifndef CONF_PWM_1_ENABLE
#define CONF_PWM_1_ENABLE 1
#endif

// <h> Basic settings

// <o> CLKA Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <i> This defines the clka source clock.
// <id> pwm_prea
#ifndef CONF_PWM_1_PREA
#define CONF_PWM_1_PREA 0
#endif

// <o> CLKA Divide Factor<0-255>
// <i> Defines the clka divided by DIVA factor
// <id> pwm_diva
#ifndef CONF_PWM_1_DIVA
#define CONF_PWM_1_DIVA 1
#endif

// <o> CLKB Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <i> This defines the clkb source clock.
// <id> pwm_preb
#ifndef CONF_PWM_1_PREB
#define CONF_PWM_1_PREB 0
#endif

// <o> CLKB Divide Factor<0-255>
// <i> Defines the clka divided by DIVB factor
// <id> pwm_divb
#ifndef CONF_PWM_1_DIVB
#define CONF_PWM_1_DIVB 1
#endif

// </h>

// <h> Channel configuration
// <e> Channel0 Settings
// <id> channel0_settings
#ifndef CONF_PWM_1_CHANNEL0_ENABLE
#define CONF_PWM_1_CHANNEL0_ENABLE 1
#endif

// <o> Channel Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <11=> CLKA
// <12=> CLKB
// <i> This defines the channel source clock
// <id> pwm_channel0_clk_src
#ifndef CONF_PWM_1_CHANNEL0_CPRE
#define CONF_PWM_1_CHANNEL0_CPRE 0
#endif

// <o> Channel Period Value <1-65535>
// <i> Channel Period Value
// <id> pwm_channel0_CPRD
#ifndef CONF_PWM_1_CHANNEL0_CPRD
#define CONF_PWM_1_CHANNEL0_CPRD 1024
#endif

// <o> Channel Duty Cycle Value <1-65535>
// <i> Channel Duty Cycle Value, this value must be defined between 0 and CPRD
// <id> pwm_channel0_CDTY
#ifndef CONF_PWM_1_CHANNEL0_CDTY
#define CONF_PWM_1_CHANNEL0_CDTY 512
#endif

// <o> Channel Polarity
// <0=> The OCx output waveform starts at a low level
// <1=> The OCx output waveform starts at a high level
// <i> Indicates whether OCx output start at high level or not
// <id> pwm_channel0_output_polarity
#ifndef CONF_PWM_1_CHANNEL0_CPOL
#define CONF_PWM_1_CHANNEL0_CPOL 0
#endif

// <q> Channel Disabled status Polarity Inverted
// <i> When the PWM channel x is disabled, whether OCx output is
// <i> inverted compared to the one defined by the CPOL bit
// <id> pwm_channel0_disabled_polarity_inverted
#ifndef CONF_PWM_1_CHANNEL0_DPOLI
#define CONF_PWM_1_CHANNEL0_DPOLI 0
#endif

// <o> Channel Alignment
// <0=> The period is left-aligned
// <1=> The period is center-aligned
// <i> Channel period Channel Alignment
// <id> pwm_channel0_alignment
#ifndef CONF_PWM_1_CHANNEL0_CALG
#define CONF_PWM_1_CHANNEL0_CALG 0
#endif

// </e>

// <e> Channel1 Settings
// <id> channel1_settings
#ifndef CONF_PWM_1_CHANNEL1_ENABLE
#define CONF_PWM_1_CHANNEL1_ENABLE 1
#endif

// <o> Channel Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <11=> CLKA
// <12=> CLKB
// <i> This defines the channel source clock
// <id> pwm_channel1_clk_src
#ifndef CONF_PWM_1_CHANNEL1_CPRE
#define CONF_PWM_1_CHANNEL1_CPRE 0
#endif

// <o> Channel Period Value <1-65535>
// <i> Channel Period Value
// <id> pwm_channel1_CPRD
#ifndef CONF_PWM_1_CHANNEL1_CPRD
#define CONF_PWM_1_CHANNEL1_CPRD 1024
#endif

// <o> Channel Duty Cycle Value <1-65535>
// <i> Channel Duty Cycle Value, this value must be defined between 0 and CPRD
// <id> pwm_channel1_CDTY
#ifndef CONF_PWM_1_CHANNEL1_CDTY
#define CONF_PWM_1_CHANNEL1_CDTY 512
#endif

// <o> Channel Polarity
// <0=> The OCx output waveform starts at a low level
// <1=> The OCx output waveform starts at a high level
// <i> Indicates whether OCx output start at high level or not
// <id> pwm_channel1_output_polarity
#ifndef CONF_PWM_1_CHANNEL1_CPOL
#define CONF_PWM_1_CHANNEL1_CPOL 0
#endif

// <q> Channel Disabled status Polarity Inverted
// <i> When the PWM channel x is disabled, whether OCx output
// <i> is inverted compared to the one defined by the CPOL bit
// <id> pwm_channel1_disabled_polarity_inverted
#ifndef CONF_PWM_1_CHANNEL1_DPOLI
#define CONF_PWM_1_CHANNEL1_DPOLI 0
#endif

// <o> Channel Alignment
// <0=> The period is left-aligned
// <1=> The period is center-aligned
// <i> Channel period Channel Alignment
// <id> pwm_channel1_alignment
#ifndef CONF_PWM_1_CHANNEL1_CALG
#define CONF_PWM_1_CHANNEL1_CALG 0
#endif

// <e> Channel 1 External Trigger Enable
// <id> pwm_channel1_trigger_enable
#ifndef CONF_PWM_1_CHANNEL1_TRIGGER_ENABLE
#define CONF_PWM_1_CHANNEL1_TRIGGER_ENABLE 0
#endif

// <o> Channel 1 External Trigger Mode
// <0x0=> External trigger is not enabled.
// <0x1=> External PWM Reset Mode
// <0x2=> External PWM Start Mode
// <0x3=> Cycle-by-cycle Duty Mode
// <i> This defines external trigger mode.
// <id> pwm_channel1_trgmode
#ifndef CONF_PWM_1_CHANNEL1_TRGMODE
#define CONF_PWM_1_CHANNEL1_TRGMODE 0
#endif

// <o> Channel 1 Trigger Source Selection
// <0x0=> By the PWMTRG input
// <0x1=> By the Analog Comparator Controller
// <i> This defines trigger source selection.
// <id> pwm_channel1_trgsrc
#ifndef CONF_PWM_1_CHANNEL1_TRGSRC
#define CONF_PWM_1_CHANNEL1_TRGSRC 0
#endif

// <o> Channel 1 Edge Selection
// <0x0=> Falling edge or level 0
// <0x1=> Rising edge or level 1
// <i> If trigger mode is Reset Mode, trigger edge is falling edge or rising edge.
// <i> If trigger mode is Start Mode or Cycle-by-cycle Duty Mode, trigger edge is level 0 or 1.
// <id> pwm_channel1_trgedge
#ifndef CONF_PWM_1_CHANNEL1_TRGEDGE
#define CONF_PWM_1_CHANNEL1_TRGEDGE 0
#endif

// <q> Channel 1 Recoverable Fault Enable
// <i> This defines whether the TRGINx signal generate a recoverable fault in place of the fault input.
// <id> pwm_channel1_rfen
#ifndef CONF_PWM_1_CHANNEL1_RFEN
#define CONF_PWM_1_CHANNEL1_RFEN 0
#endif

// <q> Channel 1 Filtered Input
// <i> This defines whether the external trigger input is filtered.
// <id> pwm_channel1_trgfilt
#ifndef CONF_PWM_1_CHANNEL1_TRGFILT
#define CONF_PWM_1_CHANNEL1_TRGFILT 0
#endif

// </e>

// </e>

// <e> Channel2 Settings
// <id> channel2_settings
#ifndef CONF_PWM_1_CHANNEL2_ENABLE
#define CONF_PWM_1_CHANNEL2_ENABLE 1
#endif

// <o> Channel Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <11=> CLKA
// <12=> CLKB
// <i> This defines the channel source clock
// <id> pwm_channel2_clk_src
#ifndef CONF_PWM_1_CHANNEL2_CPRE
#define CONF_PWM_1_CHANNEL2_CPRE 0
#endif

// <o> Channel Period Value <1-65535>
// <i> Channel Period Value
// <id> pwm_channel2_CPRD
#ifndef CONF_PWM_1_CHANNEL2_CPRD
#define CONF_PWM_1_CHANNEL2_CPRD 1024
#endif

// <o> Channel Duty Cycle Value <1-65535>
// <i> Channel Duty Cycle Value, this value must be defined between 0 and CPRD
// <id> pwm_channel2_CDTY
#ifndef CONF_PWM_1_CHANNEL2_CDTY
#define CONF_PWM_1_CHANNEL2_CDTY 512
#endif

// <o> Channel Polarity
// <0=> The OCx output waveform starts at a low level
// <1=> The OCx output waveform starts at a high level
// <i> Indicates whether OCx output start at high level or not
// <id> pwm_channel2_output_polarity
#ifndef CONF_PWM_1_CHANNEL2_CPOL
#define CONF_PWM_1_CHANNEL2_CPOL 0
#endif

// <q> Channel Disabled status Polarity Inverted
// <i> When the PWM channel x is disabled, whether OCx output
// <i> is inverted compared to the one defined by the CPOL bit
// <id> pwm_channel2_disabled_polarity_inverted
#ifndef CONF_PWM_1_CHANNEL2_DPOLI
#define CONF_PWM_1_CHANNEL2_DPOLI 0
#endif

// <o> Channel Alignment
// <0=> The period is left-aligned
// <1=> The period is center-aligned
// <i> Channel period Channel Alignment
// <id> pwm_channel2_alignment
#ifndef CONF_PWM_1_CHANNEL2_CALG
#define CONF_PWM_1_CHANNEL2_CALG 0
#endif

// <e> Channel 2 External Trigger Enable
// <id> pwm_channel2_trigger_enable
#ifndef CONF_PWM_1_CHANNEL2_TRIGGER_ENABLE
#define CONF_PWM_1_CHANNEL2_TRIGGER_ENABLE 0
#endif

// <o> Channel 2 External Trigger Mode
// <0x0=> External trigger is not enabled.
// <0x1=> External PWM Reset Mode
// <0x2=> External PWM Start Mode
// <0x3=> Cycle-by-cycle Duty Mode
// <i> This defines external trigger mode.
// <id> pwm_channel2_trgmode
#ifndef CONF_PWM_1_CHANNEL2_TRGMODE
#define CONF_PWM_1_CHANNEL2_TRGMODE 0
#endif

// <o> Channel 2 Trigger Source Selection
// <0x0=> By the PWMTRG input
// <0x1=> By the Analog Comparator Controller
// <i> This defines trigger source selection.
// <id> pwm_channel2_trgsrc
#ifndef CONF_PWM_1_CHANNEL2_TRGSRC
#define CONF_PWM_1_CHANNEL2_TRGSRC 0
#endif

// <o> Channel 2 Edge Selection
// <0x0=> Falling edge or level 0
// <0x1=> Rising edge or level 1
// <i> If trigger mode is Reset Mode, trigger edge is falling edge or rising edge.
// <i> If trigger mode is Start Mode or Cycle-by-cycle Duty Mode, trigger edge is level 0 or 1.
// <id> pwm_channel2_trgedge
#ifndef CONF_PWM_1_CHANNEL2_TRGEDGE
#define CONF_PWM_1_CHANNEL2_TRGEDGE 0
#endif

// <q> Channel 2 Recoverable Fault Enable
// <i> This defines whether the TRGINx signal generate a recoverable fault in place of the fault input.
// <id> pwm_channel2_rfen
#ifndef CONF_PWM_1_CHANNEL2_RFEN
#define CONF_PWM_1_CHANNEL2_RFEN 0
#endif

// <q> Channel 2 Filtered Input
// <i> This defines whether the external trigger input is filtered.
// <id> pwm_channel2_trgfilt
#ifndef CONF_PWM_1_CHANNEL2_TRGFILT
#define CONF_PWM_1_CHANNEL2_TRGFILT 0
#endif

// </e>

// </e>

// <e> Channel3 Settings
// <id> channel3_settings
#ifndef CONF_PWM_1_CHANNEL3_ENABLE
#define CONF_PWM_1_CHANNEL3_ENABLE 1
#endif

// <o> Channel Source Clock Selection
// <0=> Peripheral clock
// <1=> Peripheral clock/2
// <2=> Peripheral clock/4
// <3=> Peripheral clock/8
// <4=> Peripheral clock/16
// <5=> Peripheral clock/32
// <6=> Peripheral clock/64
// <7=> Peripheral clock/128
// <8=> Peripheral clock/256
// <9=> Peripheral clock/512
// <10=> Peripheral clock/1024
// <11=> CLKA
// <12=> CLKB
// <i> This defines the channel source clock
// <id> pwm_channel3_clk_src
#ifndef CONF_PWM_1_CHANNEL3_CPRE
#define CONF_PWM_1_CHANNEL3_CPRE 0
#endif

// <o> Channel Period Value <1-65535>
// <i> Channel Period Value
// <id> pwm_channel3_CPRD
#ifndef CONF_PWM_1_CHANNEL3_CPRD
#define CONF_PWM_1_CHANNEL3_CPRD 1024
#endif

// <o> Channel Duty Cycle Value <1-65535>
// <i> Channel Duty Cycle Value, this value must be defined between 0 and CPRD
// <id> pwm_channel3_CDTY
#ifndef CONF_PWM_1_CHANNEL3_CDTY
#define CONF_PWM_1_CHANNEL3_CDTY 512
#endif

// <o> Channel Polarity
// <0=> The OCx output waveform starts at a low level
// <1=> The OCx output waveform starts at a high level
// <i> Indicates whether OCx output start at high level or not
// <id> pwm_channel3_output_polarity
#ifndef CONF_PWM_1_CHANNEL3_CPOL
#define CONF_PWM_1_CHANNEL3_CPOL 0
#endif

// <q> Channel Disabled status Polarity Inverted
// <i> When the PWM channel x is disabled, whether OCx output
// <i> is inverted compared to the one defined by the CPOL bit
// <id> pwm_channel3_disabled_polarity_inverted
#ifndef CONF_PWM_1_CHANNEL3_DPOLI
#define CONF_PWM_1_CHANNEL3_DPOLI 0
#endif

// <o> Channel Alignment
// <0=> The period is left-aligned
// <1=> The period is center-aligned
// <i> Channel period Channel Alignment
// <id> pwm_channel3_alignment
#ifndef CONF_PWM_1_CHANNEL3_CALG
#define CONF_PWM_1_CHANNEL3_CALG 0
#endif
// </e>
// </h>

// <h> Comparison Configuration

// <e> Comparison 0 ENABLE
// <i> This defines the comparison 0 is enabled and can match.
// <id> pwm_comp_enable0
#ifndef CONF_PWM_1_COMP_ENABLE0
#define CONF_PWM_1_COMP_ENABLE0 0
#endif

// <q> Event Lines 0 Comparison 0 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel0_enable
#ifndef CONF_PWM_1_ELMR0_CSEL0
#define CONF_PWM_1_ELMR0_CSEL0 0
#endif

// <q> Event Lines 1 Comparison 0 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel0_enable
#ifndef CONF_PWM_1_ELMR1_CSEL0
#define CONF_PWM_1_ELMR1_CSEL0 0
#endif

// <o> Comparison 0 Value <0-65535>
// <i> Define the comparison 0 value to be compared with the counter of the channel 0.
// <id> pwm_cv0
#ifndef CONF_PWM_1_CV0
#define CONF_PWM_1_CV0 0
#endif

// <o> Comparison 0 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm0
#ifndef CONF_PWM_1_CVM0
#define CONF_PWM_1_CVM0 0
#endif

// <o> Comparison 0 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr0
#ifndef CONF_PWM_1_CTR0
#define CONF_PWM_1_CTR0 0
#endif

// <o> Comparison 0 Period <0-15>
// <i> This defines the maximum value of the comparison 0 period counter.
// <id> pwm_cpr0
#ifndef CONF_PWM_1_CPR0
#define CONF_PWM_1_CPR0 0
#endif

// <o> Comparison 0 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 0 value.
// <id> pwm_cupr0
#ifndef CONF_PWM_1_CUPR0
#define CONF_PWM_1_CUPR0 0
#endif

// </e>

// <e> Comparison 1 ENABLE
// <i> This defines the comparison 1 is enabled and can match.
// <id> pwm_comp_enable1
#ifndef CONF_PWM_1_COMP_ENABLE1
#define CONF_PWM_1_COMP_ENABLE1 0
#endif

// <q> Event Lines 0 Comparison 1 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel1_enable
#ifndef CONF_PWM_1_ELMR0_CSEL1
#define CONF_PWM_1_ELMR0_CSEL1 0
#endif

// <q> Event Lines 1 Comparison 1 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel1_enable
#ifndef CONF_PWM_1_ELMR1_CSEL1
#define CONF_PWM_1_ELMR1_CSEL1 0
#endif

// <o> Comparison 1 Value <0-65535>
// <i> Define the comparison 1 value to be compared with the counter of the channel 0.
// <id> pwm_cv1
#ifndef CONF_PWM_1_CV1
#define CONF_PWM_1_CV1 0
#endif

// <o> Comparison 1 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm1
#ifndef CONF_PWM_1_CVM1
#define CONF_PWM_1_CVM1 0
#endif

// <o> Comparison 1 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr1
#ifndef CONF_PWM_1_CTR1
#define CONF_PWM_1_CTR1 0
#endif

// <o> Comparison 1 Period <0-15>
// <i> This defines the maximum value of the comparison 1 period counter.
// <id> pwm_cpr1
#ifndef CONF_PWM_1_CPR1
#define CONF_PWM_1_CPR1 0
#endif

// <o> Comparison 1 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 1 value.
// <id> pwm_cupr1
#ifndef CONF_PWM_1_CUPR1
#define CONF_PWM_1_CUPR1 0
#endif

// </e>

// <e> Comparison 2 ENABLE
// <i> This defines the comparison 2 is enabled and can match.
// <id> pwm_comp_enable2
#ifndef CONF_PWM_1_COMP_ENABLE2
#define CONF_PWM_1_COMP_ENABLE2 0
#endif

// <q> Event Lines 0 Comparison 2 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel2_enable
#ifndef CONF_PWM_1_ELMR0_CSEL2
#define CONF_PWM_1_ELMR0_CSEL2 0
#endif

// <q> Event Lines 1 Comparison 2 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel2_enable
#ifndef CONF_PWM_1_ELMR1_CSEL2
#define CONF_PWM_1_ELMR1_CSEL2 0
#endif

// <o> Comparison 2 Value <0-65535>
// <i> Define the comparison 2 value to be compared with the counter of the channel 0.
// <id> pwm_cv2
#ifndef CONF_PWM_1_CV2
#define CONF_PWM_1_CV2 0
#endif

// <o> Comparison 2 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm2
#ifndef CONF_PWM_1_CVM2
#define CONF_PWM_1_CVM2 0
#endif

// <o> Comparison 2 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr2
#ifndef CONF_PWM_1_CTR2
#define CONF_PWM_1_CTR2 0
#endif

// <o> Comparison 2 Period <0-15>
// <i> This defines the maximum value of the comparison 2 period counter.
// <id> pwm_cpr2
#ifndef CONF_PWM_1_CPR2
#define CONF_PWM_1_CPR2 0
#endif

// <o> Comparison 2 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 2 value.
// <id> pwm_cupr2
#ifndef CONF_PWM_1_CUPR2
#define CONF_PWM_1_CUPR2 0
#endif

// </e>

// <e> Comparison 3 ENABLE
// <i> This defines the comparison 3 is enabled and can match.
// <id> pwm_comp_enable3
#ifndef CONF_PWM_1_COMP_ENABLE3
#define CONF_PWM_1_COMP_ENABLE3 0
#endif

// <q> Event Lines 0 Comparison 3 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel3_enable
#ifndef CONF_PWM_1_ELMR0_CSEL3
#define CONF_PWM_1_ELMR0_CSEL3 0
#endif

// <q> Event Lines 1 Comparison 3 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel3_enable
#ifndef CONF_PWM_1_ELMR1_CSEL3
#define CONF_PWM_1_ELMR1_CSEL3 0
#endif

// <o> Comparison 3 Value <0-65535>
// <i> Define the comparison 3 value to be compared with the counter of the channel 0.
// <id> pwm_cv3
#ifndef CONF_PWM_1_CV3
#define CONF_PWM_1_CV3 0
#endif

// <o> Comparison 3 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm3
#ifndef CONF_PWM_1_CVM3
#define CONF_PWM_1_CVM3 0
#endif

// <o> Comparison 3 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr3
#ifndef CONF_PWM_1_CTR3
#define CONF_PWM_1_CTR3 0
#endif

// <o> Comparison 3 Period <0-15>
// <i> This defines the maximum value of the comparison 3 period counter.
// <id> pwm_cpr3
#ifndef CONF_PWM_1_CPR3
#define CONF_PWM_1_CPR3 0
#endif

// <o> Comparison 3 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 3 value.
// <id> pwm_cupr3
#ifndef CONF_PWM_1_CUPR3
#define CONF_PWM_1_CUPR3 0
#endif

// </e>

// <e> Comparison 4 ENABLE
// <i> This defines the comparison 4 is enabled and can match.
// <id> pwm_comp_enable4
#ifndef CONF_PWM_1_COMP_ENABLE4
#define CONF_PWM_1_COMP_ENABLE4 0
#endif

// <q> Event Lines 0 Comparison 4 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel4_enable
#ifndef CONF_PWM_1_ELMR0_CSEL4
#define CONF_PWM_1_ELMR0_CSEL4 0
#endif

// <q> Event Lines 1 Comparison 4 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel4_enable
#ifndef CONF_PWM_1_ELMR1_CSEL4
#define CONF_PWM_1_ELMR1_CSEL4 0
#endif

// <o> Comparison 4 Value <0-65535>
// <i> Define the comparison 4 value to be compared with the counter of the channel 0.
// <id> pwm_cv4
#ifndef CONF_PWM_1_CV4
#define CONF_PWM_1_CV4 0
#endif

// <o> Comparison 4 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm4
#ifndef CONF_PWM_1_CVM4
#define CONF_PWM_1_CVM4 0
#endif

// <o> Comparison 4 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr4
#ifndef CONF_PWM_1_CTR4
#define CONF_PWM_1_CTR4 0
#endif

// <o> Comparison 4 Period <0-15>
// <i> This defines the maximum value of the comparison 4 period counter.
// <id> pwm_cpr4
#ifndef CONF_PWM_1_CPR4
#define CONF_PWM_1_CPR4 0
#endif

// <o> Comparison 4 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 4 value.
// <id> pwm_cupr4
#ifndef CONF_PWM_1_CUPR4
#define CONF_PWM_1_CUPR4 0
#endif

// </e>

// <e> Comparison 5 ENABLE
// <i> This defines the comparison 5 is enabled and can match.
// <id> pwm_comp_enable5
#ifndef CONF_PWM_1_COMP_ENABLE5
#define CONF_PWM_1_COMP_ENABLE5 0
#endif

// <q> Event Lines 0 Comparison 5 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel5_enable
#ifndef CONF_PWM_1_ELMR0_CSEL5
#define CONF_PWM_1_ELMR0_CSEL5 0
#endif

// <q> Event Lines 1 Comparison 5 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel5_enable
#ifndef CONF_PWM_1_ELMR1_CSEL5
#define CONF_PWM_1_ELMR1_CSEL5 0
#endif

// <o> Comparison 5 Value <0-65535>
// <i> Define the comparison 5 value to be compared with the counter of the channel 0.
// <id> pwm_cv5
#ifndef CONF_PWM_1_CV5
#define CONF_PWM_1_CV5 0
#endif

// <o> Comparison 5 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm5
#ifndef CONF_PWM_1_CVM5
#define CONF_PWM_1_CVM5 0
#endif

// <o> Comparison 5 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr5
#ifndef CONF_PWM_1_CTR5
#define CONF_PWM_1_CTR5 0
#endif

// <o> Comparison 5 Period <0-15>
// <i> This defines the maximum value of the comparison 5 period counter.
// <id> pwm_cpr5
#ifndef CONF_PWM_1_CPR5
#define CONF_PWM_1_CPR5 0
#endif

// <o> Comparison 5 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 5 value.
// <id> pwm_cupr5
#ifndef CONF_PWM_1_CUPR5
#define CONF_PWM_1_CUPR5 0
#endif

// </e>

// <e> Comparison 6 ENABLE
// <i> This defines the comparison 6 is enabled and can match.
// <id> pwm_comp_enable6
#ifndef CONF_PWM_1_COMP_ENABLE6
#define CONF_PWM_1_COMP_ENABLE6 0
#endif

// <q> Event Lines 0 Comparison 6 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel6_enable
#ifndef CONF_PWM_1_ELMR0_CSEL6
#define CONF_PWM_1_ELMR0_CSEL6 0
#endif

// <q> Event Lines 1 Comparison 6 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel6_enable
#ifndef CONF_PWM_1_ELMR1_CSEL6
#define CONF_PWM_1_ELMR1_CSEL6 0
#endif

// <o> Comparison 6 Value <0-65535>
// <i> Define the comparison 6 value to be compared with the counter of the channel 0.
// <id> pwm_cv6
#ifndef CONF_PWM_1_CV6
#define CONF_PWM_1_CV6 0
#endif

// <o> Comparison 6 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm6
#ifndef CONF_PWM_1_CVM6
#define CONF_PWM_1_CVM6 0
#endif

// <o> Comparison 6 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr6
#ifndef CONF_PWM_1_CTR6
#define CONF_PWM_1_CTR6 0
#endif

// <o> Comparison 6 Period <0-15>
// <i> This defines the maximum value of the comparison 6 period counter.
// <id> pwm_cpr6
#ifndef CONF_PWM_1_CPR6
#define CONF_PWM_1_CPR6 0
#endif

// <o> Comparison 6 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 6 value.
// <id> pwm_cupr6
#ifndef CONF_PWM_1_CUPR6
#define CONF_PWM_1_CUPR6 0
#endif

// </e>

// <e> Comparison 7 ENABLE
// <i> This defines the comparison 7 is enabled and can match.
// <id> pwm_comp_enable7
#ifndef CONF_PWM_1_COMP_ENABLE7
#define CONF_PWM_1_COMP_ENABLE7 0
#endif

// <q> Event Lines 0 Comparison 7 Enable
// <i> A pulse is generated on the event line 0 when the comparison match.
// <id> pwm_elmr0_csel7_enable
#ifndef CONF_PWM_1_ELMR0_CSEL7
#define CONF_PWM_1_ELMR0_CSEL7 0
#endif

// <q> Event Lines 1 Comparison 7 Enable
// <i> A pulse is generated on the event line 1 when the comparison match.
// <id> pwm_elmr1_csel7_enable
#ifndef CONF_PWM_1_ELMR1_CSEL7
#define CONF_PWM_1_ELMR1_CSEL7 0
#endif

// <o> Comparison 7 Value <0-65535>
// <i> Define the comparison 7 value to be compared with the counter of the channel 0.
// <id> pwm_cv7
#ifndef CONF_PWM_1_CV7
#define CONF_PWM_1_CV7 0
#endif

// <o> Comparison 7 Value Mode
// <0x0=> The comparison value is performed when this counter is incrementing.
// <0x1=> The comparison value is performed when this counter is decrementing.
// <i> Define comparison value mode. This bit is not relevant if the counter of the channel 0 is left-aligned.
// <id> pwm_cvm7
#ifndef CONF_PWM_1_CVM7
#define CONF_PWM_1_CVM7 0
#endif

// <o> Comparison 7 Trigger <0-15>
// <i> This defines comparison trigger.
// <id> pwm_ctr7
#ifndef CONF_PWM_1_CTR7
#define CONF_PWM_1_CTR7 0
#endif

// <o> Comparison 7 Period <0-15>
// <i> This defines the maximum value of the comparison 7 period counter.
// <id> pwm_cpr7
#ifndef CONF_PWM_1_CPR7
#define CONF_PWM_1_CPR7 0
#endif

// <o> Comparison 7 Update Period <0-15>
// <i> This defines the time between each update of the comparison x mode and the comparison 7 value.
// <id> pwm_cupr7
#ifndef CONF_PWM_1_CUPR7
#define CONF_PWM_1_CUPR7 0
#endif

// </e>

// </h>

// <h> Fault Configuration

// <e> Fault 0 Configuration
// <i> This defines fault 0 configuration enable
// <id> pwm_fault0_enable
#ifndef CONF_PWM_1_FAULT0_ENABLE
#define CONF_PWM_1_FAULT0_ENABLE 0
#endif

// <q> Fault 0 Polarity
// <i> If true, the fault 0 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault0
#ifndef CONF_PWM_1_FMR_FPOL_FAULT0
#define CONF_PWM_1_FMR_FPOL_FAULT0 1
#endif

// <q> Fault 0 Filtering
// <i> If true, the fault 0 is filtered.
// <id> pwm_fmr_ffil_fault0
#ifndef CONF_PWM_1_FMR_FFIL_FAULT0
#define CONF_PWM_1_FMR_FFIL_FAULT0 0
#endif

// <o> Fault 0 Activation Mode
// <0x0=> The fault 0 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 0 activation mode.
// <id> pwm_fmr_fmod_fault0
#ifndef CONF_PWM_1_FMR_FMOD_FAULT0
#define CONF_PWM_1_FMR_FMOD_FAULT0 0
#endif

// </e>

// <e> Fault 1 Configuration
// <i> This defines fault 1 configuration enable
// <id> pwm_fault1_enable
#ifndef CONF_PWM_1_FAULT1_ENABLE
#define CONF_PWM_1_FAULT1_ENABLE 0
#endif

// <q> Fault 1 Polarity
// <i> If true, the fault 1 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault1
#ifndef CONF_PWM_1_FMR_FPOL_FAULT1
#define CONF_PWM_1_FMR_FPOL_FAULT1 1
#endif

// <q> Fault 1 Filtering
// <i> If true, the fault 1 is filtered.
// <id> pwm_fmr_ffil_fault1
#ifndef CONF_PWM_1_FMR_FFIL_FAULT1
#define CONF_PWM_1_FMR_FFIL_FAULT1 0
#endif

// <o> Fault 1 Activation Mode
// <0x0=> The fault 1 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 1 activation mode.
// <id> pwm_fmr_fmod_fault1
#ifndef CONF_PWM_1_FMR_FMOD_FAULT1
#define CONF_PWM_1_FMR_FMOD_FAULT1 0
#endif

// </e>

// <e> Fault 2 Configuration
// <i> This defines fault 2 configuration enable
// <id> pwm_fault2_enable
#ifndef CONF_PWM_1_FAULT2_ENABLE
#define CONF_PWM_1_FAULT2_ENABLE 0
#endif

// <q> Fault 2 Polarity
// <i> If true, the fault 2 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault2
#ifndef CONF_PWM_1_FMR_FPOL_FAULT2
#define CONF_PWM_1_FMR_FPOL_FAULT2 1
#endif

// <q> Fault 2 Filtering
// <i> If true, the fault 2 is filtered.
// <id> pwm_fmr_ffil_fault2
#ifndef CONF_PWM_1_FMR_FFIL_FAULT2
#define CONF_PWM_1_FMR_FFIL_FAULT2 0
#endif

// <o> Fault 2 Activation Mode
// <0x0=> The fault 2 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 2 activation mode.
// <id> pwm_fmr_fmod_fault2
#ifndef CONF_PWM_1_FMR_FMOD_FAULT2
#define CONF_PWM_1_FMR_FMOD_FAULT2 0
#endif

// </e>

// <e> Fault 3 Configuration
// <i> This defines fault 3 configuration enable
// <id> pwm_fault3_enable
#ifndef CONF_PWM_1_FAULT3_ENABLE
#define CONF_PWM_1_FAULT3_ENABLE 0
#endif

// <q> Fault 3 Polarity
// <i> If true, the fault 3 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault3
#ifndef CONF_PWM_1_FMR_FPOL_FAULT3
#define CONF_PWM_1_FMR_FPOL_FAULT3 1
#endif

// <q> Fault 3 Filtering
// <i> If true, the fault 3 is filtered.
// <id> pwm_fmr_ffil_fault3
#ifndef CONF_PWM_1_FMR_FFIL_FAULT3
#define CONF_PWM_1_FMR_FFIL_FAULT3 0
#endif

// <o> Fault 3 Activation Mode
// <0x0=> The fault 3 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 3 activation mode.
// <id> pwm_fmr_fmod_fault3
#ifndef CONF_PWM_1_FMR_FMOD_FAULT3
#define CONF_PWM_1_FMR_FMOD_FAULT3 0
#endif

// </e>

// <e> Fault 4 Configuration
// <i> This defines fault 4 configuration enable
// <id> pwm_fault4_enable
#ifndef CONF_PWM_1_FAULT4_ENABLE
#define CONF_PWM_1_FAULT4_ENABLE 0
#endif

// <q> Fault 4 Polarity
// <i> If true, the fault 4 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault4
#ifndef CONF_PWM_1_FMR_FPOL_FAULT4
#define CONF_PWM_1_FMR_FPOL_FAULT4 1
#endif

// <q> Fault 4 Filtering
// <i> If true, the fault 4 is filtered.
// <id> pwm_fmr_ffil_fault4
#ifndef CONF_PWM_1_FMR_FFIL_FAULT4
#define CONF_PWM_1_FMR_FFIL_FAULT4 0
#endif

// <o> Fault 4 Activation Mode
// <0x0=> The fault 4 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 4 activation mode.
// <id> pwm_fmr_fmod_fault4
#ifndef CONF_PWM_1_FMR_FMOD_FAULT4
#define CONF_PWM_1_FMR_FMOD_FAULT4 0
#endif

// </e>

// <e> Fault 5 Configuration
// <i> This defines fault 5 configuration enable
// <id> pwm_fault5_enable
#ifndef CONF_PWM_1_FAULT5_ENABLE
#define CONF_PWM_1_FAULT5_ENABLE 0
#endif

// <q> Fault 5 Polarity
// <i> If true, the fault 5 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault5
#ifndef CONF_PWM_1_FMR_FPOL_FAULT5
#define CONF_PWM_1_FMR_FPOL_FAULT5 1
#endif

// <q> Fault 5 Filtering
// <i> If true, the fault 5 is filtered.
// <id> pwm_fmr_ffil_fault5
#ifndef CONF_PWM_1_FMR_FFIL_FAULT5
#define CONF_PWM_1_FMR_FFIL_FAULT5 0
#endif

// <o> Fault 5 Activation Mode
// <0x0=> The fault 5 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 5 activation mode.
// <id> pwm_fmr_fmod_fault5
#ifndef CONF_PWM_1_FMR_FMOD_FAULT5
#define CONF_PWM_1_FMR_FMOD_FAULT5 0
#endif

// </e>

// <e> Fault 6 Configuration
// <i> This defines fault 6 configuration enable
// <id> pwm_fault6_enable
#ifndef CONF_PWM_1_FAULT6_ENABLE
#define CONF_PWM_1_FAULT6_ENABLE 0
#endif

// <q> Fault 6 Polarity
// <i> If true, the fault 6 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault6
#ifndef CONF_PWM_1_FMR_FPOL_FAULT6
#define CONF_PWM_1_FMR_FPOL_FAULT6 1
#endif

// <q> Fault 6 Filtering
// <i> If true, the fault 6 is filtered.
// <id> pwm_fmr_ffil_fault6
#ifndef CONF_PWM_1_FMR_FFIL_FAULT6
#define CONF_PWM_1_FMR_FFIL_FAULT6 0
#endif

// <o> Fault 6 Activation Mode
// <0x0=> The fault 6 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 6 activation mode.
// <id> pwm_fmr_fmod_fault6
#ifndef CONF_PWM_1_FMR_FMOD_FAULT6
#define CONF_PWM_1_FMR_FMOD_FAULT6 0
#endif

// </e>

// <e> Fault 7 Configuration
// <i> This defines fault 7 configuration enable
// <id> pwm_fault7_enable
#ifndef CONF_PWM_1_FAULT7_ENABLE
#define CONF_PWM_1_FAULT7_ENABLE 0
#endif

// <q> Fault 7 Polarity
// <i> If true, the fault 7 becomes actrive when the fault is at 1. Else the fault is at 0.
// <id> pwm_fmr_fpol_fault7
#ifndef CONF_PWM_1_FMR_FPOL_FAULT7
#define CONF_PWM_1_FMR_FPOL_FAULT7 1
#endif

// <q> Fault 7 Filtering
// <i> If true, the fault 7 is filtered.
// <id> pwm_fmr_ffil_fault7
#ifndef CONF_PWM_1_FMR_FFIL_FAULT7
#define CONF_PWM_1_FMR_FFIL_FAULT7 0
#endif

// <o> Fault 7 Activation Mode
// <0x0=> The fault 7 is active until the fault condition is removed at the peripheral level.
// <0x1=> The fault y stays active until the fault condition is removed at the peripheral level and until it is cleared in the PWM Fault Clear Register.
// <i> This defines fault 7 activation mode.
// <id> pwm_fmr_fmod_fault7
#ifndef CONF_PWM_1_FMR_FMOD_FAULT7
#define CONF_PWM_1_FMR_FMOD_FAULT7 0
#endif

// </e>

// <e> Fault Configuration for Channel 0
// <id> pwm_channel0_fault_config
#ifndef CONF_PWM_1_CHANNEL0_FAULT_CONFIG
#define CONF_PWM_1_CHANNEL0_FAULT_CONFIG 0
#endif

// <q> Fault 0 Protection Enable for channel 0
// <i> This defines fault 0 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault0_enable
#ifndef CONF_PWM_1_FPE0_FAULT0_ENABLE
#define CONF_PWM_1_FPE0_FAULT0_ENABLE 0
#endif

// <q> Fault 1 Protection Enable for channel 0
// <i> This defines fault 1 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault1_enable
#ifndef CONF_PWM_1_FPE0_FAULT1_ENABLE
#define CONF_PWM_1_FPE0_FAULT1_ENABLE 0
#endif

// <q> Fault 2 Protection Enable for channel 0
// <i> This defines fault 2 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault2_enable
#ifndef CONF_PWM_1_FPE0_FAULT2_ENABLE
#define CONF_PWM_1_FPE0_FAULT2_ENABLE 0
#endif

// <q> Fault 3 Protection Enable for channel 0
// <i> This defines fault 3 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault3_enable
#ifndef CONF_PWM_1_FPE0_FAULT3_ENABLE
#define CONF_PWM_1_FPE0_FAULT3_ENABLE 0
#endif

// <q> Fault 4 Protection Enable for channel 0
// <i> This defines fault 4 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault4_enable
#ifndef CONF_PWM_1_FPE0_FAULT4_ENABLE
#define CONF_PWM_1_FPE0_FAULT4_ENABLE 0
#endif

// <q> Fault 5 Protection Enable for channel 0
// <i> This defines fault 5 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault5_enable
#ifndef CONF_PWM_1_FPE0_FAULT5_ENABLE
#define CONF_PWM_1_FPE0_FAULT5_ENABLE 0
#endif

// <q> Fault 6 Protection Enable for channel 0
// <i> This defines fault 6 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault6_enable
#ifndef CONF_PWM_1_FPE0_FAULT6_ENABLE
#define CONF_PWM_1_FPE0_FAULT6_ENABLE 0
#endif

// <q> Fault 7 Protection Enable for channel 0
// <i> This defines fault 7 protection enable for channel 0
// <id> pwm_fpe_fpe0_fault7_enable
#ifndef CONF_PWM_1_FPE0_FAULT7_ENABLE
#define CONF_PWM_1_FPE0_FAULT7_ENABLE 0
#endif

// <o> Fault Protection Value for PWMH output on channel0
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWMH output on channel 0 when fault occurs.
// <id> pwm_fpv1_fpvh0
#ifndef CONF_PWM_1_FPV1_FPVH0
#define CONF_PWM_1_FPV1_FPVH0 2
#endif

// <o> Fault Protection Value for PWML output on channel0
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWML output on channel 0 when fault occurs.
// <id> pwm_fpv1_fpvl0
#ifndef CONF_PWM_1_FPV1_FPVL0
#define CONF_PWM_1_FPV1_FPVL0 2
#endif
// </e>

// <e> Fault Configuration for Channel 1
// <id> pwm_channel1_fault_config
#ifndef CONF_PWM_1_CHANNEL1_FAULT_CONFIG
#define CONF_PWM_1_CHANNEL1_FAULT_CONFIG 0
#endif

// <q> Fault 0 Protection Enable for channel 1
// <i> This defines fault 0 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault0_enable
#ifndef CONF_PWM_1_FPE1_FAULT0_ENABLE
#define CONF_PWM_1_FPE1_FAULT0_ENABLE 0
#endif

// <q> Fault 1 Protection Enable for channel 1
// <i> This defines fault 1 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault1_enable
#ifndef CONF_PWM_1_FPE1_FAULT1_ENABLE
#define CONF_PWM_1_FPE1_FAULT1_ENABLE 0
#endif

// <q> Fault 2 Protection Enable for channel 1
// <i> This defines fault 2 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault2_enable
#ifndef CONF_PWM_1_FPE1_FAULT2_ENABLE
#define CONF_PWM_1_FPE1_FAULT2_ENABLE 0
#endif

// <q> Fault 3 Protection Enable for channel 1
// <i> This defines fault 3 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault3_enable
#ifndef CONF_PWM_1_FPE1_FAULT3_ENABLE
#define CONF_PWM_1_FPE1_FAULT3_ENABLE 0
#endif

// <q> Fault 4 Protection Enable for channel 1
// <i> This defines fault 4 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault4_enable
#ifndef CONF_PWM_1_FPE1_FAULT4_ENABLE
#define CONF_PWM_1_FPE1_FAULT4_ENABLE 0
#endif

// <q> Fault 5 Protection Enable for channel 1
// <i> This defines fault 5 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault5_enable
#ifndef CONF_PWM_1_FPE1_FAULT5_ENABLE
#define CONF_PWM_1_FPE1_FAULT5_ENABLE 0
#endif

// <q> Fault 6 Protection Enable for channel 1
// <i> This defines fault 6 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault6_enable
#ifndef CONF_PWM_1_FPE1_FAULT6_ENABLE
#define CONF_PWM_1_FPE1_FAULT6_ENABLE 0
#endif

// <q> Fault 7 Protection Enable for channel 1
// <i> This defines fault 7 protection enable for channel 1
// <id> pwm_fpe_fpe1_fault7_enable
#ifndef CONF_PWM_1_FPE1_FAULT7_ENABLE
#define CONF_PWM_1_FPE1_FAULT7_ENABLE 0
#endif

// <o> Fault Protection Value for PWMH output on channel1
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWMH output on channel 1 when fault occurs.
// <id> pwm_fpv1_fpvh1
#ifndef CONF_PWM_1_FPV1_FPVH1
#define CONF_PWM_1_FPV1_FPVH1 2
#endif

// <o> Fault Protection Value for PWML output on channel1
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWML output on channel 1 when fault occurs.
// <id> pwm_fpv1_fpvl1
#ifndef CONF_PWM_1_FPV1_FPVL1
#define CONF_PWM_1_FPV1_FPVL1 2
#endif
// </e>

// <e> Fault Configuration for Channel 2
// <id> pwm_channel2_fault_config
#ifndef CONF_PWM_1_CHANNEL2_FAULT_CONFIG
#define CONF_PWM_1_CHANNEL2_FAULT_CONFIG 0
#endif

// <q> Fault 0 Protection Enable for channel 2
// <i> This defines fault 0 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault0_enable
#ifndef CONF_PWM_1_FPE2_FAULT0_ENABLE
#define CONF_PWM_1_FPE2_FAULT0_ENABLE 0
#endif

// <q> Fault 1 Protection Enable for channel 2
// <i> This defines fault 1 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault1_enable
#ifndef CONF_PWM_1_FPE2_FAULT1_ENABLE
#define CONF_PWM_1_FPE2_FAULT1_ENABLE 0
#endif

// <q> Fault 2 Protection Enable for channel 2
// <i> This defines fault 2 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault2_enable
#ifndef CONF_PWM_1_FPE2_FAULT2_ENABLE
#define CONF_PWM_1_FPE2_FAULT2_ENABLE 0
#endif

// <q> Fault 3 Protection Enable for channel 2
// <i> This defines fault 3 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault3_enable
#ifndef CONF_PWM_1_FPE2_FAULT3_ENABLE
#define CONF_PWM_1_FPE2_FAULT3_ENABLE 0
#endif

// <q> Fault 4 Protection Enable for channel 2
// <i> This defines fault 4 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault4_enable
#ifndef CONF_PWM_1_FPE2_FAULT4_ENABLE
#define CONF_PWM_1_FPE2_FAULT4_ENABLE 0
#endif

// <q> Fault 5 Protection Enable for channel 2
// <i> This defines fault 5 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault5_enable
#ifndef CONF_PWM_1_FPE2_FAULT5_ENABLE
#define CONF_PWM_1_FPE2_FAULT5_ENABLE 0
#endif

// <q> Fault 6 Protection Enable for channel 2
// <i> This defines fault 6 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault6_enable
#ifndef CONF_PWM_1_FPE2_FAULT6_ENABLE
#define CONF_PWM_1_FPE2_FAULT6_ENABLE 0
#endif

// <q> Fault 7 Protection Enable for channel 2
// <i> This defines fault 7 protection enable for channel 2
// <id> pwm_fpe_fpe2_fault7_enable
#ifndef CONF_PWM_1_FPE2_FAULT7_ENABLE
#define CONF_PWM_1_FPE2_FAULT7_ENABLE 0
#endif

// <o> Fault Protection Value for PWMH output on channel2
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWMH output on channel 2 when fault occurs.
// <id> pwm_fpv1_fpvh2
#ifndef CONF_PWM_1_FPV1_FPVH2
#define CONF_PWM_1_FPV1_FPVH2 2
#endif

// <o> Fault Protection Value for PWML output on channel2
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWML output on channel 2 when fault occurs.
// <id> pwm_fpv1_fpvl2
#ifndef CONF_PWM_1_FPV1_FPVL2
#define CONF_PWM_1_FPV1_FPVL2 2
#endif
// </e>

// <e> Fault Configuration for Channel 3
// <id> pwm_channel3_fault_config
#ifndef CONF_PWM_1_CHANNEL3_FAULT_CONFIG
#define CONF_PWM_1_CHANNEL3_FAULT_CONFIG 0
#endif

// <q> Fault 0 Protection Enable for channel 3
// <i> This defines fault 0 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault0_enable
#ifndef CONF_PWM_1_FPE3_FAULT0_ENABLE
#define CONF_PWM_1_FPE3_FAULT0_ENABLE 0
#endif

// <q> Fault 1 Protection Enable for channel 3
// <i> This defines fault 1 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault1_enable
#ifndef CONF_PWM_1_FPE3_FAULT1_ENABLE
#define CONF_PWM_1_FPE3_FAULT1_ENABLE 0
#endif

// <q> Fault 2 Protection Enable for channel 3
// <i> This defines fault 2 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault2_enable
#ifndef CONF_PWM_1_FPE3_FAULT2_ENABLE
#define CONF_PWM_1_FPE3_FAULT2_ENABLE 0
#endif

// <q> Fault 3 Protection Enable for channel 3
// <i> This defines fault 3 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault3_enable
#ifndef CONF_PWM_1_FPE3_FAULT3_ENABLE
#define CONF_PWM_1_FPE3_FAULT3_ENABLE 0
#endif

// <q> Fault 4 Protection Enable for channel 3
// <i> This defines fault 4 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault4_enable
#ifndef CONF_PWM_1_FPE3_FAULT4_ENABLE
#define CONF_PWM_1_FPE3_FAULT4_ENABLE 0
#endif

// <q> Fault 5 Protection Enable for channel 3
// <i> This defines fault 5 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault5_enable
#ifndef CONF_PWM_1_FPE3_FAULT5_ENABLE
#define CONF_PWM_1_FPE3_FAULT5_ENABLE 0
#endif

// <q> Fault 6 Protection Enable for channel 3
// <i> This defines fault 6 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault6_enable
#ifndef CONF_PWM_1_FPE3_FAULT6_ENABLE
#define CONF_PWM_1_FPE3_FAULT6_ENABLE 0
#endif

// <q> Fault 7 Protection Enable for channel 3
// <i> This defines fault 7 protection enable for channel 3
// <id> pwm_fpe_fpe3_fault7_enable
#ifndef CONF_PWM_1_FPE3_FAULT7_ENABLE
#define CONF_PWM_1_FPE3_FAULT7_ENABLE 0
#endif

// <o> Fault Protection Value for PWMH output on channel3
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWMH output on channel 3 when fault occurs.
// <id> pwm_fpv1_fpvh3
#ifndef CONF_PWM_1_FPV1_FPVH3
#define CONF_PWM_1_FPV1_FPVH3 2
#endif

// <o> Fault Protection Value for PWML output on channel3
// <0x0=> Be forced to 0
// <0x1=> Be forced to 1
// <0x2=> Be is forced to high-impedance state
// <i> This defines fault fault protection value for PWML output on channel 3 when fault occurs.
// <id> pwm_fpv1_fpvl3
#ifndef CONF_PWM_1_FPV1_FPVL3
#define CONF_PWM_1_FPV1_FPVL3 2
#endif
// </e>

// </h>

/** Amount of Channel. */
#define CONF_PWM_1_CH_NUM                                                                                              \
	(CONF_PWM_1_CHANNEL0_ENABLE + CONF_PWM_1_CHANNEL1_ENABLE + CONF_PWM_1_CHANNEL2_ENABLE + CONF_PWM_1_CHANNEL3_ENABLE)

/** Amount of Comparison. */
#define CONF_PWM_1_COMP_NUM                                                                                            \
	(0 + CONF_PWM_1_COMP_ENABLE0 + CONF_PWM_1_COMP_ENABLE1 + CONF_PWM_1_COMP_ENABLE2 + CONF_PWM_1_COMP_ENABLE3         \
	 + CONF_PWM_1_COMP_ENABLE4 + CONF_PWM_1_COMP_ENABLE5 + CONF_PWM_1_COMP_ENABLE6 + CONF_PWM_1_COMP_ENABLE7)

/** Amount of Trigger. */
#define CONF_PWM_1_TRIGGER_NUM (CONF_PWM_1_CHANNEL1_TRIGGER_ENABLE + CONF_PWM_1_CHANNEL2_TRIGGER_ENABLE)

#ifndef CONF_PWM_1_FPV1_REGVAL
#define CONF_PWM_1_FPV1_REGVAL                                                                                         \
	(((CONF_PWM_1_FPV1_FPVH0 == 0x02) ? 0 : (CONF_PWM_1_FPV1_FPVH0 << PWM_FPV1_FPVH0_Pos))                             \
	 | ((CONF_PWM_1_FPV1_FPVL0 == 0x02) ? 0 : (CONF_PWM_1_FPV1_FPVH0 << PWM_FPV1_FPVL0_Pos))                           \
	 | ((CONF_PWM_1_FPV1_FPVH1 == 0x02) ? 0 : (CONF_PWM_1_FPV1_FPVH1 << PWM_FPV1_FPVH1_Pos))                           \
	 | ((CONF_PWM_1_FPV1_FPVL1 == 0x02) ? 0 : (CONF_PWM_1_FPV1_FPVH1 << PWM_FPV1_FPVL1_Pos))                           \
	 | ((CONF_PWM_1_FPV1_FPVH2 == 0x02) ? 0 : (CONF_PWM_1_FPV1_FPVH2 << PWM_FPV1_FPVH2_Pos))                           \
	 | ((CONF_PWM_1_FPV1_FPVL2 == 0x02) ? 0 : (CONF_PWM_1_FPV1_FPVH2 << PWM_FPV1_FPVL2_Pos))                           \
	 | ((CONF_PWM_1_FPV1_FPVH3 == 0x02) ? 0 : (CONF_PWM_1_FPV1_FPVH3 << PWM_FPV1_FPVH3_Pos))                           \
	 | ((CONF_PWM_1_FPV1_FPVL3 == 0x02) ? 0 : (CONF_PWM_1_FPV1_FPVH3 << PWM_FPV1_FPVL3_Pos)) | 0)
#endif

#ifndef CONF_PWM_1_FPV2_REGVAL
#define CONF_PWM_1_FPV2_REGVAL                                                                                         \
	(((CONF_PWM_1_FPV1_FPVH0 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                        \
	 | ((CONF_PWM_1_FPV1_FPVL0 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_1_FPV1_FPVH1 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_1_FPV1_FPVL1 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_1_FPV1_FPVH2 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_1_FPV1_FPVL2 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_1_FPV1_FPVH3 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0)                                                      \
	 | ((CONF_PWM_1_FPV1_FPVL3 == 0x02) ? PWM_FPV2_FPZH2_Msk : 0) | 0)
#endif

#ifndef CONF_PWM_1_FPE_REGVAL
#define CONF_PWM_1_FPE_REGVAL                                                                                          \
	((CONF_PWM_1_FPE0_FAULT0_ENABLE << (PWM_FPE_FPE0_Pos + 0))                                                         \
	 | (CONF_PWM_1_FPE0_FAULT1_ENABLE << (PWM_FPE_FPE0_Pos + 1))                                                       \
	 | (CONF_PWM_1_FPE0_FAULT2_ENABLE << (PWM_FPE_FPE0_Pos + 2))                                                       \
	 | (CONF_PWM_1_FPE0_FAULT3_ENABLE << (PWM_FPE_FPE0_Pos + 3))                                                       \
	 | (CONF_PWM_1_FPE0_FAULT4_ENABLE << (PWM_FPE_FPE0_Pos + 4))                                                       \
	 | (CONF_PWM_1_FPE0_FAULT5_ENABLE << (PWM_FPE_FPE0_Pos + 5))                                                       \
	 | (CONF_PWM_1_FPE0_FAULT6_ENABLE << (PWM_FPE_FPE0_Pos + 6))                                                       \
	 | (CONF_PWM_1_FPE0_FAULT7_ENABLE << (PWM_FPE_FPE0_Pos + 7))                                                       \
	 | (CONF_PWM_1_FPE1_FAULT0_ENABLE << (PWM_FPE_FPE1_Pos + 0))                                                       \
	 | (CONF_PWM_1_FPE1_FAULT1_ENABLE << (PWM_FPE_FPE1_Pos + 1))                                                       \
	 | (CONF_PWM_1_FPE1_FAULT2_ENABLE << (PWM_FPE_FPE1_Pos + 2))                                                       \
	 | (CONF_PWM_1_FPE1_FAULT3_ENABLE << (PWM_FPE_FPE1_Pos + 3))                                                       \
	 | (CONF_PWM_1_FPE1_FAULT4_ENABLE << (PWM_FPE_FPE1_Pos + 4))                                                       \
	 | (CONF_PWM_1_FPE1_FAULT5_ENABLE << (PWM_FPE_FPE1_Pos + 5))                                                       \
	 | (CONF_PWM_1_FPE1_FAULT6_ENABLE << (PWM_FPE_FPE1_Pos + 6))                                                       \
	 | (CONF_PWM_1_FPE1_FAULT7_ENABLE << (PWM_FPE_FPE1_Pos + 7))                                                       \
	 | (CONF_PWM_1_FPE2_FAULT0_ENABLE << (PWM_FPE_FPE2_Pos + 0))                                                       \
	 | (CONF_PWM_1_FPE2_FAULT1_ENABLE << (PWM_FPE_FPE2_Pos + 1))                                                       \
	 | (CONF_PWM_1_FPE2_FAULT2_ENABLE << (PWM_FPE_FPE2_Pos + 2))                                                       \
	 | (CONF_PWM_1_FPE2_FAULT3_ENABLE << (PWM_FPE_FPE2_Pos + 3))                                                       \
	 | (CONF_PWM_1_FPE2_FAULT4_ENABLE << (PWM_FPE_FPE2_Pos + 4))                                                       \
	 | (CONF_PWM_1_FPE2_FAULT5_ENABLE << (PWM_FPE_FPE2_Pos + 5))                                                       \
	 | (CONF_PWM_1_FPE2_FAULT6_ENABLE << (PWM_FPE_FPE2_Pos + 6))                                                       \
	 | (CONF_PWM_1_FPE2_FAULT7_ENABLE << (PWM_FPE_FPE2_Pos + 7))                                                       \
	 | (CONF_PWM_1_FPE3_FAULT0_ENABLE << (PWM_FPE_FPE3_Pos + 0))                                                       \
	 | (CONF_PWM_1_FPE3_FAULT1_ENABLE << (PWM_FPE_FPE3_Pos + 1))                                                       \
	 | (CONF_PWM_1_FPE3_FAULT2_ENABLE << (PWM_FPE_FPE3_Pos + 2))                                                       \
	 | (CONF_PWM_1_FPE3_FAULT3_ENABLE << (PWM_FPE_FPE3_Pos + 3))                                                       \
	 | (CONF_PWM_1_FPE3_FAULT4_ENABLE << (PWM_FPE_FPE3_Pos + 4))                                                       \
	 | (CONF_PWM_1_FPE3_FAULT5_ENABLE << (PWM_FPE_FPE3_Pos + 5))                                                       \
	 | (CONF_PWM_1_FPE3_FAULT6_ENABLE << (PWM_FPE_FPE3_Pos + 6))                                                       \
	 | (CONF_PWM_1_FPE3_FAULT7_ENABLE << (PWM_FPE_FPE3_Pos + 7)) | 0)
#endif

#ifndef CONF_PWM_1_ELMR0_REGVAL
#define CONF_PWM_1_ELMR0_REGVAL                                                                                        \
	((CONF_PWM_1_ELMR0_CSEL0 < PWM_ELMR_CSEL0_Pos) | (CONF_PWM_1_ELMR0_CSEL1 < PWM_ELMR_CSEL1_Pos)                     \
	 | (CONF_PWM_1_ELMR0_CSEL2 < PWM_ELMR_CSEL2_Pos) | (CONF_PWM_1_ELMR0_CSEL3 < PWM_ELMR_CSEL3_Pos)                   \
	 | (CONF_PWM_1_ELMR0_CSEL4 < PWM_ELMR_CSEL4_Pos) | (CONF_PWM_1_ELMR0_CSEL5 < PWM_ELMR_CSEL5_Pos)                   \
	 | (CONF_PWM_1_ELMR0_CSEL6 < PWM_ELMR_CSEL6_Pos) | (CONF_PWM_1_ELMR0_CSEL7 < PWM_ELMR_CSEL7_Pos) | 0)
#endif

#ifndef CONF_PWM_1_ELMR1_REGVAL
#define CONF_PWM_1_ELMR1_REGVAL                                                                                        \
	((CONF_PWM_1_ELMR1_CSEL0 < PWM_ELMR_CSEL0_Pos) | (CONF_PWM_1_ELMR1_CSEL1 < PWM_ELMR_CSEL1_Pos)                     \
	 | (CONF_PWM_1_ELMR1_CSEL2 < PWM_ELMR_CSEL2_Pos) | (CONF_PWM_1_ELMR1_CSEL3 < PWM_ELMR_CSEL3_Pos)                   \
	 | (CONF_PWM_1_ELMR1_CSEL4 < PWM_ELMR_CSEL4_Pos) | (CONF_PWM_1_ELMR1_CSEL5 < PWM_ELMR_CSEL5_Pos)                   \
	 | (CONF_PWM_1_ELMR1_CSEL6 < PWM_ELMR_CSEL6_Pos) | (CONF_PWM_1_ELMR1_CSEL7 < PWM_ELMR_CSEL7_Pos) | 0)
#endif

#ifndef CONF_PWM_1_FMR_REGVAL
#define CONF_PWM_1_FMR_REGVAL                                                                                          \
	((CONF_PWM_1_FMR_FPOL_FAULT0 << (PWM_FMR_FPOL_Pos + 0)) | (CONF_PWM_1_FMR_FFIL_FAULT0 << (PWM_FMR_FFIL_Pos + 0))   \
	 | (CONF_PWM_1_FMR_FMOD_FAULT0 << (PWM_FMR_FMOD_Pos + 0)) | (CONF_PWM_1_FMR_FPOL_FAULT1 << (PWM_FMR_FPOL_Pos + 1)) \
	 | (CONF_PWM_1_FMR_FFIL_FAULT1 << (PWM_FMR_FFIL_Pos + 1)) | (CONF_PWM_1_FMR_FMOD_FAULT1 << (PWM_FMR_FMOD_Pos + 1)) \
	 | (CONF_PWM_1_FMR_FPOL_FAULT2 << (PWM_FMR_FPOL_Pos + 2)) | (CONF_PWM_1_FMR_FFIL_FAULT2 << (PWM_FMR_FFIL_Pos + 2)) \
	 | (CONF_PWM_1_FMR_FMOD_FAULT2 << (PWM_FMR_FMOD_Pos + 2)) | (CONF_PWM_1_FMR_FPOL_FAULT3 << (PWM_FMR_FPOL_Pos + 3)) \
	 | (CONF_PWM_1_FMR_FFIL_FAULT3 << (PWM_FMR_FFIL_Pos + 3)) | (CONF_PWM_1_FMR_FMOD_FAULT3 << (PWM_FMR_FMOD_Pos + 3)) \
	 | (CONF_PWM_1_FMR_FPOL_FAULT4 << (PWM_FMR_FPOL_Pos + 4)) | (CONF_PWM_1_FMR_FFIL_FAULT4 << (PWM_FMR_FFIL_Pos + 4)) \
	 | (CONF_PWM_1_FMR_FMOD_FAULT4 << (PWM_FMR_FMOD_Pos + 4)) | (CONF_PWM_1_FMR_FPOL_FAULT5 << (PWM_FMR_FPOL_Pos + 5)) \
	 | (CONF_PWM_1_FMR_FFIL_FAULT5 << (PWM_FMR_FFIL_Pos + 5)) | (CONF_PWM_1_FMR_FMOD_FAULT5 << (PWM_FMR_FMOD_Pos + 5)) \
	 | (CONF_PWM_1_FMR_FPOL_FAULT6 << (PWM_FMR_FPOL_Pos + 6)) | (CONF_PWM_1_FMR_FFIL_FAULT6 << (PWM_FMR_FFIL_Pos + 6)) \
	 | (CONF_PWM_1_FMR_FMOD_FAULT6 << (PWM_FMR_FMOD_Pos + 6)) | (CONF_PWM_1_FMR_FPOL_FAULT7 << (PWM_FMR_FPOL_Pos + 7)) \
	 | (CONF_PWM_1_FMR_FFIL_FAULT7 << (PWM_FMR_FFIL_Pos + 7)) | (CONF_PWM_1_FMR_FMOD_FAULT7 << (PWM_FMR_FMOD_Pos + 7)) \
	 | 0)
#endif

#ifndef CONF_PWM_1_ETRG1_REGVAL
#define CONF_PWM_1_ETRG1_REGVAL                                                                                        \
	(PWM_ETRG1_TRGMODE(CONF_PWM_1_CHANNEL1_TRGMODE) | (CONF_PWM_1_CHANNEL1_TRGEDGE << PWM_ETRG1_TRGEDGE_Pos)           \
	 | (CONF_PWM_1_CHANNEL1_TRGFILT << PWM_ETRG1_TRGFILT_Pos) | (CONF_PWM_1_CHANNEL1_TRGSRC << PWM_ETRG1_TRGSRC_Pos)   \
	 | (CONF_PWM_1_CHANNEL1_RFEN << PWM_ETRG1_RFEN_Pos))
#endif

#ifndef CONF_PWM_1_ETRG2_REGVAL
#define CONF_PWM_1_ETRG2_REGVAL                                                                                        \
	(PWM_ETRG2_TRGMODE(CONF_PWM_1_CHANNEL2_TRGMODE) | (CONF_PWM_1_CHANNEL2_TRGEDGE << PWM_ETRG2_TRGEDGE_Pos)           \
	 | (CONF_PWM_1_CHANNEL2_TRGFILT << PWM_ETRG2_TRGFILT_Pos) | (CONF_PWM_1_CHANNEL2_TRGSRC << PWM_ETRG2_TRGSRC_Pos)   \
	 | (CONF_PWM_1_CHANNEL2_RFEN << PWM_ETRG2_RFEN_Pos))
#endif

// <<< end of configuration section >>>

#endif // HPL_PWM_CONFIG_H
