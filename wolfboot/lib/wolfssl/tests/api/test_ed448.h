/* test_ed448.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ED448_H
#define WOLFCRYPT_TEST_ED448_H

#include <tests/api/api_decl.h>

int test_wc_ed448_make_key(void);
int test_wc_ed448_make_public_stores_pub(void);
int test_wc_ed448_init(void);
int test_wc_ed448_sign_msg(void);
int test_wc_ed448_verify_sig_S_range(void);
int test_wc_ed448_sign_msg_pubonly_fails(void);
int test_wc_ed448_import_public(void);
int test_wc_ed448_import_private_key(void);
int test_wc_ed448_export(void);
int test_wc_ed448_size(void);
int test_wc_ed448_exportKey(void);
int test_wc_Ed448PublicKeyToDer(void);
int test_wc_Ed448KeyToDer(void);
int test_wc_Ed448PrivateKeyToDer(void);
int test_wc_Ed448KeyToDer_oneasymkey_version(void);
int test_wc_Ed448PrivateKeyDecode_ex(void);
int test_wc_ed448_reject_small_order_keys(void);
int test_wc_ed448_reject_noncanonical_y(void);
int test_wc_Ed448DecisionCoverage(void);
int test_wc_Ed448FeatureCoverage(void);
int test_wc_ed448_import_private_only(void);
int test_wc_ed448_check_key_decisions(void);
int test_wc_ed448_cryptocb(void);

#define TEST_ED448_DECLS                                          \
    TEST_DECL_GROUP("ed448", test_wc_ed448_make_key),             \
    TEST_DECL_GROUP("ed448", test_wc_ed448_make_public_stores_pub), \
    TEST_DECL_GROUP("ed448", test_wc_ed448_init),                 \
    TEST_DECL_GROUP("ed448", test_wc_ed448_sign_msg),             \
    TEST_DECL_GROUP("ed448", test_wc_ed448_verify_sig_S_range),   \
    TEST_DECL_GROUP("ed448", test_wc_ed448_sign_msg_pubonly_fails), \
    TEST_DECL_GROUP("ed448", test_wc_ed448_import_public),        \
    TEST_DECL_GROUP("ed448", test_wc_ed448_import_private_key),   \
    TEST_DECL_GROUP("ed448", test_wc_ed448_export),               \
    TEST_DECL_GROUP("ed448", test_wc_ed448_size),                 \
    TEST_DECL_GROUP("ed448", test_wc_ed448_exportKey),            \
    TEST_DECL_GROUP("ed448", test_wc_Ed448PublicKeyToDer),        \
    TEST_DECL_GROUP("ed448", test_wc_Ed448KeyToDer),              \
    TEST_DECL_GROUP("ed448", test_wc_Ed448PrivateKeyToDer),       \
    TEST_DECL_GROUP("ed448", test_wc_Ed448KeyToDer_oneasymkey_version), \
    TEST_DECL_GROUP("ed448", test_wc_ed448_reject_small_order_keys), \
    TEST_DECL_GROUP("ed448", test_wc_ed448_reject_noncanonical_y), \
    TEST_DECL_GROUP("ed448", test_wc_Ed448DecisionCoverage),      \
    TEST_DECL_GROUP("ed448", test_wc_Ed448FeatureCoverage),       \
    TEST_DECL_GROUP("ed448", test_wc_ed448_import_private_only),  \
    TEST_DECL_GROUP("ed448", test_wc_ed448_check_key_decisions),  \
    TEST_DECL_GROUP("ed448", test_wc_Ed448PrivateKeyDecode_ex),   \
    TEST_DECL_GROUP("ed448", test_wc_ed448_cryptocb)

#endif /* WOLFCRYPT_TEST_ED448_H */
