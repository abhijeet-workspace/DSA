# K-th Symbol in Grammar

## 1. Problem Statement
[LeetCode 779](https://leetcode.com/problems/k-th-symbol-in-grammar/) — Row 1 is `0`. Each `0` becomes `01`, each `1` becomes `10`. Return the `k`-th (1-indexed) symbol in row `n`.

- **Inputs:** `int n`, `int k`.
- **Output:** `0` or `1`.
- **Edges:** `n=1`; `k=1`; deep rows (cannot build string).

## 2. Intuition
Symbol comes from parent at `(k+1)/2`; left/right child flips depend on parent bit.

## 3. Brute Force → Optimal
Build full rows — exponential space/time. Recursion on parent is O(n).

## 4. Data Structure / Approach Justification
**Chosen:** recurse to parent row, then map child position.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. `n==1` → 0.
2. Parent = `kthGrammar(n-1, (k+1)/2)`.
3. Odd `k` = left child; decode from parent.

## 6. Dry Run
Row3 = `0110`; k=3 → 1 (right child of parent 1 at pos 2).

## 7. Time & Space Complexity
- **Time:** O(n)
- **Space:** O(n) stack

## 8. Trade-offs & Alternatives
Bit tricks / binary representation of `k-1` also work.

## 9. Common Mistakes / Edge Cases
0-based vs 1-based `k`; swapping left/right flip rules.

## 10. Interview Follow-ups / Variations
Count ones in row; generate prefix.

## 11. Tags
`recursion`, `math`, `leetcode-779`, `difficulty:medium`
