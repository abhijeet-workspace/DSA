# Competitive Template

## 1. Problem Statement
Provide a reusable C++17 contest skeleton: fast IO, type aliases, grid deltas, optional LOCAL debug, and modular arithmetic helpers — with a sample `solve` that sums an array.

- **Inputs (sample solve):** `n` then `n` integers (when enabled).
- **Output:** template self-check line; sample would print the sum.
- **Valid answer:** compiles cleanly; helpers behave under MOD.
- **Edges:** empty input when solve disabled; LOCAL vs non-LOCAL builds.

## 2. Intuition
Contests reward boilerplate that removes friction: untie streams, short names, safe mod ops, and debug that disappears in submissions (`-DLOCAL` only).

## 3. Brute Force → Optimal
- **Brute:** rewrite includes/aliases every problem; `endl` flushing; ad-hoc debug prints left in.
- **Optimal:** one template — FAST_IO, aliases, guarded `debug`, `solve(tc)` loop.

## 4. Data Structure / Approach Justification

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest
statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in
Fenwick/SegTree/graph topics.

**Chosen:** macros for IO/debug; `constexpr` constants; small template gcd/lcm and mod_* inlines.

- **vs heavy `#include <bits/stdc++.h>`:** faster compile with explicit headers here; bits OK on CF GNU.
- **vs class-based framework:** overkill for short contest files.

## 5. Logic Walkthrough
`main` enables FAST_IO, loops `t` testcases calling `solve`. Sample `solve` reads `n`, vector `a`, optionally debugs `n`, prints `accumulate` sum. Mod helpers normalize before `%`.

## 6. Dry Run
Build without calling `solve`: prints `Competitive Template compiled successfully!`.
With solve and input `3` / `1 2 3`: output `6`.

## 7. Time & Space Complexity
Template overhead **O(1)**. Sample sum **O(n)** time, **O(n)** space. Why: thin wrappers only (section 4).

## 8. Trade-offs & Alternatives
Macros can surprise (FAST_IO multi-statement). Prefer `bits/stdc++.h` on platforms that support it. Some prefer `cerr` for debug to keep stdout clean.

## 9. Common Mistakes / Edge Cases
Shipping with `-DLOCAL` debug on; `mod_sub` forgetting `+ m`; LCM overflow; enabling multi-test without reading `t`.

## 10. Interview Follow-ups / Variations
Add mint struct; random helpers; DSA snippets (DSU, segtree) as includes; stress-test harness.

## 11. Tags
`template`, `competitive-programming`, `fast-io`, `macros`, `difficulty:easy`
