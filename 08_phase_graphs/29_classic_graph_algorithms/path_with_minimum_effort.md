# Path With Minimum Effort

## 1. Problem Statement
[LeetCode 1631](https://leetcode.com/problems/path-with-minimum-effort/) — grid of heights. Effort of a path is the max absolute height difference of consecutive cells. Return minimum effort path from `(0,0)` to `(R-1,C-1)`.

- **Inputs:** `heights`.
- **Output:** min effort.
- **Valid answer:** minimax path cost.
- **Edges:** 1×1 → 0; monotonic grid.

## 2. Intuition
Treat cells as graph nodes; edge weight = abs height diff. Shortest path where path cost is max edge (Dijkstra with `max` combine).

## 3. Brute Force → Optimal
- **Brute:** DFS all paths.
- **Optimal:** Dijkstra / binary search + BFS on threshold.

## 4. Data Structure / Approach Justification
**Chosen:** Dijkstra with effort = max(prev, edge).

- **vs binary search + BFS:** also O(RC log H).

## 5. Logic Walkthrough
PQ of (effort,r,c). Relax neighbor with `max(effort, |h diff|)`.

## 6. Dry Run
Sample → effort **2**.

## 7. Time & Space Complexity
Time **O(RC log(RC))**. Space **O(RC)**. Why: Dijkstra on grid (section 4).

## 8. Trade-offs & Alternatives
Union-Find sorting edges by effort (Kruskal-like).

## 9. Common Mistakes / Edge Cases
Using sum of diffs; 8-direction; stale PQ entries.

## 10. Interview Follow-ups / Variations
Swim in rising water; path with maximum minimum.

## 11. Tags
`dijkstra`, `grid`, `leetcode-1631`, `difficulty:medium`
