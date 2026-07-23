# Search a 2D Matrix

## Problem Statement
[LeetCode 74](https://leetcode.com/problems/search-a-2d-matrix/) — matrix rows sorted left→right; first of each row > last of previous. Return whether `target` exists.

- **Inputs:** `vector<vector<int>> a` (m×n), `int target`.
- **Output:** `true` / `false`.
- **Valid answer:** membership only.
- **Edges:** empty matrix; single cell; target outside range.

## Intuition
Treat the matrix as one sorted virtual array of length `m*n`; map mid index → `(mid/n, mid%n)`.

## Brute Force → Optimal
- **Brute:** scan all cells — O(MN).
- **Optimal:** 1D binary search over flattened index — O(log(MN)).

## Data Structure / Approach Justification
**Chosen:** flatten indexing with `lo=0`, `hi=m*n-1`.

- **vs row then column BS:** also O(log M + log N); flatten is one loop.
- **vs staircase from corner (LC 240):** works without row-start monotonicity; here flatten is enough.

## Logic Walkthrough
`v = a[mid/n][mid%n]`. Equal → true. Too small → `lo = mid+1`. Else `hi = mid-1`.

## Dry Run
`{{1,3,5},{7,9,11}}`, target `9`:
- indices 0..5; mid lands on `9` → true

## Time & Space Complexity
Time **O(log(MN))**. Space **O(1)**. Why: binary search on MN cells (section 4).

## Trade-offs & Alternatives
If only rows are sorted (not globally), use per-row search or LC 240 staircase.

## Common Mistakes / Edge Cases
Wrong column count in `% n`; empty `a[0]`; overflow if using `m*n` naively on huge dims (use 64-bit if needed).

## Interview Follow-ups / Variations
Search II (240); Young tableau extraction.

## Tags
`binary-search`, `matrix`, `difficulty:medium`
