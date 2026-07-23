# Persistent SegTree — k-th in Range

## 1. Problem Statement
Given array `a[1..n]`, answer the k-th smallest in subarray `[L,R]` using prefix persistent versions.

- **Inputs:** array values, queries `(L,R,k)`.
- **Output:** k-th order statistic in that range.
- **Valid answer:** correct order statistic (with duplicates as multiset).
- **Edges:** duplicates; `k` at bounds; single-element range.

## 2. Intuition
`roots[i]` = `roots[i-1]` with +1 at compressed rank of `a[i]`. Difference tree `roots[R] - roots[L-1]` is the multiset of `[L,R]`; walk left/right by child counts.

## 3. Brute Force → Optimal
- **Brute:** copy+sort each query — O(N log N) per query.
- **Optimal:** O((N+Q) log U) with persistence.

## 4. Data Structure / Approach Justification
**Chosen:** path-copying frequency SegTree on compressed ranks.

| Alternative | Note |
|-------------|------|
| Merge-sort tree | Heavier constants; similar asymptotics |
| Wavelet tree | Strong for alphabet queries |
| Mo + fenwick | Offline only |

## 5. Logic Walkthrough
1. Compress values to ranks `1..U`.
2. Build empty tree; for each prefix, `upd` +1 at rank.
3. `kth(root[L-1], root[R])`: if left-count ≥ k go left else go right with `k - left`.

## 6. Dry Run
`a=[3,1,4,2]`, k-th in `[1,4]` with `k=2` → sorted `1,2,3,4` → **2**.

## 7. Time & Space Complexity
Time **O((N+Q) log U)**, space **O(N log U)**. Why: O(log U) new nodes per update (section 4).

## 8. Trade-offs & Alternatives
Standard advanced CP pattern. Must compress; dynamic SegTree avoids explicit U but similar idea.

## 9. Common Mistakes / Edge Cases
Not compressing; 0-based vs 1-based roots; mutating nodes in place (breaks versions).

## 10. Interview Follow-ups / Variations
Count how many ≤ x in range; add/delete online with more roots.

## 11. Tags
`persistent-segtree`, `order-statistic`, `compression`, `cp`, `difficulty:hard`
