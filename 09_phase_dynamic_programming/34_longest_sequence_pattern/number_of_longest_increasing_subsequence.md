# Number of Longest Increasing Subsequence

## Problem Statement
[LeetCode 673](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) — count LIS of maximum length.

- **Inputs:** `nums`.
- **Output:** number of LIS.
- **Valid answer:** count of LIS with max length.
- **Edges:** all equal; strictly decreasing.

## Intuition
Track len[i] and cnt[i] for LIS ending at i; combine when extending.

## Brute Force → Optimal
- **Brute:** enumerate subsequences.
- **Optimal:** O(N^2) DP with counts.

## Data Structure / Approach Justification
**Chosen:** parallel arrays len/cnt.

- **vs Fenwick:** O(N log N) advanced.

## Logic Walkthrough
If nums[j]<nums[i]: update len/cnt; if equal len, add counts.

## Dry Run
[1,3,5,4,7] -> **2**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N)**. Why: pairs (j,i) (section 4).

## Trade-offs & Alternatives
Segment tree for faster follow-up.

## Common Mistakes / Edge Cases
Resetting count instead of adding.

## Interview Follow-ups / Variations
LIS (300).

## Tags
`lis`, `dp`, `leetcode-673`, `difficulty:medium`
