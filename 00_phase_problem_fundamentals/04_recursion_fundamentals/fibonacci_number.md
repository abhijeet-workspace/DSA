# Fibonacci Number

## 1. Problem Statement
[LeetCode 509](https://leetcode.com/problems/fibonacci-number/) — The Fibonacci sequence: `F(0)=0`, `F(1)=1`, `F(n)=F(n-1)+F(n-2)`. Return `F(n)` for `0 <= n <= 30`.

- **Inputs:** `int n`.
- **Output:** `F(n)`.
- **Edges:** `n=0`; `n=1`; upper constraint 30 (naive recursion OK).

## 2. Intuition
Classic recursion: answer is sum of two smaller answers; base cases 0/1.

## 3. Brute Force → Optimal
Naive recursion is exponential — acceptable under `n<=30`. Memo/DP is the later upgrade (1D DP topic).

## 4. Data Structure / Approach Justification
**Chosen:** plain recursive definition.

| Alternative | Why later |
|-------------|----------|
| Iterative DP / memo | 1D DP topic |
| Matrix exponentiation | Math/advanced |

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. If `n <= 1`, return `n`.
2. Else return `fib(n-1) + fib(n-2)`.

## 6. Dry Run
`fib(4) = fib(3)+fib(2) = (2)+(1) = 3`.

## 7. Time & Space Complexity
- **Time:** O(φⁿ) naive
- **Space:** O(n) call stack

## 8. Trade-offs & Alternatives
Interview follow-up: O(n) iterative. Here we want the call-tree picture.

## 9. Common Mistakes / Edge Cases
Missing base case; off-by-one on `fib(0)` / `fib(1)`.

## 10. Interview Follow-ups / Variations
Memoized fib; climbing stairs (same recurrence).

## 11. Tags
`recursion`, `math`, `leetcode-509`, `difficulty:easy`
