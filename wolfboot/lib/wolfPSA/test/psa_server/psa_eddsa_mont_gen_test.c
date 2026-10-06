/* psa_eddsa_mont_gen_test.c
 *
 * Regression test: psa_generate_key() used to guard the whole
 * ECC key-pair branch on HAVE_ECC, so standalone Ed25519/Ed448/X25519/X448
 * key generation returned PSA_ERROR_NOT_SUPPORTED in builds that compile
 * the EdDSA/Montgomery backends without generic Weierstrass ECC.
 *
 * The defect only manifests in a build without HAVE_ECC, so this test is
 * the configuration-independent half of the pair: it asserts that the four
 * standalone families generate successfully whenever their backends are
 * compiled in (always true for the default build, and the assertion that
 * failed before the fix in a HAVE_ECC-off build).
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

#include <psa/crypto.h>

static int test_generate_family(psa_ecc_family_t family, psa_key_bits_t bits,
                                const char* label)
{
    psa_key_attributes_t attrs = psa_key_attributes_init();
    psa_key_attributes_t got = psa_key_attributes_init();
    psa_key_id_t key_id = PSA_KEY_ID_NULL;
    psa_key_type_t key_type;
    psa_status_t st;
    int ok = 0;

    key_type = PSA_KEY_TYPE_ECC_KEY_PAIR(family);

    psa_set_key_type(&attrs, key_type);
    psa_set_key_bits(&attrs, bits);
    psa_set_key_usage_flags(&attrs, PSA_KEY_USAGE_EXPORT);
    psa_set_key_lifetime(&attrs, PSA_KEY_LIFETIME_VOLATILE);

    st = psa_generate_key(&attrs, &key_id);
    if (st != PSA_SUCCESS) {
        printf("FAIL %s generate status=%d (want SUCCESS)\n", label,
               (int)st);
        goto out;
    }

    st = psa_get_key_attributes(key_id, &got);
    if (st != PSA_SUCCESS) {
        printf("FAIL %s attrs status=%d\n", label, (int)st);
        goto destroy;
    }

    if (psa_get_key_type(&got) != key_type) {
        printf("FAIL %s type=0x%08x expected=0x%08x\n", label,
               (unsigned)psa_get_key_type(&got), (unsigned)key_type);
        goto destroy;
    }

    if (psa_get_key_bits(&got) != bits) {
        printf("FAIL %s bits=%u expected=%u\n", label,
               (unsigned)psa_get_key_bits(&got), (unsigned)bits);
        goto destroy;
    }

    ok = 1;

destroy:
    (void)psa_destroy_key(key_id);

out:
    return ok ? 0 : 1;
}

static int test_invalid_bits_rejected(void)
{
    psa_key_attributes_t attrs = psa_key_attributes_init();
    psa_key_id_t key_id = PSA_KEY_ID_NULL;
    psa_status_t st;
    int ok = 0;

    /* No Twisted-Edwards curve with 256 bits: must fail with
     * INVALID_ARGUMENT regardless of which backends are compiled. */
    psa_set_key_type(&attrs,
        PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_TWISTED_EDWARDS));
    psa_set_key_bits(&attrs, 256);
    psa_set_key_usage_flags(&attrs, PSA_KEY_USAGE_EXPORT);
    psa_set_key_lifetime(&attrs, PSA_KEY_LIFETIME_VOLATILE);

    st = psa_generate_key(&attrs, &key_id);
    if (st == PSA_SUCCESS) {
        printf("FAIL ed255/ed448-256 generated, want INVALID_ARGUMENT\n");
        (void)psa_destroy_key(key_id);
        goto out;
    }
    if (st != PSA_ERROR_INVALID_ARGUMENT &&
        st != PSA_ERROR_NOT_SUPPORTED) {
        printf("FAIL ed255/ed448-256 status=%d (want INVALID_ARGUMENT "
               "or NOT_SUPPORTED)\n", (int)st);
        goto out;
    }

    ok = 1;

out:
    return ok ? 0 : 1;
}

int main(void)
{
    int rc = 0;

    if (psa_crypto_init() != PSA_SUCCESS) {
        printf("FAIL psa_crypto_init\n");
        return 1;
    }

    rc |= test_generate_family(PSA_ECC_FAMILY_TWISTED_EDWARDS, 255,
                               "ed25519");
    rc |= test_generate_family(PSA_ECC_FAMILY_TWISTED_EDWARDS, 448,
                               "ed448");
    rc |= test_generate_family(PSA_ECC_FAMILY_MONTGOMERY, 255, "x25519");
    rc |= test_generate_family(PSA_ECC_FAMILY_MONTGOMERY, 448, "x448");
    rc |= test_invalid_bits_rejected();

    if (rc != 0) {
        printf("PSA eccguard gen test: FAIL\n");
        return 1;
    }

    printf("PSA eccguard gen test: OK\n");
    return 0;
}
