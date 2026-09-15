# Repeated Substring Pattern

## 1. Problem Statement
[LeetCode 459](https://leetcode.com/problems/repeated-substring-pattern/) — true iff `s` is made by repeating a substring ≥ twice.

- **Inputs:** string `s`.
- **Output:** bool.
- **Valid answer:** exact.
- **Edges:** prime length; all same char.

## 2. Intuition
If `s = t*k` (k≥2), then `s` is found inside `(s+s)[1:-1]`. Equivalently LPS: `n % (n-lps[n-1])==0` and lps>0.

## 3. Brute Force → Optimal
- **Brute:** try every divisor length.
- **Optimal:** doubled-string trick or LPS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `(s+s).find(s,1) < n`.

- **vs LPS:** more 'algorithm course'; doubled string is short.

## 5. Logic Walkthrough
Build `ss=s+s`; search `s` starting at 1; success if index < n.

## 6. Dry Run
`s="abab"` → true. `s="aba"` → false.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
LPS avoids large concat when memory matters.

## 9. Common Mistakes / Edge Cases
Accepting k=1; empty string.

## 10. Interview Follow-ups / Variations
Repeated String Match; Longest Happy Prefix.

## 11. Tags
`string`, `kmp`, `leetcode-459`, `difficulty:easy`
