/* test_puf_whitebox.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*
 * MC/DC white-box supplement for wolfcrypt/src/puf.c on the m33mu lane.
 *
 * LANE CONTRACT: the m33mu lane instruments puf.c as its own clang TU and
 * links it into a firmware whose fixed entry is the wolfcrypt KAT suite. It
 * offers no per-module main() and no #include-and-trim, so this rides as a
 * lane_extra_source: compiled by the firmware's gcc (NOT instrumented), it
 * accumulates into puf.c's already-instrumented counters through real calls to
 * that module's public entry points. The driver runs from a
 * __attribute__((constructor)) -- Reset_Handler calls __libc_init_array()
 * before main(), and target.ld KEEP()s .init_array so -gc-sections cannot drop
 * it. See test_sp_cortexm_whitebox.c for the same arrangement.
 *
 * WHAT IT ADDS over puf_test(): the KAT drives enroll / reconstruct / derive /
 * identity / zeroize with well-formed arguments, so every entry guard of the
 * form
 *
 *     if (ctx == NULL || <other> == NULL)
 *
 * is only ever seen all-false. Each operand needs its own true row against
 * that shared all-false partner, so both are issued here per guard.
 *
 * Crash-safety: the guards return BAD_FUNC_ARG before touching any state, and
 * the local context is separate from the one the KAT builds later, so nothing
 * here can perturb the KAT that streams the profile out. No result is
 * asserted; a return value only bumps a local counter.
 */

#include <wolfssl/wolfcrypt/settings.h>

#if defined(WOLFSSL_PUF) && defined(WOLFSSL_PUF_TEST)

#include <wolfssl/wolfcrypt/puf.h>
#include <wolfssl/wolfcrypt/types.h>

/* Kept off the constructor's stack: the MCU boot stack is small. */
static wc_PufCtx wb_ctx;
static byte      wb_buf[WC_PUF_KEY_SZ];
static int       wb_calls;

__attribute__((constructor))
static void puf_whitebox_drive(void)
{
    /* A context of our own; the KAT builds its own later. */
    if (wc_PufInit(&wb_ctx) != 0) {
        return;
    }

    /* wc_PufReadSram: ctx == NULL || sramAddr == NULL */
    wb_calls += (wc_PufReadSram(NULL, wb_buf, (word32)sizeof(wb_buf)) != 0);
    wb_calls += (wc_PufReadSram(&wb_ctx, NULL, (word32)sizeof(wb_buf)) != 0);

    /* wc_PufReconstruct: ctx == NULL || helperData == NULL */
    wb_calls += (wc_PufReconstruct(NULL, wb_buf, (word32)sizeof(wb_buf)) != 0);
    wb_calls += (wc_PufReconstruct(&wb_ctx, NULL, (word32)sizeof(wb_buf)) != 0);

    /* wc_PufDeriveKey: ctx == NULL || key == NULL */
    wb_calls += (wc_PufDeriveKey(NULL, wb_buf, (word32)sizeof(wb_buf),
                                 wb_buf, (word32)sizeof(wb_buf)) != 0);
    wb_calls += (wc_PufDeriveKey(&wb_ctx, wb_buf, (word32)sizeof(wb_buf),
                                 NULL, (word32)sizeof(wb_buf)) != 0);

    /* wc_PufGetIdentity: ctx == NULL || id == NULL */
    wb_calls += (wc_PufGetIdentity(NULL, wb_buf, (word32)sizeof(wb_buf)) != 0);
    wb_calls += (wc_PufGetIdentity(&wb_ctx, NULL, (word32)sizeof(wb_buf)) != 0);

    /* wc_PufSetTestData: ctx == NULL || data == NULL */
    wb_calls += (wc_PufSetTestData(NULL, wb_buf, (word32)sizeof(wb_buf)) != 0);
    wb_calls += (wc_PufSetTestData(&wb_ctx, NULL, (word32)sizeof(wb_buf)) != 0);

    /* wc_PufGetParams: the all-NULL rejection is a five-operand chain, so each
     * operand needs the vector where it alone is non-NULL. */
    {
        int v;

        wb_calls += (wc_PufGetParams(NULL, NULL, NULL, NULL, NULL) != 0);
        wb_calls += (wc_PufGetParams(&v, NULL, NULL, NULL, NULL) == 0);
        wb_calls += (wc_PufGetParams(NULL, &v, NULL, NULL, NULL) == 0);
        wb_calls += (wc_PufGetParams(NULL, NULL, &v, NULL, NULL) == 0);
        wb_calls += (wc_PufGetParams(NULL, NULL, NULL, &v, NULL) == 0);
        wb_calls += (wc_PufGetParams(NULL, NULL, NULL, NULL, &v) == 0);
    }

    /* wc_PufGetHelperData: ctx == NULL || helper == NULL */
    wb_calls += (wc_PufGetHelperData(NULL, wb_buf,
                                     (word32)sizeof(wb_buf)) != 0);
    wb_calls += (wc_PufGetHelperData(&wb_ctx, NULL,
                                     (word32)sizeof(wb_buf)) != 0);

    (void)wc_PufZeroize(&wb_ctx);
}

#else

/* PUF not selected by this config: empty TU. */
typedef int puf_whitebox_not_configured;

#endif /* WOLFSSL_PUF && WOLFSSL_PUF_TEST */
