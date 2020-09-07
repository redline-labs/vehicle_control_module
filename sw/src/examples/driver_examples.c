/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

static uint8_t aes_plain_text[16]
    = {0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a};
static uint8_t aes_key[16]
    = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
static uint8_t aes_cipher_text[16]
    = {0x3a, 0xd7, 0x7b, 0xb4, 0x0d, 0x7a, 0x36, 0x60, 0xa8, 0x9e, 0xca, 0xf3, 0x24, 0x66, 0xef, 0x97};
uint8_t aes_output[16] = {0x00};
/**
 * Example of using CRYPTOGRAPHY_0 to Encrypt/Decrypt datas.
 */
void CRYPTOGRAPHY_0_example(void)
{
	int32_t i;
	aes_sync_enable(&CRYPTOGRAPHY_0);
	aes_sync_set_encrypt_key(&CRYPTOGRAPHY_0, aes_key, AES_KEY_128);
	aes_sync_ecb_crypt(&CRYPTOGRAPHY_0, AES_ENCRYPT, aes_plain_text, aes_output);
	for (i = 0; i < 16; i++) {
		while (aes_output[i] != aes_cipher_text[i])
			;
	}
}

/**
 * Example of using ADC_0 to generate waveform.
 */
void ADC_0_example(void)
{

	while (1) {
	}
}

/**
 * Example of using ADC_1 to generate waveform.
 */
void ADC_1_example(void)
{

	while (1) {
	}
}

static void button_on_PA0_pressed(void)
{
}

/**
 * Example of using EXTERNAL_IRQ_0
 */
void EXTERNAL_IRQ_0_example(void)
{
	ext_irq_register(PIO_PA0_IDX, button_on_PA0_pressed);
}

static void period_cb_PWM_0(const struct pwm_descriptor *const descr)
{
	/* period interrupt */
}
/**
 * Example of using PWM_0.
 */
void PWM_0_example(void)
{
	pwm_register_callback(&PWM_0, PWM_PERIOD_CB, period_cb_PWM_0);
	pwm_enable(&PWM_0);
}

static void period_cb_PWM_1(const struct pwm_descriptor *const descr)
{
	/* period interrupt */
}
/**
 * Example of using PWM_1.
 */
void PWM_1_example(void)
{
	pwm_register_callback(&PWM_1, PWM_PERIOD_CB, period_cb_PWM_1);
	pwm_enable(&PWM_1);
}

/**
 * Example of using QUAD_SPI_0 to get S25FL1XX status1 value,
 * and check bit 0 which indicate embedded operation is busy or not.
 */
void QUAD_SPI_0_example(void)
{
	uint8_t              status = 0xFF;
	struct _qspi_command cmd    = {
        .inst_frame.bits.inst_en  = 1,
        .inst_frame.bits.data_en  = 1,
        .inst_frame.bits.tfr_type = QSPI_READ_ACCESS,
        .instruction              = 0x05,
        .buf_len                  = 1,
        .rx_buf                   = &status,
    };

	qspi_sync_enable(&QUAD_SPI_0);
	while (status & (1 << 0)) {
		qspi_sync_serial_run_command(&QUAD_SPI_0, &cmd);
	}
	qspi_sync_deinit(&QUAD_SPI_0);
}

/**
 * Example of using CALENDAR_0.
 */
static struct calendar_alarm alarm;

static void alarm_cb(struct calendar_descriptor *const descr)
{
	/* alarm expired */
}

void CALENDAR_0_example(void)
{
	struct calendar_date date;
	struct calendar_time time;

	calendar_enable(&CALENDAR_0);

	date.year  = 2000;
	date.month = 12;
	date.day   = 31;

	time.hour = 12;
	time.min  = 59;
	time.sec  = 59;

	calendar_set_date(&CALENDAR_0, &date);
	calendar_set_time(&CALENDAR_0, &time);

	alarm.cal_alarm.datetime.time.sec = 4;
	alarm.cal_alarm.option            = CALENDAR_ALARM_MATCH_SEC;
	alarm.cal_alarm.mode              = REPEAT;

	calendar_set_alarm(&CALENDAR_0, &alarm, alarm_cb);
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_0[12] = "Hello World!";

void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_0, &io);

	spi_m_sync_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
}

/**
 * Example of using RAND_0 to generate waveform.
 */
void RAND_0_example(void)
{
	uint32_t random_n[4];
	rand_sync_enable(&RAND_0);
	random_n[0] = rand_sync_read32(&RAND_0);
	random_n[1] = rand_sync_read32(&RAND_0);
	rand_sync_read_buf32(&RAND_0, &random_n[2], 2);
	if (random_n[0] == random_n[1]) {
		/* halt */
		while (1)
			;
	}
	if (random_n[2] == random_n[3]) {
		/* halt */
		while (1)
			;
	}
}

void I2C_0_example(void)
{
	struct io_descriptor *I2C_0_io;

	i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
	i2c_m_sync_enable(&I2C_0);
	i2c_m_sync_set_slaveaddr(&I2C_0, 0x12, I2C_M_SEVEN);
	io_write(I2C_0_io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using USART_0 to write "Hello World" using the IO abstraction.
 */
void USART_0_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&USART_0, &io);
	usart_sync_enable(&USART_0);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using USART_1 to write "Hello World" using the IO abstraction.
 */
void USART_1_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&USART_1, &io);
	usart_sync_enable(&USART_1);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using USART_2 to write "Hello World" using the IO abstraction.
 */
