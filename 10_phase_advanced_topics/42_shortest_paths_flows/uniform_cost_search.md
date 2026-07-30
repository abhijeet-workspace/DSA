# Uniform Cost Search (UCS)

## Problem Statement
Single-source cheapest-path search on a graph with **non-negative** edge costs — the AI/search name for what DSA usually calls Dijkstra.

- **Inputs:** `V`, weighted adjacency list `(v, w)`, source `S`.
- **Output:** `dist[]` from `S`.
- **Edges:** unreachable nodes; zero-weight edges; unit weights (degenerates toward BFS).

## Intuition
Always expand the frontier node with the smallest path cost so far. First time a node is settled, its cost is optimal under non-negative weights.

## Brute Force → Optimal
- **Brute:** enumerate paths.
- **UCS / Dijkstra:** O((V+E) log V) with a binary heap.

## Data Structure / Approach Justification
**Chosen:** min-heap of `(cost, node)` with lazy stale-entry skipping.

- **vs BFS:** BFS is optimal only for uniform/unit edge weights.
- **vs A*:** UCS is A* with `h=0`.

## Logic Walkthrough
`dist[S]=0`, push `(0,S)`. Pop cheapest `u`. Relax outgoing edges; push improved costs.

## Dry Run
Edges from 0 yield distances `[0,2,3,4,6]` after expanding cheapest nodes in order.

## Time & Space Complexity
Time **O(E log V)**. Space **O(V+E)**.

## Trade-offs & Alternatives
Same limits as Dijkstra: no negative edges. Prefer A* when a good heuristic exists.

## Common Mistakes / Edge Cases
Treating UCS as BFS with a queue; negatives; overflow on `INT_MAX + w`.

## Interview Follow-ups / Variations
Early exit when goal is dequeued; path reconstruction; relationship to Dijkstra / A*.

## Tags
`graph`, `ucs`, `dijkstra`, `shortest-path`, `difficulty:medium`
