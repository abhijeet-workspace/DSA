# Maximum Profit in Job Scheduling

## Problem Statement
[LeetCode 1235](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) — jobs with start, end, profit; at most one job at a time. Maximize profit.

- **Inputs:** `startTime`, `endTime`, `profit`.
- **Output:** `int` max profit.
- **Valid answer:** weighted interval scheduling DP.
- **Edges:** no overlap possible; nested jobs; equal end times.

## Intuition
Sort by end. `dp[i] = max(skip i, take i + dp[prev])` where `prev` is the last job with `end <= start_i` — found by binary search.

## Brute Force → Optimal
- **Brute:** O(N²) linear prev scan.
- **Optimal:** sort + DP + binary search prev — O(N log N).

## Data Structure / Approach Justification
**Chosen:** DP where the transition uses binary search (study-plan last group).

- **vs N² prev loop:** too slow for N=5e4
- **vs greedy by profit:** wrong

## Logic Walkthrough
Jobs as `(end, start, profit)`. `ends` stays sorted. Rightmost `end <= start` is `prev`.

## Dry Run
`[1,2,3,3] / [3,4,5,6] / [50,10,40,70]` → 120 (first + last).

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: N log searches on the prefix of ended jobs.

## Trade-offs & Alternatives
Max events II (1751) adds a “take at most k” dimension.

## Common Mistakes / Edge Cases
Using `< start` vs `<= start` (touching ends are allowed); unsorted ends array.

## Interview Follow-ups / Variations
Max events II; LIS via DP+BS.

## Tags
`binary-search`, `dp`, `intervals`, `leetcode-1235`, `difficulty:hard`
