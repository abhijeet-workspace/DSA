# Graph BFS

## 1. Problem Statement
Traverse an undirected graph in **breadth-first** (level) order starting from a source vertex and print visit order.

- **Inputs:** adjacency list `adj`, source `src`.
- **Output:** vertices in BFS order from `src`.
- **Valid answer:** each reachable vertex appears once; same-level order may vary by neighbor list order.
- **Edges:** disconnected components beyond `src` are not visited; empty graph / isolated source.

## 2. Intuition
BFS expands frontier layer by layer using a queue. Mark visited when enqueueing so each vertex enters the queue once — natural for unweighted shortest paths (distance = level).

## 3. Brute Force → Optimal
- **Brute:** restart searches or re-scan all edges without a visited set — may reprocess vertices/edges.
- **Optimal:** queue + `visited` — each vertex/edge examined once → `O(V+E)`.

## 4. Data Structure / Approach Justification
**Chosen:** `std::queue` for FIFO levels; `vector<bool> visited` sized to `V`.

- **vs DFS:** DFS goes deep first; BFS guarantees minimal hop count on unweighted graphs.
- **vs priority queue:** unnecessary without edge weights.

## 5. Logic Walkthrough
Mark `src` visited and enqueue. While queue non-empty: dequeue `u`, print it, enqueue each unvisited neighbor `v` (mark before push).

## 6. Dry Run
Edges `0-1`, `0-2`, `1-3`, `2-4`, BFS from `0`:
- start: visit `0`
- level 1: `1`, `2`
- level 2: `3` (from 1), `4` (from 2)
- print: `0 1 2 3 4` (same-level order may swap)

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V)** for queue + visited. Why: each vertex and edge touched constantly often (section 4).

## 8. Trade-offs & Alternatives
BFS needs `O(W)` queue memory at widest level. For single-source distances on unweighted graphs, BFS is preferred over Dijkstra.

## 9. Common Mistakes / Edge Cases
Marking visited only on dequeue (duplicates in queue); forgetting undirected edges need both directions in the list; not handling unreachable vertices.

## 10. Interview Follow-ups / Variations
Multi-source BFS; shortest path distances; bipartite 2-coloring with BFS levels; 0-1 BFS with deque.

## 11. Tags
`graph`, `bfs`, `queue`, `traversal`, `difficulty:easy`
