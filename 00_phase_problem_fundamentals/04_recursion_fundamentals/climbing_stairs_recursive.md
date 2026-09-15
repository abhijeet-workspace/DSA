# Climbing Stairs (Recursive Memo)

## 1. Problem Statement
[LeetCode 70](https://leetcode.com/problems/climbing-stairs/) — You can climb 1 or 2 steps. How many distinct ways to reach the top `n`?

- **Inputs:** `int n`.
- **Output:** Number of ways.
- **Edges:** `n=1`; `n=2`; larger n.

## 2. Intuition
`ways(n)=ways(n-1)+ways(n-2)` — Fibonacci structure.

## 3. Brute Force → Optimal
Pure recursion exponential; memoized recursion O(n).

## 4. Data Structure / Approach Justification
**Chosen:** top-down recursion + memo.

This *is* 1D DP in recursive clothing. We keep it here to show overlapping subproblems on the call tree; the dedicated **1D DP topic** will re-frame the same recurrence iteratively.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. Base `k<=2` return `k`.
2. Else memoized `dfs(k-1)+dfs(k-2)`.

## 6. Dry Run
`n=3` → `2+1=3` ways.

## 7. Time & Space Complexity
- **Time:** O(n)
- **Space:** O(n)

## 8. Trade-offs & Alternatives
Bottom-up two variables is production-optimal.

## 9. Common Mistakes / Edge Cases
Naive recursion for large n; off-by-one bases.

## 10. Interview Follow-ups / Variations
Min cost climbing stairs; k steps.

## 11. Tags
`recursion`, `memoization`, `leetcode-70`, `difficulty:easy`
