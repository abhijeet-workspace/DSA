# Bellman–Ford Potentials

## Problem Statement
Teaching piece for Johnson / differential constraints — given a directed weighted graph, compute potentials `h[v]` such that reweighted edges `w'(u,v)=w(u,v)+h[u]-h[v]` are all non-negative, or detect a negative cycle.

- **Inputs:** `n` vertices, edge list `(u,v,w)`.
- **Output:** `h[0..n-1]` or failure on negative cycle.
- **Valid answer:** any `h` satisfying triangle inequalities (unique up to additive constant).
- **Edges:** already non-negative weights (`h=0` works); disconnected graph.

## Intuition
Add super-source `s` with 0-weight edges to all `v`; Bellman–Ford distances from `s` are valid potentials when no negative cycle is reachable. Triangle: `h[v] ≤ h[u]+w` ⇔ `w+h[u]-h[v] ≥ 0`.

## Brute Force → Optimal
- **Brute:** guess potentials — impossible at scale.
- **Optimal:** one Bellman–Ford with `|V|` relax rounds + cycle check.

## Data Structure / Approach Justification
**Chosen:** edge list + super-source, classic BF.

- **vs SPFA:** often faster in practice, same worst-case.
- **vs topo BF on DAGs:** linear when acyclic; not general.

## Logic Walkthrough
Append `s→v` weight 0. Init `h[s]=0`, others INF. Relax all edges up to `n` times. Extra relaxable edge ⇒ negative cycle. Resize `h` to drop `s`.

## Dry Run
Edges `0→1 (1)`, `1→2 (−1)`, `0→2 (3)`: `ok=1`; all `w'` non-negative (e.g. `h` near `[0,0,-1]` up to shift).

## Time & Space Complexity
Time **O(V·E)**. Space **O(V+E)**. Why: standard BF with one extra vertex/edges.

## Trade-offs & Alternatives
Clear teaching step for Johnson; full APSP still needs V Dijkstras after. Super-source is mandatory for disconnected graphs.

## Common Mistakes / Edge Cases
Running BF from an arbitrary vertex (misses unreachable components); forgetting the final cycle check; overflow when adding weights.

## Interview Follow-ups / Variations
Relate potentials to difference constraints / Feasible LP. Why Dijkstra alone fails with negatives?

## Tags
`bellman-ford`, `potentials`, `reweighting`, `johnson`, `difficulty:medium`
