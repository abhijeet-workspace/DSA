# Minimum Path Sum

## Problem Statement
[LeetCode 64](https://leetcode.com/problems/minimum-path-sum/) — min sum path from top-left to bottom-right moving only right/down.

- **Inputs:** `vector<vector<int>> grid`.
- **Output:** minimum path sum.
- **Valid answer:** sum along an optimal right/down path.
- **Edges:** 1×N / M×1; negatives allowed in variants (here non-neg).

## Intuition
Each cell’s best = grid[i][j] + min(from top, from left). Fill in order.

## Brute Force → Optimal
- **Brute:** recurse both moves — exponential.
- **Optimal:** O(M·N) DP; can mutate grid or use 1D.

## Data Structure / Approach Justification
**Chosen:** in-place `grid[i][j] += min(up, left)`.

- **vs full extra table:** same asymptotics, less memory.
- **vs Dijkstra:** overkill on DAG with unit moves.

## Logic Walkthrough
Prefix first row/col by cumulative sums. Interior: add min(up,left).

## Dry Run
`[[1,3,1],[1,5,1],[4,2,1]]` → path `1-3-1-1-1` = **7**.

## Time & Space Complexity
Time **O(M·N)**. Space **O(1)** extra (in-place). Why: each cell once (section 4).

## Trade-offs & Alternatives
1D rolling when mutation forbidden. Obstacles → Unique Paths II style.

## Common Mistakes / Edge Cases
Forgetting first row/col init; using max instead of min.

## Interview Follow-ups / Variations
Dungeon Game (174); path reconstruction; 4-direction graphs.

## Tags
`grid-dp`, `2d-dp`, `leetcode-64`, `difficulty:medium`
