/* test_ocsp.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_TEST_OCSP_H
#define WOLFSSL_TEST_OCSP_H

int test_ocsp_certid_enc_dec(void);
int test_ocsp_certid_dup(void);
int test_ocsp_resp_find_status_serial_prefix(void);
int test_ocsp_status_callback(void);
int test_ocsp_status_request_scr(void);
int test_ocsp_basic_verify(void);
int test_ocsp_responder_keyhash_binding(void);
int test_ocsp_response_parsing(void);
int test_ocsp_tls_cert_cb(void);
int test_ocsp_status_request_v2_multi_revoked_single(void);
int test_ocsp_cert_unknown_crl_fallback(void);
int test_ocsp_cert_unknown_crl_fallback_nonleaf(void);
int test_ocsp_no_url_policy(void);
int test_ocsp_checkall_staple_crl_missing(void);
int test_ocsp_staple_crl_no_checkall(void);
int test_ocsp_no_url_crl_fallback(void);
int test_ocsp_no_url_crl_fallback_nonleaf(void);
int test_ocsp_no_url_crl_not_loaded(void);
int test_tls13_nonblock_ocsp_low_mfl(void);
int test_ocsp_ctx_request_cache(void);
int test_ocsp_responder(void);
int test_ocsp_ancestor_responder_rejected(void);
int test_ocsp_forged_responder_cert_rejected(void);
int test_wolfIO_DecodeUrl_crlf_reject(void);
int test_wolfIO_DecodeUrl_host_bounds(void);
#endif /* WOLFSSL_TEST_OCSP_H */

