# Min Cost to Connect All Points

## Problem Statement
[LeetCode 1584](https://leetcode.com/problems/min-cost-to-connect-all-points/) — connect all points on a 2D plane into one component; cost of an edge is Manhattan distance; minimize total cost.

- **Inputs:** `vector<vector<int>> points` as `[x, y]` pairs.
- **Output:** minimum total connection cost (MST weight).
- **Valid answer:** MST on the complete graph with `w(i,j)=|xi-xj|+|yi-yj|`.
- **Edges:** `n=1` → 0; duplicate coordinates; large coordinates.

## Intuition
Any connecting network without cycles of minimum cost is an MST. Build all pairwise Manhattan edges, then run Kruskal.

## Brute Force → Optimal
- **Brute:** try all spanning trees — exponential.
- **Optimal:** Kruskal O(N² log N) on O(N²) edges, or Prim O(N²) on the dense graph.

## Data Structure / Approach Justification
**Chosen:** generate all pairs → sort → DSU (Kruskal).

- **vs Prim with adj matrix:** often faster for dense N×N; similar interview clarity.
- **vs A* / heuristics:** unnecessary; exact MST is required.

## Logic Walkthrough
For each `i<j`, push `(manhattan, i, j)`. Sort. Union edges; accumulate weight until `n-1` unions.

## Dry Run
Points `(0,0),(2,2),(3,10),(5,2),(7,0)` → MST cost **20** (standard sample).

## Time & Space Complexity
Time **O(N² log N)**. Space **O(N²)** for edges. Why: complete graph has Θ(N²) edges to sort (section 4).

## Trade-offs & Alternatives
Prim O(N²) avoids storing all edges explicitly. For very large N, geometric MST techniques exist but are overkill here.

## Common Mistakes / Edge Cases
Using Euclidean instead of Manhattan; double-adding undirected edges in Kruskal list; off-by-one on `n-1`.

## Interview Follow-ups / Variations
Euclidean MST. Prim implementation. Connect with max edge minimized (bottleneck MST).

## Tags
`mst`, `kruskal`, `union-find`, `manhattan`, `leetcode-1584`, `difficulty:medium`
