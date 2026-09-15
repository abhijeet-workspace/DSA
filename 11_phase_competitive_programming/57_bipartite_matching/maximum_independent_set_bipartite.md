# Maximum Independent Set (Bipartite)

## 1. Problem Statement
CP classic — in a bipartite graph, maximum independent set size = `|V| − maximum matching` (König).

- **Inputs:** bipartite edges, `nL`, `nR`.
- **Output:** MIS cardinality.
- **Edges:** no edges → all vertices; perfect matching → `|V|/2` on balanced complete.

## 2. Intuition
König: MVC size = matching size; MIS = V − MVC.

## 3. Brute Force → Optimal
- **Brute:** 2^V subsets.
- **Optimal:** matching + formula.

## 4. Data Structure / Approach Justification
**Chosen:** Kuhn then `|V|-matching`.

| Alternative | Note |
|-------------|------|
| Explicit Konig cover construction | Needed for the vertex set, not only size |

## 5. Logic Walkthrough
Compute max matching; return `nL+nR-matching`.

## 6. Dry Run
Two left vertices sharing one right → MIS `2`.

## 7. Time & Space Complexity
Time **O(VE)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
See `min_vertex_cover_bipartite` for constructing the cover set.

## 9. Common Mistakes / Edge Cases
Applying formula on non-bipartite graphs.

## 10. Interview Follow-ups / Variations
Weighted MIS on bipartite graphs.

## 11. Tags
`independent-set`, `konig`, `bipartite`, `cp`, `difficulty:medium`
