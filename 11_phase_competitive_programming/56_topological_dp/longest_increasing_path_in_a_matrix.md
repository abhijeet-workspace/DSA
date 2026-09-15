# Longest Increasing Path in a Matrix

## 1. Problem Statement
[LeetCode 329](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) — longest strictly increasing path in a matrix (4-direction moves).

- **Inputs:** `matrix`.
- **Output:** path length (cells).
- **Edges:** all equal → 1; single cell.

## 2. Intuition
Cells form a DAG under `value` edges to larger neighbors; DP/memo is topo DP on that DAG.

## 3. Brute Force → Optimal
- **Brute:** DFS without memo — exponential.
- **Optimal:** memo DFS / Kahn on cell DAG — O(RC).

## 4. Data Structure / Approach Justification
**Chosen:** DFS + memo (implicit topo on value-DAG).

| Alternative | Note |
|-------------|------|
| Explicit Kahn on cells | Same O(RC) |
| Dijkstra | Unnecessary |

## 5. Logic Walkthrough
`dfs(i,j)` = 1 + max over larger neighbors; memoize.

## 6. Dry Run
Sample matrix → longest path length `4`.

## 7. Time & Space Complexity
Time **O(RC)**. Space **O(RC)**.

## 8. Trade-offs & Alternatives
Clean example of building a DAG from a grid for topo DP.

## 9. Common Mistakes / Edge Cases
Allowing non-strict increases; mutating matrix as memo.

## 10. Interview Follow-ups / Variations
Path with maximum sum; 8 directions.

## 11. Tags
`leetcode-329`, `dag`, `memoization`, `matrix`, `difficulty:hard`
