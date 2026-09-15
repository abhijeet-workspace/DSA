# Inversions Fenwick Compressed

## 1. Problem Statement
Count pairs `(i,j)` with `i < j` and `a[i] > a[j]` (inversions). Related: [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/).

- **Inputs:** integer array (possibly large/sparse values).
- **Output:** total inversion count as `long long`.
- **Valid answer:** number of strictly greater-before pairs; equals are not inversions.
- **Edges:** sorted ascending (0); descending `N(N-1)/2`; all duplicates (0).

## 2. Intuition
Process left→right. Before inserting `a[i]`, query how many already-seen values have rank `> rank[i]`. Compress so Fenwick indices are `1..U`.

## 3. Brute Force → Optimal
- **Brute:** check all pairs — `O(N²)`.
- **Optimal:** compress + Fenwick counts — `O(N log N)`.

## 4. Data Structure / Approach Justification

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree
topic owns tree ops; here the skill is sparse→`1..U`.

**Chosen:** Fenwick of occurrence counts on compressed ranks.

- **vs merge-sort counting:** no compression needed; natural during merge.
- **vs policy-based order statistics:** shorter in GCC contests; less portable.

## 5. Logic Walkthrough
Compress to ranks. For each rank `r`: `inv += seen - sumPrefix(r)`, then `add(r,1)`.

## 6. Dry Run
`[3,1,2]` → ranks `[3,1,2]`:
- insert 3; at 1 query ranks `>1` → 1; at 2 query ranks `>2` → 1; total **2**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: Fenwick prefix gives counts ≤ `r`; complement gives greater (section 4).

## 8. Trade-offs & Alternatives
Fenwick is short and fast; merge sort needs no compression. Process right→left for “smaller after self” style.

## 9. Common Mistakes / Edge Cases
Treating equals as inversions; 0-based Fenwick off-by-one; sizing tree from `max(a[i])` without compression.

## 10. Interview Follow-ups / Variations
LC 315 count-of-smaller-after-self? Inversions with updates?

## 11. Tags
`fenwick`, `coordinate-compression`, `inversions`, `counting`, `difficulty:medium`
