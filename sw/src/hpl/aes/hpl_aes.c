/**
 * \file
 *
 * \brief AES Advanced Encryption Standard(Sync) functionality declaration.
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
#include <string.h>
#include <utils_assert.h>
#include <hpl_aes_sync.h>

/**
 * \internal Update the AES KEY Register
 *
 * \param[in] hw The pointer to hardware instance
 * \param[in] key AES KEY
 * \param[in] keysize AES KEY size
 */
static inline void __aes_sync_set_key(void *const hw, uint8_t *key, uint8_t keysize)
{
	int     i;
	uint8_t size = (keysize >> 2);

	for (i = 0; i < size; i++) {
		hri_aes_write_KEYWR_reg(hw, i, ((uint32_t *)key)[i]);
	}
}

/**
 * \internal Update the Initialization Vector Register
 *
 * \param[in] hw The pointer to hardware instance
 * \param[in] iv Initialization Vector
 */
static inline void __aes_sync_set_iv(void *const hw, uint8_t *iv)
{
	int i;

	for (i = 0; i < 4; i++) {
		hri_aes_write_IVR_reg(hw, i, ((uint32_t *)iv)[i]);
	}
}

/**
 * \internal Update the INDATA Register
 *
 * \param[in] hw The pointer to hardware instance
 * \param[in] data Data write to INDATA Register
 */
static inline void __aes_sync_set_indata(void *const hw, const uint8_t *data)
{
	uint32_t i;

	for (i = 0; i < 4; i++) {
		hri_aes_write_IDATAR_reg(hw, i, ((uint32_t *)data)[i]);
	}
}

/**
 * \internal Get data from INDATA Register
 *
 * \param[in] hw The pointer to hardware instance
 * \param[out] output Get INDATA Register value
 */
static inline void __aes_sync_get_indata(void *const hw, uint8_t *output)
{
	uint32_t i;

	for (i = 0; i < 4; i++) {
		((uint32_t *)output)[i] = hri_aes_read_ODATAR_reg(hw, i);
	}
}

/**
 * \internal
 * \param[in] enc AES_DECRYPT/AES_ENCRYPT
 * \param[in] input  input text
 * \param[in] output output text
 * \param[in] length text length
 * \param[out] iv Initialization Vector
 */
static inline void __aes_sync_update_cfb_iv(const enum aes_action enc, const uint8_t *input, uint8_t *output,
                                            uint32_t length, uint8_t *iv)
{
	const uint8_t *ptr = ((enc == AES_ENCRYPT) ? output : input);

	if (length >= 16) {
		memcpy(iv, ptr + length - 16, 16);
	} else {
		memcpy(iv, iv + length, 16 - length);
		memcpy(iv + 16 - length, ptr, length);
	}
}

int32_t _aes_sync_init(struct _aes_sync_device *const dev, void *const hw)
{
	dev->hw = hw;

	return ERR_NONE;
}

int32_t _aes_sync_deinit(struct _aes_sync_device *dev)
{
	hri_aes_write_CR_reg(dev->hw, AES_CR_SWRST);
	dev->hw = NULL;

	return ERR_NONE;
}

int32_t _aes_sync_enable(struct _aes_sync_device *const dev)
{
	(void)dev;
	return ERR_NONE;
}

int32_t _aes_sync_disable(struct _aes_sync_device *const dev)
{
	(void)dev;
	return ERR_NONE;
}

int32_t _aes_sync_set_key(struct _aes_sync_device *const dev, const uint8_t *key, const enum aes_keysize size)
{
	dev->keysize = size;
	memcpy(dev->key, key, (size + 2) << 3);

	return ERR_NONE;
}

int32_t _aes_sync_ecb_crypt(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                            uint8_t *output)
{
	void *hw = dev->hw;

	hri_aes_write_MR_reg(hw, enc | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_ECB);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_indata(hw, input);
	hri_aes_write_CR_reg(hw, AES_CR_START);
	while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
	}
	__aes_sync_get_indata(hw, output);

	return ERR_NONE;
}

