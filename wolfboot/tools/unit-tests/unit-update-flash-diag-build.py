#!/usr/bin/env python3
# unit-update-flash-diag-build.py
#
# Compile check for the WOLFBOOT_PERSIST_FAILURE_STATUS path of
# wolfBoot_record_verify_failure() in src/update_flash.c. The failing
# image's version is read through wolfBoot_get_image_version(part),
# which fetches the header from external flash; no runtime unit test
# builds update_flash.c with this option, so keep the ext-flash
# configuration compiling in the host unit CI.
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
    p = subprocess.run(["make", "unit-update-flash-diag-build"],
                       capture_output=True, text=True)
    if p.returncode != 0:
        print("FAIL: PERSIST_FAILURE_STATUS update_flash.c "
              "does not compile:\n")
        print(p.stdout[-2000:])
        print(p.stderr[-2000:])
        return 1
    print("PASS: PERSIST_FAILURE_STATUS update_flash.c compiles")
    return 0


if __name__ == "__main__":
    sys.exit(main())
