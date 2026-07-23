# Palindromic Substrings

## Problem Statement
[LeetCode 647](https://leetcode.com/problems/palindromic-substrings/) — count how many substrings of `s` are palindromes.

- **Inputs:** string `s`.
- **Output:** integer count.
- **Valid answer:** every palindromic substring counted once (single chars included).
- **Edges:** single char; empty; all identical (`"aaa"` → 6).

## Intuition
Same expand-around-center as LC 5; each successful expansion step counts one palindrome. Every palindromic substring is discovered from its center.

## Brute Force → Optimal
- **Brute:** test every substring — O(N³).
- **Optimal:** expand centers — O(N²)/O(1).

## Data Structure / Approach Justification
**Chosen:** expand-around-center counter — O(1) extra space.

- **vs DP table `dp[i][j]`:** O(N²) space; same time.
- **vs counting only maximal palindromes:** undercounts nested ones like `"aaa"`.

## Logic Walkthrough
For each center, expand while chars match; increment `ans` each step. Odd `(i,i)` and even `(i,i+1)`.

## Dry Run
`"aaa"` → 6: `"a","a","a","aa","aa","aaa"`. `"abc"` → 3 (only singles).

## Time & Space Complexity
Time **O(N²)**. Space **O(1)**. Why: 2N centers × O(N) expand (section 4).

## Trade-offs & Alternatives
Expand reuses LC 5 muscle memory with O(1) space. DP is clearer for some but heavier on memory.

## Common Mistakes / Edge Cases
Counting only maximal palindromes, not every expansion step; skipping even centers.

## Interview Follow-ups / Variations
Longest palindromic substring (5); palindromic subsequence (516).

## Tags
`string`, `expand-around-center`, `palindrome`, `difficulty:medium`
