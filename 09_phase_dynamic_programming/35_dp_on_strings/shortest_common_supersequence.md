# Shortest Common Supersequence

## Problem Statement
[LeetCode 1092](https://leetcode.com/problems/shortest-common-supersequence/) — shortest string that has both str1 and str2 as subsequences.

- **Inputs:** `str1`, `str2`.
- **Output:** any SCS string.
- **Valid answer:** length = n+m-LCS; reconstruct from LCS DP.
- **Edges:** one empty; identical.

## Intuition
Build LCS table; reconstruct by walking back merging non-LCS chars.

## Brute Force → Optimal
- **Brute:** all supersequences.
- **Optimal:** O(NM) LCS + reconstruct.

## Data Structure / Approach Justification
**Chosen:** LCS DP then backtrack build.

## Logic Walkthrough
When equal take char once; else take from larger side.

## Dry Run
abac / cab -> cabac.

## Time & Space Complexity
Time **O(NM)**. Space **O(NM)**. Why: LCS (section 4).

## Trade-offs & Alternatives
Any valid SCS of min length accepted.

## Common Mistakes / Edge Cases
Forgetting to append remaining prefixes.

## Interview Follow-ups / Variations
LCS (1143).

## Tags
`string-dp`, `lcs`, `leetcode-1092`, `difficulty:hard`
