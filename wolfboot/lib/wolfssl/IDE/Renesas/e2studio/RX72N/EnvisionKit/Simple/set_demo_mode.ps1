# set_demo_mode.ps1
#
# Copyright (C) 2006-2026 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfSSL.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com

param(
    [Parameter(Mandatory=$true)]
    [ValidateSet('crypt', 'bench', 'TLSClient')]
    [string]$Mode
)

$macroMap = [ordered]@{
    'crypt'     = 'CRYPT_TEST'
    'bench'     = 'BENCHMARK'
    'TLSClient' = 'SIMPLE_TLS_TSIP_CLIENT'
}
$selected = $macroMap[$Mode]

$file = Join-Path $PSScriptRoot 'test\src\wolfssl_simple_demo.h'
if (-not (Test-Path $file)) {
    Write-Error "File not found: $file"
    exit 1
}

$content = Get-Content -Raw -Path $file

# Pass 1: normalize all three macros to the uncommented ("#define X") form,
# regardless of their current state, so pass 2's substring replace can't
# double-wrap an already-commented line (e.g. match "#define X" inside
# "/*#define X*/").
foreach ($m in $macroMap.Values) {
    $content = $content.Replace("/*#define $m*/", "#define $m")
}

# Pass 2: comment out every macro except the selected one.
foreach ($m in $macroMap.Values) {
    if ($m -ne $selected) {
        $content = $content.Replace("#define $m", "/*#define $m*/")
    }
}

Set-Content -NoNewline -Path $file -Value $content
Write-Host "[demo mode] $Mode -> #define $selected enabled (others disabled)"

# make's generated dependency (.d) files don't reliably list wolfssl_simple_demo.h as a
# prerequisite for every .c that includes it, so an incremental build can silently relink a
# stale .obj (compiled under the old macro) into a fresh-looking test.x. Force a rebuild of
# exactly the affected files by touching their mtime, rather than doing a full clean (slow)
# or trusting make's dependency tracking (unreliable here).
$srcDir = Join-Path $PSScriptRoot 'test\src'
$dependents = Get-ChildItem -Path $srcDir -Recurse -Include '*.c','*.h' |
    Where-Object { $_.FullName -ne $file } |
    Select-String -Pattern 'wolfssl_simple_demo\.h' -List |
    Select-Object -ExpandProperty Path

foreach ($dep in $dependents) {
    (Get-Item $dep).LastWriteTime = Get-Date
}
Write-Host "[demo mode] Touched $($dependents.Count) dependent source file(s) to force recompilation:"
$dependents | ForEach-Object { Write-Host "  $_" }
