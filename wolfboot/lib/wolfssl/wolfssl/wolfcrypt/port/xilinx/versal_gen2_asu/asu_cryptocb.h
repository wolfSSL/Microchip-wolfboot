/* asu_cryptocb.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Crypto callback device for the ASU. Anything the ASU cannot do falls back
 * to software. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_CRYPTOCB_H
#define WOLFSSL_VERSAL_GEN2_ASU_CRYPTOCB_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_VERSAL_GEN2_ASU

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Register the ASU device, which also starts the ASU client. Use the same
 * devId as WC_USE_DEVID. */
WOLFSSL_API int wc_AsuCryptoCb_RegisterDevice(int devId);

/* Remove the ASU device from the crypto callback framework. */
WOLFSSL_API void wc_AsuCryptoCb_UnRegisterDevice(int devId);

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_VERSAL_GEN2_ASU */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_CRYPTOCB_H */
