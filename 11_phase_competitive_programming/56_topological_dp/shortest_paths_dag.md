# Shortest Paths on DAG

## Problem Statement
CP classic — weighted DAG; compute single-source shortest-path distances from source `s` (contrast with Dijkstra / Bellman–Ford).

- **Inputs:** weighted DAG, source `src`, nodes `1..n`.
- **Output:** `dist[v]` for each v (INF if unreachable).
- **Valid answer:** handles negative edge weights when acyclic.
- **Edges:** unreachable nodes; source with positive indegree; negatives OK.

## Intuition
Relax every edge once in topological order — enough because no path revisits an earlier node; when `u` is processed, `dist[u]` is final.

## Brute Force → Optimal
- **Brute / overkill:** Dijkstra O((V+E) log V) — works for non-neg but unnecessary on DAGs.
- **Optimal:** Kahn/DFS topo then relax — O(V+E); negatives allowed.

## Data Structure / Approach Justification
**Chosen:** Kahn topo order array + one forward relaxation pass.

- **vs Dijkstra:** slower constants and fails with negatives.
- **vs Bellman–Ford:** O(VE) general graphs; DAG needs only one pass.

## Logic Walkthrough
Compute topo order. Set `dist[src]=0`, others INF. For each `u` in order, if reachable, relax outgoing edges.

## Dry Run
`1→2 (3)`, `1→3 (1)`, `3→2 (1)`. From 1: `dist[3]=1`, `dist[2]=min(3,1+1)=2`.

## Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**. Why: each edge relaxes once after predecessors finalize.

## Trade-offs & Alternatives
Fastest for DAGs; requires acyclicity (condense SCCs first if needed). Prefer Dijkstra when non-neg and cycles may exist.

## Common Mistakes / Edge Cases
Relaxing in BFS order with varied weights (incorrect); not skipping unreachable `u`; confusing with longest-path DP (use min vs max).

## Interview Follow-ups / Variations
Count number of shortest paths? Longest path (swap to max)? Rebuild path via parents?

## Tags
`dag`, `shortest-path`, `topological-sort`, `cp`, `difficulty:medium`
