# Longest Substring with At Least K Repeating Characters

## 1. Problem Statement
[LeetCode 395](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/) — Longest substring length where every distinct character appears at least `k` times.

- **Inputs:** `string s`, `int k`.
- **Output:** Max length (0 if none).
- **Edges:** `k=1`; `k > |s|`; all same char; separators that split the string.

## 2. Intuition
Chars with global freq `< k` can never appear in a valid substring — they are split points. Recurse on pieces between them.

## 3. Brute Force → Optimal
Check all substrings O(n²)·scan. Divide-and-conquer uses rare chars as pivots.

## 4. Data Structure / Approach Justification
**Chosen:** divide-and-conquer recursion on `[L,R)`.

Sliding-window variants exist with fixed alphabet size; here the lesson is **split on invalid characters**.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. Count freqs on segment.
2. If any char mid has freq `<k`, split around all such chars and take max of recursive pieces.
3. Else whole segment is valid → length.

## 6. Dry Run
`ababbc`, k=2: `c` freq 1 → split; best piece `ababb` length 5.

## 7. Time & Space Complexity
- **Time:** O(n²) worst (alphabet-bounded better in practice)
- **Space:** O(n) stack

## 8. Trade-offs & Alternatives
O(26·n) two-pointer with “exactly m unique chars” is often faster.

## 9. Common Mistakes / Edge Cases
Not splitting on *all* rare chars; returning length when segment shorter than `k`.

## 10. Interview Follow-ups / Variations
Return the substring; Unicode alphabet.

## 11. Tags
`recursion`, `divide-and-conquer`, `string`, `leetcode-395`, `difficulty:medium`
