#!/usr/bin/env bash
set -euo pipefail

# Simple compile check for CI: compile both demos with -fsyntax-only to check for errors
HERE="$(cd "$(dirname "$0")" && pwd)"
cd "$HERE"

echo "Checking compilation (syntax-only)..."
g++ -std=c++17 -fsyntax-only basics_header_files.cpp widget.cpp pimpl_widget.cpp
g++ -std=c++17 -fsyntax-only complete_headers_demo.cpp widget.cpp pimpl_widget.cpp
echo "Compilation checks passed."
