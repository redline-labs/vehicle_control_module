/**
 * \file
 *
 * \brief Syscalls for SAM (GCC).
 *
 * Copyright (c) 2011-2018 Microchip Technology Inc. and its subsidiaries.
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
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <stdio.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#undef errno
extern int errno;
extern int _end;
extern int __ram_end__;

extern caddr_t _sbrk(int incr);
extern int link(char* old, char* new);
extern int _link(char* old, char* new);
extern int _unlink(const char* pathname);
extern int _open(int file);
extern int _close(int file);
extern int _fstat(int file, struct stat *st);
extern int _isatty(int file);
extern int _lseek(int file, int ptr, int dir);
extern void _exit(int status);
extern void _kill(int pid, int sig);
extern int _getpid(void);
extern int _times(struct tms* buf);
extern int _gettimeofday(struct timeval *tv, struct timezone* tz);

extern caddr_t _sbrk(int incr)
{
	static unsigned char *heap = NULL;
	unsigned char *prev_heap;
	int ramend = (int)&__ram_end__;

	if (heap == NULL) {
		heap = (unsigned char *)&_end;
	}
	prev_heap = heap;

	if (((int)prev_heap + incr) > ramend) {
		return (caddr_t) -1;
	}

	heap += incr;

	return (caddr_t) prev_heap;
}

extern int link(char* old, char* new)
{
    (void)old;
    (void)new;
	return -1;
}

extern int _link(char* old, char* new)
{
    (void)old;
    (void)new;
	return -1;
}


extern int _unlink(const char* pathname)
{
    (void)pathname;
	return -1;
}

extern int _open(int file)
{
    (void)file;
	return -1;
}

extern int _close(int file)
{
    (void)file;
	return -1;
}

extern int _fstat(int file, struct stat* st)
{
    (void)file;
    (void)st;
	st->st_mode = S_IFCHR;

	return 0;
}

extern int _isatty(int file)
{
    (void)file;
	return 1;
}

extern int _lseek(int file, int ptr, int dir)
{
    (void)file;
    (void)ptr;
    (void)dir;
	return 0;
}

extern void _exit(int status)
{
    (void)status;
	asm("BKPT #0");
	for (;;);
}

extern void _kill(int pid, int sig)
{
    (void)pid;
    (void)sig;
	return;
}

extern int _getpid(void)
{
	return -1;
}

extern int _times(struct tms* buf)
{
    (void)buf;
	return -1;
}

extern int _gettimeofday(struct timeval* tv, struct timezone* tz)
{
    (void)tv;
    (void)tz;
    int ret = -1;
    /*uint64_t ticks_since_start = xTaskGetTickCount();

    if (nullptr != tv)
    {
        tv->tv_sec = ticks_since_start / configTICK_RATE_HZ;
        tv->tv_usec = ( ticks_since_start % configTICK_RATE_HZ ) / 1000;

        ret = 0;
    }*/

    return ret;
}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
