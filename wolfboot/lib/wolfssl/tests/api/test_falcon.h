/* test_falcon.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_FALCON_H
#define WOLFCRYPT_TEST_FALCON_H

#include <tests/api/api_decl.h>

int test_wc_falcon_sizes(void);
int test_wc_falcon_make_key(void);
int test_wc_falcon_sign_vfy(void);
int test_wc_falcon_import_export(void);
int test_wc_falcon_check_key(void);
int test_wc_falcon_der(void);
int test_wc_falcon_error_paths(void);
int test_wc_FalconDecisionCoverage(void);
int test_falcon_cb_free(void);

#define TEST_FALCON_DECLS                                                      \
    TEST_DECL_GROUP("falcon", test_wc_falcon_sizes),                          \
    TEST_DECL_GROUP("falcon", test_wc_falcon_make_key),                       \
    TEST_DECL_GROUP("falcon", test_wc_falcon_sign_vfy),                       \
    TEST_DECL_GROUP("falcon", test_wc_falcon_import_export),                  \
    TEST_DECL_GROUP("falcon", test_wc_falcon_check_key),                      \
    TEST_DECL_GROUP("falcon", test_wc_falcon_der),                            \
    TEST_DECL_GROUP("falcon", test_wc_falcon_error_paths),                    \
    TEST_DECL_GROUP("falcon", test_wc_FalconDecisionCoverage),                \
    TEST_DECL_GROUP("falcon", test_falcon_cb_free)

#endif /* WOLFCRYPT_TEST_FALCON_H */
