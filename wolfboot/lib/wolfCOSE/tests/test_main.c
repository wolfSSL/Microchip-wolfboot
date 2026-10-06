/* test_main.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/**
 * wolfCOSE test harness. CI-friendly: returns 0 if all pass, 1 on failure.
 */

#include <stdio.h>

#include "test_suite.h"

int main(void)
{
    int failures = 0;

    printf("=== wolfCOSE Test Suite ===\n\n");

    printf("--- CBOR Tests (RFC 8949) ---\n");
    failures += test_cbor();

    printf("\n--- COSE Tests (RFC 9052) ---\n");
    failures += test_cose();

    printf("\n--- Interoperability Tests ---\n");
    failures += test_interop();

    printf("\n--- COSE WG Example Tests ---\n");
    failures += test_cose_examples();

    printf("\n--- PSA Attestation Token Tests ---\n");
    failures += test_psa_attestation();

    printf("\n--- PSA/EAT Tests ---\n");
    failures += test_eat_psa();
    failures += test_eat_psa_profiles();

    printf("\n=== Results: %s ===\n",
           (failures == 0) ? "ALL PASSED" : "FAILURES");

    if (failures > 0) {
        printf("%d test(s) failed.\n", failures);
    }

    return (failures == 0) ? 0 : 1;
}
