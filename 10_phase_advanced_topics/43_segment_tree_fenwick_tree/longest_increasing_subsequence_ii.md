# Longest Increasing Subsequence II

## 1. Problem Statement
[LeetCode 2407](https://leetcode.com/problems/longest-increasing-subsequence-ii/) — LIS length with adjacent difference at most `k`.

- **Inputs:** `nums`, `k`.
- **Output:** max LIS length under the gap constraint.
- **Valid answer:** exact length.
- **Edges:** `k=0`; strictly decreasing; duplicates.

## 2. Intuition
DP: `dp[i] = 1 + max dp[j]` over `nums[i]-k ≤ nums[j] < nums[i]`. Segment tree on value domain stores max dp.

## 3. Brute Force → Optimal
- **Brute:** O(N²) DP.
- **Optimal:** segtree max query/update on values — O(N log V).

## 4. Data Structure / Approach Justification
**Chosen:** segment tree over value range `[1, maxNum]` storing max LIS ending at that value.

- **vs Fenwick max:** Fenwick needs careful max-prefix; segtree range-max is direct.

## 5. Logic Walkthrough
For each x: `best = 1 + query(x-k, x-1)`; `update(x, best)`; track global max.

## 6. Dry Run
`nums=[4,2,1,4,3,4,5,8,15], k=3` → **5**.

## 7. Time & Space Complexity
Time **O(N log V)**. Space **O(V)**.

## 8. Trade-offs & Alternatives
Coordinate compress if values are sparse/huge.

## 9. Common Mistakes / Edge Cases
Inclusive range bugs; updating before querying; allowing equal when strict increase required.

## 10. Interview Follow-ups / Variations
Classic LIS (300); Russian Doll Envelopes.

## 11. Tags
`segment-tree`, `dp`, `leetcode-2407`, `difficulty:hard`
