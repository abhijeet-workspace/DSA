# Scramble String

## Problem Statement
[LeetCode 87](https://leetcode.com/problems/scramble-string/) — can s2 be a scramble of s1 by recursively splitting and optionally swapping?

- **Inputs:** `s1`, `s2`.
- **Output:** bool.
- **Valid answer:** true iff scramble tree exists.
- **Edges:** unequal length; identical; anagrams only.

## Intuition
Interval DP / memo: try every split; match without or with swap.

## Brute Force → Optimal
- **Brute:** all scramble trees.
- **Optimal:** memo O(N^4) with pruning by counts.

## Data Structure / Approach Justification
**Chosen:** memo on (i1,i2,len) substrings.

## Logic Walkthrough
If equal return true; if counts differ false; try splits.

## Dry Run
great / rgeat -> **true**.

## Time & Space Complexity
Time **O(N^4)**. Space **O(N^3)**. Why: states x splits (section 4).

## Trade-offs & Alternatives
3D bottom-up DP also common.

## Common Mistakes / Edge Cases
Skipping anagram prune.

## Interview Follow-ups / Variations
Interleaving String (97).

## Tags
`string-dp`, `leetcode-87`, `difficulty:hard`
