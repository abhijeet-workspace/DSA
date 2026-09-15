# Debug Macro Template

## 1. Problem Statement
Teaching-lab — `debug(x)` expands only when compiled with `-DLOCAL`; submissions compile without it and drop prints.

- **Output:** sum demo; with `-DLOCAL`, also `n = 4` on stderr.

## 2. Intuition
Keep instrumentation without editing source before submit.

## 3. Brute Force → Optimal
- **Brute:** leave `cerr` prints forever.
- **Optimal:** macro gated by `LOCAL`.

## 4. Data Structure / Approach Justification
**Chosen:** single-arg debug macro to `cerr`.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

## 5. Logic Walkthrough
Define `#ifdef LOCAL` / `#else` empty macro; use freely in solve.

## 6. Dry Run
Without LOCAL: only `sum=6`. With LOCAL: stderr shows `n = 4`.

## 7. Time & Space Complexity
Macro overhead **O(1)** when disabled (empty).

## 8. Trade-offs & Alternatives
Variadic debug like competitive_template; pretty-print containers.

## 9. Common Mistakes / Edge Cases
Forgetting to strip `-DLOCAL` on submit platforms that keep flags.

## 10. Interview Follow-ups / Variations
Timer macros; assert helpers.

## 11. Tags
`template`, `debug`, `macros`, `difficulty:easy`
