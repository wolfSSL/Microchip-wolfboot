/* psa_key_infer_bits_test.c
 *
 * Regression test: wolfpsa_infer_key_bits() computed
 * attr->bits = (psa_key_bits_t)(data_length * 8U) for unstructured key
 * types with no bound check. psa_key_bits_t is 16-bit, so an 8192-byte
 * RAW_DATA/HMAC/etc. import with bits left at 0 recorded 65536 bits
 * truncated to 0, and 8193 bytes recorded 8, both silently accepted.
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
#include <string.h>

#include <psa/crypto.h>

#define WOLFPSA_TEST_MAX_LEN 8193

static int test_boundary(psa_key_type_t type, size_t len,
                         psa_key_bits_t expected_bits,
                         psa_status_t expected_status, const char* label)
{
    psa_key_attributes_t attrs = psa_key_attributes_init();
    psa_key_attributes_t got = psa_key_attributes_init();
    static uint8_t data[WOLFPSA_TEST_MAX_LEN];
    psa_key_id_t key_id = PSA_KEY_ID_NULL;
    psa_status_t st;
    int ok = 0;

    memset(data, 0x5A, sizeof(data));

    psa_set_key_type(&attrs, type);
    psa_set_key_usage_flags(&attrs, PSA_KEY_USAGE_EXPORT);
    psa_set_key_lifetime(&attrs, PSA_KEY_LIFETIME_VOLATILE);

    st = psa_import_key(&attrs, data, len, &key_id);
    if (st != expected_status) {
        printf("FAIL %s status=%d expected=%d\n", label, (int)st,
               (int)expected_status);
        goto out;
    }
    if (expected_status != PSA_SUCCESS) {
        ok = 1;
        goto out;
    }

    st = psa_get_key_attributes(key_id, &got);
    if (st != PSA_SUCCESS) {
        printf("FAIL %s attrs status=%d\n", label, (int)st);
        goto destroy;
    }

    if (psa_get_key_bits(&got) != expected_bits) {
        printf("FAIL %s bits=%u expected=%u\n", label,
               (unsigned)psa_get_key_bits(&got),
               (unsigned)expected_bits);
        goto destroy;
    }

    ok = 1;

destroy:
    (void)psa_destroy_key(key_id);

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

    /* 8191 bytes = 65528 bits: largest representable, must import. */
    rc |= test_boundary(PSA_KEY_TYPE_RAW_DATA, 8191, PSA_MAX_KEY_BITS,
                        PSA_SUCCESS, "raw-8191");

    /* 8192 bytes = 65536 bits: wraps to 0 before the fix, must reject. */
    rc |= test_boundary(PSA_KEY_TYPE_RAW_DATA, 8192, 0,
                        PSA_ERROR_INVALID_ARGUMENT, "raw-8192");

    /* 8193 bytes = 65544 bits: wraps to 8 before the fix, must reject. */
    rc |= test_boundary(PSA_KEY_TYPE_HMAC, 8193, 0,
                        PSA_ERROR_INVALID_ARGUMENT, "hmac-8193");

    if (rc != 0) {
        printf("PSA inferbits test: FAIL\n");
        return 1;
    }

    printf("PSA inferbits test: OK\n");
    return 0;
}
