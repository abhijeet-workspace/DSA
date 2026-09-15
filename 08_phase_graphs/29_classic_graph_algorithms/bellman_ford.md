# Bellman-Ford

## 1. Problem Statement
Classic Bellman-Ford: compute single-source shortest paths on a directed graph that may have negative weights. Report failure if a negative cycle is reachable from the source.

- **Inputs:** `n`, edge list `(u,v,w)`, `src`.
- **Output:** distances + boolean ok (no reachable neg cycle).
- **Valid answer:** after n-1 relaxations, distances final iff no neg cycle.
- **Edges:** neg edges without cycles; unreachable neg cycle; disconnected.

## 2. Intuition
Relax all edges |V|-1 times. A further improving relaxation implies a negative cycle on a path from src.

## 3. Brute Force → Optimal
- **Brute:** enumerate walks.
- **Optimal:** Bellman-Ford O(nE); Dijkstra faster if all weights ≥0.

## 4. Data Structure / Approach Justification
**Chosen:** edge-list relaxation + nth-pass cycle check.

- **vs SPFA:** average faster, worst-case weak.
- **vs Floyd:** all-pairs.

## 5. Logic Walkthrough
Init dist[src]=0. Loop n-1 times relaxing. Extra pass: if improve, return false.

## 6. Dry Run
Classic CLRS-style graph from 0 yields finite distances without neg cycle.

## 7. Time & Space Complexity
Time **O(nE)**. Space **O(n)**. Why: n passes over edges (section 4).

## 8. Trade-offs & Alternatives
[Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) is hop-limited BF.

## 9. Common Mistakes / Edge Cases
Relaxing from INF nodes; missing early stop; confusing undirected neg edges.

## 10. Interview Follow-ups / Variations
Negative cycle detection only; difference constraints; FX arbitrage.

## 11. Tags
`bellman-ford`, `shortest-path`, `classic`, `difficulty:medium`
