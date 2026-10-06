/* test_wc_encrypt.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_WC_ENCRYPT_H
#define WOLFCRYPT_TEST_WC_ENCRYPT_H

#include <tests/api/api_decl.h>

int test_wc_Des3_CbcEncryptDecryptWithKey(void);
int test_wc_Des_CbcEncryptDecryptWithKey(void);
int test_wc_AesCbcEncryptDecryptWithKey(void);
int test_wc_BufferKeyEncryptDecryptDecisionCoverage(void);
int test_wc_BufferKeyEncryptDecryptUnknownCipher(void);

#define TEST_WC_ENCRYPT_DECLS                                                   \
    TEST_DECL_GROUP("wc_encrypt", test_wc_Des3_CbcEncryptDecryptWithKey),       \
    TEST_DECL_GROUP("wc_encrypt", test_wc_Des_CbcEncryptDecryptWithKey),        \
    TEST_DECL_GROUP("wc_encrypt", test_wc_AesCbcEncryptDecryptWithKey),         \
    TEST_DECL_GROUP("wc_encrypt",                                               \
        test_wc_BufferKeyEncryptDecryptDecisionCoverage),                       \
    TEST_DECL_GROUP("wc_encrypt",                                               \
        test_wc_BufferKeyEncryptDecryptUnknownCipher)

#endif /* WOLFCRYPT_TEST_WC_ENCRYPT_H */
