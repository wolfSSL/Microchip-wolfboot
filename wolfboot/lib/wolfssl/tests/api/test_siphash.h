/* test_siphash.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SIPHASH_H
#define WOLFCRYPT_TEST_SIPHASH_H

#include <tests/api/api_decl.h>

int test_wc_SipHash_DecisionCoverage(void);
int test_wc_SipHash_FeatureCoverage(void);

#define TEST_SIPHASH_DECLS                                        \
    TEST_DECL_GROUP("siphash", test_wc_SipHash_DecisionCoverage), \
    TEST_DECL_GROUP("siphash", test_wc_SipHash_FeatureCoverage)

#endif /* WOLFCRYPT_TEST_SIPHASH_H */
