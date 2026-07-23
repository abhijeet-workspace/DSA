#!/usr/bin/env bash
# Compile every teaching .cpp under foundations + phases 01-11.
# Usage: bash test/compile_all.sh
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

CXX="${CXX:-g++}"
# -Werror enforced; suppress demo-noise / clang pedantic warnings chosen for this repo
CXXFLAGS="-std=c++17 -Wall -Wextra -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-sign-compare -Wno-missing-braces -Wno-reorder-ctor -Wno-unqualified-std-cast-call -Wno-vla-cxx-extension -O0"

DIRS="
00_cpp_fundamentals
00_daa_foundations
01_phase_arrays_strings_hashing
02_phase_searching_sorting
03_phase_linked_lists
04_phase_stacks_queues
05_phase_trees
06_phase_heaps_intervals
07_phase_recursion_backtracking
08_phase_graphs
09_phase_dynamic_programming
10_phase_advanced_topics
11_phase_competitive_programming
"

tmpdir=$(mktemp -d)
trap 'rm -rf "$tmpdir"' EXIT

list_file="$tmpdir/files.txt"
: > "$list_file"
for d in $DIRS; do
  if [ -d "$d" ]; then
    find "$d" -name '*.cpp' >> "$list_file"
  fi
done

count=$(wc -l < "$list_file" | tr -d ' ')
echo "Compiling $count files with $CXX $CXXFLAGS"
fail=0

while IFS= read -r f; do
  [ -z "$f" ] && continue
  out="$tmpdir/obj.o"
  if ! $CXX $CXXFLAGS -c "$f" -o "$out" 2>"$tmpdir/err.txt"; then
    echo "FAIL: $f"
    cat "$tmpdir/err.txt"
    fail=1
  fi
done < "$list_file"

if [ "$fail" -ne 0 ]; then
  echo "compile-all: FAILED"
  exit 1
fi
echo "compile-all: OK ($count files)"
