/* zephyr_init.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* The wolfSSL Zephyr module needs no boot-time SYS_INIT hook. wolfCrypt's
 * Hash-DRBG is seeded on demand by wc_GenerateSeed() -- which on Zephyr draws
 * from the hardware entropy driver when one is present (see
 * wolfcrypt/src/random.c) -- and wolfCrypt_Init()/wolfSSL_Init() run lazily
 * from the first library call. This translation unit is kept (it is referenced
 * by the module CMakeLists) as the place for any future module init. */
