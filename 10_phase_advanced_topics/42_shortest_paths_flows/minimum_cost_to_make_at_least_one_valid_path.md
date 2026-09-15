# Minimum Cost to Make at Least One Valid Path

## Problem Statement
[LeetCode 1368](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/) — each cell has an arrow `1..4` (R,L,D,U). Moving with the arrow costs `0`; changing it costs `1`. Min cost from `(0,0)` to `(m-1,n-1)`.

- **Inputs:** `grid` of directions.
- **Output:** minimum change cost.
- **Valid answer:** shortest path with 0/1 edge weights.
- **Edges:** already a free path; 1×1; all arrows wrong.

## Intuition
Edges weight 0 or 1 → 0-1 BFS (deque): push_front on 0-cost, push_back on 1-cost.

## Brute Force → Optimal
- **Brute:** Dijkstra — correct but heavier.
- **Optimal:** 0-1 BFS — **O(RC)**.

## Data Structure / Approach Justification
**Chosen:** deque 0-1 BFS + `dist` matrix.

- **vs Dijkstra:** same answer; 0-1 BFS is linear.
- **vs plain BFS:** ignores cheaper 0-edges ordering.

## Logic Walkthrough
`dist[0][0]=0`. Pop front; for 4 dirs compute `cost` vs cell arrow; relax and push front/back accordingly.

## Dry Run
Sample 4×4 alternating rows: need 3 changes → `3`.

## Time & Space Complexity
Time **O(RC)**. Space **O(RC)**. Why: each cell enters deque O(1) amortized with 0-1 edges (section 4).

## Trade-offs & Alternatives
Dijkstra with heap if weights were arbitrary. DP on DAG if graph is layered specially.

## Common Mistakes / Edge Cases
Wrong arrow index mapping; using queue only (not deque); mutating grid incorrectly.

## Interview Follow-ups / Variations
Obstacle removal (2290); general 0-1 grid costs; k changes limit.

## Tags
`grid`, `0-1-bfs`, `shortest-path`, `leetcode-1368`, `difficulty:hard`