int32_t _aes_sync_cbc_crypt(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                            uint8_t *output, uint32_t length, uint8_t iv[16])
{
	void *         hw = dev->hw;
	uint8_t        block;
	const uint8_t *inptr;
	uint8_t *      outptr;

	hri_aes_write_MR_reg(hw, enc | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CBC);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, iv);
	/* Enc/Dec plain text */
	inptr  = input;
	outptr = output;
	for (block = 0; block < (length >> 4); block++) {
		__aes_sync_set_indata(hw, inptr);
		inptr += 16;
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		__aes_sync_get_indata(hw, outptr);
		outptr += 16;
	}
	/* Last IV equals last cipher text */
	memcpy(iv, (enc == AES_ENCRYPT) ? output + length - 16 : input + length - 16, 16);

	return ERR_NONE;
}

int32_t _aes_sync_cfb128_crypt(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                               uint8_t *output, uint32_t length, uint8_t *iv)
{
	void *         hw = dev->hw;
	uint8_t        block;
	const uint8_t *inptr;
	uint8_t *      outptr;

	hri_aes_write_MR_reg(hw, enc | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CFB | AES_MR_CFBS_SIZE_128BIT);
	/* Cipher Feedback Data Size: 128-bit */
	hri_aes_write_MR_CFBS_bf(hw, 0);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, iv);

	/* Enc/Dec plain text */
	inptr  = input;
	outptr = output;
	for (block = 0; block < (length >> 4); block++) {
		__aes_sync_set_indata(hw, inptr);
		inptr += 16;
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		__aes_sync_get_indata(hw, outptr);
		outptr += 16;
	}

	__aes_sync_update_cfb_iv(enc, input, output, length, iv);

	return ERR_NONE;
}

int32_t _aes_sync_cfb64_crypt(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                              uint8_t *output, uint32_t length, uint8_t *iv)
{
	void *         hw = dev->hw;
	uint8_t        block;
	const uint8_t *inptr;
	uint8_t *      outptr;

	hri_aes_write_MR_reg(hw, enc | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CFB | AES_MR_CFBS_SIZE_64BIT);
	/* Cipher Feedback Data Size: 64-bit */
	hri_aes_write_MR_CFBS_bf(hw, 1);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, iv);

	/* Enc/Dec plain text */
	inptr  = input;
	outptr = output;
	for (block = 0; block < (length >> 3); block++) {
		hri_aes_write_IDATAR_reg(hw, 0, ((uint32_t *)inptr)[0]);
		hri_aes_write_IDATAR_reg(hw, 1, ((uint32_t *)inptr)[1]);
		inptr += 8;
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		((uint32_t *)outptr)[0] = hri_aes_read_ODATAR_reg(hw, 0);
		((uint32_t *)outptr)[1] = hri_aes_read_ODATAR_reg(hw, 1);
		outptr += 8;
	}

	__aes_sync_update_cfb_iv(enc, input, output, length, iv);

	return ERR_NONE;
}

int32_t _aes_sync_cfb32_crypt(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                              uint8_t *output, uint32_t length, uint8_t *iv)
{
	void *         hw = dev->hw;
	uint8_t        block;
	const uint8_t *inptr;
	uint8_t *      outptr;

	hri_aes_write_MR_reg(hw, enc | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CFB | AES_MR_CFBS_SIZE_32BIT);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, iv);

	/* Enc/Dec plain text */
	inptr  = input;
	outptr = output;
	for (block = 0; block < (length >> 2); block++) {
		hri_aes_write_IDATAR_reg(hw, 0, ((uint32_t *)inptr)[0]);
		inptr += 4;
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		((uint32_t *)outptr)[0] = hri_aes_read_ODATAR_reg(hw, 0);
		outptr += 4;
	}

	__aes_sync_update_cfb_iv(enc, input, output, length, iv);

	return ERR_NONE;
}

int32_t _aes_sync_cfb16_crypt(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                              uint8_t *output, uint32_t length, uint8_t *iv)
{
	void *  hw = dev->hw;
	uint8_t block;

	hri_aes_write_MR_reg(hw, enc | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CFB | AES_MR_CFBS_SIZE_16BIT);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, iv);

	/* Enc/Dec plain text */
	for (block = 0; block < (length >> 1); block++) {
		hri_aes_write_IDATAR_reg(hw, 0, ((uint16_t *)input)[block]);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		((uint16_t *)output)[block] = hri_aes_read_ODATAR_reg(hw, 0) & 0xffff;
	}

	__aes_sync_update_cfb_iv(enc, input, output, length, iv);

	return ERR_NONE;
}

