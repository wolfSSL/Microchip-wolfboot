/* test_keystore.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLFCRYPT_TEST_KEYSTORE_H
#define WOLFCRYPT_TEST_KEYSTORE_H

#include <tests/api/api_decl.h>

int test_wc_KeyStore_ImportPlain(void);
int test_wc_KeyStore_ExportPlain(void);
int test_wc_KeyStore_ImportWrapped(void);
int test_wc_KeyStore_ExportWrapped(void);
int test_wc_KeyStore_Derive(void);
int test_wc_KeyStore_Delete(void);
int test_wc_KeyStore_GetInfo(void);
int test_wc_KeyStore_NoDevice(void);

/* Defined unconditionally, like TEST_SRP_DECLS and TEST_ASYNC_DECLS: each test
 * body compiles to a skip when the feature is off, so the entries are always
 * listed and always reported. TEST_SHE_CB_DECLS takes the conditional route
 * instead, which keeps them out of the listing entirely. */
#define TEST_KEYSTORE_DECLS                                              \
    TEST_DECL_GROUP("keystore", test_wc_KeyStore_ImportPlain),           \
    TEST_DECL_GROUP("keystore", test_wc_KeyStore_ExportPlain),           \
    TEST_DECL_GROUP("keystore", test_wc_KeyStore_ImportWrapped),         \
    TEST_DECL_GROUP("keystore", test_wc_KeyStore_ExportWrapped),         \
    TEST_DECL_GROUP("keystore", test_wc_KeyStore_Derive),                \
    TEST_DECL_GROUP("keystore", test_wc_KeyStore_Delete),                \
    TEST_DECL_GROUP("keystore", test_wc_KeyStore_GetInfo),               \
    TEST_DECL_GROUP("keystore", test_wc_KeyStore_NoDevice)

#endif /* WOLFCRYPT_TEST_KEYSTORE_H */
