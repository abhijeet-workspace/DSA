# Binary Lifting LCA

## 1. Problem Statement
Teaching/contest — LCA via binary lifting (equalize depth, joint lift).

- Also appears under shortest-paths/flows notes; here it's the Euler-tour topic companion to RMQ LCA.

## 2. Intuition
After depths match, lift both until parents equal.

## 3. Brute Force → Optimal
- Euler+RMQ O(1). Lifting O(log) and supports kth ancestor.

## 4. Data Structure / Approach Justification
**Chosen:** `up[][]` LCA.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
Build; lift deeper; binary search jump; parent.

## 6. Dry Run
LCA(3,4)=0; LCA(3,1)=1.

## 7. Time & Space Complexity
Prep **O(n log n)**; query **O(log n)**.

## 8. Trade-offs & Alternatives
Cross-ref `lca_rmq_sparse_table` in this folder.

## 9. Common Mistakes / Edge Cases
Not lifting from high bit; off-by-one depth.

## 10. Interview Follow-ups / Variations
HLD for path aggregates.

## 11. Tags
`binary-lifting`, `lca`, `teaching-lab`, `difficulty:hard`

