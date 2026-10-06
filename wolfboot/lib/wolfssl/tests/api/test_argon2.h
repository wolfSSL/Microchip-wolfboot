/* test_argon2.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ARGON2_H
#define WOLFCRYPT_TEST_ARGON2_H

#include <tests/api/api_decl.h>

int test_wc_Argon2_rfc9106(void);
int test_wc_Argon2_long_tag(void);
int test_wc_Argon2_params(void);
int test_wc_Argon2_variants_differ(void);
int test_wc_Argon2_badargs(void);
int test_wc_Argon2Init(void);
int test_wc_Argon2New(void);
int test_wc_Argon2SetParams(void);
int test_wc_Argon2DeriveTag(void);
int test_wc_Argon2SetThreads(void);

#define TEST_ARGON2_DECLS                                       \
    TEST_DECL_GROUP("argon2", test_wc_Argon2_rfc9106),          \
    TEST_DECL_GROUP("argon2", test_wc_Argon2_long_tag),         \
    TEST_DECL_GROUP("argon2", test_wc_Argon2_params),           \
    TEST_DECL_GROUP("argon2", test_wc_Argon2_variants_differ),  \
    TEST_DECL_GROUP("argon2", test_wc_Argon2_badargs),          \
    TEST_DECL_GROUP("argon2", test_wc_Argon2Init),              \
    TEST_DECL_GROUP("argon2", test_wc_Argon2New),               \
    TEST_DECL_GROUP("argon2", test_wc_Argon2SetParams),         \
    TEST_DECL_GROUP("argon2", test_wc_Argon2DeriveTag),         \
    TEST_DECL_GROUP("argon2", test_wc_Argon2SetThreads)

#endif /* WOLFCRYPT_TEST_ARGON2_H */
