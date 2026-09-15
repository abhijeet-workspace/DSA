# Climbing Stairs

## 1. Problem Statement
[LeetCode 70](https://leetcode.com/problems/climbing-stairs/) — `n` steps; each move takes 1 or 2 steps; count distinct ways to reach the top.

- **Inputs:** `int n`.
- **Output:** number of distinct sequences.
- **Valid answer:** ways(n) with ways(1)=1, ways(2)=2.
- **Edges:** `n=1`; `n=2`; large `n` (int overflow under LC constraints is fine).

## 2. Intuition
Last step is either a single from `n-1` or a double from `n-2` → Fibonacci recurrence.

## 3. Brute Force → Optimal
- **Brute:** recurse without memo — exponential.
- **Optimal:** rolling two variables — O(N) time, O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** two ints (`prev2`, `prev1`) updated in a loop.

- **vs full `dp[]`:** same recurrence; array is clearer but uses O(N) space.
- **vs matrix expo / Binet:** O(log N) or closed form — overkill and precision risks in interviews.

## 5. Logic Walkthrough
If `n<=2` return `n`. Else for `i=3..n`: `cur = prev1 + prev2`, shift window.

## 6. Dry Run
`n=5`:
- start `prev2=1`, `prev1=2`
- i=3 → 3; i=4 → 5; i=5 → 8

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: each step uses only the prior two values (section 4).

## 8. Trade-offs & Alternatives
Iterative DP is interview-standard. Matrix expo wins asymptotically for huge `n`.

## 9. Common Mistakes / Edge Cases
Wrong base cases; treating ways(0)=1 when not asked; int overflow for very large `n`.

## 10. Interview Follow-ups / Variations
`k` step sizes; Min Cost Climbing Stairs (746).

## 11. Tags
`1d-dp`, `fibonacci`, `leetcode-70`, `difficulty:easy`
