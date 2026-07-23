# Competitive Template

## Problem Statement
Provide a reusable C++17 contest skeleton: fast IO, type aliases, grid deltas, optional LOCAL debug, and modular arithmetic helpers — with a sample `solve` that sums an array.

- **Inputs (sample solve):** `n` then `n` integers (when enabled).
- **Output:** template self-check line; sample would print the sum.
- **Valid answer:** compiles cleanly; helpers behave under MOD.
- **Edges:** empty input when solve disabled; LOCAL vs non-LOCAL builds.

## Intuition
Contests reward boilerplate that removes friction: untie streams, short names, safe mod ops, and debug that disappears in submissions (`-DLOCAL` only).

## Brute Force → Optimal
- **Brute:** rewrite includes/aliases every problem; `endl` flushing; ad-hoc debug prints left in.
- **Optimal:** one template — FAST_IO, aliases, guarded `debug`, `solve(tc)` loop.

## Data Structure / Approach Justification
**Chosen:** macros for IO/debug; `constexpr` constants; small template gcd/lcm and mod_* inlines.

- **vs heavy `#include <bits/stdc++.h>`:** faster compile with explicit headers here; bits OK on CF GNU.
- **vs class-based framework:** overkill for short contest files.

## Logic Walkthrough
`main` enables FAST_IO, loops `t` testcases calling `solve`. Sample `solve` reads `n`, vector `a`, optionally debugs `n`, prints `accumulate` sum. Mod helpers normalize before `%`.

## Dry Run
Build without calling `solve`: prints `Competitive Template compiled successfully!`.
With solve and input `3` / `1 2 3`: output `6`.

## Time & Space Complexity
Template overhead **O(1)**. Sample sum **O(n)** time, **O(n)** space. Why: thin wrappers only (section 4).

## Trade-offs & Alternatives
Macros can surprise (FAST_IO multi-statement). Prefer `bits/stdc++.h` on platforms that support it. Some prefer `cerr` for debug to keep stdout clean.

## Common Mistakes / Edge Cases
Shipping with `-DLOCAL` debug on; `mod_sub` forgetting `+ m`; LCM overflow; enabling multi-test without reading `t`.

## Interview Follow-ups / Variations
Add mint struct; random helpers; DSA snippets (DSU, segtree) as includes; stress-test harness.

## Tags
`template`, `competitive-programming`, `fast-io`, `macros`, `difficulty:easy`
