/* test_frodokem_fault_whitebox.c
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
 * MC/DC fault-injection white-box for wolfcrypt/src/wc_frodokem.c.
 *
 * #includes wc_frodokem.c directly so llvm-cov instruments this file's copy
 * (reaching its file-static helpers), then #includes the shared driver body which
 * installs the heap-fault injector and sweeps the fail-index across
 * make/encap/decap for every compiled parameter set -- driving the FALSE
 * (ret != 0) halves of wc_frodokem.c's allocation success chains. See
 * test_frodokem_fault_common.h for the full rationale.
 */

#include <wolfcrypt/src/wc_frodokem.c>

#include "test_frodokem_fault_common.h"
