# Minimum Falling Path Sum II

## Problem Statement
[LeetCode 1289](https://leetcode.com/problems/minimum-falling-path-sum-ii/) — like 931 but next cell must be a different column.

- **Inputs:** `n×n` grid.
- **Output:** min falling path sum.
- **Valid answer:** no two consecutive same column.
- **Edges:** n=1; n=2.

## Intuition
Per row keep two smallest values (and indices) from previous row.

## Brute Force → Optimal
- **Brute:** O(N³) try all next columns.
- **Optimal:** O(N²) with top-2 mins per row.

## Data Structure / Approach Justification
**Chosen:** track first/second min of previous row.

- **vs naive O(N³):** TLE when n~200.

## Logic Walkthrough
For each cell, add prev first-min if different col else second-min.

## Dry Run
[[1,2,3],[4,5,6],[7,8,9]] → **13**.

## Time & Space Complexity
Time **O(N²)**. Space **O(N)**. Why: each cell + top2 scan (section 4).

## Trade-offs & Alternatives
Full prev row min over ≠c is O(N³).

## Common Mistakes / Edge Cases
Using same column; forgetting update of top-2 indices.

## Interview Follow-ups / Variations
Falling Path Sum I (931).

## Tags
`grid-dp`, `leetcode-1289`, `difficulty:hard`
