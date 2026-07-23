# Longest Palindromic Subsequence

## Problem Statement
[LeetCode 516](https://leetcode.com/problems/longest-palindromic-subsequence/) — length of the longest subsequence of `s` that is a palindrome.

- **Inputs:** string `s`.
- **Output:** integer length.
- **Valid answer:** any max-length palindromic subsequence’s length.
- **Edges:** length 1; all same chars; already palindrome; no pairs.

## Intuition
A palindrome reads the same forward/back → LPS length equals LCS of `s` and `reverse(s)`.

## Brute Force → Optimal
- **Brute:** all subsequences, check palindrome — exponential.
- **Optimal:** LCS(`s`, `rev(s)`) with rolling DP — O(N²) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** reduce to LCS via reverse; reuse classic 2-row DP.

- **vs interval DP `dp[i][j]` on `s[i..j]`:** equally standard; more direct but same O(N²).
- **vs expand-around-center:** works for **substring**, not subsequence.

## Logic Walkthrough
`rev = reverse(s)`. Run LCS: match → `1+prev[j-1]`; else max(up,left). Return LCS length.

## Dry Run
`s=bbbab`, `rev=babbb`: LCS length **4** (e.g. `bbbb`).

## Time & Space Complexity
Time **O(N²)**. Space **O(N)** rolling rows. Why: LCS on two length-N strings (section 4).

## Trade-offs & Alternatives
Interval DP avoids building `rev` explicitly. Reconstruct subsequence needs full table or Hirschberg.

## Common Mistakes / Edge Cases
Solving longest palindromic **substring** (5) instead; off-by-one on single-char base in interval form.

## Interview Follow-ups / Variations
Count palindromic subsequences; longest palindromic substring; print one LPS.

## Tags
`string-dp`, `2d-dp`, `palindrome`, `lcs`, `leetcode-516`, `difficulty:medium`
