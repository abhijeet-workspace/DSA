# Dijkstra on Reweighted Edges

## 1. Problem Statement
Teaching lab — run Dijkstra on a graph whose edges are already Johnson-reweighted (nonnegative). Inner loop of APSP Johnson.

- **Inputs:** nonnegative weighted digraph, source.
- **Output:** distances from source.
- **Edges:** unreachable INF; zero weights.

## 2. Intuition
Binary-heap Dijkstra after potentials guarantee `w'≥0`.

## 3. Brute Force → Optimal
- **BF from each source:** slower.
- **Dijkstra:** O(E log V) per source.

## 4. Data Structure / Approach Justification
**Chosen:** standard Dijkstra.

| Alternative | Note |
|-------------|------|
| Dial / radix heap | Faster special weights |

## 5. Logic Walkthrough
PQ relax until empty; return `dist`.

## 6. Dry Run
Graph `0→1(2),1→2(1),0→2(5)` → `d[2]=3`.

## 7. Time & Space Complexity
Time **O(E log V)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Compose with `reweight_edges_johnson_step` and recover via `d'-h[s]+h[v]`.

## 9. Common Mistakes / Edge Cases
Running on raw negative edges.

## 10. Interview Follow-ups / Variations
Potential-aware distance recovery demo.

## 11. Tags
`dijkstra`, `johnson`, `teaching`, `difficulty:easy`
