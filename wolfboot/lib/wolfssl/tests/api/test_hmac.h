/* test_hmac.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_HMAC_H
#define WOLFCRYPT_TEST_HMAC_H

#include <tests/api/api_decl.h>

int test_wc_Md5HmacSetKey(void);
int test_wc_Md5HmacUpdate(void);
int test_wc_Md5HmacFinal(void);
int test_wc_ShaHmacSetKey(void);
int test_wc_ShaHmacUpdate(void);
int test_wc_ShaHmacFinal(void);
int test_wc_Sha224HmacSetKey(void);
int test_wc_Sha224HmacUpdate(void);
int test_wc_Sha224HmacFinal(void);
int test_wc_Sha256HmacSetKey(void);
int test_wc_Sha256HmacUpdate(void);
int test_wc_Sha256HmacFinal(void);
int test_wc_Sha384HmacSetKey(void);
int test_wc_Sha384HmacUpdate(void);
int test_wc_Sha384HmacFinal(void);
int test_tls_hmac_size_overflow(void);
int test_tls_timing_pad_verify_hmac_len(void);
int test_wc_HmacSizeByType(void);
int test_wc_HmacCopy(void);
int test_wc_HmacInit_Id(void);
int test_wc_HmacInit_Label(void);
int test_wc_HmacFree_CryptoCb(void);
int test_wc_HKDF_NullKeyEdgeCases(void);
int test_wc_Tls13_HKDF_Extract_ZeroLenIkm(void);

#define TEST_HMAC_DECLS                                 \
    TEST_DECL_GROUP("hmac", test_wc_Md5HmacSetKey),     \
    TEST_DECL_GROUP("hmac", test_wc_Md5HmacUpdate),     \
    TEST_DECL_GROUP("hmac", test_wc_Md5HmacFinal),      \
    TEST_DECL_GROUP("hmac", test_wc_ShaHmacSetKey),     \
    TEST_DECL_GROUP("hmac", test_wc_ShaHmacUpdate),     \
    TEST_DECL_GROUP("hmac", test_wc_ShaHmacFinal),      \
    TEST_DECL_GROUP("hmac", test_wc_Sha224HmacSetKey),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha224HmacUpdate),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha224HmacFinal),   \
    TEST_DECL_GROUP("hmac", test_wc_Sha256HmacSetKey),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha256HmacUpdate),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha256HmacFinal),   \
    TEST_DECL_GROUP("hmac", test_wc_Sha384HmacSetKey),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha384HmacUpdate),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha384HmacFinal),   \
    TEST_DECL_GROUP("hmac", test_tls_hmac_size_overflow), \
    TEST_DECL_GROUP("hmac", test_tls_timing_pad_verify_hmac_len), \
    TEST_DECL_GROUP("hmac", test_wc_HmacSizeByType),    \
    TEST_DECL_GROUP("hmac", test_wc_HmacCopy),          \
    TEST_DECL_GROUP("hmac", test_wc_HmacInit_Id),       \
    TEST_DECL_GROUP("hmac", test_wc_HmacInit_Label),    \
    TEST_DECL_GROUP("hmac", test_wc_HmacFree_CryptoCb), \
    TEST_DECL_GROUP("hmac", test_wc_HKDF_NullKeyEdgeCases), \
    TEST_DECL_GROUP("hmac", test_wc_Tls13_HKDF_Extract_ZeroLenIkm)

#endif /* WOLFCRYPT_TEST_HMAC_H */
