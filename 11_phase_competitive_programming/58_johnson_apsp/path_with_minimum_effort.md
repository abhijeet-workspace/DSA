# Path With Minimum Effort

## 1. Problem Statement
[LeetCode 1631](https://leetcode.com/problems/path-with-minimum-effort/) — path from top-left to bottom-right minimizing the maximum absolute height difference of any step.

- **Inputs:** `heights` matrix.
- **Output:** minimum effort.
- **Edges:** 1×1 → 0; steep cliffs.

## 2. Intuition
Dijkstra on effort = max edge along path (bottleneck shortest path).

## 3. Brute Force → Optimal
- **Brute:** DFS all paths.
- **Optimal:** Dijkstra / binary search + BFS.

## 4. Data Structure / Approach Justification
**Chosen:** Dijkstra with `nd = max(cur, edge)`.

| Alternative | Note |
|-------------|------|
| Binary search + BFS | Also popular |
| Floyd | Too heavy |

## 5. Logic Walkthrough
PQ by effort; relax neighbors with bottleneck update.

## 6. Dry Run
Sample → effort `2`.

## 7. Time & Space Complexity
Time **O(RC log RC)**. Space **O(RC)**.

## 8. Trade-offs & Alternatives
Variant of shortest-path techniques in the APSP toolkit.

## 9. Common Mistakes / Edge Cases
Using sum instead of max; 8-direction.

## 10. Interview Follow-ups / Variations
Maximize minimum edge; 3D grids.

## 11. Tags
`leetcode-1631`, `dijkstra`, `bottleneck`, `difficulty:medium`
