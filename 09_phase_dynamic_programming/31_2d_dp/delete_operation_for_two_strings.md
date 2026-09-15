# Delete Operation for Two Strings

## Problem Statement
[LeetCode 583](https://leetcode.com/problems/delete-operation-for-two-strings/) — minimum deletions to make `word1` and `word2` equal (only delete allowed).

- **Inputs:** two strings.
- **Output:** min total deletions.
- **Valid answer:** equal to edit distance with insert/replace forbidden equivalently via LCS.
- **Edges:** identical; disjoint alphabets; one empty.

## Intuition
Characters kept form an LCS. Delete everything else from both → `m + n - 2·LCS`.

## Brute Force → Optimal
- **Brute:** try all deletion sequences — exponential.
- **Optimal:** LCS DP then formula — O(MN).

## Data Structure / Approach Justification
**Chosen:** rolling-row LCS + closed form.

- **vs direct DP `dp[i][j]` min deletes on prefixes:** same complexity, more states to reason about.
- **vs edit distance (72):** related; here only deletes.

## Logic Walkthrough
Compute `L = LCS(word1,word2)`. Return `m+n-2*L`.

## Dry Run
`"sea"`,`"eat"`: LCS `"ea"` length 2 → deletions **2**.

## Time & Space Complexity
Time **O(MN)**. Space **O(min(M,N))**. Why: classic LCS (section 4).

## Trade-offs & Alternatives
Full 2D delete DP mirrors intuition without naming LCS.

## Common Mistakes / Edge Cases
Using LCS of contiguous substring; forgetting both sides’ deletions; off-by-one on empty string.

## Interview Follow-ups / Variations
Allow insert too (edit distance); make equal with replace cost; print kept subsequence.

## Tags
`string-dp`, `2d-dp`, `lcs`, `leetcode-583`, `difficulty:medium`