int32_t _aes_sync_cfb8_crypt(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                             uint8_t *output, uint32_t length, uint8_t *iv)
{
	void *  hw = dev->hw;
	uint8_t block;

	hri_aes_write_MR_reg(hw, enc | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CFB | AES_MR_CFBS_SIZE_8BIT);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, iv);

	/* Enc/Dec plain text */
	for (block = 0; block < length; block++) {
		hri_aes_write_IDATAR_reg(hw, 0, input[block]);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		output[block] = hri_aes_read_ODATAR_reg(hw, 0) & 0xff;
	}

	__aes_sync_update_cfb_iv(enc, input, output, length, iv);

	return ERR_NONE;
}

int32_t _aes_sync_ofb_crypt(struct _aes_sync_device *const dev, const uint8_t *input, uint8_t *output, uint32_t length,
                            uint8_t *iv)
{
	void *         hw = dev->hw;
	uint8_t        index;
	uint8_t        block;
	const uint8_t *inptr;
	uint8_t *      outptr;

	hri_aes_write_MR_reg(hw, AES_ENCRYPT | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_OFB);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, iv);
	hri_aes_set_IMR_DATRDY_bit(hw);
	/* Enc/Dec plain text */
	inptr  = input;
	outptr = output;
	for (block = 0; block < (length >> 4); block++) {
		__aes_sync_set_indata(hw, inptr);
		inptr += 16;
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		__aes_sync_get_indata(hw, outptr);
		outptr += 16;
	}
	hri_aes_clear_IMR_DATRDY_bit(hw);
	/* IV equals last plain text XOR cipher text */
	for (index = 0; index < 16; index++) {
		iv[index] = input[length - 16 + index] ^ output[length - 16 + index];
	}

	return ERR_NONE;
}

int32_t _aes_sync_ctr_crypt(struct _aes_sync_device *const dev, const uint8_t *input, uint8_t *output, uint32_t length,
                            uint8_t nc[16])
{
	void *         hw = dev->hw;
	uint8_t        index;
	uint8_t        block;
	const uint8_t *inptr;
	uint8_t *      outptr;

	hri_aes_write_MR_reg(hw, AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CTR);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, nc);

	/* Enc/Dec plain text */
	inptr  = input;
	outptr = output;
	for (block = 0; block < (length >> 4); block++) {
		__aes_sync_set_indata(hw, inptr);
		inptr += 16;
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		__aes_sync_get_indata(hw, outptr);
		outptr += 16;

		/* NC equals last NC + 1 */
		for (index = 0; index < 16; index++) {
			nc[15 - index] += 1;

			if (nc[15 - index]) {
				break;
			}
		}
	}

	return ERR_NONE;
}

/**
 * \internal AES-GCM block start
 *
 * \param[in] dev The pointer to AES device struct
 * \param[in] enc AES_ENCRYPT/AES_DECRYPT
 * \param[in] iv Initialization Vector
 * \param[in] iv_len Initialization Vector length
 * \param[in] aad Additional Authenticated Data
 * \param[in] aad_len Byte length of Additional Authenticated Data
 */
