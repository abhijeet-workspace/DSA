# K-th Between Two Versions

## 1. Problem Statement
Given chairman-tree prefix versions of a sequence, find the k-th smallest value in subarray `[L,R]` using `root[R] - root[L-1]`.

- **Inputs:** array `a` (compressed), queries `(L,R,k)` 1-based.
- **Output:** k-th order statistic in range.
- **Edges:** k=1; full array; duplicates.

## 2. Intuition
Difference of two persistent frequency trees encodes the multiset of the range.

## 3. Brute Force → Optimal
- **Brute:** copy subarray and sort.
- **Chairman:** O(log U) per query after O(N log U) build.

## 4. Data Structure / Approach Justification
**Chosen:** persistent freq segtree on compressed values (same idea as `persistent_segtree_kth`).

| Alternative | Note |
|-------------|------|
| Merge-sort tree | O(log² N) |
| Wavelet tree | Related |

## 5. Logic Walkthrough
1. Compress values.
2. `root[i] = upd(root[i-1], a[i])`.
3. Walk counts on `root[R]` vs `root[L-1]`.

## 6. Dry Run
`[1,5,2,6,3,7,4]`, `[2,5]` k=3 → 5? (values 5,2,6,3 → 2,3,5) → **5**.

## 7. Time & Space Complexity
Build **O(N log U)**, query **O(log U)**.

## 8. Trade-offs & Alternatives
Standard SPOJ/CSES-style technique.

## 9. Common Mistakes / Edge Cases
Off-by-one on L-1; wrong compression rank.

## 10. Interview Follow-ups / Variations
Count ≤ x in range; distinct count.

## 11. Tags
`chairman-tree`, `kth`, `persistent`, `difficulty:hard`
