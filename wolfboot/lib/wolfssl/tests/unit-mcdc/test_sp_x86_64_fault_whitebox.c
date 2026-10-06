/* test_sp_x86_64_fault_whitebox.c
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
 * Heap-fault MC/DC supplement for wolfcrypt/src/sp_x86_64.c.
 *
 * Drives the `err == MP_OKAY` operand of the file's success chains by failing
 * an SP temporary allocation. See tests/unit-mcdc/test_sp_fault_common.h for
 * why that operand is otherwise dead, and what the sweep does.
 */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>

#include <wolfcrypt/src/sp_x86_64.c>

/* After the .c: only the test key material is wanted here, and the
 * module config does not ask for the buffers itself. */
#ifndef USE_CERT_BUFFERS_2048
    #define USE_CERT_BUFFERS_2048
#endif
#include <wolfssl/certs_test.h>

#define SP_FAULT_LABEL "sp_x86_64.c"
#include "test_sp_fault_common.h"
