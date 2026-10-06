/* test_hpke.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_HPKE_H
#define WOLFCRYPT_TEST_HPKE_H

#include <tests/api/api_decl.h>

int test_wc_Hpke_DecisionCoverage(void);
int test_wc_Hpke_FeatureCoverage(void);

#define TEST_HPKE_DECLS                                        \
    TEST_DECL_GROUP("hpke", test_wc_Hpke_DecisionCoverage),    \
    TEST_DECL_GROUP("hpke", test_wc_Hpke_FeatureCoverage)

#endif /* WOLFCRYPT_TEST_HPKE_H */
