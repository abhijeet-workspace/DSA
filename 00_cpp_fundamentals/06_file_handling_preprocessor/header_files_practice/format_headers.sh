#!/usr/bin/env bash
set -euo pipefail

# Simple header hygiene checker: ensures headers have include guards or pragma once
HERE="$(cd "$(dirname "$0")" && pwd)"
echo "Checking headers in $HERE..."
shopt -s nullglob
fail=0
for f in "$HERE"/*.h "$HERE"/*.hpp; do
  if grep -q "#pragma once" "$f"; then
    continue
  fi
  # check if both #ifndef and #define exist somewhere in file
  if !(grep -q "#ifndef" "$f" && grep -q "#define" "$f"); then
    echo "WARNING: $f may be missing include guards or #pragma once"
    fail=1
  fi
done
if [ $fail -ne 0 ]; then
  echo "Header hygiene checks found issues."; exit 1
else
  echo "All headers look OK (basic check)."
fi
