# Dijkstra

## Problem Statement
Single-source shortest paths on a directed/undirected graph with **non-negative** edge weights.

- **Inputs:** `V`, adjacency list of `(v, weight)`, source `S`.
- **Output:** `dist[0..V-1]` from `S` (`INF` if unreachable).
- **Valid answer:** true shortest distances under non-neg weights.
- **Edges:** disconnected nodes; zero-weight edges; dense vs sparse graphs.

## Intuition
Always expand the unsettled node with smallest tentative distance. With non-negative weights, the first finalized distance is optimal (greedy).

## Brute Force → Optimal
- **Brute:** Bellman-Ford O(VE) even without negatives.
- **Optimal:** binary heap Dijkstra O((V+E) log V); Dial/Fibonacci variants for special cases.

## Data Structure / Approach Justification
**Chosen:** `priority_queue` min-heap of `(dist, node)` with lazy decrease-key.

- **vs set-based Dijkstra:** explicit erase/reinsert; similar complexity.
- **vs Bellman-Ford:** slower, but required if negatives exist.

## Logic Walkthrough
`dist[S]=0`, push `(0,S)`. Pop `(d,u)`; skip if stale. For each edge `u→v`, if `dist[u]+w < dist[v]`, update and push.

## Dry Run
From 0: edges to 4(3),3(5),2(6),1(9). Via `0→2→1` cost 8 beats direct 9 → `dist=[0,8,6,5,3]`.

## Time & Space Complexity
Time **O(E log V)** (binary heap). Space **O(V+E)**. Why: each edge may push a heap entry (section 4).

## Trade-offs & Alternatives
Fails with negative edges. Dense graphs: O(V²) array Dijkstra can win.

## Common Mistakes / Edge Cases
Using Dijkstra with negatives; not skipping stale heap entries; `INT_MAX + w` overflow.

## Interview Follow-ups / Variations
Path reconstruction via parent; Network Delay Time (743); 0-1 BFS; A*.

## Tags
`graph`, `shortest-path`, `dijkstra`, `priority-queue`, `difficulty:medium`
