/* test_eccsi.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ECCSI_H
#define WOLFCRYPT_TEST_ECCSI_H

#include <tests/api/api_decl.h>

int test_wc_Eccsi_DecisionCoverage(void);
int test_wc_Eccsi_FeatureCoverage(void);

#define TEST_ECCSI_DECLS                                          \
    TEST_DECL_GROUP("eccsi", test_wc_Eccsi_DecisionCoverage),     \
    TEST_DECL_GROUP("eccsi", test_wc_Eccsi_FeatureCoverage)

#endif /* WOLFCRYPT_TEST_ECCSI_H */
