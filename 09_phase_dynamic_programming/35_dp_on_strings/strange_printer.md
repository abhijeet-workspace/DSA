# Strange Printer

## Problem Statement
[LeetCode 664](https://leetcode.com/problems/strange-printer/) — printer prints contiguous same chars; min turns to print s.

- **Inputs:** string `s`.
- **Output:** min turns.
- **Valid answer:** optimal interval printing.
- **Edges:** all same; all unique.

## Intuition
Interval DP: dp[i][j] min turns for s[i..j]; if s[i]==s[k] merge turns.

## Brute Force → Optimal
- **Brute:** exponential partitions.
- **Optimal:** O(N^3) interval DP.

## Data Structure / Approach Justification
**Chosen:** dp[i][j] with split k.

## Logic Walkthrough
Base 1; for length, try splits; same char reduces.

## Dry Run
aaabbb -> **2**.

## Time & Space Complexity
Time **O(N^3)**. Space **O(N^2)**. Why: intervals x splits (section 4).

## Trade-offs & Alternatives
Remove consecutive duplicates first as optimization.

## Common Mistakes / Edge Cases
Off-by-one intervals.

## Interview Follow-ups / Variations
Burst Balloons style interval DP.

## Tags
`string-dp`, `interval-dp`, `leetcode-664`, `difficulty:hard`
