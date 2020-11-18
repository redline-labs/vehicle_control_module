/**
 * \file
 *
 * \brief GMAC (Ethernet MAC) driver for SAM.
 *
 * Copyright (c) 2013-2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef GMAC_HANDLER_H_
#define GMAC_HANDLER_H_

#include <gmac.h>

/* 1536 bytes is more than needed, 1524 would be enough.
 * But 1536 is a multiple of 32, which gives a great alignment for
 * cached memories. */

#define NETWORK_BUFFER_SIZE    1536

/**
* GMAC driver structure.
*/
typedef struct gmac_device
{
    /** Pointer to HW register base */
    Gmac * p_hw;

    /**
     * Pointer to allocated TX buffer.
     * Section 3.6 of AMBA 2.0 spec states that burst should not cross
     * 1K Boundaries.
     * Receive buffer manager writes are burst of 2 words => 3 lsb bits
     * of the address shall be set to 0.
     */
    /** RX index for current processing TD */
    uint32_t ul_rx_idx;
    /** Circular buffer head pointer by upper layer (buffer to be sent) */
    int32_t l_tx_head;
    /** Circular buffer tail pointer incremented by handlers (buffer sent) */
    int32_t l_tx_tail;

    /** Number of free TD before wakeup callback is invoked */
    uint32_t ul_wakeup_threshold;
} gmac_device_t;

/* Get and set DMA Configuration Register */
static inline void gmac_set_dma(Gmac* p_gmac, uint32_t ul_cfg)
{
    p_gmac->GMAC_DCFGR = ul_cfg;
}

static inline uint32_t gmac_get_dma(Gmac* p_gmac)
{
    return p_gmac->GMAC_DCFGR;
}

uint8_t gmac_wait_phy(Gmac * p_gmac, const uint32_t ul_retry);

void gmac_dev_init(Gmac * p_gmac, gmac_device_t * p_gmac_dev);
uint32_t gmac_dev_read(gmac_device_t* p_gmac_dev, uint8_t* p_frame, uint32_t ul_frame_size, uint32_t* p_rcv_size,
    uint8_t** pp_recv_frame );
uint32_t gmac_dev_write(gmac_device_t * p_gmac_dev, void * p_buffer, uint32_t ul_size);
uint32_t gmac_dev_get_tx_load(gmac_device_t * p_gmac_dev);

void gmac_dev_reset(gmac_device_t * p_gmac_dev);

void gmac_reset_tx_mem(gmac_device_t * p_dev);

void gmac_dev_halt(Gmac * p_gmac);

void gmac_handler( gmac_device_t * p_gmac_dev, BaseType_t* task_switch_required);

#endif /* GMAC_HANDLER_H_ */
