# Floyd-Warshall

## Problem Statement
Compute **all-pairs shortest paths** on a weighted directed graph (adjacency matrix). Handles negative edges; assumes no negative cycle.

- **Inputs:** `V`, matrix `graph[i][j]` = weight or `INF` if no edge; `graph[i][i]=0`.
- **Output:** matrix of shortest distances `i → j`.
- **Valid answer:** min path weights over all intermediate vertex sets.
- **Edges:** unreachable pairs stay `INF`; negative edges OK without neg cycles.

## Intuition
DP: after considering intermediates `{0..k}`, `dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])`. Triple loop over `k,i,j`.

## Brute Force → Optimal
- **Brute:** Dijkstra/Bellman from every source — O(V·(E log V)) or O(V²E).
- **Optimal for dense:** Floyd-Warshall — O(V³) time, O(V²) space.

## Data Structure / Approach Justification
**Chosen:** in-place-style DP on a distance matrix copy.

- **vs V×Dijkstra:** better when dense or negative edges (no potentials).
- **vs Johnson:** Johnson wins on sparse graphs with negatives.

## Logic Walkthrough
Copy `graph` → `dist`. For each intermediate `k`, relax all pairs `(i,j)` through `k` when both sides finite. Print matrix.

## Dry Run
`0→1=3`, `1→2=2` ⇒ after `k=1`, `0→2 ≤ 5`. Continue for all `k` until closure.

## Time & Space Complexity
Time **O(V³)**. Space **O(V²)**. Why: three nested loops over vertices (section 4).

## Trade-offs & Alternatives
Prefer Dijkstra-per-source on sparse non-negative graphs. Use Bellman-Ford + detection if negative cycles may exist (check `dist[i][i] < 0`).

## Common Mistakes / Edge Cases
Overflow when adding `INF`; wrong loop order (`k` must be outermost); mutating input unexpectedly; ignoring negative cycles.

## Interview Follow-ups / Variations
Recover paths via `next[i][j]`. Detect negative cycles. Transitive closure (boolean Floyd).

## Tags
`shortest-path`, `floyd-warshall`, `dp`, `all-pairs`, `difficulty:medium`
