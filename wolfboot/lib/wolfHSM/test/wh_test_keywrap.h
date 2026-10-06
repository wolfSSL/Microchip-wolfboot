/*
 * Copyright (C) 2006-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfHSM.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifndef WH_TEST_KEYWRAP_H_
#define WH_TEST_KEYWRAP_H_

#include "wolfhsm/wh_server.h"
#include "wolfhsm/wh_client.h"

int whTest_Client_KeyWrap(whClientContext* ctx);
int whTest_Client_DataWrap(whClientContext* ctx);
int whTest_KeyWrapClientConfig(whClientConfig* cf);

#if defined(WOLFHSM_CFG_HWKEYSTORE) && defined(WOLFHSM_CFG_KEYWRAP)
#include "wolfhsm/wh_hwkeystore.h"

/* Test getKey callback emulating a hardware keystore backend; bind this to
 * the server's whHwKeystoreContext when running whTest_Client_HwKeystore.
 * Defined in wh_test_keywrap.c, so only available when keywrap is enabled */
int whTest_HwKeystoreGetKeyCb(void* context, whKeyId keyId, uint8_t* out,
                              uint16_t* inout_len);
int whTest_Client_HwKeystore(whClientContext* ctx);

/* Convenience callback-table initializer for the emulated test backend. The
 * backend needs no setup/teardown, so Init and Cleanup are NULL */
/* clang-format off */
#define WH_TEST_HWKEYSTORE_CB                 \
    {                                         \
        .Init    = NULL,                      \
        .Cleanup = NULL,                      \
        .GetKey  = whTest_HwKeystoreGetKeyCb, \
    }
/* clang-format on */
#endif /* WOLFHSM_CFG_HWKEYSTORE && WOLFHSM_CFG_KEYWRAP */

#endif /* WH_TEST_KEYWRAP_H_ */
