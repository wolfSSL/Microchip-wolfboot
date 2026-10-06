/* psa_crypto.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include "psa_config.h"

#if defined(WOLFSSL_PSA_ENGINE)

#include <psa/crypto.h>
#include "psa_trace.h"
#include "psa_lock.h"
#include <wolfpsa/psa_engine.h>
#include <wolfssl/wolfcrypt/wc_port.h>

/* Init latch. psa_crypto_init() must complete single-threaded (per the PSA
 * contract) before any concurrent PSA use: the mutex-creation bootstrap in
 * wolfpsa_lock_ensure_init() is a plain, non-atomic flag guard. Once the lock
 * is established, this latch serializes subsequent calls so wolfCrypt_Init()
 * runs exactly once, and the read below takes the same lock so it is not a
 * data race with that write. */
static int g_psa_crypto_initialized = 0;

int wolfPSA_CryptoIsInitialized(void)
{
    int initialized;

    if (WOLFPSA_LOCK_INIT() != 0) {
        return 0;
    }

    WOLFPSA_LOCK();
    initialized = g_psa_crypto_initialized;
    WOLFPSA_UNLOCK();

    return initialized;
}

psa_status_t psa_crypto_init(void)
{
    int ret = 0;
    psa_status_t status = PSA_SUCCESS;

    wolfpsa_trace("psa_crypto_init()");

    /* Create the key-store mutex before any WOLFPSA_LOCK() runs. This is the
     * platform-neutral init point: the PSA contract requires psa_crypto_init()
     * before any other PSA call, so a bare (non-Zephyr) build lands here just as
     * Zephyr's boot glue does. The init is idempotent, so repeated calls (or an
     * additional platform bootstrap) are harmless. */
    if (WOLFPSA_LOCK_INIT() != 0) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    WOLFPSA_LOCK();
    if (!g_psa_crypto_initialized) {
        ret = wolfCrypt_Init();
        if (ret != 0) {
            status = wc_error_to_psa_status(ret);
        }
        else {
            g_psa_crypto_initialized = 1;
        }
    }
    WOLFPSA_UNLOCK();

    return status;
}

#endif /* WOLFSSL_PSA_ENGINE */
