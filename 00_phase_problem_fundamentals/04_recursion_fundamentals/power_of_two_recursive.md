# Power of Two (Recursive)

## 1. Problem Statement
[LeetCode 231](https://leetcode.com/problems/power-of-two/) — Return true if `n` is a power of two.

- **Inputs:** `int n`.
- **Output:** `bool`.
- **Edges:** `n<=0`; `n=1` (2⁰); odd numbers.

## 2. Intuition
Repeatedly halve even positives until 1; fail on odds/non-positives.

## 3. Brute Force → Optimal
Loop multiply from 1 — iterative. Recursion makes the reduction explicit.

## 4. Data Structure / Approach Justification
**Chosen:** recursive halving.

Bit trick `n&(n-1)` appears in the bit-manipulation topic — different skill. Filename is `power_of_two_recursive` to avoid clashing with that folder's `power_of_two`.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. `n<=0` → false; `n==1` → true.
2. Odd → false; else recurse `n/2`.

## 6. Dry Run
`16→8→4→2→1` true; `3` odd false.

## 7. Time & Space Complexity
- **Time:** O(log n)
- **Space:** O(log n) stack

## 8. Trade-offs & Alternatives
Bit check is O(1); here we practice reduction recursion.

## 9. Common Mistakes / Edge Cases
Allowing `n=0`; integer overflow if multiplying up.

## 10. Interview Follow-ups / Variations
Power of three/four (next).

## 11. Tags
`recursion`, `math`, `leetcode-231`, `difficulty:easy`
