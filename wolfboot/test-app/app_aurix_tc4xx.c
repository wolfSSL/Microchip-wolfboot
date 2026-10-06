/* app_aurix_tc4xx.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* wolfBoot test app for AURIX TC4xx.
 * Host mode (TARGET=aurix_tc4xx) runs on CPU0.
 * CSRM mode (TARGET=aurix_tc4xx_csrm, see app_aurix_tc4xx_csrm.c) runs
 * on CPU6.
 * Flash helpers run from PSPR. */

#if defined(TARGET_aurix_tc4xx) || defined(TARGET_aurix_tc4xx_csrm)

#include <stdint.h>
#include <string.h>
#include "target.h"
#include "printf.h"
#include "hal.h"
#include "wolfboot/wolfboot.h"
#ifdef WOLFBOOT_ENABLE_WOLFHSM_CLIENT
#include "wolfhsm/wh_client.h"
/* Defined by the port client glue. */
extern whClientContext hsmClientCtx;
#endif

#define BASE_FW_VERSION 1

/* Empty _init for the SSW C init hook. */
void _init(void) {}

/* Hang on flash HAL faults. */
void wolfBoot_panic(void)
{
    while (1) {
        __asm volatile("nop");
    }
}

/* Entry after C runtime init. */
#ifdef TARGET_aurix_tc4xx_csrm
void core6_main(void)
#else
void core0_main(void)
#endif
{
#ifdef DEBUG_UART
    uart_init();
#endif
#ifdef TARGET_aurix_tc4xx_csrm
    wolfBoot_printf("TC4xx CSRM Test Application\n");
#else
    wolfBoot_printf("TC4xx Test Application\n");
#endif
    wolfBoot_printf("Version: %d\n", wolfBoot_current_firmware_version());

    if (wolfBoot_current_firmware_version() <= BASE_FW_VERSION) {
        /* Stage the update from base firmware. */
        wolfBoot_update_trigger();
    }
    else {
        /* Confirm updated firmware. */
        wolfBoot_success();
    }

#ifdef WOLFBOOT_ENABLE_WOLFHSM_CLIENT
    /* Full-system echo through the wolfHSM server. */
    {
        int        rc;
        const char echoMsg[] = "wolfHSM echo test";
        char       echoResp[sizeof(echoMsg)];
        uint16_t   echoRespLen = 0;

        rc = hal_hsm_init_connect();
        if (rc == 0) {
            wolfBoot_printf("wolfHSM Echo: sending %d bytes\n",
                            sizeof(echoMsg));
            rc = wh_Client_Echo(&hsmClientCtx, sizeof(echoMsg), echoMsg,
                                &echoRespLen, echoResp);
            if (rc != 0) {
                wolfBoot_printf("wolfHSM Echo test failed: %d\n", rc);
            }
            else if ((echoRespLen != sizeof(echoMsg)) ||
                     (memcmp(echoResp, echoMsg, sizeof(echoMsg)) != 0)) {
                /* The reply must match what was sent, byte for byte. */
                wolfBoot_printf("wolfHSM Echo mismatch: received %d bytes\n",
                                echoRespLen);
            }
            else {
                wolfBoot_printf("wolfHSM Echo success: received %d bytes\n",
                                echoRespLen);
            }
            hal_hsm_disconnect();
        }
        else {
            wolfBoot_printf("HSM connect failed: %d\n", rc);
        }
    }
#endif

    /* Main application loop. */
    while (1) {
        /* Spin forever. */
    }
}

#endif /* TARGET_aurix_tc4xx || TARGET_aurix_tc4xx_csrm */
