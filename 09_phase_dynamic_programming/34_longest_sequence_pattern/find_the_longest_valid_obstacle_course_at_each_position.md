# Find the Longest Valid Obstacle Course at Each Position

## Problem Statement
[LeetCode 1964](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/) — for each index, longest non-decreasing course ending there.

- **Inputs:** `obstacles`.
- **Output:** ans[i] lengths.
- **Valid answer:** non-decreasing LIS ending at i.
- **Edges:** strictly decreasing; equal heights ok.

## Intuition
Patience sorting tails for non-decreasing; ans[i]=position in tails.

## Brute Force → Optimal
- **Brute:** O(N^2) DP.
- **Optimal:** O(N log N) tails upper_bound.

## Data Structure / Approach Justification
**Chosen:** tails of min end for each length; upper_bound for <=.

## Logic Walkthrough
For each x: pos = upper_bound; replace/append; ans=pos+1.

## Dry Run
[1,2,3,2] -> [1,2,3,3].

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: patience (section 4).

## Trade-offs & Alternatives
Strict increasing would use lower_bound.

## Common Mistakes / Edge Cases
Using lower_bound for non-decreasing.

## Interview Follow-ups / Variations
LIS (300).

## Tags
`lis`, `binary-search`, `leetcode-1964`, `difficulty:hard`
