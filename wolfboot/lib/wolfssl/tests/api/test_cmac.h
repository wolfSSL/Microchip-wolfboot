/* test_cmac.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_CMAC_H
#define WOLFCRYPT_TEST_CMAC_H

#include <tests/api/api_decl.h>

int test_wc_InitCmac(void);
int test_wc_CmacUpdate(void);
int test_wc_CmacFinal(void);
int test_wc_AesCmacGenerate(void);
int test_wc_CMAC_Grow(void);
int test_wc_InitCmac_Id(void);
int test_wc_InitCmac_Label(void);
int test_wc_AesCmacGenerateExDecisionCoverage(void);
int test_wc_AesCmacVerifyExDecisionCoverage(void);
int test_wc_AesCmacVerify_CryptoCb_LenMismatch(void);
int test_wc_CryptoCb_CmacFree(void);

#define TEST_CMAC_DECLS                                 \
    TEST_DECL_GROUP("cmac", test_wc_InitCmac),          \
    TEST_DECL_GROUP("cmac", test_wc_CmacUpdate),        \
    TEST_DECL_GROUP("cmac", test_wc_CmacFinal),         \
    TEST_DECL_GROUP("cmac", test_wc_AesCmacGenerate),   \
    TEST_DECL_GROUP("cmac", test_wc_CMAC_Grow),         \
    TEST_DECL_GROUP("cmac", test_wc_InitCmac_Id),       \
    TEST_DECL_GROUP("cmac", test_wc_InitCmac_Label),    \
    TEST_DECL_GROUP("cmac", test_wc_AesCmacGenerateExDecisionCoverage), \
    TEST_DECL_GROUP("cmac", test_wc_AesCmacVerifyExDecisionCoverage), \
    TEST_DECL_GROUP("cmac", test_wc_AesCmacVerify_CryptoCb_LenMismatch), \
    TEST_DECL_GROUP("cmac", test_wc_CryptoCb_CmacFree)

#endif /* WOLFCRYPT_TEST_CMAC_H */
