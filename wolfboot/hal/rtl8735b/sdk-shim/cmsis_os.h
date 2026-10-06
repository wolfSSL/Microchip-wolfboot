/* cmsis_os.h (wolfBoot AmebaPro2 SDK shim)
 *
 * The RealTek SDK header chain (cmsis.h) unconditionally includes "cmsis_os.h",
 * which in the SDK is the CMSIS-OS wrapper over FreeRTOS. wolfBoot's use of the
 * SDK flash / log-UART / cache drivers is bare-metal and never calls any
 * CMSIS-OS API, but a few SDK headers (e.g. diag.h: "extern osMutexId
 * PrintLock_id;") reference CMSIS-OS types while being parsed.
 *
 * This stub satisfies those references with opaque types so the SDK headers
 * compile WITHOUT pulling FreeRTOS into wolfBoot's standalone build. It is
 * placed on the include path ahead of the SDK's real cmsis_os.h, and is used
 * only for hal/rtl8735b.o when HAL_BACKEND=sdk.
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifndef WOLFBOOT_AMEBAPRO2_CMSIS_OS_SHIM_H
#define WOLFBOOT_AMEBAPRO2_CMSIS_OS_SHIM_H

#include <stdint.h>

typedef void    *osMutexId;
typedef void    *osSemaphoreId;
typedef void    *osThreadId;
typedef void    *osMessageQId;
typedef void    *osMailQId;
typedef void    *osTimerId;
typedef void    *osPoolId;
typedef int32_t  osStatus;

#endif /* WOLFBOOT_AMEBAPRO2_CMSIS_OS_SHIM_H */
