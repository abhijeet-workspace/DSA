# Dot Product of Two Sparse Vectors

## Problem Statement
[LeetCode 1570](https://leetcode.com/problems/dot-product-of-two-sparse-vectors/) — design a sparse vector and compute dot product efficiently.

- **Inputs:** two vectors that may be mostly zeros.
- **Output:** integer dot product.
- **Edges:** all zeros; no overlapping non-zeros.

## Intuition
Store only non-zeros as sorted `(index,value)` lists; two-pointer merge for intersection.

## Brute Force → Optimal
- **Brute:** dense loop O(N).
- **Optimal:** O(L1 + L2) on non-zero counts.

## Data Structure / Approach Justification
**Chosen:** compressed list + two pointers (hash map also fine).

## Logic Walkthrough
Advance the smaller index; on equal indices multiply-add.

## Dry Run
`[1,0,0,2,3]·[0,3,0,4,0]` → `2*4=8`.

## Time & Space Complexity
Time **O(L1+L2)**. Space **O(L)** to store non-zeros.

## Trade-offs & Alternatives
Hash the shorter vector for lookups when densities differ a lot.

## Common Mistakes / Edge Cases
Assuming equal length storage incorrectly; overflow on large products.

## Interview Follow-ups / Variations
CSR sparse matrices; batched dots.

## Tags
`array`, `hash-map`, `two-pointers`, `difficulty:medium`
