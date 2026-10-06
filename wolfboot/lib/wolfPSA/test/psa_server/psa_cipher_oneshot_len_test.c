/* psa_cipher_oneshot_len_test.c
 *
 * Regression test: psa_cipher_encrypt() and
 * psa_cipher_decrypt() never validated output_length and wrote through
 * it after completing the cryptographic operation, so a call with
 * output_length == NULL crashed on the final write. psa_cipher_encrypt()
 * also never validated output itself: with a generated-IV algorithm
 * and output == NULL it reached the IV copy and crashed.
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

int main(void)
{
    psa_key_attributes_t attrs = psa_key_attributes_init();
    psa_key_id_t key_id = PSA_KEY_ID_NULL;
    uint8_t plain[16];
    uint8_t ct[64];
    uint8_t pt[64];
    uint8_t ct_in[32];
    size_t ct_len = 0;
    size_t pt_len = 0;
    psa_status_t st;
    int i;
    int rc = 0;

    if (psa_crypto_init() != PSA_SUCCESS) {
        printf("FAIL psa_crypto_init\n");
        return 1;
    }

    psa_set_key_type(&attrs, PSA_KEY_TYPE_AES);
    psa_set_key_bits(&attrs, 128);
    psa_set_key_usage_flags(&attrs, PSA_KEY_USAGE_ENCRYPT |
                            PSA_KEY_USAGE_DECRYPT);
    psa_set_key_algorithm(&attrs, PSA_ALG_CBC_NO_PADDING);
    psa_set_key_lifetime(&attrs, PSA_KEY_LIFETIME_VOLATILE);
    if (psa_generate_key(&attrs, &key_id) != PSA_SUCCESS) {
        printf("FAIL generate_key\n");
        return 1;
    }

    for (i = 0; i < (int)sizeof(plain); i++) {
        plain[i] = (uint8_t)(i + 10);
    }
    for (i = 0; i < (int)sizeof(ct_in); i++) {
        ct_in[i] = (uint8_t)(i + 1);
    }

    /* NULL output_length must be rejected before any processing.
     * Pre-fix the call completed the encryption and crashed on the
     * final write. */
    st = psa_cipher_encrypt(key_id, PSA_ALG_CBC_NO_PADDING, plain, 16,
                            ct, sizeof(ct), NULL);
    if (st != PSA_ERROR_INVALID_ARGUMENT) {
        printf("FAIL encrypt NULL outlen: status=%d\n", (int)st);
        rc = 1;
    }

    st = psa_cipher_decrypt(key_id, PSA_ALG_CBC_NO_PADDING, plain, 16,
                            pt, sizeof(pt), NULL);
    if (st != PSA_ERROR_INVALID_ARGUMENT) {
        printf("FAIL decrypt NULL outlen: status=%d\n", (int)st);
        rc = 1;
    }

    /* NULL output with a non-zero output_size must be rejected before
     * the IV is written to it. Pre-fix the encrypt path reached the IV
     * copy and crashed. Decrypt carries the same explicit guard; the
     * input is a full IV plus block (longer than the IV) so the call
     * exercises the real update path, not the zero-byte edge. */
    st = psa_cipher_encrypt(key_id, PSA_ALG_CBC_NO_PADDING, plain, 16,
                            NULL, sizeof(ct), &ct_len);
    if (st != PSA_ERROR_INVALID_ARGUMENT) {
        printf("FAIL encrypt NULL output: status=%d\n", (int)st);
        rc = 1;
    }

    st = psa_cipher_decrypt(key_id, PSA_ALG_CBC_NO_PADDING, ct_in,
                            sizeof(ct_in), NULL, sizeof(pt), &pt_len);
    if (st != PSA_ERROR_INVALID_ARGUMENT) {
        printf("FAIL decrypt NULL output: status=%d\n", (int)st);
        rc = 1;
    }

    /* NULL input with a non-zero input_length must be rejected too.
     * psa_cipher_encrypt() only ever touches the input through
     * psa_cipher_update(), which guards it; psa_cipher_decrypt()
     * copies the IV prefix out of the input first, so without its own
     * guard this call dereferenced NULL. */
    st = psa_cipher_encrypt(key_id, PSA_ALG_CBC_NO_PADDING, NULL,
                            sizeof(ct_in), ct, sizeof(ct), &ct_len);
    if (st != PSA_ERROR_INVALID_ARGUMENT) {
        printf("FAIL encrypt NULL input: status=%d\n", (int)st);
        rc = 1;
    }

    st = psa_cipher_decrypt(key_id, PSA_ALG_CBC_NO_PADDING, NULL,
                            sizeof(ct_in), pt, sizeof(pt), &pt_len);
    if (st != PSA_ERROR_INVALID_ARGUMENT) {
        printf("FAIL decrypt NULL input: status=%d\n", (int)st);
        rc = 1;
    }

    /* Controls: a normal one-shot roundtrip still works. */
    st = psa_cipher_encrypt(key_id, PSA_ALG_CBC_NO_PADDING, plain, 16,
                            ct, sizeof(ct), &ct_len);
    if (st != PSA_SUCCESS || ct_len != 32) {
        printf("FAIL control encrypt status=%d len=%u\n", (int)st,
               (unsigned)ct_len);
        rc = 1;
    }
    if (rc == 0) {
        st = psa_cipher_decrypt(key_id, PSA_ALG_CBC_NO_PADDING, ct,
                                ct_len, pt, sizeof(pt), &pt_len);
        if (st != PSA_SUCCESS || pt_len != 16 ||
            memcmp(pt, plain, 16) != 0) {
            printf("FAIL control decrypt status=%d len=%u\n", (int)st,
                   (unsigned)pt_len);
            rc = 1;
        }
    }

    (void)psa_destroy_key(key_id);

    if (rc != 0) {
        printf("PSA oneshot NULL test: FAIL\n");
        return 1;
    }

    printf("PSA oneshot NULL test: OK\n");
    return 0;
}
