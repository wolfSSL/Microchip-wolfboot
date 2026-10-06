/* test_wolfentropy.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_WOLFENTROPY_H
#define WOLFCRYPT_TEST_WOLFENTROPY_H

#include <tests/api/api_decl.h>

int test_wc_Entropy_GetRawEntropy(void);
int test_wc_Entropy_OnDemandTest(void);
int test_wc_EntropyDecisionCoverage(void);
int test_wc_EntropyFeatureCoverage(void);

#define TEST_WOLFENTROPY_DECLS                                              \
    TEST_DECL_GROUP("wolfentropy", test_wc_Entropy_GetRawEntropy),         \
    TEST_DECL_GROUP("wolfentropy", test_wc_Entropy_OnDemandTest),          \
    TEST_DECL_GROUP("wolfentropy", test_wc_EntropyDecisionCoverage),       \
    TEST_DECL_GROUP("wolfentropy", test_wc_EntropyFeatureCoverage)

#endif /* WOLFCRYPT_TEST_WOLFENTROPY_H */
