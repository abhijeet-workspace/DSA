# Longest Palindromic Substring

## Problem Statement
[LeetCode 5](https://leetcode.com/problems/longest-palindromic-substring/) — return any longest palindromic **substring** of `s`.

- **Inputs:** string `s`.
- **Output:** a longest palindromic substring.
- **Valid answer:** any max-length palindrome substring.
- **Edges:** length 1; all same chars; even/odd centers.

## Intuition
Expand around centers, or DP `P[i][j]` true if `s[i..j]` palindrome.

## Brute Force → Optimal
- **Brute:** all substrings + check — O(N³).
- **Optimal:** expand centers O(N²) or Manacher O(N).

## Data Structure / Approach Justification
**Chosen:** expand-around-center (interview default).

- **vs DP table:** clearer transitions, more memory.
- **vs Manacher:** linear but trickier to code.

## Logic Walkthrough
For each index (and gap), expand while ends match; track best `[L,R)`.

## Dry Run
`babad` → `bab` or `aba`.

## Time & Space Complexity
Time **O(N²)**. Space **O(1)** expand. Why: O(N) centers × O(N) expand (section 4).

## Trade-offs & Alternatives
DP useful when you already need all substring palindrome flags (132).

## Common Mistakes / Edge Cases
Confusing substring vs subsequence; off-by-one on even length.

## Interview Follow-ups / Variations
Longest Palindromic Subsequence (516); Palindrome Partitioning II (132).

## Tags
`string-dp`, `2d-dp`, `palindrome`, `leetcode-5`, `difficulty:medium`
