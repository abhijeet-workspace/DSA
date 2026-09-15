# Find the Winner of the Circular Game

## 1. Problem Statement
[LeetCode 1823](https://leetcode.com/problems/find-the-winner-of-the-circular-game/) — `n` friends in a circle count every `k`-th remaining person out until one remains. Return the winner’s 1-based label.

- **Inputs:** `int n`, `int k`.
- **Output:** Winner label in `[1..n]`.
- **Edges:** `k=1` (last person); `n=1`; large `k`.

## 2. Intuition
Josephus recurrence: after one elimination, the circle of size `n-1` has a rotated indexing.

## 3. Brute Force → Optimal
Simulate with a queue/list — O(n·k) or O(n²). Closed recurrence is O(n).

## 4. Data Structure / Approach Justification
**Chosen:** Josephus recursion `f(1)=0`, `f(n)=(f(n-1)+k)%n`, then `+1` for 1-based.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. Base: one person → index 0.
2. Recurrence rotates by `k` after shrinking.
3. Map 0-based → 1-based.

## 6. Dry Run
`n=5,k=2`: eliminations leave person 3.

## 7. Time & Space Complexity
- **Time:** O(n)
- **Space:** O(n) stack (iterative Josephus O(1) space)

## 8. Trade-offs & Alternatives
Queue simulation is clearer for interviews if recurrence is unfamiliar.

## 9. Common Mistakes / Edge Cases
Off-by-one 0/1-based; wrong modulo when `k` large.

## 10. Interview Follow-ups / Variations
Return elimination order; Josephus for arbitrary start.

## 11. Tags
`recursion`, `math`, `josephus`, `leetcode-1823`, `difficulty:medium`