static void __aes_sync_gcm_start(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *iv,
                                 uint32_t iv_len, const uint8_t *aad, uint32_t aad_len)
{
	void *         hw = dev->hw;
	uint8_t        index;
	uint32_t       use_len;
	int32_t        left_len;
	uint8_t        workbuf[16];
	const uint8_t *ptr;

	hri_aes_write_MR_reg(hw, enc | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_GCM | AES_MR_GTAGEN);

	/* Step 1 Generate generate GCMH Subkey */
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);

	/* Step 2: Generate pre-counter block j0 from the IV */
	if (iv_len == 12) {
		memcpy(dev->iv, iv, 12);
		memset(dev->iv + 12, 0, 3);
		dev->iv[15] = 0x01;
	} else {
		/* If iv_len != 96, then j0 = GHASH(H, {}, IV) */
		for (index = 0; index < 4; index++) {
			hri_aes_write_GHASHR_reg(hw, index, 0x0);
		}
		/* GHASH IV */
		ptr      = iv;
		left_len = iv_len;
		while (left_len >= 0) {
			use_len = (left_len < 16) ? left_len : 16;

			if (use_len == 16) {
				__aes_sync_set_indata(hw, ptr);
				hri_aes_write_CR_reg(hw, AES_CR_START);
				while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
				}
			} else {
				memset(workbuf, 0, 16);
				memcpy(workbuf, ptr, use_len);
				__aes_sync_set_indata(hw, workbuf);
				hri_aes_write_CR_reg(hw, AES_CR_START);
				while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
				}
			}

			left_len -= use_len;
			ptr += use_len;
			left_len = left_len ? left_len : -1;
		}

		/* GHASH len(IV)64 */
		memset(workbuf, 0, 12);
		workbuf[12] = ((iv_len << 3) >> 24) & 0xFF;
		workbuf[13] = ((iv_len << 3) >> 16) & 0xFF;
		workbuf[14] = ((iv_len << 3) >> 8) & 0xFF;
		workbuf[15] = (iv_len << 3) & 0xFF;
		__aes_sync_set_indata(hw, workbuf);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		/* Get j0 from GHASH reg */
		for (index = 0; index < 4; index++) {
			((uint32_t *)dev->iv)[index] = hri_aes_read_GHASHR_reg(hw, index);
			hri_aes_write_GHASHR_reg(hw, index, 0x0);
		}
	}

	/* Step 3: GHASH AAD */
	ptr      = aad;
	left_len = aad_len;
	while (left_len > 0) {
		use_len = (left_len < 16) ? left_len : 16;

		if (use_len == 16) {
			__aes_sync_set_indata(hw, ptr);
			hri_aes_write_CR_reg(hw, AES_CR_START);
			while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
			}
		} else {
			memset(workbuf, 0, 16);
			memcpy(workbuf, ptr, use_len);
			__aes_sync_set_indata(hw, workbuf);
			hri_aes_write_CR_reg(hw, AES_CR_START);
			while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
			}
		}

		left_len -= use_len;
		ptr += use_len;
		left_len = left_len ? left_len : -1;
	}

	dev->aad_len = aad_len;
}

/**
 * \internal AES-GCM block update
 *
 * \param[in] dev The pointer to AES device struct
 * \param[in] input Buffer holding the input data
 * \param[out] output Buffer holding the output data
 * \param[in] length  Byte length of the input data
 */
static void __aes_sync_gcm_update(struct _aes_sync_device *const dev, const uint8_t *input, uint8_t *output,
                                  uint32_t length)
{
	void *         hw = dev->hw;
	int8_t         index;
	uint8_t        block;
	uint8_t        workbuf[16];
	const uint8_t *inptr;
	uint8_t *      outptr;
	uint8_t *      ptr;
	uint32_t       ghash[4];

	/* Store the GHASHRx */
	for (index = 0; index < 4; index++) {
		ghash[index] = hri_aes_read_GHASHR_reg(hw, index);
	}

	/* Set iv = j1 =  j0 + 1 */
	for (index = 16; index > 12; index--) {
		if (++dev->iv[index - 1] != 0)
			break;
	}
	memcpy(workbuf, dev->iv, 16);
	__aes_sync_set_iv(hw, workbuf);

	hri_aes_write_CLENR_reg(hw, length);

	/* Enc/Dec plain text */
	inptr  = input;
	outptr = output;
	for (block = 0; block < (length >> 4); block++) {
		__aes_sync_set_indata(hw, inptr);
		inptr += 16;
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		__aes_sync_get_indata(hw, outptr);
		outptr += 16;
	}

	/* If length it not 16 bytes align, then process last one */
	if (length & 0xF) {
		memset(workbuf, 0, 16);
		memcpy(workbuf, input + (length & ~0xF), length & 0xF);
		__aes_sync_set_indata(hw, workbuf);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		__aes_sync_get_indata(hw, workbuf);
		memcpy(output + (length & ~0xF), workbuf, length & 0xF);
	}

	/* Generate GHASH */
	hri_aes_write_CLENR_reg(hw, 0);
	hri_aes_write_AADLENR_reg(hw, 0);
	for (index = 0; index < 4; index++) {
		hri_aes_write_GHASHR_reg(hw, index, ghash[index]);
	}

	if (hri_aes_get_MR_CIPHER_bit(hw) == AES_DECRYPT) {
		ptr = (uint8_t *)input;
	} else {
		ptr = output;
	}
	for (block = 0; block < (length >> 4); block++) {
		__aes_sync_set_indata(hw, ptr);
		ptr += 16;
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
	}
	if (length & 0xF) {
		memset(workbuf, 0, 16);
		memcpy(workbuf, ptr, length & 0xF);
		__aes_sync_set_indata(hw, workbuf);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
	}

	/* Generate Final GHASH by GHASH(H, A, C) */
	memset(workbuf, 0, 16);
	((uint8_t *)workbuf)[4]  = ((dev->aad_len << 3) >> 24) & 0xFF;
	((uint8_t *)workbuf)[5]  = ((dev->aad_len << 3) >> 16) & 0xFF;
	((uint8_t *)workbuf)[6]  = ((dev->aad_len << 3) >> 8) & 0xFF;
	((uint8_t *)workbuf)[7]  = (dev->aad_len << 3) & 0xFF;
	((uint8_t *)workbuf)[12] = ((length << 3) >> 24) & 0xFF;
	((uint8_t *)workbuf)[13] = ((length << 3) >> 16) & 0xFF;
	((uint8_t *)workbuf)[14] = ((length << 3) >> 8) & 0xFF;
	((uint8_t *)workbuf)[15] = (length << 3) & 0xFF;

	__aes_sync_set_indata(hw, workbuf);
	hri_aes_write_CR_reg(hw, AES_CR_START);
	while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
	}
}

