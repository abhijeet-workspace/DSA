# Unique Paths II

## Problem Statement
[LeetCode 63](https://leetcode.com/problems/unique-paths-ii/) — same as Unique Paths, but cells with `1` are obstacles; count paths from top-left to bottom-right (right/down only).

- **Inputs:** `obstacleGrid` of 0/1.
- **Output:** number of unique paths (0 if start/end blocked).
- **Valid answer:** path count avoiding obstacles.
- **Edges:** start blocked; end blocked; full wall in a row/col; `1×1`.

## Intuition
`dp[i][j] = dp[i-1][j] + dp[i][j-1]` unless obstacle → 0. Roll into one row.

## Brute Force → Optimal
- **Brute:** DFS both moves — exponential.
- **Optimal:** O(MN) DP with O(N) space.

## Data Structure / Approach Justification
**Chosen:** 1D `dp` row; zero out on obstacles.

- **vs full 2D:** clearer teaching version.
- **vs DFS+memo:** same asymptotics, more stack.

## Logic Walkthrough
If start is obstacle return 0. `dp[0]=1`. For each cell: obstacle → `dp[j]=0`; else if `j>0` add `dp[j-1]` (left) into existing `dp[j]` (up from prev row).

## Dry Run
3×3 with center obstacle → **2** paths around it.

## Time & Space Complexity
Time **O(M·N)**. Space **O(N)**. Why: each cell once (section 4).

## Trade-offs & Alternatives
In-place mutate of `obstacleGrid` saves the extra vector when allowed.

## Common Mistakes / Edge Cases
Not handling start obstacle; using `int` when counts can be large (use long long intermediate); forgetting left contribution only when `j>0`.

## Interview Follow-ups / Variations
Min path sum with obstacles; 4-direction movement; modulo path counts.

## Tags
`grid-dp`, `unique-paths`, `obstacles`, `leetcode-63`, `difficulty:medium`
