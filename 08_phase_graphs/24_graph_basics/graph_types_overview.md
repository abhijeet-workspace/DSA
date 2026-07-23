# Graph Types Demo

## Problem Statement
Demonstrate core graph **types** in code: directed vs undirected storage, weighted edges, DAG topological order (Kahn), and bipartite 2-coloring.

- **Inputs:** small hard-coded graphs per demo.
- **Output:** printed representations / topo order / BIPARTITE vs NOT.
- **Valid answer:** matches the structural rules of each type.
- **Edges:** cycles break topo; odd cycles break bipartite.

## Intuition
Classification drives algorithm choice: undirected friendship vs directed follows; weights need Dijkstra not plain BFS; DAGs admit topo order; bipartite ≡ 2-colorable ≡ no odd cycle.

## Brute Force → Optimal
- **Topo:** try all permutations — `O(V!)`; Kahn/DFS linear `O(V+E)`.
- **Bipartite:** search for odd cycles naively or 2-color with BFS/DFS — `O(V+E)`.

## Data Structure / Approach Justification
**Chosen:** adjacency lists (+ matrix for weighted demo); queue for Kahn and bipartite BFS.

- **vs DFS topo:** both linear; Kahn also detects cycles via incomplete order.
- **vs matching algorithms for bipartite:** 2-coloring only *checks* bipartiteness.

## Logic Walkthrough
(1) Push both ways vs one way. (2) Store weights in matrix/`pair`. (3) Kahn: peel indegree-0 nodes. (4) BFS color opposite; conflict ⇒ not bipartite.

## Dry Run
Kahn edges `5→2,5→0,4→0,4→1,2→3,3→1`: start queue `{4,5}` → valid topo length 6. Triangle odd cycle → NOT bipartite; C4 → BIPARTITE.

## Time & Space Complexity
Each demo **O(V+E)** (matrix print **O(V²)**). Space **O(V+E)**. Why: standard graph passes (section 4).

## Trade-offs & Alternatives
One file keeps types together for teaching; production code splits checks. DFS coloring equals BFS for bipartite.

## Common Mistakes / Edge Cases
Treating cyclic digraph as DAG; forgetting disconnected components in bipartite/topo; using 0 as “no weight” when 0 is valid.

## Interview Follow-ups / Variations
Course schedule (207/210); is-graph-bipartite (785); strongly connected components; Euler vs Hamiltonian.

## Tags
`graph`, `dag`, `bipartite`, `topological-sort`, `weighted`, `difficulty:easy`
