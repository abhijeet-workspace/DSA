# Negative Cycle Detection

## Problem Statement
Detect whether a **negative-weight cycle** is reachable from a source in a directed weighted graph (Bellman-Ford).

- **Inputs:** `V`, edge list `(src, dest, weight)`, source `src`.
- **Output:** `bool` — true if a negative cycle is reachable from `src`.
- **Valid answer:** true iff the V-th relaxation still improves some reachable dist.
- **Edges:** neg cycle unreachable from `src`; zero-weight cycles; disconnected nodes.

## Intuition
After `V-1` relaxations, shortest paths without cycles are final. Any further improvement implies a negative cycle on a reachable path.

## Brute Force → Optimal
- **Brute:** enumerate walks of increasing length — exponential.
- **Optimal:** Bellman-Ford — O(V·E); SPFA variants exist but can be weak worst-case.

## Data Structure / Approach Justification
**Chosen:** edge-list Bellman-Ford with an extra detection pass.

- **vs Floyd `dist[i][i]<0`:** finds any neg cycle, not necessarily src-reachable.
- **vs Dijkstra:** incorrect with negatives.

## Logic Walkthrough
Init `dist[src]=0`, others `INF`. Relax all edges `V-1` times. One more pass: if any edge still relaxes from a finite dist, return true.

## Dry Run
Edges `0→1 (1)`, `1→2 (-1)`, `2→3 (-1)`, `3→1 (-1)`: after `V-1` passes, the cycle keeps decreasing → detection returns **YES**.

## Time & Space Complexity
Time **O(V·E)**. Space **O(V)**. Why: `V` sweeps over all edges (section 4).

## Trade-offs & Alternatives
To detect any cycle in the graph, run from a super-source linked to all nodes with 0-weight edges. Floyd checks diagonal for any cycle.

## Common Mistakes / Edge Cases
Relaxing from `INF` (false improvements); stopping at `V-1` without the detection pass; missing that unreachable neg cycles should return false for a given `src`.

## Interview Follow-ups / Variations
Recover the cycle nodes. Arbitrage (log rates → neg cycle). Difference constraints.

## Tags
`bellman-ford`, `negative-cycle`, `shortest-path`, `difficulty:medium`
