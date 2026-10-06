#!/bin/sh
#
# der2c.sh <file.der> <symbol> - emit a DER blob as a C array on stdout.
#
# Used to embed wolfBoot's exported signing public key into a HAL that must
# hand it to an HSM at boot
#
# Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfBoot.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com

set -eu

if [ $# -ne 2 ]; then
    echo "usage: $0 <file.der> <symbol>" >&2
    exit 1
fi

DER="$1"
SYM="$2"

if [ ! -r "$DER" ]; then
    echo "$0: cannot read $DER" >&2
    exit 1
fi

echo "/* Generated from $(basename "$DER") by tools/scripts/der2c.sh. Do not edit. */"
echo "#ifndef WOLFBOOT_GEN_$(echo "$SYM" | tr '[:lower:]' '[:upper:]')_H"
echo "#define WOLFBOOT_GEN_$(echo "$SYM" | tr '[:lower:]' '[:upper:]')_H"
echo ""
echo "#include <stdint.h>"
echo ""
echo "static const uint8_t ${SYM}[] = {"
od -An -v -tx1 "$DER" | awk '
{
    for (i = 1; i <= NF; i++) {
        if (n % 12 == 0) printf "   "
        printf " 0x%s,", $i
        n++
        if (n % 12 == 0) printf "\n"
    }
}
END { if (n % 12 != 0) printf "\n" }'
echo "};"
echo ""
echo "#endif"
