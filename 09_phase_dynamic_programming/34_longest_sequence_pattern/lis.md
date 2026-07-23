# Longest Increasing Subsequence

## Problem Statement
[LeetCode 300](https://leetcode.com/problems/longest-increasing-subsequence/) — length of the longest **strictly** increasing subsequence (not necessarily contiguous).

- **Inputs:** `vector<int> nums`.
- **Output:** `int` length.
- **Valid answer:** max over all increasing subsequences.
- **Edges:** empty → 0; strictly decreasing → 1; duplicates (strict `<`).

## Intuition
`dp[i]` = LIS length ending at index `i`. Extend any earlier `j` with `nums[j] < nums[i]`.

## Brute Force → Optimal
- **Brute:** all subsequences — O(2^N).
- **Shown:** O(N²) DP.
- **Faster:** patience sorting / tails binary search — O(N log N).

## Data Structure / Approach Justification
**Chosen:** `vector<int> dp(n, 1)` + nested scan.

- **vs patience tails:** interview follow-up; length only unless you track parents.
- **vs LCS with sorted unique:** works but heavier and mishandles duplicates.

## Logic Walkthrough
Init each `dp[i]=1`. For `i`, for `j < i` with `nums[j] < nums[i]`, `dp[i] = max(dp[i], dp[j]+1)`. Track global max.

## Dry Run
`[10,9,2,5,3,7,101,18]`:
- build e.g. `2,3,7,101` → length **4**.

## Time & Space Complexity
Time **O(N²)** (shown). Space **O(N)**. Why: each pair `(j,i)` considered once (section 4).

## Trade-offs & Alternatives
N² is clearest. Mention O(N log N) tails for production/follow-up. Reconstruct path needs parent pointers.

## Common Mistakes / Edge Cases
Substring vs subsequence; non-strict `<=` when problem wants strict; empty array.

## Interview Follow-ups / Variations
O(N log N) LIS; reconstruct one LIS; Russian Doll Envelopes (354); longest decreasing.

## Tags
`dp`, `lis`, `sequence`, `leetcode-300`, `difficulty:medium`
