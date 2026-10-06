/* asu_util.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Shared helpers for the ASU port: waiting on a request and cache handling. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_UTIL_H
#define WOLFSSL_VERSAL_GEN2_ASU_UTIL_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_VERSAL_GEN2_ASU

#include <wolfssl/wolfcrypt/types.h>
#include "xasu_client.h"
#include <wolfssl/wolfcrypt/port/xilinx/versal_gen2_asu/asu_compat.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Debug print to show work going through the ASU. Turn it on with
 * WOLFSSL_VERSAL_GEN2_ASU_DEBUG in user_settings.h. */
#ifdef WOLFSSL_VERSAL_GEN2_ASU_DEBUG
    #include "xil_printf.h"
    #define WC_ASU_PRINTF(...) xil_printf(__VA_ARGS__)
#else
    #define WC_ASU_PRINTF(...) ((void)0)
#endif

/* One record per request. The handler fills it in and the caller waits for
 * Done to be set. */
typedef struct AsuWait {
    volatile byte   Done;   /* set once the handler has run */
    volatile word32 Status; /* status the handler saved */
} AsuWait;

#ifndef WOLFSSL_VERSAL_GEN2_ASU_NO_CLIENT_INIT
/* Open the IPI mailbox and bring the ASU client up on it. 0 or WC_HW_E. */
WOLFSSL_LOCAL int wc_AsuClientInit(void);
#endif

/* Set up the wait record and point the params at the handler. */
WOLFSSL_LOCAL void wc_AsuWaitPrepare(AsuWait* wait, XAsu_ClientParams* params);

/* Wait for the request to finish and return its status. */
WOLFSSL_LOCAL word32 wc_AsuWaitDone(AsuWait* wait);

/* Push a buffer out to memory so the ASU sees the newest data. */
WOLFSSL_LOCAL void wc_AsuCacheFlush(const void* addr, word32 len);

/* Reload a buffer so the CPU sees what the ASU wrote. */
WOLFSSL_LOCAL void wc_AsuCacheInvalidate(void* addr, word32 len);


/* ----------------------------------------------------------------------- */
/* Transaction and concurrency (ticketing)                                 */
/* ----------------------------------------------------------------------- */
/* Fills in a request and queues it. Called with the lock held, so it must
 * only queue the request and never wait. */
typedef int (*AsuSubmitFn)(XAsu_ClientParams* params, void* ctx);

/* Run one ASU operation and return its status. additionalStatus, when given,
 * receives the extra status field used by things like the GCM tag check. */
WOLFSSL_LOCAL word32 wc_AsuTransact(AsuSubmitFn submit, void* ctx,
    word32* additionalStatus);


/* ----------------------------------------------------------------------- */
/* Timer and RTC (optional, for benchmarking)                              */
/* ----------------------------------------------------------------------- */
/* All of this is gated by WOLFSSL_VERSAL_GEN2_ASU_RTC, so it disappears in a
 * build that does not benchmark. */
#ifdef WOLFSSL_VERSAL_GEN2_ASU_RTC

/* Bring up the time source. Returns 0 on success. */
WOLFSSL_LOCAL int wc_AsuTimerInit(void);

/* Raw monotonic count from the generic timer. */
WOLFSSL_LOCAL word64 wc_AsuTimerCount(void);

/* Seconds from the timer, which is what the benchmark reports. */
WOLFSSL_LOCAL double wc_AsuTimerSeconds(void);

/* Wall clock seconds. Only good to one second, so use it for timestamps. */
WOLFSSL_LOCAL word32 wc_AsuRtcSeconds(void);

#endif /* WOLFSSL_VERSAL_GEN2_ASU_RTC */

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_VERSAL_GEN2_ASU */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_UTIL_H */
