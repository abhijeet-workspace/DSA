# Generate Parentheses

## 1. Problem Statement
[LeetCode 22](https://leetcode.com/problems/generate-parentheses/) — given `n` pairs, generate all combinations of well-formed parentheses.

- **Inputs:** `int n`.
- **Output:** all valid strings of length `2n`.
- **Valid answer:** Catalan-number many strings; order free.
- **Edges:** `n=1` → `"()"`; `n=0` empty.

## 2. Intuition
Backtracking with counts: add `(` if `open < n`; add `)` if `close < open`. This enforces prefix validity.

## 3. Brute Force → Optimal
- **Brute:** all 2^(2n) bit strings, filter validity.
- **Optimal:** prune invalid partials — Catalan C_n outputs.

## 4. Data Structure / Approach Justification
**Chosen:** DFS with open/close counters.

- **vs stack simulation per candidate:** slower.
- **vs DP concatenating valid pairs:** also valid; DFS is classic backtracking.

## 5. Logic Walkthrough
If length `2n`, record. Try `(` then `)` under constraints; undo char.

## 6. Dry Run
`n=3` → 5 strings: `"((()))","(()())","(())()","()(())","()()()"`.

## 7. Time & Space Complexity
Time **O(4^n / sqrt(n))** (Catalan growth). Space **O(n)** recursion. Why: valid parentheses count (section 4).

## 8. Trade-offs & Alternatives
DP by inserting pairs around smaller solutions. Same asymptotics.

## 9. Common Mistakes / Edge Cases
Allowing `close > open`; forgetting undo; comparing to `n` incorrectly.

## 10. Interview Follow-ups / Variations
Count only; remove invalid parentheses; generate with multiple bracket types.

## 11. Tags
`backtracking`, `catalan`, `leetcode-22`, `difficulty:medium`
