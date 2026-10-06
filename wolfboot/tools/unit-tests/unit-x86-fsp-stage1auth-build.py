#!/usr/bin/env python3
# unit-x86-fsp-stage1auth-build.py
#
# Compile check for the STAGE1_AUTH variant of src/boot_x86_fsp.c. The real
# stage1 authentication build needs an i686 toolchain the unit test CI does
# not have, so this compile-only target keeps the variant from silently
# rotting: it used to carry dead FSP-M verification scaffolding (an unused
# struct wolfBoot_image and int in start()) and a comment claiming the FSPs
# were authenticated, when only the stage2 wolfBoot payload is.
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
    p = subprocess.run(["make", "unit-boot-x86-fsp-stage1auth"],
                       capture_output=True, text=True)
    if p.returncode != 0:
        print("FAIL: STAGE1_AUTH variant of boot_x86_fsp.c "
              "does not compile:\n")
        print(p.stdout[-2000:])
        print(p.stderr[-2000:])
        return 1
    print("PASS: STAGE1_AUTH variant of boot_x86_fsp.c compiles")
    return 0


if __name__ == "__main__":
    sys.exit(main())
