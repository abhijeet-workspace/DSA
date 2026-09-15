# Number of Ways to Form a Target String Given a Dictionary

## Problem Statement
[LeetCode 1639](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/) — form target using words as columns; count ways mod 1e9+7.

- **Inputs:** `words`, `target`.
- **Output:** ways mod 10^9+7.
- **Valid answer:** pick increasing columns spelling target.
- **Edges:** impossible; single column.

## Intuition
Count freq of each char at each column; DP ways to form target prefix.

## Brute Force → Optimal
- **Brute:** DFS columns.
- **Optimal:** O(cols * |target| * 26) with freq.

## Data Structure / Approach Justification
**Chosen:** dp[j] ways to form target[:j]; update by column.

## Logic Walkthrough
For each column, update dp backward using freq[col][char].

## Dry Run
words=[acca,bbbb,caca], target=aba -> **6**.

## Time & Space Complexity
Time **O(C*|target|)**. Space **O(|target|)**. Why: string DP (section 4).

## Trade-offs & Alternatives
Must process columns left-to-right once each.

## Common Mistakes / Edge Cases
Forward update double-counting.

## Interview Follow-ups / Variations
Distinct Subsequences (115).

## Tags
`string-dp`, `leetcode-1639`, `difficulty:hard`
