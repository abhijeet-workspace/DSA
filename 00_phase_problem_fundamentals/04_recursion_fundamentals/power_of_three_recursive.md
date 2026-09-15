# Power of Three (Recursive)

## 1. Problem Statement
[LeetCode 326](https://leetcode.com/problems/power-of-three/) — Return true if `n` is a power of three.

- **Inputs:** `int n`.
- **Output:** `bool`.
- **Edges:** `n<=0`; `n=1`; not divisible by 3.

## 2. Intuition
Same reduction pattern as power-of-two, divisor 3.

## 3. Brute Force → Optimal
Loop; recursion for the teaching parallel.

## 4. Data Structure / Approach Justification
**Chosen:** recursive divide-by-3. Filename `power_of_three_recursive` avoids clash with math-topic `power_of_three`.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. `n<=0` → false; `n==1` → true.
2. Not multiple of 3 → false; else recurse `n/3`.

## 6. Dry Run
`27→9→3→1` true.

## 7. Time & Space Complexity
- **Time:** O(log n)
- **Space:** O(log n)

## 8. Trade-offs & Alternatives
Max power-of-three int constant-division trick in interviews.

## 9. Common Mistakes / Edge Cases
Floating `log` precision; `n=0`.

## 10. Interview Follow-ups / Variations
Power of four; generalize base `k`.

## 11. Tags
`recursion`, `math`, `leetcode-326`, `difficulty:easy`
