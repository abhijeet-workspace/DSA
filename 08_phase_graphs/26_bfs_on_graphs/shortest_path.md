# Shortest Path (Unweighted)

## Problem Statement
Find a **minimum-edge** path from `src` to `dest` in an undirected unweighted graph; return the vertex sequence (or empty if unreachable).

- **Inputs:** `V`, adjacency list, `src`, `dest`.
- **Output:** path vector `src … dest`.
- **Valid answer:** any shortest path (ties allowed).
- **Edges:** `src==dest`; disconnected; cycles.

## Intuition
On unit-weight edges, BFS discovers nodes in increasing distance; first time you reach `dest` is optimal. Store `parent` to reconstruct.

## Brute Force → Optimal
- **Brute:** DFS all simple paths — exponential.
- **Optimal:** BFS — **O(V+E)** time, **O(V)** space.

## Data Structure / Approach Justification
**Chosen:** queue + `dist`/`parent` arrays.

- **vs Dijkstra:** unnecessary without positive weights.
- **vs DFS:** not shortest on unweighted graphs.

## Logic Walkthrough
`dist[src]=0`, enqueue. For each pop, relax unvisited neighbors with `dist+1` and set parent. Walk parents from `dest` back to `src`, reverse.

## Dry Run
`0—1—3—5` and `0—2—4—5`: BFS may yield `0 1 3 5` (length 3).

## Time & Space Complexity
Time **O(V+E)**. Space **O(V)**. Why: classic BFS (section 4).

## Trade-offs & Alternatives
If only distance needed, drop path reconstruction. Weighted → Dijkstra/0-1 BFS.

## Common Mistakes / Edge Cases
Marking visited late (longer paths); forgetting reverse; assuming unique path.

## Interview Follow-ups / Variations
k-shortest; weighted; grid shortest path; bidirectional BFS.

## Tags
`graph`, `bfs`, `shortest-path`, `unweighted`, `difficulty:easy`
