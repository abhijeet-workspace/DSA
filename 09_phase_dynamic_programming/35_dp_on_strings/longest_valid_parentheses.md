# Longest Valid Parentheses

## Problem Statement
[LeetCode 32](https://leetcode.com/problems/longest-valid-parentheses/) — length of longest valid parentheses substring.

- **Inputs:** string `s` of '(' and ')'.
- **Output:** length.
- **Valid answer:** max valid contiguous length.
- **Edges:** empty; all invalid.

## Intuition
DP: dp[i] length of valid ending at i; or stack of indices.

## Brute Force → Optimal
- **Brute:** check all substrings.
- **Optimal:** O(N) DP or stack.

## Data Structure / Approach Justification
**Chosen:** DP on ')'.

## Logic Walkthrough
If s[i]=')': look matching; extend with previous valid.

## Dry Run
(() -> **2**; )()()) -> **4**.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: one pass (section 4).

## Trade-offs & Alternatives
Two-counter left/right scan also O(1) space.

## Common Mistakes / Edge Cases
Stack off-by-one.

## Interview Follow-ups / Variations
Valid Parentheses (20).

## Tags
`string-dp`, `stack`, `leetcode-32`, `difficulty:hard`
