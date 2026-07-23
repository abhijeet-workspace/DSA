# 2D Prefix Sum

## Problem Statement
Preprocess a static matrix so any axis-aligned subrectangle sum answers in O(1).

Related: [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)

**Inputs:** matrix, queries `(r1,c1,r2,c2)` inclusive.  
**Valid answer:** sum of all cells in that submatrix.  
**Edges:** 1×1; full matrix; top-left at `(0,0)`.

## Intuition
Store sums of every “origin-anchored” rectangle. Any subrectangle is origin sum to bottom-right, minus the strips above and left, plus the double-subtracted corner.

## Brute Force → Optimal
- **Brute:** sum each query cell-by-cell — O(area) per query.
- **Optimal:** O(RC) build once; O(1) query via inclusion-exclusion.

## Data Structure / Approach Justification (REQUIRED)
2D `prefix` of size `(R+1)×(C+1)` with zero border.
- **vs 2D Fenwick / segment tree:** needed only if cells update.
- **vs scanning each query:** fails when query count × area is large.

## Logic Walkthrough
Build: `prefix[r][c] = cell + above + left − corner`.  
Query: `P[r2+1][c2+1] − P[r1][c2+1] − P[r2+1][c1] + P[r1][c1]`.

## Dry Run
`[[1,2],[3,4]]` whole sum = `P[2][2] = 10`.

## Time & Space Complexity
Build **O(RC)**, query **O(1)**, space **O(RC)**. Why: every cell contributes once to the table (section 4).

## Trade-offs & Alternatives
Static matrices only unless rebuilt. Updates → 2D BIT / segtree.

## Common Mistakes / Edge Cases
Sign errors in inclusion-exclusion; 1-indexed off-by-one on query bounds.

## Interview Follow-ups / Variations
How to support updates? (2D Fenwick / segment tree)

## Tags
`prefix-sum-2d`, `inclusion-exclusion`, `matrix`, `medium`
