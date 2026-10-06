/* test_coding.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_CODING_H
#define WOLFCRYPT_TEST_CODING_H

#include <tests/api/api_decl.h>

int test_wc_Base64_DecodeDecisionCoverage(void);
int test_wc_Base64_DecodeWhitespaceCoverage(void);
int test_wc_Base64_EncodeDecisionCoverage(void);
int test_wc_Base16DecisionCoverage(void);
int test_wc_Utf8_DecodeChar(void);

#define TEST_CODING_DECLS                                                    \
    TEST_DECL_GROUP("coding", test_wc_Base64_DecodeDecisionCoverage),        \
    TEST_DECL_GROUP("coding", test_wc_Base64_DecodeWhitespaceCoverage),      \
    TEST_DECL_GROUP("coding", test_wc_Base64_EncodeDecisionCoverage),        \
    TEST_DECL_GROUP("coding", test_wc_Base16DecisionCoverage),               \
    TEST_DECL_GROUP("coding", test_wc_Utf8_DecodeChar)

#endif /* WOLFCRYPT_TEST_CODING_H */
