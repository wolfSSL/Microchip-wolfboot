/* sleep.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Minimal Xilinx-compatible <sleep.h> shim for the board-supplied
 * psu_init_gpl.c. Implemented in hal/zynqmp_psu_shim.c using the ARMv8
 * generic timer (CNTPCT/CNTFRQ), matching how the Xilinx FSBL provides
 * usleep()/sleep() during early init. */

#ifndef WOLFBOOT_ZYNQMP_SLEEP_H
#define WOLFBOOT_ZYNQMP_SLEEP_H

void usleep(unsigned long useconds);
unsigned int sleep(unsigned int seconds);

#endif /* WOLFBOOT_ZYNQMP_SLEEP_H */
