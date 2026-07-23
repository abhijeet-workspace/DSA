# Kruskal's MST

## Problem Statement
Classic **Kruskal** — given an undirected weighted graph, compute the total weight of a Minimum Spanning Tree (MST).

- **Inputs:** `V` vertices, list of edges `(u, v, weight)`.
- **Output:** integer MST total weight (assumes the graph is connected).
- **Valid answer:** any MST’s weight (unique weight even if tree not unique).
- **Edges:** equal weights; dense vs sparse; already a tree.

## Intuition
Greedy: sort edges ascending; add an edge iff it connects different components (no cycle). Stop after `V-1` edges.

## Brute Force → Optimal
- **Brute:** enumerate spanning trees — exponential.
- **Optimal:** sort + DSU — O(E log E).

## Data Structure / Approach Justification
**Chosen:** edge list sorted by weight + Union-Find for cycle checks.

- **vs Prim:** Prim shines on dense graphs with a heap/matrix; Kruskal is natural for sparse edge lists.
- **vs Borůvka:** similar asymptotics; less common in interviews.

## Logic Walkthrough
Sort edges. For each edge, `unionSets`; on success add weight and increment used. Break at `V-1` edges.

## Dry Run
Edges weights 4,5,6,10,15 on 4 nodes: take `(2,3)=4`, `(0,3)=5`, `(0,1)=10` → weight **19** (skip 6 as it would cycle with 4+5 path).

## Time & Space Complexity
Time **O(E log E)** (sort dominates). Space **O(V + E)**. Why: DSU ops are ~α(V) after sorting (section 4).

## Trade-offs & Alternatives
Prefer Prim when building from adjacency and V is small. Prefer Kruskal when edges are already listed / sparse.

## Common Mistakes / Edge Cases
Forgetting undirected double-representation is unnecessary with edge list; continuing after V−1; not handling disconnected graphs (partial forest).

## Interview Follow-ups / Variations
Return the edge list of the MST. Second-best MST. Max spanning tree (sort descending).

## Tags
`mst`, `kruskal`, `union-find`, `greedy`, `difficulty:medium`
