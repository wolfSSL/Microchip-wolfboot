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
 * benchmark/wh_bench.h
 *
 */
#ifndef WH_BENCH_H_
#define WH_BENCH_H_

#if defined(WOLFHSM_CFG_BENCH_ENABLE)

#include "wolfhsm/wh_client.h"

/*
 * Client-side benchmarking function. Takes in a client configuration,
 * initializes the client, runs benchmarks against the server, then cleans up
 * and closes the client.
 */
int wh_Bench_ClientCfg(whClientConfig* clientCfg, int transport);

/*
 * Client-side benchmarking function. Runs the benchmarks on an already
 * initialized client context with no initialization or cleanup.
 */
int wh_Bench_ClientCtx(whClientContext* client, int transport);

#if defined(WOLFHSM_CFG_ENABLE_SERVER)
#include "wolfhsm/wh_server.h"

/* Server-side processing loop for benchmarking */
int wh_Bench_ServerCfgLoop(whServerConfig* serverCfg);

#if defined(WOLFHSM_CFG_TEST_POSIX)
/*
 * Runs the client benchmarks against a server using POSIX threads
 * transport: The type of transport to use for communication
 * moduleIndex: The specific benchmark module to run (optional, -1 for all)
 * Returns 0 on success and a non-zero error code on failure
 */
int wh_Bench_ClientServer_Posix(int transport, int moduleIndex);
#endif /* WOLFHSM_CFG_TEST_POSIX */

#endif /* WOLFHSM_CFG_ENABLE_SERVER */

/* List all modules */
void wh_Bench_ListModules(void);

#endif /* WOLFHSM_CFG_BENCH_ENABLE */

#endif /* WH_BENCH_H_ */
