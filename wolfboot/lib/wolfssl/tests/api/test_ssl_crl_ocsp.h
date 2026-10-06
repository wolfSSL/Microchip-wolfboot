/* test_ssl_crl_ocsp.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_SSL_CRL_OCSP_H
#define TESTS_API_SSL_CRL_OCSP_H

#include <tests/api/api_decl.h>

int test_wolfSSL_ocsp_url_api(void);
int test_wolfSSL_get_ocsp_producedDate(void);
int test_wolfSSL_tlsext_status_type(void);
int test_wolfSSL_CTX_tlsext_status_cb(void);
int test_wolfSSL_tlsext_status_ocsp_resp(void);
int test_wolfSSL_OCSP_parse_url_api(void);

#define TEST_SSL_CRL_OCSP_DECLS                                                \
        TEST_DECL_GROUP("ssl_crl_ocsp", test_wolfSSL_ocsp_url_api),            \
        TEST_DECL_GROUP("ssl_crl_ocsp", test_wolfSSL_get_ocsp_producedDate),   \
        TEST_DECL_GROUP("ssl_crl_ocsp", test_wolfSSL_tlsext_status_type),      \
        TEST_DECL_GROUP("ssl_crl_ocsp", test_wolfSSL_CTX_tlsext_status_cb),    \
        TEST_DECL_GROUP("ssl_crl_ocsp", test_wolfSSL_tlsext_status_ocsp_resp), \
        TEST_DECL_GROUP("ssl_crl_ocsp", test_wolfSSL_OCSP_parse_url_api)

#endif /* TESTS_API_SSL_CRL_OCSP_H */
