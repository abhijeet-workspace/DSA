# Order Statistic Fenwick Lab

## 1. Problem Statement
Teaching-lab — order statistics (`k`-th smallest) using Fenwick frequencies after compression.

**Skipped:** GNU `pbds` `indexed_set` (not portable on Apple clang). This lab is the portable substitute.

## 2. Intuition
Freq BIT + binary lifting on the tree finds the smallest index with prefix freq ≥ k.

## 3. Brute Force → Optimal
- **pbds:** shorter on GCC. **Fenwick:** portable CP default.

## 4. Data Structure / Approach Justification
**Chosen:** compressed Fenwick kth.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

## 5. Logic Walkthrough
Compress → add +1 at rank → kth walks BIT.

## 6. Dry Run
Insert 40,10,30,20 → order 10,20,30,40.

## 7. Time & Space Complexity
Insert/kth **O(log U)** after compression.

## 8. Trade-offs & Alternatives
Policy-based data on CF GNU; treaps.

## 9. Common Mistakes / Edge Cases
k larger than size; 0-based rank bugs.

## 10. Interview Follow-ups / Variations
Delete via add -1; count strictly less.

## 11. Tags
`order-statistic`, `fenwick`, `teaching-lab`, `difficulty:medium`