/**
 * \internal AES-GCM generate Tag
 *
 * \param[in] dev The pointer to AES device struct
 * \param[out] tag Buffer holding the output data
 * \param[in] tag_len  Byte length of tag
 */
static void __aes_sync_gcm_generate_tag(struct _aes_sync_device *const dev, uint8_t *tag, uint32_t tag_len)
{
	void *  hw = dev->hw;
	int8_t  index;
	uint8_t j0[16];

	hri_aes_write_MR_reg(hw, AES_ENCRYPT | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CTR | AES_MR_LOD);

	__aes_sync_set_iv(hw, dev->iv);

	for (index = 0; index < 4; index++) {
		hri_aes_write_IDATAR_reg(hw, index, (uint32_t)hri_aes_read_GHASHR_reg(hw, index));
	}
	hri_aes_write_CR_reg(hw, AES_CR_START);
	while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
	}

	__aes_sync_get_indata(hw, j0);
	memcpy(tag, j0, tag_len);

	/* Cleanup */
	for (index = 0; index < 4; index++) {
		hri_aes_write_GHASHR_reg(hw, index, 0x0);
		hri_aes_write_GCMHR_reg(hw, index, 0x0);
	}
	hri_aes_write_CLENR_reg(hw, 0);
	hri_aes_write_AADLENR_reg(hw, 0);
}

int32_t _aes_sync_gcm_crypt_and_tag(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                                    uint8_t *output, uint32_t length, const uint8_t *iv, uint32_t iv_len,
                                    const uint8_t *aad, uint32_t aad_len, uint8_t *tag, uint32_t tag_len)
{
	__aes_sync_gcm_start(dev, enc, iv, iv_len, aad, aad_len);
	__aes_sync_gcm_update(dev, input, output, length);
	__aes_sync_gcm_generate_tag(dev, tag, tag_len);

	return ERR_NONE;
}

int32_t _aes_sync_gcm_start(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *iv,
                            uint32_t iv_len, const uint8_t *aad, uint32_t aad_len)
{
	__aes_sync_gcm_start(dev, enc, iv, iv_len, aad, aad_len);
	return ERR_NONE;
}

int32_t _aes_sync_gcm_update(struct _aes_sync_device *const dev, const uint8_t *input, uint8_t *output, uint32_t length)
{
	__aes_sync_gcm_update(dev, input, output, length);
	return ERR_NONE;
}

int32_t _aes_sync_gcm_finish(struct _aes_sync_device *const dev, uint8_t *tag, uint32_t tag_len)
{
	/* Generate Tag, The final GHash should be present at GHASHx reg now */
	__aes_sync_gcm_generate_tag(dev, tag, tag_len);
	return ERR_NONE;
}

