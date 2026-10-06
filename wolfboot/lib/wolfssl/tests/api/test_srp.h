/* test_srp.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SRP_H
#define WOLFCRYPT_TEST_SRP_H

#include <tests/api/api_decl.h>

int test_wc_Srp_DecisionCoverage(void);
int test_wc_Srp_FeatureCoverage(void);

#define TEST_SRP_DECLS                                       \
    TEST_DECL_GROUP("srp", test_wc_Srp_DecisionCoverage),    \
    TEST_DECL_GROUP("srp", test_wc_Srp_FeatureCoverage)

#endif /* WOLFCRYPT_TEST_SRP_H */
