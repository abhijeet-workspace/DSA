# Longest Arithmetic Subsequence

## Problem Statement
[LeetCode 1027](https://leetcode.com/problems/longest-arithmetic-subsequence/) — longest arithmetic subsequence length.

- **Inputs:** `nums`.
- **Output:** length.
- **Valid answer:** max over common differences.
- **Edges:** n=2; negatives.

## Intuition
dp[i][d] = best length ending at i with difference d.

## Brute Force → Optimal
- **Brute:** all pairs as AP start.
- **Optimal:** O(N^2) DP.

## Data Structure / Approach Justification
**Chosen:** vector of unordered_map at each index.

## Logic Walkthrough
For i>j: d=nums[i]-nums[j]; dp[i][d]=dp[j][d]+1 (or 2).

## Dry Run
[3,6,9,12] -> **4**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N^2)**. Why: each pair (section 4).

## Trade-offs & Alternatives
Given-difference variant is O(N) (1218).

## Common Mistakes / Edge Cases
Not handling negative diffs.

## Interview Follow-ups / Variations
LAS of Given Difference (1218).

## Tags
`lis`, `dp`, `leetcode-1027`, `difficulty:medium`
