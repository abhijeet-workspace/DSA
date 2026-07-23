# Graph Adjacency List

## Problem Statement
Represent an undirected graph with an **adjacency list**: for each vertex, store a list of neighbors.

- **Inputs:** `V` vertices, undirected edges `(u, v)`.
- **Output:** printable neighbor lists per vertex.
- **Valid answer:** each undirected edge appears in both endpoints’ lists.
- **Edges:** isolated vertices (empty lists); self-loops / multi-edges if allowed by problem.

## Intuition
Sparse graphs have far fewer than `V²` edges. Storing only real neighbors uses `O(V+E)` space and lets you iterate neighbors in `O(deg(u))`.

## Brute Force → Optimal
- **Brute / matrix:** `V×V` grid — fine for dense graphs, wasteful when `E ≪ V²`.
- **Optimal for sparse:** adjacency list — `O(V+E)` space, `O(deg(u))` neighbor scan.

## Data Structure / Approach Justification
**Chosen:** `vector<vector<int>> adj(V)` — dynamic neighbor lists.

- **vs adjacency matrix:** matrix wins for `O(1)` edge existence; loses memory on sparse graphs.
- **vs edge list only:** listing all edges is compact to store but slow to find neighbors of one vertex.

## Logic Walkthrough
Allocate `V` empty vectors. `addEdge(u,v)` pushes `v` onto `adj[u]` and `u` onto `adj[v]`. Print each row.

## Dry Run
`V=4`, edges `0-1`, `0-2`, `1-2`, `2-3`:
- `0: 1 2`
- `1: 0 2`
- `2: 0 1 3`
- `3: 2`

## Time & Space Complexity
Build **O(E)** pushes. Space **O(V+E)**. Why: one entry per directed half-edge (section 4).

## Trade-offs & Alternatives
Lists are the default interview representation for DFS/BFS/Dijkstra. Use a matrix when `V` is small and you need frequent edge queries.

## Common Mistakes / Edge Cases
Adding only one direction for undirected graphs; forgetting isolated vertices still need an empty slot; 1-indexed vs 0-indexed vertices.

## Interview Follow-ups / Variations
Directed lists (one push); weighted `pair<neighbor,weight>`; CSR / compressed sparse row for memory-tight systems.

## Tags
`graph`, `adjacency-list`, `representation`, `difficulty:easy`
