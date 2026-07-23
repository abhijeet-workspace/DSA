# Bitmask DP (TSP)

## Problem Statement
Traveling Salesman via Held–Karp: visit each city exactly once and return to start; minimize total distance.

- **Inputs:** `dist[V][V]` symmetric (or directed) cost matrix.
- **Output:** min tour cost.
- **Valid answer:** Hamiltonian cycle of minimum weight.
- **Edges:** `V=1`; disconnected (INF); asymmetric costs.

## Intuition
Subset of visited cities fits in a bit mask. `dp[u][mask]` = min cost to reach `u` having visited `mask`, ending ready to extend.

## Brute Force → Optimal
- **Brute:** all permutations — O(V!).
- **Optimal:** DP over subsets — O(V² · 2^V).

## Data Structure / Approach Justification
**Chosen:** memo `memo[u][mask]` with DFS/`tsp` recursion.

- **vs iterative subset DP:** same complexity; iterative may be clearer for bottom-up.
- **vs MST / approximation:** not exact; used when V is large.

## Logic Walkthrough
Start `(u=0, mask=1)`. If `mask` full, add `dist[u][0]`. Else try unset bits `v`, recurse with `mask|1<<v`. Memoize.

## Dry Run
4 cities; path `0→1→2→3→0` = `20+30+10+25` = **85**.

## Time & Space Complexity
Time **O(V² · 2^V)**. Space **O(V · 2^V)**. Why: each `(u,mask)` tries ≤ V edges (section 4).

## Trade-offs & Alternatives
Exact only for small V (≤20-ish). Branch-and-bound or ILP for larger instances.

## Common Mistakes / Edge Cases
Forgetting return to 0; starting mask without city 0; using `#define INF` that overflows on add.

## Interview Follow-ups / Variations
Path (not cycle) TSP; assign jobs to workers (min cost bipartite via mask); LC 847 shortest path visiting all nodes.

## Tags
`bitmask-dp`, `tsp`, `held-karp`, `difficulty:hard`
