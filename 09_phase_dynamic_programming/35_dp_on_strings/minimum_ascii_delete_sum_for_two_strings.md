# Minimum ASCII Delete Sum for Two Strings

## Problem Statement
[LeetCode 712](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) — min ASCII sum of deleted characters to make two strings equal.

- **Inputs:** `s1`, `s2`.
- **Output:** min delete ASCII sum.
- **Valid answer:** delete to LCS; cost = totalASCII - 2*LCS_ascii.
- **Edges:** empty; identical.

## Intuition
2D DP like edit distance but only deletes; cost is char ASCII.

## Brute Force → Optimal
- **Brute:** all delete sequences.
- **Optimal:** O(NM) DP.

## Data Structure / Approach Justification
**Chosen:** dp[i][j] min cost for prefixes.

## Logic Walkthrough
Match: take diag; else min(delete s1, delete s2).

## Dry Run
sea / eat -> **231**.

## Time & Space Complexity
Time **O(NM)**. Space **O(NM)**. Why: edit-style (section 4).

## Trade-offs & Alternatives
Equivalent to weighted LCS.

## Common Mistakes / Edge Cases
Using length LCS not ASCII weights.

## Interview Follow-ups / Variations
Edit Distance (72); Delete Operation (583).

## Tags
`string-dp`, `leetcode-712`, `difficulty:medium`
