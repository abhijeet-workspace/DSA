# Longest Common Subsequence

## Problem Statement
[LeetCode 1143](https://leetcode.com/problems/longest-common-subsequence/) — length of the longest subsequence common to `text1` and `text2`.

- **Inputs:** strings `text1`, `text2`.
- **Output:** integer length (not the string).
- **Valid answer:** any max-length common subsequence’s length.
- **Edges:** empty; no overlap; identical; repeated letters.

## Intuition
On prefixes: equal last chars → `1 + LCS(i-1,j-1)`; else `max(skip text1, skip text2)`.

## Brute Force → Optimal
- **Brute:** enumerate all subsequences — exponential.
- **Optimal:** DP with two rolling rows — O(MN) time, O(min(M,N)) space.

## Data Structure / Approach Justification
**Chosen:** `prev`/`curr` rows for LCS of prefixes; swap so shorter string is the column dimension.

- **vs full 2D table:** needed if reconstructing the actual LCS.
- **vs contiguous DP (LC 718):** different problem — subsequence may skip.

## Logic Walkthrough
Match → diagonal + 1. Else max of up / left. Swap rows each `i`; clear `curr`.

## Dry Run
`abcde` vs `ace`: matches `a,c,e` → length **3**. `abc` vs `def` → **0**.

## Time & Space Complexity
Time **O(MN)**. Space **O(min(M,N))** after swap. Why: every prefix pair; shorter axis stored (section 4).

## Trade-offs & Alternatives
Full matrix for path reconstruction. Hirschberg recovers string in O(min) space with more code.

## Common Mistakes / Edge Cases
Confusing with longest common **substring**; not resetting `curr`; reading `prev[j-1]` after overwrite in 1-row DP.

## Interview Follow-ups / Variations
Print one LCS; edit distance relation; LCS of three strings.

## Tags
`string-dp`, `2d-dp`, `lcs`, `leetcode-1143`, `difficulty:medium`
