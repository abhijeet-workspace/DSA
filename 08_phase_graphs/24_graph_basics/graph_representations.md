# Graph Representations

## Problem Statement
Compare the two standard graph storages on the **same** undirected graph: adjacency matrix vs adjacency list.

- **Inputs:** fixed demo graph with `V=4` and edges `0-1,0-2,1-2,2-3`.
- **Output:** printed matrix grid and neighbor lists.
- **Valid answer:** matrix is symmetric 0/1; lists contain both directions per edge.
- **Edges:** isolated vertices; directed/weighted variants change the schema.

## Intuition
Matrix answers “edge exists?” in `O(1)` at `Θ(V²)` memory. List stores only real edges at `O(V+E)` and iterates neighbors in `O(deg)`.

## Brute Force → Optimal
- No single “optimal” representation — choose by density and query pattern.
- Dense / frequent edge checks → matrix. Sparse / traversal → list.

## Data Structure / Approach Justification
**Chosen:** side-by-side demos of `vector<vector<int>>` matrix and list.

- **vs edge list alone:** hard to iterate neighbors of one vertex quickly.
- **vs CSR:** production sparse format; overkill for teaching demos.

## Logic Walkthrough
Build both structures with the same four undirected edges (write both directions). Print matrix rows, then each vertex’s neighbor vector.

## Dry Run
Edges `0-1,0-2,1-2,2-3` → matrix row0 `0 1 1 0`; list `0: 1 2`, `3: 2`.

## Time & Space Complexity
Build **O(E)** (plus **O(V²)** matrix init). Space matrix **O(V²)**, list **O(V+E)**. Why: storage model (section 4).

## Trade-offs & Alternatives
Interview default is usually the list. Floyd–Warshall / dense DP prefer a matrix. See also dedicated `graph_adjacency_*` files.

## Common Mistakes / Edge Cases
Forgetting undirected symmetry; confusing 0-based vs 1-based labels; using matrix memory on huge sparse `V`.

## Interview Follow-ups / Variations
Weighted matrix with `INF`; directed one-way inserts; convert matrix ↔ list in code.

## Tags
`graph`, `adjacency-matrix`, `adjacency-list`, `representation`, `difficulty:easy`
