/* wolfboot_smc.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* SMC ABI between the wolfBoot EL3 secure monitor (server) and the normal
 * world (client). This is the shared contract used by both sides:
 *
 *   - The crypto / key / secure-storage surface is carried by the wolfHSM
 *     client/server protocol over a shared-memory transport (wh_transport_mem).
 *     SMC is used only as a doorbell: the client writes a request into the
 *     shared buffer, issues WOLFBOOT_SMC_FID_HSM_DOORBELL, and the EL3 server
 *     processes exactly one wolfHSM request and writes the response back.
 *   - A few small fixed-ABI calls (firmware update trigger/status, version)
 *     do not need the wolfHSM channel.
 *
 * Function IDs use the SMCCC Fast Call, SMC64, OEM range (0xC3000000+) to
 * avoid the Xilinx SiP range (0xC2000000, used by PM_SIP_SVC in hal/zynq.c).
 */

#ifndef WOLFBOOT_SMC_H
#define WOLFBOOT_SMC_H

/* SMCCC Fast Call / SMC64 / OEM service range base. */
#define WOLFBOOT_SMC_FID_BASE            0xC3000000U

/* Doorbell: a wolfHSM request is ready in the shared buffer. The server runs
 * one wh_Server_HandleRequestMessage() pass. Returns WOLFBOOT_SMC_OK on a
 * processed request, WOLFBOOT_SMC_NOT_READY if none was pending. */
#define WOLFBOOT_SMC_FID_HSM_DOORBELL    (WOLFBOOT_SMC_FID_BASE + 0x00U)

/* Firmware update / boot control (fixed ABI, no wolfHSM channel). */
#define WOLFBOOT_SMC_FID_FW_UPDATE       (WOLFBOOT_SMC_FID_BASE + 0x01U)
#define WOLFBOOT_SMC_FID_FW_STATUS       (WOLFBOOT_SMC_FID_BASE + 0x02U)
#define WOLFBOOT_SMC_FID_VERSION         (WOLFBOOT_SMC_FID_BASE + 0x03U)

/* SMC return codes (in x0). Aligned with SMCCC conventions: 0 success,
 * negative for errors. */
#define WOLFBOOT_SMC_OK                  (0)
#define WOLFBOOT_SMC_NOT_READY           (-1)
#define WOLFBOOT_SMC_NOT_SUPPORTED       (-2)
#define WOLFBOOT_SMC_ERROR               (-3)

/* Shared-memory region for the wolfHSM transport (wh_transport_mem). Carved
 * out of DDR and mapped on both sides; must be reserved from the OS via the
 * device tree (/reserved-memory) so Linux does not use it. The region holds
 * the request buffer followed by the response buffer.
 *
 * Override at build time with -DWOLFBOOT_HSM_SHM_BASE / _SIZE to match the
 * DTB reservation and the wolfHSM whTransportMemConfig on both ends. */
#ifndef WOLFBOOT_HSM_SHM_BASE
#define WOLFBOOT_HSM_SHM_BASE            0x7F000000UL
#endif
#ifndef WOLFBOOT_HSM_SHM_SIZE
#define WOLFBOOT_HSM_SHM_SIZE            0x00010000UL   /* 64 KB total */
#endif

/* Split the region into request and response halves for wh_transport_mem. */
#define WOLFBOOT_HSM_SHM_REQ_BASE        (WOLFBOOT_HSM_SHM_BASE)
#define WOLFBOOT_HSM_SHM_REQ_SIZE        (WOLFBOOT_HSM_SHM_SIZE / 2U)
#define WOLFBOOT_HSM_SHM_RESP_BASE       (WOLFBOOT_HSM_SHM_BASE + \
                                          WOLFBOOT_HSM_SHM_REQ_SIZE)
#define WOLFBOOT_HSM_SHM_RESP_SIZE       (WOLFBOOT_HSM_SHM_SIZE / 2U)

#endif /* WOLFBOOT_SMC_H */
