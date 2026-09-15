# Decode String (Recursive)

## 1. Problem Statement
[LeetCode 394](https://leetcode.com/problems/decode-string/) — Encoded string uses `k[encoded_string]`. Return the decoded string. Nested encodings allowed.

- **Inputs:** `string s`.
- **Output:** Decoded `string`.
- **Edges:** No brackets (plain text); nested; multi-digit `k`.

## 2. Intuition
Recursive descent: read chars; on digit parse `k`, parse bracket body recursively, repeat.

## 3. Brute Force → Optimal
Stack of strings/counts is the classic iterative solution. Recursion mirrors the nested grammar.

## 4. Data Structure / Approach Justification
**Chosen:** recursive descent with a shared index.

A **stack**-based decode is the usual interview default and belongs with the stack topic later. Here we train nested recursion / parsing.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. Accumulate letters into `cur`.
2. On digit: read `k`, skip `[`, recurse for inner, skip `]`, append inner `k` times.

## 6. Dry Run
`3[a2[c]]` → inner `cc`, then `acc` ×3 → `accaccacc`.

## 7. Time & Space Complexity
- **Time:** O(decoded length)
- **Space:** O(nesting depth + output)

## 8. Trade-offs & Alternatives
Stack version avoids deep recursion on pathological nesting.

## 9. Common Mistakes / Edge Cases
Not skipping `]`; mishandling multi-digit counts; mutating index incorrectly.

## 10. Interview Follow-ups / Variations
Encode string; validate encoding.

## 11. Tags
`recursion`, `string`, `parsing`, `leetcode-394`, `difficulty:medium`
