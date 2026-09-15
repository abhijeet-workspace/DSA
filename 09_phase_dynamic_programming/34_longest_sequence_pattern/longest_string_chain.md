# Longest String Chain

## Problem Statement
[LeetCode 1048](https://leetcode.com/problems/longest-string-chain/) — longest chain where each word adds exactly one letter.

- **Inputs:** `words`.
- **Output:** longest chain length.
- **Valid answer:** predecessor chain length.
- **Edges:** no chains; single letters.

## Intuition
Sort by length; DP like LIS where edge = delete-one-char predecessor.

## Brute Force → Optimal
- **Brute:** DAG path exponential.
- **Optimal:** O(N*L^2) with hash.

## Data Structure / Approach Justification
**Chosen:** map word->best length; try delete each char.

## Logic Walkthrough
Sort; for each word try all one-char deletions present in map.

## Dry Run
[a,b,ba,bca,bda,bdca] -> **4**.

## Time & Space Complexity
Time **O(N log N + N*L^2)**. Space **O(N*L)**. Why: each word x L deletes (section 4).

## Trade-offs & Alternatives
Build explicit graph + topo DP.

## Common Mistakes / Edge Cases
Not sorting by length.

## Interview Follow-ups / Variations
LIS pattern.

## Tags
`lis`, `string`, `leetcode-1048`, `difficulty:medium`
