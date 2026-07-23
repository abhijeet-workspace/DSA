# Johnson APSP

## Problem Statement
Related to LC 787 / 1334-style shortest-path ideas — weighted directed graph (may have negative edges). Compute all-pairs shortest paths, or report a negative cycle.

- **Inputs:** digraph with edge weights.
- **Output:** `dist[n][n]` or failure flag.
- **Valid answer:** recovers original distances after reweighting.
- **Edges:** negative cycle; disconnected pairs; zero-weight edges.

## Intuition
Bellman–Ford potentials make all reweighted edges non-negative; run Dijkstra from every vertex; recover `d = d' - h[s] + h[v]`. Reweighting preserves shortest-path argmins.

## Brute Force → Optimal
- **Brute:** Bellman–Ford from each source — O(V²E).
- **Optimal:** Johnson — one BF + V Dijkstras on sparse graphs.

## Data Structure / Approach Justification
**Chosen:** edge list for BF potentials + binary-heap Dijkstra on reweighted adj.

- **vs Floyd–Warshall:** O(V³) — better for dense/tiny V.
- **vs V×Bellman–Ford:** same correctness, slower on sparse graphs.

## Logic Walkthrough
Super-source BF → `h[]` (abort on neg cycle). Build `w'=w+h[u]-h[v]`. Dijkstra from each `s`; set `dist[s][v]=d'[v]-h[s]+h[v]`.

## Dry Run
3 nodes: `0→1 (1)`, `1→2 (−1)`, `0→2 (3)` → `d[0][2]=0`, `d[0][1]=1`. Cycle `0→1 (1)`, `1→0 (−2)` → detected.

## Time & Space Complexity
Time **O(VE + V(E log V))** with binary heap. Space **O(V²)** for the distance matrix (+ O(V+E) working). Why: one BF then V sparse Dijkstras.

## Trade-offs & Alternatives
Better than Floyd on sparse graphs; worse constant and code size. Prefer Floyd for contest V≤400 dense.

## Common Mistakes / Edge Cases
Forgetting the super-source; returning raw `d'` without converting with `h[]`; allowing Dijkstra to run when a neg cycle exists.

## Interview Follow-ups / Variations
Why Dijkstra alone fails with negatives even without cycles? Complexity crossover vs Floyd?

## Tags
`johnson`, `apsp`, `dijkstra`, `bellman-ford`, `difficulty:hard`
