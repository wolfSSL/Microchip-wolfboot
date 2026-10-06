/* test_eat_psa_profile_main.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <stdio.h>

#include "test_suite.h"

int main(void)
{
    int failures;

    (void)printf("=== wolfCOSE PSA/EAT Feature Profile Tests ===\n\n");
    failures = test_eat_psa_profiles();
    (void)printf("\n=== Results: %s ===\n",
        (failures == 0) ? "ALL PASSED" : "FAILURES");

    return (failures == 0) ? 0 : 1;
}
