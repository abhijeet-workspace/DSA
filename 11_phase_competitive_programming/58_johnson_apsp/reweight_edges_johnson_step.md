# Reweight Edges (Johnson Step)

## 1. Problem Statement
Teaching lab — compute Bellman–Ford potentials from a super-source and reweight edges `w' = w + h[u] − h[v]` so all `w' ≥ 0` when no negative cycle.

- **Inputs:** digraph with possible negative edges (no neg cycle).
- **Output:** potentials and verification that reweighted edges are nonnegative.
- **Edges:** already nonnegative; negative tree edges.

## 2. Intuition
Potential reweighting preserves shortest-path trees; nonnegative `w'` enables Dijkstra.

## 3. Brute Force → Optimal
- **Skip potentials:** Dijkstra fails with negatives.
- **Johnson step:** one BF then V Dijkstras.

## 4. Data Structure / Approach Justification
**Chosen:** super-source BF → print reweighted weights.

| Alternative | Note |
|-------------|------|
| Full Johnson | See `johnson_apsp` |

## 5. Logic Walkthrough
Add `s→v` weight 0; BF for `h`; compute `w'`.

## 6. Dry Run
Graph with a negative edge reweights to all `w'≥0`.

## 7. Time & Space Complexity
Time **O(VE)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Core algebraic step separating Johnson from Floyd.

## 9. Common Mistakes / Edge Cases
Using `h[v]-h[u]` sign flip; running Dijkstra before reweight.

## 10. Interview Follow-ups / Variations
Recover original distances `d = d' - h[s] + h[v]`.

## 11. Tags
`johnson`, `potentials`, `reweighting`, `teaching`, `difficulty:medium`
