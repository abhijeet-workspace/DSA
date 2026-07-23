# Activity Selection

## Problem Statement
Classic interval scheduling: maximum number of non-overlapping activities. Related to [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/).

- **Inputs:** intervals `[start, end)`.
- **Output:** max count of mutually non-overlapping intervals.
- **Valid answer:** any max-size feasible subset’s size.
- **Edges:** all overlap; touching endpoints; empty list.

## Intuition
Always take the interval that finishes earliest among remaining — it leaves the most room for future choices (exchange argument).

## Brute Force → Optimal
- **Brute:** try all subsets — exponential.
- **Optimal:** sort by end time; greedily take non-overlapping — O(N log N).

## Data Structure / Approach Justification
**Chosen:** sort by `end`, scan once keeping `lastEnd`.

- **vs DP LIS-style:** O(N²) correct but slower.
- **vs sort by start:** not always optimal.

## Logic Walkthrough
Sort by end ascending. Take first; for each next, take if `start >= lastEnd`, update `lastEnd`.

## Dry Run
`[1,3],[2,4],[3,5],[0,6]` → take `[1,3]` then `[3,5]` → count 2.

## Time & Space Complexity
Time **O(N log N)** sort. Space **O(1)** extra (aside from sort). Why: greedy after ordering by finish (section 4).

## Trade-offs & Alternatives
Unweighted greedy is optimal; weighted activity selection needs DP.

## Common Mistakes / Edge Cases
Sorting by start instead of end; treating touching endpoints as overlap when `>=` is allowed.

## Interview Follow-ups / Variations
Weighted intervals → DP. Min removals to make non-overlapping (LC 435).

## Tags
`greedy`, `intervals`, `sorting`, `difficulty:medium`
