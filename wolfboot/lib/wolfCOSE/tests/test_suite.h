/* test_suite.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCOSE_TEST_SUITE_H
#define WOLFCOSE_TEST_SUITE_H

/* Shared prototypes for the test entry points so a compatible declaration is
 * visible at each definition (MISRA C:2023 Rule 8.4). */
int test_cbor(void);
int test_cose(void);
int test_interop(void);
int test_cose_examples(void);
int test_psa_attestation(void);
int test_eat_psa(void);
int test_eat_psa_profiles(void);

#endif /* WOLFCOSE_TEST_SUITE_H */
