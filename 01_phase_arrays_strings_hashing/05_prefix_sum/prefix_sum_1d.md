# 1D Prefix Sum

## Problem Statement
Preprocess a static array so any contiguous range sum `arr[l..r]` (inclusive) answers in O(1).

Related: [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)

**Inputs:** array `arr`, many queries `(l, r)`.  
**Valid answer:** exact sum of elements from `l` to `r`.  
**Edges:** `l=0`, `l=r`, empty array, negatives.

## Intuition
If you already know the sum from the start up to every index, a range sum is just “sum to `r` minus sum to before `l`.”

## Brute Force → Optimal
- **Brute:** for each query, loop `l..r` — O(N) per query → too slow for many queries.
- **Optimal:** build `prefix` once in O(N); each query is O(1) subtraction.

## Data Structure / Approach Justification (REQUIRED)
1-indexed-style `prefix` vector of size `N+1` with `prefix[0]=0`.
- **vs Fenwick / segment tree:** those support updates; overkill for immutable arrays.
- **vs recomputing each query:** wastes repeated work when the array never changes.

## Logic Walkthrough
`prefix[i+1] = prefix[i] + arr[i]`. Then `query(l,r) = prefix[r+1] - prefix[l]`.

## Dry Run
`arr=[3,1,4,1]` → `prefix=[0,3,4,8,9]`.  
`sum[1..2] = prefix[3]-prefix[1] = 8-3 = 5`.

## Time & Space Complexity
Build **O(N)** time / **O(N)** space. Query **O(1)**. Why: one linear scan stores all left-anchored sums (section 4).

## Trade-offs & Alternatives
Fast queries, static only. Point/range updates need Fenwick or segment tree (or rebuild).

## Common Mistakes / Edge Cases
Off-by-one on 0- vs 1-indexed prefix; forgetting `prefix[0]=0` for ranges starting at 0.

## Interview Follow-ups / Variations
Support point updates efficiently? Prefers Fenwick/segment tree.

## Tags
`prefix-sum`, `range-query`, `array`, `easy`
