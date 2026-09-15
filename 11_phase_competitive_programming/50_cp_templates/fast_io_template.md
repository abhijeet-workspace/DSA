# Fast IO Template

## 1. Problem Statement
Teaching-lab — contest fast-IO boilerplate: disable sync with C stdio and untie `cin`/`cout`.

- **Inputs (demo):** hardcoded array.
- **Output:** sum and OK/FAIL.
- **Edges:** large input volume in real contests (not shown here).

## 2. Intuition
IO bottlenecks dominate when Q·log factors are fine but flushing/`endl`/`tie` costs dominate.

## 3. Brute Force → Optimal
- **Brute:** default sync + `endl` every line.
- **Optimal:** `sync_with_stdio(false)` + `cin.tie(nullptr)` (+ avoid `endl`).

## 4. Data Structure / Approach Justification
**Chosen:** classic CF/AtCoder FAST_IO pair.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

- **vs `scanf`:** C++ streams with untie are usually enough.
- **vs file IO:** same flags; freopen optional.

## 5. Logic Walkthrough
Enable flags once in `main`, then read/write normally.

## 6. Dry Run
Demo array sums to 14.

## 7. Time & Space Complexity
Flags **O(1)** setup. Demo sum **O(n)**.

## 8. Trade-offs & Alternatives
Some judges prefer `getchar`/custom scanners for extreme TL; start with this.

## 9. Common Mistakes / Edge Cases
Leaving `tie` on; mixing `printf` after untie without care.

## 10. Interview Follow-ups / Variations
Add `cout << fixed << setprecision`; buffered `cerr` for debug.

## 11. Tags
`template`, `fast-io`, `contest`, `difficulty:easy`
