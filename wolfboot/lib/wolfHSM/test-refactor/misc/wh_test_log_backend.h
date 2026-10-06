/*
 * Copyright (C) 2006-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfHSM.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
/*
 * test-refactor/misc/wh_test_log_backend.h
 *
 * Backend-agnostic log harness shared by the portable Misc log tests
 * (mock, ring buffer) and the POSIX port log tests (file backend). The
 * caller supplies a backend callback table and context; the harness runs
 * the same suite against it.
 */

#ifndef WH_TEST_LOG_BACKEND_H_
#define WH_TEST_LOG_BACKEND_H_

#include <stddef.h>

#include "wolfhsm/wh_log.h"

/* Configuration describing a backend under test. */
typedef struct {
    const char* backend_name;    /* Backend name for test output */
    whLogCb*    cb;              /* Backend callback table */
    void*       config;          /* Backend-specific config */
    size_t      config_size;     /* Size of context structure */
    void*       backend_context; /* Pre-allocated backend context */

    /* Capabilities */
    int expected_capacity;   /* Max entries (-1 = unlimited) */
    int supports_concurrent; /* supports multithreaded use */

    /* Optional hooks */
    int (*setup)(void** context);   /* Setup hook (optional) */
    int (*teardown)(void* context); /* Teardown hook (optional) */
    void* test_context;             /* Context for setup/teardown */
} whTestLogBackendTestConfig;

/*
 * Runs all generic test suites against the supplied backend.
 * Returns WH_ERROR_OK on success, non-zero on failure.
 */
int whTest_LogBackend_RunAll(whTestLogBackendTestConfig* cfg);

#endif /* WH_TEST_LOG_BACKEND_H_ */
