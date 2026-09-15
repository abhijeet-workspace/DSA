# Perfect Squares

## Problem Statement
[LeetCode 279](https://leetcode.com/problems/perfect-squares/) — least number of perfect square numbers that sum to `n`.

- **Inputs:** positive integer `n`.
- **Output:** minimum count of squares.
- **Valid answer:** Lagrange’s four-square theorem bounds ≤ 4.
- **Edges:** `n` itself a square; `n=1`; large `n`.

## Intuition
Same as unbounded coin change where coins are `1,4,9,…`; `dp[i]` = min pieces to make `i`.

## Brute Force → Optimal
- **Brute:** recurse subtracting squares — exponential.
- **Optimal:** 1D DP O(N√N), or BFS levels from 0, or math theorems O(√N).

## Data Structure / Approach Justification
**Chosen:** `dp[0..n]` coin-change style.

- **vs BFS:** often faster in practice (shortest path in square graph).
- **vs Legendre / Lagrange checks:** O(√N) clever; less “DP interview”.

## Logic Walkthrough
`dp[0]=0`, else large. For each `i`, for each `s*s<=i`: `dp[i]=min(dp[i], dp[i-s*s]+1)`.

## Dry Run
`n=12`: `4+4+4` → **3**. `n=13`: `4+9` → **2**.

## Time & Space Complexity
Time **O(N√N)**. Space **O(N)**. Why: each amount tries all squares ≤ amount (section 4).

## Trade-offs & Alternatives
BFS preferred when early termination matters. Math solution for contests.

## Common Mistakes / Edge Cases
Starting squares at 0; off-by-one `dp` size; assuming answer always 1 or 2.

## Interview Follow-ups / Variations
Count ways; restricted to at most k squares; BFS vs DP tradeoff.

## Tags
`1d-dp`, `math`, `bfs`, `leetcode-279`, `difficulty:medium`
