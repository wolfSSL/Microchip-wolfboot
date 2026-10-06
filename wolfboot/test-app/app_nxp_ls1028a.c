/* app_nxp_ls1028a.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <stdint.h>
#include "wolfboot/wolfboot.h"
#include "printf.h"

#ifdef ENABLE_WOLFIP
#include "wolfip_tftp_test.h"
#endif

#if defined(WOLFCRYPT_TEST) || defined(WOLFCRYPT_BENCHMARK)
#include <wolfssl/wolfcrypt/settings.h>
#endif
#ifdef WOLFCRYPT_TEST
#include <wolfcrypt/test/test.h>
int wolfcrypt_test(void *args);
#endif
#ifdef WOLFCRYPT_BENCHMARK
#include <wolfcrypt/benchmark/benchmark.h>
int benchmark_test(void *args);
#endif

/* UART is up from wolfBoot hal_init; wolfBoot_printf() routes to it (no-op
 * when DEBUG_UART=0). */
__attribute__((section(".boot")))
void main(void)
{
    /* App BSS lives in uninitialized DDR (no crt0 startup), so zero it. */
    extern char _start_bss[], _end_bss[];
    char *p;

    for (p = _start_bss; p < _end_bss; p++)
        *p = 0;

    wolfBoot_printf("Test App\r\n");

#if defined(WOLFCRYPT_TEST) || defined(WOLFCRYPT_BENCHMARK)
    wolfCrypt_Init();
#ifdef WOLFCRYPT_TEST
    wolfBoot_printf("\r\nRunning wolfCrypt tests...\r\n");
    wolfcrypt_test(NULL);
    wolfBoot_printf("Tests complete.\r\n");
#endif
#ifdef WOLFCRYPT_BENCHMARK
    wolfBoot_printf("\r\nRunning wolfCrypt benchmarks...\r\n");
    benchmark_test(NULL);
    wolfBoot_printf("Benchmarks complete.\r\n");
#endif
    wolfCrypt_Cleanup();
#endif

#ifdef ENABLE_WOLFIP
    wolfip_tftp_test_report();
#endif

    wolfBoot_printf("Test App: idle\r\n");
    while (1)
        ;
}
