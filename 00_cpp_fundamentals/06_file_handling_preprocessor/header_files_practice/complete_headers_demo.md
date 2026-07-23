# Complete Headers Demo

## Problem Statement

Tour common C++ standard headers (I/O, containers, algorithms, smart pointers, regex, filesystem, threads, random, math, vocabulary types) plus this folder’s project headers.

- **Build:** link with `widget.cpp` and `pimpl_widget.cpp`.
- **Output:** labeled mini-demos for each header group.

## Intuition

The standard library is header-driven: include what you use. Grouping includes by concern keeps translation units readable.

## Brute Force → Optimal

**Naive:** `#include <bits/stdc++.h>` — non-portable, slow compiles.

**This approach:** include only needed headers and show one tiny use each so you remember which header owns which API.

## Data Structure / Approach Justification

**Chosen:** explicit includes + small demo functions per domain.

- **vs umbrella headers:** clearer dependencies and faster incremental builds.
- **vs modules (C++20):** cleaner long-term, but classic includes remain the interview/default baseline.

## Logic Walkthrough

`main` calls `io_demo`, `string_demo`, `containers_demo`, … each constructing a representative object and printing one fact. `manual_headers_demo` ties in `greet`, `Widget`, and `PimplWidget`.

## Dry Run

Example: `algorithm_demo` starts with `{3,1,2,3,2}` → sort → `{1,2,2,3,3}` → `unique`+`erase` → `{1,2,3}` printed.

## Time & Space Complexity

Each demo is O(n) in its tiny local input (n ≤ 10 here). Overall program is O(1) relative to problem size because inputs are fixed.

## Trade-offs & Alternatives

Comprehensive demos teach discovery but are not production architecture. Prefer focused files in real codebases.

## Common Mistakes / Edge Cases

- Including unused heavy headers (`<regex>`, `<filesystem>`) without need.
- Forgetting `-pthread` / filesystem linker flags on some platforms when linking (compile-only `-c` is fine).
- Treating `std::any` as a default variant replacement.

## Interview Follow-ups / Variations

- Trim this into per-header kata files.
- Add CMake `target_link_libraries` notes for `stdc++fs` / threads.
- Compare `<chrono>` clocks for seeding vs `random_device`.

## Tags

`standard-library`, `headers`, `demo`, `difficulty:easy`
