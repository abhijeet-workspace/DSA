# Longest Palindromic Subsequence

## Problem Statement
[LeetCode 516](https://leetcode.com/problems/longest-palindromic-subsequence/) — length of longest palindromic subsequence.

- **Inputs:** string `s`.
- **Output:** length.
- **Valid answer:** max LPS length.
- **Edges:** empty; all unique; all same.

## Intuition
LCS(s, reverse(s)) or interval DP dp[i][j].

## Brute Force → Optimal
- **Brute:** subsequences.
- **Optimal:** O(N^2) interval DP.

## Data Structure / Approach Justification
**Chosen:** dp[i][j] = 2+dp[i+1][j-1] if match else max(skip ends).

## Logic Walkthrough
Fill by increasing length.

## Dry Run
bbbab -> **4**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N^2)** or O(N). Why: intervals (section 4).

## Trade-offs & Alternatives
Same as 31 folder longest_palindromic_subseq.

## Common Mistakes / Edge Cases
Confusing with substring.

## Interview Follow-ups / Variations
Palindrome Partitioning II (132).

## Tags
`string-dp`, `leetcode-516`, `difficulty:medium`
