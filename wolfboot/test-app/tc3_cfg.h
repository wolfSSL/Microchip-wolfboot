/* tc3_cfg.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TC3_CFG_H
#define TC3_CFG_H

#if defined(TARGET_aurix_tc3xx_hsm)
#define TC3_CFG_HAVE_ARM
#else
#define TC3_CFG_HAVE_TRICORE
#endif

#define TC3_CFG_HAVE_BOARD
#define TC3_BOARD_TC375LITEKIT 1

#endif /* TC3_CFG_H */
