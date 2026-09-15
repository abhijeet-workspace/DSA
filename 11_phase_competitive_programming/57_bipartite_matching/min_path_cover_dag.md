# Minimum Path Cover in DAG

## 1. Problem Statement
CP classic — minimum vertex-disjoint path cover in a DAG = `n − maximum matching` on the split bipartite graph.

- **Inputs:** DAG edges on `n` nodes.
- **Output:** cover size.
- **Edges:** no edges → `n`; tournament chain → `1`.

## 2. Intuition
Matched edges chain nodes; each unmatched left starts a path.

## 3. Brute Force → Optimal
- **Brute:** exponential path sets.
- **Optimal:** matching reduction.

## 4. Data Structure / Approach Justification
**Chosen:** Kuhn on L(u)→R(v).

| Alternative | Note |
|-------------|------|
| Dilworth dual | Antichain size on posets |

## 5. Logic Walkthrough
`answer = n - matching`.

## 6. Dry Run
DAG that can be one path → cover `1`.

## 7. Time & Space Complexity
Time **O(VE)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Same reduction as `dag_min_path_cover_via_matching` in topo-DP folder; kept here for matching-first study.

## 9. Common Mistakes / Edge Cases
Using on cyclic graphs.

## 10. Interview Follow-ups / Variations
Edge-disjoint cover; minimum path cover with shared vertices.

## 11. Tags
`path-cover`, `dag`, `kuhn`, `cp`, `difficulty:hard`
