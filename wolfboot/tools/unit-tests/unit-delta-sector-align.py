#!/usr/bin/env python3
# unit-delta-sector-align.py
#
# Build-time invariant for DELTA_UPDATES: the per-sector fill loop in
# wolfBoot_delta_update() (src/update_flash.c) calls wb_patch() with
# DELTA_BLOCK_SIZE chunks until WOLFBOOT_SECTOR_SIZE bytes are produced, so
# the reconstructed image is only sector-aligned when WOLFBOOT_SECTOR_SIZE is
# a multiple of DELTA_BLOCK_SIZE. A mismatched config used to compile fine
# and corrupt the delta apply (write past the one-sector SWAP partition,
# misaligned resume); the build now rejects it with an #error.
#
# This test builds the real update_flash.c (via unit-update-flash.c) with a
# deliberately misaligned DELTA_BLOCK_SIZE and asserts the build fails with
# the invariant message.
#
# Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfBoot.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com

import os
import subprocess
import sys

MESSAGE = "WOLFBOOT_SECTOR_SIZE % DELTA_BLOCK_SIZE != 0"


def main():
    # The misalign target is not in $(TESTS) and its rule does not track
    # src/update_flash.c (included via unit-update-flash.c), so drop any
    # stale artifact to force a real rebuild.
    try:
        os.remove("unit-update-flash-delta-misalign")
    except FileNotFoundError:
        pass
    p = subprocess.run(["make", "unit-update-flash-delta-misalign"],
                       capture_output=True, text=True)
    if p.returncode == 0:
        print("FAIL: misaligned DELTA_BLOCK_SIZE config built, "
              "expected the sector alignment #error")
        return 1
    if MESSAGE not in (p.stdout + p.stderr):
        print("FAIL: build failed for the wrong reason:\n")
        print(p.stderr[-2000:])
        return 1
    print("PASS: misaligned DELTA_BLOCK_SIZE rejected at build time")
    return 0


if __name__ == "__main__":
    sys.exit(main())
