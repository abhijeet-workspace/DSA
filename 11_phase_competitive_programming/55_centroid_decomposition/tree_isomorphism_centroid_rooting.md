# Tree Isomorphism (Centroid Rooting)

## 1. Problem Statement
Teaching lab — decide whether two undirected trees are isomorphic by rooting each at its centroid(s) and comparing AHU bracket encodings.

- **Inputs:** two trees on `n` nodes.
- **Output:** yes/no isomorphism.
- **Edges:** path vs star; two-centroid even trees.

## 2. Intuition
Rooting at the unique centroid (or trying both when two exist) removes root ambiguity; sorted child encodings give a canonical form.

## 3. Brute Force → Optimal
- **Brute:** try all roots on both trees — O(N²) encodings.
- **Optimal:** centroid root + AHU — O(N log N) with sorting children.

## 4. Data Structure / Approach Justification
**Chosen:** find centroids → AHU string encode → compare.

| Alternative | Note |
|-------------|------|
| Hash of multisets | Faster compare, hash risk |
| Degree sequence only | Insufficient |

## 5. Logic Walkthrough
Compute centroids; for each candidate root build sorted bracket encoding; take lexicographically smallest; compare trees.

## 6. Dry Run
Same Y-shape trees with relabeled nodes → `yes`; path vs branched → `no`.

## 7. Time & Space Complexity
Time **O(N log N)** from child sorts. Space **O(N)**. Why: section 4.

## 8. Trade-offs & Alternatives
Hashing encodings speeds equality; keep strings for pedagogy.

## 9. Common Mistakes / Edge Cases
Forgetting the second centroid when `n` even; unsorted children.

## 10. Interview Follow-ups / Variations
Rooted tree iso; labeled edges.

## 11. Tags
`tree-isomorphism`, `centroid`, `AHU`, `teaching`, `difficulty:hard`
