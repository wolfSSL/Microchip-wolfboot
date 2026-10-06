/* test_port.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_PORT_H
#define WOLFCRYPT_TEST_PORT_H

#include <tests/api/api_decl.h>

int test_wc_PortDecisionCoverage(void);

#define TEST_PORT_DECLS                                                        \
    TEST_DECL_GROUP("port", test_wc_PortDecisionCoverage)

#endif /* WOLFCRYPT_TEST_PORT_H */