/**
 * \internal Encrypt CCM Data, the process follow the SP800-38C
 *  Section 6.1 Generation-Encryption Process
 *
 * \param[in] dev The pointer to AES device struct
 * \param[in] input Source text
 * \param[out] output Target text
 * \param[in] length Input text length
 * \param[in] iv Initialization Vector
 * \param[in] iv_len Byte length of Initialization Vector
 * \param[in] aad Additional Authenticated Data
 * \param[in] aad_len Byte length of Additional Authenticated Data
 * \param[out] tag Authentication Tag
 * \param[in] tag_len Authentication Tag length
 *
 * \return The status of CCM Generation-Encryption result
 */
static int32_t __aes_sync_ccm_crypt_and_tag(struct _aes_sync_device *const dev, const uint8_t *input, uint8_t *output,
                                            uint32_t length, const uint8_t *iv, uint32_t iv_len, const uint8_t *aad,
                                            uint32_t aad_len, uint8_t *tag, uint32_t tag_len)
{
	void *         hw = dev->hw;
	int8_t         index;
	uint8_t        block;
	uint8_t        q;
	uint8_t        b[16];
	uint8_t        ctr[16];
	const uint8_t *src;
	uint8_t *      dst;
	uint8_t        len_left;
	uint8_t        len_use;

	/* Step 1 (SP800-38C, 6.1): Apply the formatting function to (N,A,P) to
	 * produce the blocks B0,...Br */

	/* Generate first block B0 */
	memset(b, 0, 16);
	q    = (16 - 1 - (uint8_t)iv_len);
	b[0] = 0;
	b[0] |= (aad_len > 0) << 6;
	b[0] |= ((tag_len - 2) / 2) << 3;
	b[0] |= q - 1;
	memcpy(b + 1, iv, iv_len);
	for (index = 0, block = length; index < q; index++, block >>= 8) {
		b[15 - index] = (uint8_t)(block & 0xFF);
	}

	if (block > 0) {
		return ERR_INVALID_ARG;
	}

	/* Prepare CBC-MAC */
	hri_aes_write_MR_reg(hw, AES_ENCRYPT | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CBC | AES_MR_LOD);

	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);

	/* For CBC-MAC, zero block is used as the IV (SP800-38C, 5.2) */
	for (index = 0; index < 4; index++) {
		hri_aes_write_IVR_reg(hw, index, 0x0);
	}

	/* Step 2(SP800-38C, 6.1): CBC-MAC for block0 */
	__aes_sync_set_indata(hw, b);
	hri_aes_write_CR_reg(hw, AES_CR_START);
	while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
	}

	/* Step 3(SP800-38C, 6.1) Continue process B1 to Br */
	/* Process additional data if have */
	if (aad_len > 0) {
		len_left = aad_len;
		src      = aad;

		memset(b, 0, 16);
		b[0] = (uint8_t)((aad_len >> 8) & 0xFF);
		b[1] = (uint8_t)(aad_len & 0xFF);

		len_use = len_left < 16 - 2 ? len_left : 16 - 2;
		for (index = 2; index < len_use + 2; index++) {
			b[index] = *src;
			src++;
		}
		len_left -= len_use;

		/* Update CBC-MAC */
		__aes_sync_set_indata(hw, b);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}

		while (len_left > 0) {
			len_use = len_left > 16 ? 16 : len_left;
			memset(b, 0, 16);
			memcpy(b, src, len_use);
			__aes_sync_set_indata(hw, b);
			hri_aes_write_CR_reg(hw, AES_CR_START);
			while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
			}
			len_left -= len_use;
		}
	}

	/* Process plain text */
	len_left = length;
	src      = input;
	dst      = output;
	while (len_left > 0) {
		len_use = len_left > 16 ? 16 : len_left;

		if (len_use < 16) {
			memset(b, 0, 16);
		}

		memcpy(b, src, len_use);
		src += len_use;

		/* Update CBC-MAC */
		__aes_sync_set_indata(hw, b);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		len_left -= len_use;
	}

	/* Step 4 (800-38C, 6.1) Get Tag from MSB(Br),
	 * Temporary save to output tag, the tag
	 * will be update at the final step.
	 */
	__aes_sync_get_indata(hw, b);
	memcpy(tag, b, tag_len);

	/* Step 5,6,7 (800-38C, 6.1) Change to counter mode and encrypt plain text */
	hri_aes_write_MR_OPMOD_bf(hw, 4); /* Counter MODE */
	hri_aes_set_MR_LOD_bit(hw);
	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);

	/* Prepare counter block for encryption */
	memset(ctr, 0, 16);
	ctr[0] = q - 1;
	memcpy(ctr + 1, iv, iv_len);
	ctr[15] = 1;
	__aes_sync_set_iv(hw, ctr);

	len_left = length;
	src      = input;
	dst      = output;
	while (len_left > 0) {
		len_use = len_left > 16 ? 16 : len_left;

		if (len_use < 16) {
			memset(b, 0, 16);
		}

		memcpy(b, src, len_use);
		src += len_use;

		/* UPDATE Cipher text */
		__aes_sync_set_indata(hw, b);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		__aes_sync_get_indata(hw, b);
		memcpy(dst, b, len_use);
		dst += len_use;
		len_left -= len_use;
	}

	/* Step 8 (800-38C, 6.1) Update Tag = Tag XOR MSBtlen(S0) */
	ctr[15] = 0;
	__aes_sync_set_iv(hw, ctr);

	if (tag_len < 16) {
		memset(b, 0, 16);
	}

	memcpy(b, tag, tag_len);
	__aes_sync_set_indata(hw, b);
	hri_aes_write_CR_reg(hw, AES_CR_START);
	while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
	}
	__aes_sync_get_indata(hw, b);
	memcpy(tag, b, tag_len);

	return ERR_NONE;
}

