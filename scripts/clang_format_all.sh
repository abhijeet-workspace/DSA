#!/usr/bin/env bash
# Format all teaching / project .cpp files with clang-format (repo .clang-format).
#
# Usage:
#   bash scripts/clang_format_all.sh           # format in place
#   bash scripts/clang_format_all.sh --check   # exit 1 if any file needs formatting
#
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

CHECK=0
if [[ "${1:-}" == "--check" ]]; then
  CHECK=1
fi

resolve_clang_format() {
  if command -v clang-format >/dev/null 2>&1; then
    command -v clang-format
    return 0
  fi
  for c in \
    /opt/homebrew/opt/llvm/bin/clang-format \
    /usr/local/opt/llvm/bin/clang-format \
    /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang-format
  do
    if [[ -x "$c" ]]; then
      echo "$c"
      return 0
    fi
  done
  echo "error: clang-format not found (install LLVM or Xcode)" >&2
  exit 1
}

CF="$(resolve_clang_format)"
if [[ ! -f "$ROOT/.clang-format" ]]; then
  echo "error: missing $ROOT/.clang-format" >&2
  exit 1
fi

LIST="$(mktemp)"
trap 'rm -f "$LIST"' EXIT

find "$ROOT" -type f -name '*.cpp' \
  ! -path '*/.git/*' \
  ! -path '*/build/*' \
  ! -path '*/.tmp_build/*' \
  ! -path '*/cmake-build-*/*' \
  | sort > "$LIST"

COUNT="$(wc -l < "$LIST" | tr -d ' ')"
if [[ "$COUNT" -eq 0 ]]; then
  echo "no .cpp files found"
  exit 0
fi

echo "Using: $CF"
"$CF" --version 2>/dev/null | head -n 1 || true
echo "Files: $COUNT"

if [[ "$CHECK" -eq 1 ]]; then
  fail=0
  while IFS= read -r f; do
    [[ -z "$f" ]] && continue
    if ! "$CF" -style=file --dry-run -Werror "$f" >/dev/null 2>&1; then
      echo "needs format: $f"
      fail=1
    fi
  done < "$LIST"
  if [[ "$fail" -ne 0 ]]; then
    echo "clang-format check: FAILED"
    exit 1
  fi
  echo "clang-format check: OK"
  exit 0
fi

# Format in batches of 40 (portable; avoids huge argv)
batch=()
flush() {
  if [[ ${#batch[@]} -gt 0 ]]; then
    "$CF" -i -style=file "${batch[@]}"
    batch=()
  fi
}

while IFS= read -r f; do
  [[ -z "$f" ]] && continue
  batch+=("$f")
  if [[ ${#batch[@]} -ge 40 ]]; then
    flush
  fi
done < "$LIST"
flush

echo "clang-format: OK ($COUNT files)"
