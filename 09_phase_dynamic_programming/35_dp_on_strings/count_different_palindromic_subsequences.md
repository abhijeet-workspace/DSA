# Count Different Palindromic Subsequences

## Problem Statement
[LeetCode 730](https://leetcode.com/problems/count-different-palindromic-subsequences/) — count distinct palindromic subsequences mod 1e9+7.

- **Inputs:** string `s` (letters a-d typically).
- **Output:** count mod 10^9+7.
- **Valid answer:** distinct palindromic subsequences.
- **Edges:** single char; all same.

## Intuition
Interval DP by first/last char; handle inner duplicates carefully.

## Brute Force → Optimal
- **Brute:** all subsequences.
- **Optimal:** O(N^2) DP with next/prev char positions.

## Data Structure / Approach Justification
**Chosen:** dp[i][j] distinct pal subs in s[i..j].

## Logic Walkthrough
Standard LC 730 recurrence with 4 letters.

## Dry Run
bccb -> **6**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N^2)**. Why: intervals (section 4).

## Trade-offs & Alternatives
Hard edge cases with repeats.

## Common Mistakes / Edge Cases
Off-by-one on empty inner.

## Interview Follow-ups / Variations
LPS (516).

## Tags
`string-dp`, `leetcode-730`, `difficulty:hard`
