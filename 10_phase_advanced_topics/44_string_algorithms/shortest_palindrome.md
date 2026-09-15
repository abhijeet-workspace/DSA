# Shortest Palindrome

## 1. Problem Statement
[LeetCode 214](https://leetcode.com/problems/shortest-palindrome/) — add the fewest characters in front of `s` to make a palindrome.

- **Inputs:** string `s`.
- **Output:** shortest palindrome string.
- **Valid answer:** any shortest (unique under greedy prefix).
- **Edges:** already palindrome; single char; all same.

## 2. Intuition
Longest palindromic prefix of `s` can stay; reverse of the suffix goes in front. KMP LPS of `s + '#' + reverse(s)` gives that prefix length (`lps.back()`).

## 3. Brute Force → Optimal
- **Brute:** try expanding.
- **Optimal:** KMP on `s#rev(s)` — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** KMP LPS trick.

- **vs Manacher:** also finds longest palindromic prefix.

## 5. Logic Walkthrough
Build `t=s+'#'+rev`; LPS; `prefix=lps.back()`; return `rev.substr(0,n-prefix)+s`.

## 6. Dry Run
`s="aacecaaa"` → `"aaacecaaa"`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Manacher is alternative; KMP is cleaner here.

## 9. Common Mistakes / Edge Cases
Forgetting separator `#`; using LPS of s alone.

## 10. Interview Follow-ups / Variations
Longest Happy Prefix; Palindrome Pairs.

## 11. Tags
`kmp`, `palindrome`, `leetcode-214`, `difficulty:hard`
