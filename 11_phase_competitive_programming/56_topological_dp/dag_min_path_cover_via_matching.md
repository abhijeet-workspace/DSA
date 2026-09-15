# DAG Minimum Path Cover via Matching

## 1. Problem Statement
Teaching lab — minimum path cover in a **DAG** (vertex-disjoint paths covering all vertices) equals `n - maximum matching` in the split bipartite graph.

- **Inputs:** DAG on `n` nodes, edges.
- **Output:** size of minimum path cover.
- **Edges:** empty DAG → `n`; single chain → `1`.

## 2. Intuition
Each matched bipartite edge chains `u` into `v`; unmatched starts a new path.

## 3. Brute Force → Optimal
- **Brute:** set cover of paths.
- **Optimal:** Kuhn/Hopcroft on split graph — O(VE).

## 4. Data Structure / Approach Justification
**Chosen:** node split + Kuhn matching.

| Alternative | Note |
|-------------|------|
| Dilworth (comparability) | Related theory |
| Greedy chains | Wrong |

## 5. Logic Walkthrough
Build `L(u)→R(v)` for each DAG edge; `answer = n - max_matching`.

## 6. Dry Run
Chain of 3 → cover `1`; two disjoint edges on 4 nodes → cover `2`.

## 7. Time & Space Complexity
Time **O(VE)** with Kuhn. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Bridge topic between topo DP folder and bipartite matching folder.

## 9. Common Mistakes / Edge Cases
Applying to general graphs with cycles (NP-hard); forgetting split.

## 10. Interview Follow-ups / Variations
Edge-disjoint path cover; weighted.

## 11. Tags
`dag`, `path-cover`, `bipartite-matching`, `teaching`, `difficulty:hard`
