#!/usr/bin/env bash
set -euo pipefail

# Quick build and run helper for header_files demos
HERE="$(cd "$(dirname "$0")" && pwd)"
cd "$HERE"

if [ "$#" -eq 0 ]; then
  echo "Usage: $0 [basics|complete|all]"
  exit 1
fi

case "$1" in
  basics)
    make run-basics
    ;;
  complete)
    make run-complete
    ;;
  all)
    make
    make run-basics
    make run-complete
    ;;
  *)
    echo "Unknown target: $1"; exit 2
    ;;
esac
