/* app_mpfs250.c
 *
 * Test bare-metal application for PolarFire SoC MPFS250.
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "hal.h"
#include "wolfboot/wolfboot.h"
#include "target.h"
#include "printf.h"

#include "../hal/mpfs250.h"

/* wolfCrypt test/benchmark support */
#ifdef WOLFCRYPT_TEST
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfcrypt/test/test.h>
int wolfcrypt_test(void *args);
#endif

#ifdef WOLFCRYPT_BENCHMARK
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfcrypt/benchmark/benchmark.h>
int benchmark_test(void *args);
#endif


void main(void)
{
    /* wolfBoot fully configured UART0 before jumping here.
     * Calling uart_init() again clears the TX FIFO (FCR write) while wolfBoot's
     * last output may still be draining, which can leave THRE stuck at 0.
     * Calling hal_init() writes to _main_hart_hls=0 (NULL ptr crash).
     * So use wolfBoot_printf directly — UART0 is already ready. */

    wolfBoot_printf("========================\r\n");
    wolfBoot_printf("PolarFire SoC MPFS250 wolfBoot demo Application\r\n");
    wolfBoot_printf("Copyright 2025 wolfSSL Inc\r\n");
    wolfBoot_printf("GPL v3\r\n");
    wolfBoot_printf("========================\r\n");

#ifdef WOLFCRYPT_TEST
    wolfBoot_printf("\r\nRunning wolfCrypt tests...\r\n");
    wolfCrypt_Init();
    wolfcrypt_test(NULL);
    wolfCrypt_Cleanup();
    wolfBoot_printf("Tests complete.\r\n\r\n");
#endif

#ifdef WOLFCRYPT_BENCHMARK
    wolfBoot_printf("Running wolfCrypt benchmarks...\r\n");
    wolfCrypt_Init();
    benchmark_test(NULL);
    wolfCrypt_Cleanup();
    wolfBoot_printf("Benchmarks complete.\r\n\r\n");
#endif

    while(1) {
        /* Main application loop */
        /* TODO: Add watchdog feed if needed */
    }
}

