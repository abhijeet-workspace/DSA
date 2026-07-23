# Generate Parentheses

## Problem Statement
[LeetCode 22](https://leetcode.com/problems/generate-parentheses/) — generate all combinations of `n` pairs of well-formed parentheses.

- **Inputs:** `int n` (pairs).
- **Output:** all valid strings of length `2n`.
- **Valid answer:** Catalan-number many strings; order may vary.
- **Edges:** `n=1` → `"()"`; `n=0` → `[""]` depending on judge.

## Intuition
Build left-to-right under two rules: never place more `(` than `n`; never place `)` when it would exceed opens so far. That enumerates exactly the Dyck words.

## Brute Force → Optimal
- **Brute:** all `2^(2n)` bitstrings, filter with a balance check — huge waste.
- **Optimal:** constrained backtracking — O(C_n) outputs, each built in O(n).

## Data Structure / Approach Justification
**Chosen:** recursive DFS with a mutable `cur` string (implicit call stack).

- **vs explicit `stack` BFS:** same search space; recursion is clearer here.
- **vs closed Catalan formulas:** don’t enumerate strings.

## Logic Walkthrough
If `cur` length is `2n`, record. Else try `'('` when `open<n`, try `')'` when `close<open`; backtrack after each.

## Dry Run
`n=3` yields `((())) (()()) (())() ()(()) ()()`.

## Time & Space Complexity
Time **O(4^n / √n)** (Catalan). Space **O(n)** recursion + output size. Why: valid paths only; depth `2n` (section 4).

## Trade-offs & Alternatives
Iterative stack of partial states mirrors DFS without call stack. DP by inserting pairs into smaller solutions also works.

## Common Mistakes / Edge Cases
Allowing `close>open`; forgetting backtrack `pop_back`; generating only length without validity.

## Interview Follow-ups / Variations
Count only (Catalan); generate with multiple bracket types; longest valid substring.

## Tags
`backtracking`, `recursion`, `parentheses`, `catalan`, `leetcode-22`, `difficulty:medium`
