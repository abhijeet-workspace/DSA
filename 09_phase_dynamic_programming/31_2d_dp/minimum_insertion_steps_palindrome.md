# Minimum Insertion Steps to Make a String Palindrome

## Problem Statement
[LeetCode 1312](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) — minimum insertions (any positions) to make `s` a palindrome.

- **Inputs:** string `s`.
- **Output:** min insertion count.
- **Valid answer:** equals `n - LPS(s)`.
- **Edges:** already palindrome → 0; length 1; all distinct chars.

## Intuition
Keep a longest palindromic subsequence; every other character needs a mirror insert → `n - LPS`. LPS of `s` is LCS(`s`, reverse(`s`)).

## Brute Force → Optimal
- **Brute:** try inserts / interval DP without reuse — heavier.
- **Optimal:** LCS with reverse — O(N²).

## Data Structure / Approach Justification
**Chosen:** rolling LCS of `s` and `rev(s)`.

- **vs interval DP `dp[i][j]` for substring:** classic palindrome DP; same O(N²).
- **vs expansions:** for substring palindromes, not subsequence.

## Logic Walkthrough
`rev = reverse(s)`. `LPS = LCS(s, rev)`. Return `n - LPS`.

## Dry Run
`"mbadm"`: LPS length 3 (e.g. `madam` core) → insertions **2**. `"zzazz"` already palindrome → **0**.

## Time & Space Complexity
Time **O(N²)**. Space **O(N)**. Why: LCS of two length-N strings (section 4).

## Trade-offs & Alternatives
Interval DP states “min inserts on `s[i..j]`” more direct for teaching without LCS.

## Common Mistakes / Edge Cases
Confusing LPS with longest palindromic **substring**; mutating `s` while reversing without a copy.

## Interview Follow-ups / Variations
Min deletions to palindrome (same `n-LPS`); min replacements; construct one resulting palindrome.

## Tags
`string-dp`, `2d-dp`, `lcs`, `palindrome`, `leetcode-1312`, `difficulty:hard`
