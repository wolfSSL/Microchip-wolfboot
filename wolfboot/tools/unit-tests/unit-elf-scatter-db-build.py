#!/usr/bin/env python3
# unit-elf-scatter-db-build.py
#
# Compile check for the DISABLE_BACKUP + WOLFBOOT_ELF_FLASH_SCATTER +
# EXT_FLASH combination: the ELF-scatter restore block in
# wolfBoot_update() (src/update_flash.c) used to pass the boot struct by
# value to the pointer-taking PART_IS_EXT macro, so this configuration
# failed to build and the branch could never be exercised. It must now
# compile, with the load result checked like in wolfBoot_start().
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
    p = subprocess.run(["make", "unit-update-flash-elf-scatter-db"],
                       capture_output=True, text=True)
    if p.returncode != 0:
        print("FAIL: DISABLE_BACKUP + ELF scatter + EXT_FLASH "
              "does not compile:\n")
        print(p.stdout[-2000:])
        print(p.stderr[-2000:])
        return 1
    print("PASS: DISABLE_BACKUP + ELF scatter + EXT_FLASH compiles")
    return 0


if __name__ == "__main__":
    sys.exit(main())
