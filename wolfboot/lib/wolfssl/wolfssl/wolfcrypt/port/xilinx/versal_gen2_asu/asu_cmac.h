/* asu_cmac.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ASU AES-CMAC for the wolfSSL crypto callback: the message is accumulated per
 * Cmac context and the whole CMAC is produced in one ASU operation at finalize. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_CMAC_H
#define WOLFSSL_VERSAL_GEN2_ASU_CMAC_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_VERSAL_GEN2_ASU_CMAC

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Single entry point for the CMAC engine (WC_ALGO_TYPE_CMAC): single-call and
 * init/update/final. Returns 0, CRYPTOCB_UNAVAILABLE for software, or an error. */
WOLFSSL_LOCAL int wc_AsuCmac(wc_CryptoInfo* info);

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_VERSAL_GEN2_ASU_CMAC */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_CMAC_H */
