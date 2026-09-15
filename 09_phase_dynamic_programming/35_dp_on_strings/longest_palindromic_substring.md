# Longest Palindromic Substring

## Problem Statement
[LeetCode 5](https://leetcode.com/problems/longest-palindromic-substring/) — return any longest palindromic substring of s.

- **Inputs:** string `s`.
- **Output:** a longest palindromic substring.
- **Valid answer:** any max-length palindrome substring.
- **Edges:** length 1; all same; even/odd centers.

## Intuition
Expand around centers, or DP P[i][j] for substring palindrome.

## Brute Force → Optimal
- **Brute:** all substrings O(N^3).
- **Optimal:** expand O(N^2) or Manacher O(N).

## Data Structure / Approach Justification
**Chosen:** expand-around-center.

## Logic Walkthrough
For each index (and gap), expand while ends match; track best.

## Dry Run
babad -> bab or aba.

## Time & Space Complexity
Time **O(N^2)**. Space **O(1)**. Why: O(N) centers (section 4).

## Trade-offs & Alternatives
DP useful when all substring flags needed (132).

## Common Mistakes / Edge Cases
Substring vs subsequence confusion.

## Interview Follow-ups / Variations
Longest Palindromic Subsequence (516).

## Tags
`string-dp`, `palindrome`, `leetcode-5`, `difficulty:medium`
