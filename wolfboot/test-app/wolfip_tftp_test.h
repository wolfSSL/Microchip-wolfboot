/* wolfip_tftp_test.h
 *
 * Optional wolfIP network test entry for the wolfBoot test-app.
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifndef WOLFIP_TFTP_TEST_H
#define WOLFIP_TFTP_TEST_H

/* Run the wolfIP network test. Returns 0 on success, negative on failure.
 * Without WOLFBOOT_TEST_TFTP this is a link/PHY bring-up smoke test;
 * with WOLFBOOT_TEST_TFTP it performs a full TFTP fetch and verify. */
int wolfip_tftp_test_run(void);

/* Run the test and print the "Starting..." banner and PASS/FAIL result.
 * Convenience wrapper so each target app's main() is a single call. */
void wolfip_tftp_test_report(void);

#endif /* WOLFIP_TFTP_TEST_H */
