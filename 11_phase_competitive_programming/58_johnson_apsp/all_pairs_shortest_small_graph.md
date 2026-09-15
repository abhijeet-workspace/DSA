# All-Pairs Shortest (Small Graph Lab)

## 1. Problem Statement
Teaching lab — compute APSP on a tiny digraph with Floyd and verify a known distance.

- **Inputs:** hard-coded small graph.
- **Output:** `d[0][3]` (and matrix in principle).
- **Edges:** unreachable stays INF.

## 2. Intuition
Floyd fills all pairs; path `0-1-2-3` costs `3+1+2=6`.

## 3. Brute Force → Optimal
- **Brute:** BFS/Dijkstra per source.
- **Lab:** Floyd for clarity.

## 4. Data Structure / Approach Justification
**Chosen:** Floyd on 4 nodes.

| Alternative | Note |
|-------------|------|
| Johnson on same graph | Same distances |

## 5. Logic Walkthrough
Init; Floyd; print one entry.

## 6. Dry Run
`d[0][3]=6`.

## 7. Time & Space Complexity
Time **O(1)** for fixed n=4 / general **O(n³)**.

## 8. Trade-offs & Alternatives
Unit test fixture for comparing Johnson implementations.

## 9. Common Mistakes / Edge Cases
Forgetting undirected symmetry when graph is undirected.

## 10. Interview Follow-ups / Variations
Add negative edges and compare to Johnson.

## 11. Tags
`apsp`, `floyd`, `teaching`, `lab`, `difficulty:easy`
