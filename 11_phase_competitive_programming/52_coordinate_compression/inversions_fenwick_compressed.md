# Inversions Fenwick Compressed

## Problem Statement
Count pairs `(i,j)` with `i < j` and `a[i] > a[j]` (inversions). Related: [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/).

- **Inputs:** integer array (possibly large/sparse values).
- **Output:** total inversion count as `long long`.
- **Valid answer:** number of strictly greater-before pairs; equals are not inversions.
- **Edges:** sorted ascending (0); descending `N(N-1)/2`; all duplicates (0).

## Intuition
Process left→right. Before inserting `a[i]`, query how many already-seen values have rank `> rank[i]`. Compress so Fenwick indices are `1..U`.

## Brute Force → Optimal
- **Brute:** check all pairs — `O(N²)`.
- **Optimal:** compress + Fenwick counts — `O(N log N)`.

## Data Structure / Approach Justification
**Chosen:** Fenwick of occurrence counts on compressed ranks.

- **vs merge-sort counting:** no compression needed; natural during merge.
- **vs policy-based order statistics:** shorter in GCC contests; less portable.

## Logic Walkthrough
Compress to ranks. For each rank `r`: `inv += seen - sumPrefix(r)`, then `add(r,1)`.

## Dry Run
`[3,1,2]` → ranks `[3,1,2]`:
- insert 3; at 1 query ranks `>1` → 1; at 2 query ranks `>2` → 1; total **2**.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: Fenwick prefix gives counts ≤ `r`; complement gives greater (section 4).

## Trade-offs & Alternatives
Fenwick is short and fast; merge sort needs no compression. Process right→left for “smaller after self” style.

## Common Mistakes / Edge Cases
Treating equals as inversions; 0-based Fenwick off-by-one; sizing tree from `max(a[i])` without compression.

## Interview Follow-ups / Variations
LC 315 count-of-smaller-after-self? Inversions with updates?

## Tags
`fenwick`, `coordinate-compression`, `inversions`, `counting`, `difficulty:medium`