/**
 * \internal Encrypt CCM Data, the process follow the SP800-38C
 * Section 6.2 Decryption-Verification Process
 *
 * \param[in] dev The pointer to AES device struct
 * \param[in] input Source text
 * \param[out] output Target text
 * \param[in] length Text length
 * \param[in] iv Initialization Vector
 * \param[in] iv_len Initialization Vector length
 * \param[in] aad Additional Authenticated Data
 * \param[in] aad_len Additional Authenticated Data length
 * \param[out] tag Authentication Tag
 * \param[in] tag_len Authentication Tag length
 *
 * \return The status of CCM Decryption-Verification result
 */
static int32_t __aes_sync_ccm_decrypt_and_tag(struct _aes_sync_device *const dev, const uint8_t *input, uint8_t *output,
                                              uint32_t length, const uint8_t *iv, uint32_t iv_len, const uint8_t *aad,
                                              uint32_t aad_len, uint8_t *tag, uint32_t tag_len)
{
	void *         hw = dev->hw;
	int8_t         index;
	uint8_t        block; /* Number of blocks (16 bytes) */
	uint8_t        q;
	uint8_t        b[16];
	uint8_t        ctr[16];
	const uint8_t *src;
	uint8_t *      dst;
	uint8_t        len_left;
	uint8_t        len_use;

	/* Step 2(SP800-38C, 6.2) Prepare Counter for decrypt cipher text */
	memset(ctr, 0, 16);
	q      = (16 - 1 - (uint8_t)iv_len);
	ctr[0] = q - 1;
	memcpy(ctr + 1, iv, iv_len);
	ctr[15] = 1;

	/* Step 3,4,5(SP800-38C, 6.2) Decrypt cipher text */
	hri_aes_write_MR_reg(hw, AES_DECRYPT | AES_MR_KEYSIZE(dev->keysize) | AES_MR_OPMOD_CTR);

	__aes_sync_set_key(hw, dev->key, (dev->keysize + 2) << 3);
	__aes_sync_set_iv(hw, ctr);

	len_left = length;
	src      = input;
	dst      = output;
	while (len_left > 0) {
		size_t len_use = len_left > 16 ? 16 : len_left;

		if (len_use < 16) {
			memset(b, 0, 16);
		}

		memcpy(b, src, len_use);
		src += len_use;
		/* Update Cipher text */
		__aes_sync_set_indata(hw, b);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}
		__aes_sync_get_indata(hw, b);
		memcpy(dst, b, len_use);
		dst += len_use;

		len_left -= len_use;
	}

	/* Step 6(SP800-38C, 6.2) this step was skipped, the input tag will be
	 * checked in HAL, below step will generate tag from plain text(output)
	 */

	/* Step 7(SP800-38C, 6.2) Prepare CBC-MAC */
	hri_aes_write_MR_CIPHER_bit(hw, AES_ENCRYPT);
	hri_aes_write_MR_OPMOD_bf(hw, 1);
	hri_aes_set_MR_LOD_bit(hw);
	/* For CBC-MAC, zero block is used as the IV (SP800-38C, 5.2)*/
	for (index = 0; index < 4; index++) {
		hri_aes_write_IVR_reg(hw, index, 0x0);
	}
	/* Step 8(SP800-38C, 6.2) CBC-MAC for block0 */
	b[0] = 0;
	b[0] |= (aad_len > 0) << 6;
	b[0] |= ((tag_len - 2) / 2) << 3;
	b[0] |= q - 1;
	memcpy(b + 1, iv, iv_len);
	for (index = 0, block = length; index < q; index++, block >>= 8) {
		b[15 - index] = (uint8_t)(block & 0xFF);
	}

	if (block > 0) {
		return ERR_INVALID_ARG;
	}

	__aes_sync_set_indata(hw, b);
	hri_aes_write_CR_reg(hw, AES_CR_START);
	while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
	}

	/* Step 9(SP800-38C, 6.2) Continue process B1 to Br */
	if (aad_len > 0) {
		len_left = aad_len;
		src      = aad;
		memset(b, 0, 16);
		b[0] = (uint8_t)((aad_len >> 8) & 0xFF);
		b[1] = (uint8_t)(aad_len & 0xFF);

		len_use = len_left < 16 - 2 ? len_left : 16 - 2;
		for (index = 2; index < len_use + 2; index++) {
			b[index] = *src;
			src++;
		}
		len_left -= len_use;

		/* Update CBC-MAC */
		__aes_sync_set_indata(hw, b);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}

		while (len_left > 0) {
			len_use = len_left > 16 ? 16 : len_left;

			if (len_use < 16) {
				memset(b, 0, 16);
			}

			memcpy(b, src, len_use);
			src += len_use;
			/* UPDATE CBC-MAC */
			__aes_sync_set_indata(hw, b);
			hri_aes_write_CR_reg(hw, AES_CR_START);
			while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
			}
			len_left -= len_use;
		}
	}

	/* Process plain text */
	len_left = length;
	src      = output;
	while (len_left > 0) {
		len_use = len_left > 16 ? 16 : len_left;

		if (len_use != 16) {
			memset(b, 0, 16);
		}

		memcpy(b, src, len_use);
		src += len_use;

		/* Update CBC-MAC */
		__aes_sync_set_indata(hw, b);
		hri_aes_write_CR_reg(hw, AES_CR_START);
		while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
		}

		len_left -= len_use;
	}

	/* Step 10(SP800-38C, 6.2) Get Tag from MSBtlen(Yr) */
	__aes_sync_get_indata(hw, b);
	memcpy(tag, b, tag_len);
	/* Update Tag = Tag XOR MSBtlen(Yr) */
	hri_aes_write_MR_OPMOD_bf(hw, 4);
	hri_aes_clear_MR_LOD_bit(hw);

	ctr[15] = 0;
	__aes_sync_set_iv(hw, ctr);
	if (tag_len < 16) {
		memset(b, 0, 16);
	}

	memcpy(b, tag, tag_len);
	__aes_sync_set_indata(hw, b);
	hri_aes_write_CR_reg(hw, AES_CR_START);
	while (!hri_aes_get_ISR_DATRDY_bit(hw)) {
	}
	__aes_sync_get_indata(hw, b);
	memcpy(tag, b, tag_len);

	return ERR_NONE;
}

int32_t _aes_sync_ccm_crypt_and_tag(struct _aes_sync_device *const dev, const enum aes_action enc, const uint8_t *input,
                                    uint8_t *output, uint32_t length, const uint8_t *iv, uint32_t iv_len,
                                    const uint8_t *aad, uint32_t aad_len, uint8_t *tag, uint32_t tag_len)
{
	if (enc) {
		__aes_sync_ccm_crypt_and_tag(dev, input, output, length, iv, iv_len, aad, aad_len, tag, tag_len);
	} else {
		__aes_sync_ccm_decrypt_and_tag(dev, input, output, length, iv, iv_len, aad, aad_len, tag, tag_len);
	}

	return ERR_NONE;
}
