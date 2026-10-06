/* test_async.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ASYNC_H
#define WOLFCRYPT_TEST_ASYNC_H

#include <tests/api/api_decl.h>

int test_wc_CryptoCb_AsyncPollAesGcm(void);
int test_wc_CryptoCb_AsyncPollAesCbc(void);
int test_wc_CryptoCb_AsyncPollAesCcm(void);
int test_wc_CryptoCb_AsyncPollDes3(void);
int test_wc_CryptoCb_AsyncPollUnsupported(void);
int test_wc_CryptoCb_AsyncPollChachaUnimpl(void);
int test_wc_CryptoCb_AsyncPollDesUnimpl(void);
int test_wc_CryptoCb_AsyncPollTlsAesGcm(void);
int test_wc_CryptoCb_AsyncPollTlsChachaNotOffloaded(void);
int test_wc_CryptoCb_AsyncPollTlsNoPollFails(void);
int test_wc_CryptoCb_AsyncPollTlsBothDirections(void);

#define TEST_ASYNC_DECLS                                                \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollAesGcm),         \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollAesCbc),         \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollAesCcm),         \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollDes3),           \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollUnsupported),    \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollChachaUnimpl),   \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollDesUnimpl),      \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollTlsAesGcm),      \
    TEST_DECL_GROUP("async",                                            \
        test_wc_CryptoCb_AsyncPollTlsChachaNotOffloaded),              \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollTlsNoPollFails), \
    TEST_DECL_GROUP("async", test_wc_CryptoCb_AsyncPollTlsBothDirections)

#endif /* WOLFCRYPT_TEST_ASYNC_H */
