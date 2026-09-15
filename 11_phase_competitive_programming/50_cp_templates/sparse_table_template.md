# Sparse Table Template

## 1. Problem Statement
Teaching-lab — static idempotent RMQ via sparse table. Demo min on `[1,4]→1`.

## 2. Intuition
`st[k][i]` = combine of length `2^k` starting at `i`; overlapping blocks for idempotent ops.

## 3. Brute Force → Optimal
- **Brute:** scan. **Optimal:** O(1) query after O(n log n) build (idempotent).

## 4. Data Structure / Approach Justification
**Chosen:** min sparse table.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

Used heavily inside Euler+RMQ LCA.

## 5. Logic Walkthrough
Precompute floor-log; answer with two overlapping `2^k` windows.

## 6. Dry Run
Array `4,2,3,7,1,5`; indices 1..4 min is 1.

## 7. Time & Space Complexity
Build **O(n log n)**; query **O(1)**. Space **O(n log n)**.

## 8. Trade-offs & Alternatives
SegTree if updates needed; disjoint sparse table for non-idempotent sums.

## 9. Common Mistakes / Edge Cases
Off-by-one on `r-(1<<k)+1`; using for sum without care.

## 10. Interview Follow-ups / Variations
GCD table; LCA via Euler tour.

## 11. Tags
`sparse-table`, `rmq`, `template`, `difficulty:medium`
