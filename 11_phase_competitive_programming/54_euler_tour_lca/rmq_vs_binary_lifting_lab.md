# RMQ vs Binary Lifting Lab

## 1. Problem Statement
Teaching-lab — verify **Euler+RMQ LCA** and **binary lifting LCA** agree on all pairs.

- Not HLD; HLD is for path aggregates. Label clarifies RMQ vs lifting (and vs HLD).

## 2. Intuition
Same tree, two independent LCA algorithms must match.

## 3. Brute Force → Optimal
- Either is fine; lifting also gives kth ancestor; RMQ is O(1) query.

## 4. Data Structure / Approach Justification
**Chosen:** cross-check lab.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
Build both; compare all pairs.

## 6. Dry Run
All pairs agree → OK.

## 7. Time & Space Complexity
Build costs as usual.

## 8. Trade-offs & Alternatives
HLD belongs when you need path sums/updates, not bare LCA.

## 9. Common Mistakes / Edge Cases
RMQ on node ids instead of depths.

## 10. Interview Follow-ups / Variations
Subtree queries via Euler.

## 11. Tags
`lca`, `rmq`, `binary-lifting`, `teaching-lab`, `difficulty:medium`

