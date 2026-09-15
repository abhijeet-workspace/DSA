# Longest Happy Prefix

## 1. Problem Statement
[LeetCode 1392](https://leetcode.com/problems/longest-happy-prefix/) — longest proper prefix that is also a suffix (KMP border of whole string).

- **Inputs:** string `s`.
- **Output:** that prefix string (possibly empty).
- **Valid answer:** longest proper border.
- **Edges:** no border; whole string repeated.

## 2. Intuition
Exactly the final LPS value of KMP: `lps[n-1]` is the longest happy prefix length.

## 3. Brute Force → Optimal
- **Brute:** check all lengths.
- **Optimal:** LPS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** compute LPS; take `s.substr(0, lps.back())`.

## 5. Logic Walkthrough
Build LPS; return prefix of length `lps[n-1]`.

## 6. Dry Run
`s="level"` → `"l"`. `s="ababab"` → `"abab"`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Z-algorithm `z[i]==n-i` max also works.

## 9. Common Mistakes / Edge Cases
Returning improper full string; off-by-one LPS.

## 10. Interview Follow-ups / Variations
Shortest Palindrome; KMP automaton.

## 11. Tags
`kmp`, `lps`, `leetcode-1392`, `difficulty:hard`
