/* test_sakke.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SAKKE_H
#define WOLFCRYPT_TEST_SAKKE_H

#include <tests/api/api_decl.h>

int test_wc_Sakke_DecisionCoverage(void);
int test_wc_Sakke_FeatureCoverage(void);

#define TEST_SAKKE_DECLS                                          \
    TEST_DECL_GROUP("sakke", test_wc_Sakke_DecisionCoverage),     \
    TEST_DECL_GROUP("sakke", test_wc_Sakke_FeatureCoverage)

#endif /* WOLFCRYPT_TEST_SAKKE_H */
