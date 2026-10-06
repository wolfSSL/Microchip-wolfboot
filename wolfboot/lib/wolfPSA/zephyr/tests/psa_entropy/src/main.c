/* main.c - wolfPSA entropy smoke test
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
 * Verifies the PSA RNG works end-to-end: psa_generate_random() succeeds, which
 * means wolfCrypt's Hash-DRBG got a valid seed. On Zephyr that seed comes from
 * the hardware entropy driver via wc_GenerateSeed() (see the wolfSSL module's
 * wolfcrypt/src/random.c); wolfPSA registers no seed callback of its own.
 *
 * The dead-entropy -> PSA_ERROR_INSUFFICIENT_ENTROPY mapping is a
 * wolfCrypt-internal contract (wc_GenerateSeed() error -> wc_InitRng() fails ->
 * wc_error_to_psa_status()) covered by wolfCrypt's own tests; it is no longer
 * driven from here now that the injectable seed callback is gone.
 */

#include <zephyr/ztest.h>
#include <psa/crypto.h>

ZTEST(wolfpsa_entropy, test_psa_generate_random_succeeds)
{
	uint8_t buf[32];
	psa_status_t status;

	zassert_equal(psa_crypto_init(), PSA_SUCCESS);

	/* Each psa_generate_random() seeds a fresh WC_RNG via wc_GenerateSeed(), so
	 * PSA_SUCCESS proves the entropy-driver seed path works end-to-end. */
	status = psa_generate_random(buf, sizeof(buf));
	zassert_equal(status, PSA_SUCCESS,
		      "psa_generate_random failed to seed: %d", (int)status);
}

ZTEST_SUITE(wolfpsa_entropy, NULL, NULL, NULL, NULL, NULL);
