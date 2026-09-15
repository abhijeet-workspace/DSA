# Palindrome Partitioning II

## Problem Statement
[LeetCode 132](https://leetcode.com/problems/palindrome-partitioning-ii/) — min cuts so every substring is a palindrome.

- **Inputs:** string `s`.
- **Output:** min cuts.
- **Valid answer:** fewest cuts.
- **Edges:** already palindrome -> 0; all unique.

## Intuition
Precompute palindrome table; dp[i]=min cuts for prefix s[0..i).

## Brute Force → Optimal
- **Brute:** all partitions.
- **Optimal:** O(N^2) pal + DP.

## Data Structure / Approach Justification
**Chosen:** isPal[i][j] + cuts[i].

## Logic Walkthrough
For end j, try start i if isPal[i][j]: cuts[j+1]=cuts[i]+1.

## Dry Run
aab -> **1**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N^2)**. Why: palindrome table (section 4).

## Trade-offs & Alternatives
Expand centers to mark palindromes.

## Common Mistakes / Edge Cases
Off-by-one on cuts array.

## Interview Follow-ups / Variations
Palindrome Partitioning (131).

## Tags
`string-dp`, `leetcode-132`, `difficulty:hard`
