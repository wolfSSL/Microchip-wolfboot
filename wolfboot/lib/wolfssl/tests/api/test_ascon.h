/* test_ascon.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_TEST_ASCON_H
#define TESTS_API_TEST_ASCON_H

#include <tests/api/api_decl.h>

int test_ascon_hash256(void);
int test_ascon_aead128(void);
int test_ascon_aead128_edge_cases(void);
int test_ascon_decision_coverage(void);
int test_ascon_reuse_after_final(void);

#define TEST_ASCON_DECLS                                     \
    TEST_DECL_GROUP("ascon", test_ascon_hash256),            \
    TEST_DECL_GROUP("ascon", test_ascon_aead128),            \
    TEST_DECL_GROUP("ascon", test_ascon_aead128_edge_cases), \
    TEST_DECL_GROUP("ascon", test_ascon_decision_coverage),  \
    TEST_DECL_GROUP("ascon", test_ascon_reuse_after_final)

#endif /* TESTS_API_TEST_ASCON_H */
