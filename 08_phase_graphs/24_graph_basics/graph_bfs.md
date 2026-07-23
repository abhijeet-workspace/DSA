# Graph BFS

## Problem Statement
Traverse an undirected graph in **breadth-first** (level) order starting from a source vertex and print visit order.

- **Inputs:** adjacency list `adj`, source `src`.
- **Output:** vertices in BFS order from `src`.
- **Valid answer:** each reachable vertex appears once; same-level order may vary by neighbor list order.
- **Edges:** disconnected components beyond `src` are not visited; empty graph / isolated source.

## Intuition
BFS expands frontier layer by layer using a queue. Mark visited when enqueueing so each vertex enters the queue once — natural for unweighted shortest paths (distance = level).

## Brute Force → Optimal
- **Brute:** restart searches or re-scan all edges without a visited set — may reprocess vertices/edges.
- **Optimal:** queue + `visited` — each vertex/edge examined once → `O(V+E)`.

## Data Structure / Approach Justification
**Chosen:** `std::queue` for FIFO levels; `vector<bool> visited` sized to `V`.

- **vs DFS:** DFS goes deep first; BFS guarantees minimal hop count on unweighted graphs.
- **vs priority queue:** unnecessary without edge weights.

## Logic Walkthrough
Mark `src` visited and enqueue. While queue non-empty: dequeue `u`, print it, enqueue each unvisited neighbor `v` (mark before push).

## Dry Run
Edges `0-1`, `0-2`, `1-3`, `2-4`, BFS from `0`:
- start: visit `0`
- level 1: `1`, `2`
- level 2: `3` (from 1), `4` (from 2)
- print: `0 1 2 3 4` (same-level order may swap)

## Time & Space Complexity
Time **O(V+E)**. Space **O(V)** for queue + visited. Why: each vertex and edge touched constantly often (section 4).

## Trade-offs & Alternatives
BFS needs `O(W)` queue memory at widest level. For single-source distances on unweighted graphs, BFS is preferred over Dijkstra.

## Common Mistakes / Edge Cases
Marking visited only on dequeue (duplicates in queue); forgetting undirected edges need both directions in the list; not handling unreachable vertices.

## Interview Follow-ups / Variations
Multi-source BFS; shortest path distances; bipartite 2-coloring with BFS levels; 0-1 BFS with deque.

## Tags
`graph`, `bfs`, `queue`, `traversal`, `difficulty:easy`
