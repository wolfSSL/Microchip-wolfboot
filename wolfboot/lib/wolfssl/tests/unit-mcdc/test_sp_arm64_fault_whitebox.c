/* test_sp_arm64_fault_whitebox.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*
 * Heap-fault MC/DC supplement for wolfcrypt/src/sp_arm64.c, run inside this
 * module's own emulator lane.
 *
 * Drives the `err == MP_OKAY` operand of the file's success chains by failing
 * an SP temporary allocation. See tests/unit-mcdc/test_sp_arm_fault_common.h
 * for why that operand is otherwise dead by construction, why this TU (not a
 * new lane variant) turns WOLFSSL_SP_SMALL_STACK on, and what the sweep does.
 */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

/* Before ANY wolfSSL header, so sp_arm64.c's own
 *     #ifdef WOLFSSL_SP_SMALL_STACK ... SP_ALLOC_VAR = XMALLOC + err
 * arm of the SP_DECL_VAR/SP_ALLOC_VAR macro pair is the one compiled into this
 * translation unit. No header reacts to this macro, so it changes nothing but
 * function-local storage inside the file under test. */
#ifndef WOLFSSL_SP_SMALL_STACK
    #define WOLFSSL_SP_SMALL_STACK
#endif

#include <wolfssl/wolfcrypt/settings.h>

#include <wolfcrypt/src/sp_arm64.c>

#define SP_ARM_FAULT_LABEL "sp_arm64.c"
#include "test_sp_arm_fault_common.h"
