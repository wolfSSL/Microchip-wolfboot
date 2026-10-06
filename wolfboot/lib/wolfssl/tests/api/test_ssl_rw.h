/* test_ssl_rw.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_SSL_RW_H
#define TESTS_API_SSL_RW_H

#include <tests/api/api_decl.h>

int test_wolfSSL_send(void);
int test_wolfSSL_writev(void);
int test_wolfSSL_get_shutdown(void);
int test_wolfSSL_want(void);
int test_wolfSSL_pending_api(void);
int test_wolfSSL_rw_bad_args(void);
int test_wolfSSL_rw_info_callback(void);
int test_wolfSSL_write_ex_partial(void);
int test_wolfSSL_inject_app_data_ready(void);
int test_wolfSSL_shutdown_no_notify(void);
int test_wolfSSL_shutdown_repeat_after_done(void);
int test_wolfSSL_shutdown_flush_no_notify(void);
int test_wolfSSL_shutdown_quic_alert_refused(void);
int test_wolfSSL_SendUserCanceled_paths(void);
int test_wolfSSL_write_dup_err(void);

#define TEST_SSL_RW_DECLS                                                      \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_send),                          \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_writev),                        \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_get_shutdown),                  \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_want),                          \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_pending_api),                   \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_rw_bad_args),                   \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_rw_info_callback),              \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_write_ex_partial),              \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_inject_app_data_ready),         \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_shutdown_no_notify),            \
        TEST_DECL_GROUP("ssl_rw",                                              \
            test_wolfSSL_shutdown_repeat_after_done),                          \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_shutdown_flush_no_notify),      \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_shutdown_quic_alert_refused),   \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_SendUserCanceled_paths),        \
        TEST_DECL_GROUP("ssl_rw", test_wolfSSL_write_dup_err)

#endif /* TESTS_API_SSL_RW_H */
