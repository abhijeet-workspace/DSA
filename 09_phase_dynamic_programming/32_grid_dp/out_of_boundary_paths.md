# Out of Boundary Paths

## Problem Statement
[LeetCode 576](https://leetcode.com/problems/out-of-boundary-paths/) — on `m×n` grid start `(startRow,startColumn)`; move 4-dir; count ways to walk out of bounds in at most `maxMove` steps (mod 1e9+7).

- **Inputs:** `m,n,maxMove,startRow,startColumn`.
- **Output:** ways mod 10⁹+7.
- **Valid answer:** paths that exit within ≤ maxMove moves.
- **Edges:** maxMove=0; start on edge; 1×1.

## Intuition
DP on (row,col,movesLeft): try 4 neighbors; out-of-grid contributes 1.

## Brute Force → Optimal
- **Brute:** DFS all walks — exponential.
- **Optimal:** memo / iterative DP O(m·n·maxMove).

## Data Structure / Approach Justification
**Chosen:** rolling layers of grid counts.

- **vs BFS counting:** harder with move budget.

## Logic Walkthrough
If out → 1. If moves=0 inside → 0. Else sum four directions.

## Dry Run
`m=n=1,maxMove=1` start 0,0 → **4**.

## Time & Space Complexity
Time **O(m·n·maxMove)**. Space **O(m·n)**. Why: each state once (section 4).

## Trade-offs & Alternatives
Iterative bottom-up avoids recursion depth issues.

## Common Mistakes / Edge Cases
Forgetting mod; counting exit after move incorrectly.

## Interview Follow-ups / Variations
Knight Probability on Chessboard (688).

## Tags
`grid-dp`, `leetcode-576`, `difficulty:medium`
