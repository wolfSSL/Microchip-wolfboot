/* visibility.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCOSE_VISIBILITY_H
#define WOLFCOSE_VISIBILITY_H

/* WOLFCOSE_API: marks symbols exported from the shared library.
 * WOLFCOSE_LOCAL: applies hidden visibility on supported GNU builds. It does
 * not provide C internal linkage and is empty on other supported builds. */

#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef BUILDING_WOLFCOSE
        #define WOLFCOSE_API __declspec(dllexport)
    #else
        #define WOLFCOSE_API __declspec(dllimport)
    #endif
    #define WOLFCOSE_LOCAL
#elif defined(__GNUC__) && (__GNUC__ >= 4)
    #ifdef BUILDING_WOLFCOSE
        #define WOLFCOSE_API __attribute__((visibility("default")))
    #else
        #define WOLFCOSE_API
    #endif
    #define WOLFCOSE_LOCAL __attribute__((visibility("hidden")))
#else
    #define WOLFCOSE_API
    #define WOLFCOSE_LOCAL
#endif

#endif /* WOLFCOSE_VISIBILITY_H */
