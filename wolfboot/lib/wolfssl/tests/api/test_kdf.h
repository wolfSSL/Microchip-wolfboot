/* test_kdf.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_KDF_H
#define WOLFCRYPT_TEST_KDF_H

#include <tests/api/api_decl.h>

int test_wc_KdfDecisionCoverage(void);
int test_wc_KdfFeatureCoverage(void);

#define TEST_KDF_DECLS                                       \
    TEST_DECL_GROUP("kdf", test_wc_KdfDecisionCoverage),      \
    TEST_DECL_GROUP("kdf", test_wc_KdfFeatureCoverage)

#endif /* WOLFCRYPT_TEST_KDF_H */
