/* test_error.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ERROR_H
#define WOLFCRYPT_TEST_ERROR_H

#include <tests/api/api_decl.h>

int test_wc_GetErrorStringDecisionCoverage(void);
int test_wc_ErrorStringDecisionCoverage(void);

#define TEST_ERROR_DECLS                                                     \
    TEST_DECL_GROUP("error", test_wc_GetErrorStringDecisionCoverage),        \
    TEST_DECL_GROUP("error", test_wc_ErrorStringDecisionCoverage)

#endif /* WOLFCRYPT_TEST_ERROR_H */
