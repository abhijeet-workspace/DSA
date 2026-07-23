# Fenwick Tree (Binary Indexed Tree)

## Problem Statement
Support **point updates** and **prefix / range sum queries** on a 1-indexed array (and optionally a 2D grid) in logarithmic time.

- **Inputs:** size `n`; updates `add(i, val)`; queries `rangeQuery(l, r)` (1D) or box `(r1,c1)–(r2,c2)` (2D).
- **Output:** sum over the requested range after updates.
- **Valid answer:** exact integer sum (no modular arithmetic here).
- **Edges:** `l == 1` (prefix = query only); empty prefix `query(0)`; 2D inclusion–exclusion corners.

## Intuition
Store partial sums so each index `i` owns a contiguous block ending at `i`. The block length is the lowest set bit `i & -i`. Walking with `i += lsb` updates ancestors; `i -= lsb` folds a prefix.

## Brute Force → Optimal
- **Brute:** scan `[l..r]` each query — O(N) query, O(1) update (or rebuild).
- **Prefix array:** O(1) query, O(N) update.
- **Optimal:** Fenwick — O(log N) update and query, O(N) space.

## Data Structure / Approach Justification
**Chosen:** 1-based `vector` BIT; 2D nested loops over row/col LSBs.

- **vs segment tree:** Fenwick is leaner for pure sum + point update; segtree wins for arbitrary merge ops / range assign.
- **vs sparse table:** sparse table is static RMQ/idempotent, not updates.

## Logic Walkthrough
1D: `add` loops `i += i & -i` adding `val`; `query` loops `i -= i & -i` summing. Range = `query(r) - query(l-1)`. 2D: same idea on both axes; box sum uses four corner prefixes.

## Dry Run
`nums={1,7,3,0,5,8,3}` loaded 1-indexed:
- `rangeQuery(2,5)` → 7+3+0+5 = **15**
- `add(3, 2)` then `rangeQuery(2,5)` → **17**

2D 1..9 matrix: `rangeQuery(2,2,3,3)` → 5+6+8+9 = **28**

## Time & Space Complexity
1D: update/query **O(log N)**; space **O(N)**. 2D: **O(log R · log C)** per op; space **O(RC)**. Why: each walk climbs O(log) LSB steps (section 4).

## Trade-offs & Alternatives
Fenwick is simplest for competitive-programming sum problems. Prefer segtree when you need min/max, lazy range add, or non-invertible merges. Frequency tables / order statistics are classic BIT uses.

## Common Mistakes / Edge Cases
0-indexing the tree (must be 1-based); forgetting `query(l-1)` for ranges starting at 1; negative modular hashes (N/A here) but negative 2D corners if order wrong; off-by-one on size `n+1`.

## Interview Follow-ups / Variations
Range add + point query (difference array + BIT); 2D fenwick for matrix problems; inversion count via rank fenwick.

## Tags
`fenwick`, `binary-indexed-tree`, `prefix-sum`, `range-query`, `difficulty:medium`
