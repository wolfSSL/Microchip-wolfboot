/* test_x509.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_X509_H
#define WOLFCRYPT_TEST_X509_H

int test_x509_rfc2818_verification_callback(void);
int test_x509_GetCAByAKID(void);
int test_x509_set_serialNumber(void);
int test_x509_verify_cert_hostname_check(void);
int test_x509_verify_cert_store_hostname_check(void);
int test_x509_ctx_param_hostname_check(void);
int test_x509_time_field_overread_via_tls(void);
int test_x509_CertFromX509_akid_overflow(void);
int test_x509_ReqCertFromX509_skid_overflow(void);
int test_x509_ReqCertFromX509_skid_boundary(void);
int test_x509_ReqCertFromX509_ext_critical(void);
int test_x509_REQ_sign_mldsa(void);

#define TEST_X509_DECLS                                                        \
    TEST_DECL_GROUP("x509", test_x509_rfc2818_verification_callback),          \
    TEST_DECL_GROUP("x509", test_x509_GetCAByAKID),                            \
    TEST_DECL_GROUP("x509", test_x509_set_serialNumber),                       \
    TEST_DECL_GROUP("x509", test_x509_verify_cert_hostname_check),             \
    TEST_DECL_GROUP("x509", test_x509_verify_cert_store_hostname_check),       \
    TEST_DECL_GROUP("x509", test_x509_ctx_param_hostname_check),               \
    TEST_DECL_GROUP("x509", test_x509_time_field_overread_via_tls),             \
    TEST_DECL_GROUP("x509", test_x509_CertFromX509_akid_overflow),             \
    TEST_DECL_GROUP("x509", test_x509_ReqCertFromX509_skid_overflow),          \
    TEST_DECL_GROUP("x509", test_x509_ReqCertFromX509_skid_boundary),          \
    TEST_DECL_GROUP("x509", test_x509_ReqCertFromX509_ext_critical),           \
    TEST_DECL_GROUP("x509", test_x509_REQ_sign_mldsa)

#endif /* WOLFCRYPT_TEST_X509_H */
