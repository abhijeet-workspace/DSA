# Path With Minimum Effort

## Problem Statement
[LeetCode 1631](https://leetcode.com/problems/path-with-minimum-effort/) — path effort is the max absolute height difference between consecutive cells. Minimize effort from `(0,0)` to `(m-1,n-1)` (4-dir).

- **Inputs:** `heights` grid.
- **Output:** minimum achievable effort.
- **Valid answer:** min over paths of max edge diff on the path.
- **Edges:** 1×1 → `0`; strictly increasing line; flat grid.

## Intuition
Bottleneck shortest path: Dijkstra with cost `max(path_so_far, edge_diff)`. Equivalently binary search effort `mid` + BFS on edges with diff ≤ `mid`.

## Brute Force → Optimal
- **Brute:** all paths — exponential.
- **Optimal:** Dijkstra **O(RC log RC)** or binary search + BFS **O(RC log H)**.

## Data Structure / Approach Justification
**Chosen:** min-heap Dijkstra on effort.

- **vs binary search + BFS:** same complexity class; BS is easy to reason “feasible”.
- **vs plain BFS:** ignores weighted bottleneck.

## Logic Walkthrough
`dist[0][0]=0`. Pop smallest effort; for neighbors `ne = max(eff, |h[u]-h[v]|)`; relax if smaller.

## Dry Run
Sample grid: path with max step `2` is optimal (e.g. right/right/down/down).

## Time & Space Complexity
Time **O(RC log RC)**. Space **O(RC)**. Why: heap Dijkstra on grid graph (section 4).

## Trade-offs & Alternatives
Binary search when you want unweighted BFS primitives. Union-Find on sorted edge diffs also works (Kruskal-style).

## Common Mistakes / Edge Cases
Summing diffs instead of max; 8-dir; treating as 0-1 BFS.

## Interview Follow-ups / Variations
Swim in Rising Water (778); minimize sum of diffs; k obstacles.

## Tags
`grid`, `dijkstra`, `binary-search`, `leetcode-1631`, `difficulty:medium`
