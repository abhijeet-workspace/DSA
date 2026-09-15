# Longest Palindromic Substring

## 1. Problem Statement
[LeetCode 5](https://leetcode.com/problems/longest-palindromic-substring/) — return any longest palindromic substring.

- **Inputs:** string `s`.
- **Output:** longest palindromic substring.
- **Valid answer:** any max-length palindrome substring.
- **Edges:** single char; all same; even/odd centers.

## 2. Intuition
Expand around centers O(N²), or Manacher O(N) already studied in this folder — apply Manacher radii to recover the best slice.

## 3. Brute Force → Optimal
- **Brute:** all substrings check — O(N³).
- **Expand:** O(N²).
- **Manacher:** O(N).

## 4. Data Structure / Approach Justification
**Chosen:** expand-around-center for clarity; Manacher file covers the linear algorithm.

## 5. Logic Walkthrough
For each center (and between-index even center), expand while matches; track best `[l,r)`.

## 6. Dry Run
`s="babad"` → `"bab"` or `"aba"`.

## 7. Time & Space Complexity
Time **O(N²)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Use Manacher from `manacher.cpp` when N is large.

## 9. Common Mistakes / Edge Cases
Missing even-length centers; off-by-one slice.

## 10. Interview Follow-ups / Variations
Shortest Palindrome; Palindrome Pairs.

## 11. Tags
`palindrome`, `expand-center`, `leetcode-5`, `difficulty:medium`
