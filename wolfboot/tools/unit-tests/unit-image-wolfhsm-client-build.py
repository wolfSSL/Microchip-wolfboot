#!/usr/bin/env python3
# unit-image-wolfhsm-client-build.py
#
# Compile check for the WOLFBOOT_ENABLE_WOLFHSM_CLIENT path in
# wolfBoot_verify_signature_ecc() (src/image.c). The raw-to-DER
# signature conversion passes the output length to
# wc_ecc_rs_raw_to_sig(), which expects a word32*; this branch was
# only built by the PIC32CZ cross CI, so keep it compiling in the
# host unit CI as well.
#
# Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfBoot.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com

import subprocess
import sys


def main():
    p = subprocess.run(["make", "unit-image-wolfhsm-client-build"],
                       capture_output=True, text=True)
    if p.returncode != 0:
        print("FAIL: WOLFBOOT_ENABLE_WOLFHSM_CLIENT image.c "
              "does not compile:\n")
        print(p.stdout[-2000:])
        print(p.stderr[-2000:])
        return 1
    print("PASS: WOLFBOOT_ENABLE_WOLFHSM_CLIENT image.c compiles")
    return 0


if __name__ == "__main__":
    sys.exit(main())
