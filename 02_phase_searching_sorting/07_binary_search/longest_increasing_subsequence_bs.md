# Longest Increasing Subsequence (Binary Search)

## Problem Statement
[LeetCode 300](https://leetcode.com/problems/longest-increasing-subsequence/) — length of the longest strictly increasing subsequence (not necessarily contiguous).

- **Inputs:** `vector<int> nums`.
- **Output:** `int` length.
- **Valid answer:** patience-sort pile count.
- **Edges:** empty; strictly decreasing (answer 1); duplicates.

## Intuition
`tails` is sorted. Each new `x` replaces the first tail ≥ x (lower bound), or extends the LIS.

## Brute Force → Optimal
- **Brute:** O(N²) DP `dp[i] = 1 + max dp[j]`.
- **Optimal:** patience sorting — O(N log N).

## Data Structure / Approach Justification
**Chosen:** binary search as a tool inside LIS (study-plan group “As A Tool”).

- **vs DP:** N² is simpler to reconstruct the sequence
- **vs Fenwick/seg on compressed values:** also N log N; heavier

## Logic Walkthrough
For each x, `lower_bound` in tails; replace or append.

## Dry Run
`[10,9,2,5,3,7,101,18]` → length 4 (`2,3,7,18`).

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: N lower_bounds on a tails array of size ≤ N.

## Trade-offs & Alternatives
The N² DP in `09_phase_dynamic_programming/.../lis.cpp` reconstructs more easily.

## Common Mistakes / Edge Cases
Using upper_bound (allows non-strict); thinking tails is an actual subsequence.

## Interview Follow-ups / Variations
Russian doll envelopes (354); LIS compressed Fenwick.

## Tags
`binary-search`, `patience-sort`, `leetcode-300`, `difficulty:medium`
