/* zephyr_init.c - wolfPSA PSA Crypto provider boot initialisation
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
 * The in-tree mbedtls module only calls psa_crypto_init() when its own
 * CONFIG_MBEDTLS_PSA_CRYPTO_CLIENT is set, so a custom provider must register
 * its own SYS_INIT. psa_crypto_init() runs at POST_KERNEL /
 * CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, matching the mbedtls module so PSA is
 * ready by the time downstream PSA consumers initialise.
 */

#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <psa/crypto.h>

#include <wolfssl/wolfcrypt/settings.h>
#include "psa_lock.h"

/* wolfPSA needs wolfCrypt's Hash-DRBG for its RNG. Fail the build with a clear
 * message if the chosen wolfCrypt config (the module-default Kconfig, or a
 * user-supplied CONFIG_WOLFSSL_SETTINGS_FILE) did not enable it -- rather than
 * silently injecting it via Kconfig on top of the user's settings file. */
#if !defined(HAVE_HASHDRBG)
#error "wolfPSA requires HAVE_HASHDRBG: enable it in your wolfCrypt config " \
       "(the module Kconfig default enables it; a custom " \
       "CONFIG_WOLFSSL_SETTINGS_FILE must define it itself)."
#endif
LOG_MODULE_REGISTER(wolfpsa, CONFIG_WOLFPSA_LOG_LEVEL);

/* The global key-store mutex (WOLFPSA_THREAD_SAFE) is created inside
 * psa_crypto_init() -- the platform-neutral PSA init point -- so it needs no
 * Zephyr-specific bootstrap. The POST_KERNEL wolfpsa_init() below runs
 * psa_crypto_init() at boot, single-threaded, before any consumer's first PSA
 * call, so the lock is ready without an init-time race. */

/* wolfCrypt's DRBG seeding (from the hardware entropy driver when present, else
 * the default) is owned by the wolfSSL module's zephyr_init.c, so wolfPSA no
 * longer registers a seed callback of its own -- it just uses wc_InitRng(). */

static int wolfpsa_init(void)
{
	psa_status_t status = psa_crypto_init();

	if (status != PSA_SUCCESS) {
		LOG_ERR("psa_crypto_init() failed: %d", (int)status);
		return -EIO;
	}

	LOG_DBG("wolfPSA PSA Crypto provider initialised");
	return 0;
}

SYS_INIT(wolfpsa_init, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
