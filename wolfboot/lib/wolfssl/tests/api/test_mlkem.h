/* test_mlkem.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_MLKEM_H
#define WOLFCRYPT_TEST_MLKEM_H

#include <tests/api/api_decl.h>

int test_wc_mlkem_make_key_kats(void);
int test_wc_mlkem_encapsulate_kats(void);
int test_wc_mlkem_decapsulate_kats(void);
int test_wc_mlkem_decapsulate_pubonly_fails(void);
int test_wc_mlkem_decap_fo_reject(void);
int test_wc_mlkem_decode_privkey_bad_pubhash(void);
int test_wc_MlkemFeatureCoverage(void);
int test_wc_MlkemDecisionCoverage(void);
int test_wc_mlkem_init_id_decision(void);
int test_wc_mlkem_init_label_decision(void);
int test_wc_mlkem_encapsulate_pubkey_unset_decision(void);
int test_wc_mlkem_encode_key_len_decision(void);
int test_wc_mlkem_cb_free(void);
int test_wc_mlkem_cb_pending_rejected(void);

#define TEST_MLKEM_DECLS                                                \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_make_key_kats),              \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_encapsulate_kats),           \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_decapsulate_kats),           \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_decapsulate_pubonly_fails),  \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_decap_fo_reject),            \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_decode_privkey_bad_pubhash), \
    TEST_DECL_GROUP("mlkem", test_wc_MlkemFeatureCoverage),             \
    TEST_DECL_GROUP("mlkem", test_wc_MlkemDecisionCoverage),            \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_init_id_decision),           \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_init_label_decision),        \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_encapsulate_pubkey_unset_decision), \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_encode_key_len_decision), \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_cb_free),                    \
    TEST_DECL_GROUP("mlkem", test_wc_mlkem_cb_pending_rejected)

#endif /* WOLFCRYPT_TEST_MLKEM_H */
