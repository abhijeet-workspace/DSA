# Longest Palindromic Substring

## Problem Statement
[LeetCode 5](https://leetcode.com/problems/longest-palindromic-substring/) — return the longest palindromic substring of `s` (any one if ties).

- **Inputs:** string `s`.
- **Output:** a longest palindromic substring.
- **Valid answer:** any maximal-length palindrome.
- **Edges:** empty; single char; all identical; even-length only (`abba`).

## Intuition
Expand around every center (odd and even length). Every palindrome has a unique center on a char or between chars.

## Brute Force → Optimal
- **Brute:** check all substrings — O(N³) / O(N²) with DP table.
- **Optimal here:** expand-around-center O(N²)/O(1); Manacher O(N).

## Data Structure / Approach Justification
**Chosen:** expand-around-center with two starts per index — O(1) extra space.

- **vs DP boolean table:** O(N²) space; same time.
- **vs Manacher:** linear time but harder to code correctly in interviews.

## Logic Walkthrough
For each `i`, expand `(i,i)` and `(i,i+1)`. When bounds break, length is `r-l-1`; track `start`/`best`.

## Dry Run
`"babad"` → `"bab"` or `"aba"`. `"cbbd"` → `"bb"`.

## Time & Space Complexity
Time **O(N²)** expansions. Space **O(1)** extra (output string aside). Why: 2N centers, each up to O(N) (section 4).

## Trade-offs & Alternatives
Expand is interview-standard; mention Manacher as advanced follow-up.

## Common Mistakes / Edge Cases
Only expanding odd centers (misses `"abba"`); off-by-one when computing `start` after failed expand.

## Interview Follow-ups / Variations
Count all palindromic substrings (647); Manacher; longest palindromic subsequence (516).

## Tags
`string`, `expand-around-center`, `palindrome`, `difficulty:medium`
