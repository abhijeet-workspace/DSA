# N-th Tribonacci Number

## 1. Problem Statement
[LeetCode 1137](https://leetcode.com/problems/n-th-tribonacci-number/) — `T0=0`, `T1=1`, `T2=1`, `Tn=T(n-1)+T(n-2)+T(n-3)`. Return `Tn` (`n<=37`).

- **Inputs:** `int n`.
- **Output:** `Tn`.
- **Edges:** `n=0..2`; larger `n` needing memo.

## 2. Intuition
Same recursion idea as Fibonacci with three branches; memoize because `n=37` blows the naive tree.

## 3. Brute Force → Optimal
Pure recursion exponential. Top-down memo is still recursive — shows *why* overlapping subproblems hurt.

## 4. Data Structure / Approach Justification
**Chosen:** recursive DFS + memo vector.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly. Memo here is a teaching bridge toward DP, not the full 1D DP unit.

## 5. Logic Walkthrough
1. Bases: 0 → 0; 1/2 → 1.
2. Else memoized sum of three smaller calls.

## 6. Dry Run
`T4 = T3+T2+T1 = 2+1+1 = 4`.

## 7. Time & Space Complexity
- **Time:** O(n) with memo
- **Space:** O(n)

## 8. Trade-offs & Alternatives
Bottom-up loop is cleaner production code.

## 9. Common Mistakes / Edge Cases
Naive recursion at `n=37` (TLE); wrong bases.

## 10. Interview Follow-ups / Variations
k-bonacci; modular trib.

## 11. Tags
`recursion`, `memoization`, `leetcode-1137`, `difficulty:easy`
