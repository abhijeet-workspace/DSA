# Graph Adjacency Matrix

## 1. Problem Statement
Represent an undirected graph with an **adjacency matrix**: `mat[i][j] = 1` iff edge `(i,j)` exists.

- **Inputs:** `V` vertices, undirected edges.
- **Output:** printed `V×V` 0/1 grid.
- **Valid answer:** symmetric matrix for undirected simple graphs.
- **Edges:** diagonal usually 0 (no self-loops); directed graphs need asymmetry.

## 2. Intuition
A full grid answers “is `(u,v)` an edge?” in `O(1)`. Cost is always `Θ(V²)` memory regardless of how sparse the graph is.

## 3. Brute Force → Optimal
- **Always Θ(V²) space** for a dense matrix — no asymptotic “better matrix.”
- **Choose matrix when:** `V` small / dense / need frequent edge existence checks.
- **Prefer list when:** sparse traversal-heavy algorithms (DFS/BFS).

## 4. Data Structure / Approach Justification
**Chosen:** fixed `int mat[V][V]` initialized to 0.

- **vs adjacency list:** list is leaner for sparse graphs and neighbor iteration.
- **vs bitset matrix:** saves memory; same asymptotic idea.

## 5. Logic Walkthrough
Zero the matrix. `addEdge(u,v)` sets `mat[u][v]` and `mat[v][u]` to 1. Print all rows.

## 6. Dry Run
Edges `0-1`, `0-2`, `1-2`, `2-3` → row0 `0 1 1 0`, row1 `1 0 1 0`, row2 `1 1 0 1`, row3 `0 0 1 0`.

## 7. Time & Space Complexity
Edge insert **O(1)**. Space **O(V²)**. Neighbor scan of `u` is **O(V)**. Why: full grid (section 4).

## 8. Trade-offs & Alternatives
Matrix shines in Floyd–Warshall and dense DP. For interviews on grids-as-graphs, people often skip an explicit matrix and index cells directly.

## 9. Common Mistakes / Edge Cases
Forgetting undirected symmetry; treating weights as 0/1 without a sentinel for “no edge”; off-by-one on `V`.

## 10. Interview Follow-ups / Variations
Weighted matrix with `INF` sentinel; directed-only upper/lower triangle; convert matrix ↔ list.

## 11. Tags
`graph`, `adjacency-matrix`, `representation`, `difficulty:easy`