void USART_2_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&USART_2, &io);
	usart_sync_enable(&USART_2);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using USART_3 to write "Hello World" using the IO abstraction.
 */
void USART_3_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&USART_3, &io);
	usart_sync_enable(&USART_3);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using WDT_0.
 */
void WDT_0_example(void)
{
	/**
	 * ATSAMV71Q21B do not support wdt_set_timeout_period()
	 * and wdt_enable(), the watch dog will start counting once
	 * wdt_init() been called.
	 * The application should call wdt_feed(&WDT_0) at
	 * regular intervals before the timer underflow.
	 */
	wdt_feed(&WDT_0);
}

void ETHERNET_MAC_0_example(void)
{
	mac_async_enable(&ETHERNET_MAC_0);
	mac_async_write(&ETHERNET_MAC_0, (uint8_t *)"Hello World!", 12);
}

void CAN_0_tx_callback(struct can_async_descriptor *const descr)
{
	(void)descr;
}
void CAN_0_rx_callback(struct can_async_descriptor *const descr)
{
	struct can_message msg;
	uint8_t            data[64];
	msg.data = data;
	can_async_read(descr, &msg);
	return;
}

/**
 * Example of using CAN_0 to Encrypt/Decrypt datas.
 */
void CAN_0_example(void)
{
	struct can_message msg;
	struct can_filter  filter;
	uint8_t            send_data[4];
	send_data[0] = 0x00;
	send_data[1] = 0x01;
	send_data[2] = 0x02;
	send_data[3] = 0x03;

	msg.id   = 0x45A;
	msg.type = CAN_TYPE_DATA;
	msg.data = send_data;
	msg.len  = 4;
	msg.fmt  = CAN_FMT_STDID;
	can_async_register_callback(&CAN_0, CAN_ASYNC_TX_CB, (FUNC_PTR)CAN_0_tx_callback);
	can_async_enable(&CAN_0);
	/**
	 * CAN_0_tx_callback callback should be invoked after call
	 * can_async_write, and remote device should recieve message with ID=0x45A
	 */
	can_async_write(&CAN_0, &msg);

	msg.id  = 0x100000A5;
	msg.fmt = CAN_FMT_EXTID;
	/**
	 * remote device should recieve message with ID=0x100000A5
	 */
	can_async_write(&CAN_0, &msg);

	/**
	 * CAN_0_rx_callback callback should be invoked after call
	 * can_async_set_filter and remote device send CAN Message with the same
	 * content as the filter.
	 */
	can_async_register_callback(&CAN_0, CAN_ASYNC_RX_CB, (FUNC_PTR)CAN_0_rx_callback);
	filter.id   = 0x469;
	filter.mask = 0;
	can_async_set_filter(&CAN_0, 0, CAN_FMT_STDID, &filter);

	filter.id   = 0x10000096;
	filter.mask = 0;
	can_async_set_filter(&CAN_0, 1, CAN_FMT_EXTID, &filter);
}

void CAN_1_tx_callback(struct can_async_descriptor *const descr)
{
	(void)descr;
}
void CAN_1_rx_callback(struct can_async_descriptor *const descr)
{
	struct can_message msg;
	uint8_t            data[64];
	msg.data = data;
	can_async_read(descr, &msg);
	return;
}

/**
 * Example of using CAN_1 to Encrypt/Decrypt datas.
 */
void CAN_1_example(void)
{
	struct can_message msg;
	struct can_filter  filter;
	uint8_t            send_data[4];
	send_data[0] = 0x00;
	send_data[1] = 0x01;
	send_data[2] = 0x02;
	send_data[3] = 0x03;

	msg.id   = 0x45A;
	msg.type = CAN_TYPE_DATA;
	msg.data = send_data;
	msg.len  = 4;
	msg.fmt  = CAN_FMT_STDID;
	can_async_register_callback(&CAN_1, CAN_ASYNC_TX_CB, (FUNC_PTR)CAN_1_tx_callback);
	can_async_enable(&CAN_1);
	/**
	 * CAN_1_tx_callback callback should be invoked after call
	 * can_async_write, and remote device should recieve message with ID=0x45A
	 */
	can_async_write(&CAN_1, &msg);

	msg.id  = 0x100000A5;
	msg.fmt = CAN_FMT_EXTID;
	/**
	 * remote device should recieve message with ID=0x100000A5
	 */
	can_async_write(&CAN_1, &msg);

	/**
	 * CAN_1_rx_callback callback should be invoked after call
	 * can_async_set_filter and remote device send CAN Message with the same
	 * content as the filter.
	 */
	can_async_register_callback(&CAN_1, CAN_ASYNC_RX_CB, (FUNC_PTR)CAN_1_rx_callback);
	filter.id   = 0x469;
	filter.mask = 0;
	can_async_set_filter(&CAN_1, 0, CAN_FMT_STDID, &filter);

	filter.id   = 0x10000096;
	filter.mask = 0;
	can_async_set_filter(&CAN_1, 1, CAN_FMT_EXTID, &filter);
}
