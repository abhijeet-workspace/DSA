# Bellman-Ford

## Problem Statement
Single-source shortest paths on a directed graph that may have negative edge weights; detect a negative cycle reachable from the source.

- **Inputs:** `V`, edge list `(u,v,w)`, source `src`.
- **Output:** distances from `src`, or signal negative cycle.
- **Valid answer:** shortest-path distances if no reachable neg cycle.
- **Edges:** unreachable nodes; neg weights without cycle; cycle reachable vs not.

## Intuition
A simple shortest path has ≤ `V-1` edges. Relaxing every edge `V-1` times propagates improvements. A further successful relaxation implies a negative cycle.

## Brute Force → Optimal
- **Brute:** enumerate all simple paths — exponential.
- **Optimal:** Bellman-Ford — O(VE). Faster with non-neg weights: Dijkstra O(E log V).

## Data Structure / Approach Justification
**Chosen:** edge-list relaxation + distance array.

- **vs Dijkstra:** cannot handle negative weights.
- **vs SPFA:** often faster average, worse worst-case / contested in contests.

## Logic Walkthrough
`dist[src]=0`, others INF. Repeat `V-1` times: for each edge, if `dist[u]+w < dist[v]`, update. Extra pass: if any update possible → negative cycle.

## Dry Run
Edges include `4→3 (-3)` and path `0→1→4→3`: after relaxations `dist[4]=-2`. Second graph’s cycle `1→2→3→1` sum `-2` → detection fires.

## Time & Space Complexity
Time **O(VE)**. Space **O(V)** (+ O(E) for edges). Why: `V-1` full edge passes (section 4).

## Trade-offs & Alternatives
Handles negatives; slower than Dijkstra. Floyd-Warshall for all-pairs dense graphs O(V³).

## Common Mistakes / Edge Cases
Relaxing from INF `u`; missing the detection pass; reporting cycle not reachable from `src`.

## Interview Follow-ups / Variations
Print the cycle; arbitrage (log rates → neg cycle); difference constraints.

## Tags
`graph`, `shortest-path`, `bellman-ford`, `negative-cycle`, `difficulty:medium`
