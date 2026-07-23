# Sparse Table (Range Minimum Query)

## Problem Statement
Answer many **static** range minimum queries (RMQ) on an array with no updates.

- **Inputs:** array `a`; queries inclusive `[L, R]`.
- **Output:** `min(a[L..R])`.
- **Valid answer:** the minimum value in the range.
- **Edges:** `N=1`; full-range query; negative values.

## Intuition
Precompute answers for every interval whose length is a power of two. Any range length `len` is covered by two overlapping blocks of length `2^⌊log₂ len⌋`. Overlap is fine because min is idempotent.

## Brute Force → Optimal
- **Brute:** scan each query — O(N) per query.
- **Segment tree:** O(N) build, O(log N) query, supports updates.
- **Optimal static:** sparse table — O(N log N) build, O(1) query.

## Data Structure / Approach Justification
**Chosen:** `st[k][i]` = min on `[i, i+2^k)`; `lg[]` for floor-log.

- **vs segtree:** faster queries, no updates.
- **vs Fenwick:** Fenwick targets sums/prefixes, not static RMQ.

## Logic Walkthrough
Fill `st[0]` with `a`. For `k≥1`, `st[k][i] = min(st[k-1][i], st[k-1][i+2^{k-1}])`. Query: `k = lg[R-L+1]`; return `min(st[k][L], st[k][R-2^k+1])`.

## Dry Run
`a={1,3,-2,8,5,-4,7}`:
- `query(1,4)` → min(3,-2,8,5) = **-2**
- `query(0,6)` → **-4**

## Time & Space Complexity
Build **O(N log N)**; query **O(1)**; space **O(N log N)**. Why: O(log N) layers × N starts (section 4).

## Trade-offs & Alternatives
Use when the array is immutable and query count is large. If updates appear, switch to a segment tree. Works for any idempotent op (min, max, gcd); **not** for sum with overlapping blocks.

## Common Mistakes / Edge Cases
Using sparse table for sum (double-counting overlap); wrong `R - (1<<k) + 1`; forgetting `lg` precompute; empty range.

## Interview Follow-ups / Variations
LCA via Euler tour + RMQ; range GCD; Cartesian tree / Fischer–Heun for O(N)/O(1) RMQ.

## Tags
`sparse-table`, `rmq`, `static`, `idempotent`, `difficulty:medium`
