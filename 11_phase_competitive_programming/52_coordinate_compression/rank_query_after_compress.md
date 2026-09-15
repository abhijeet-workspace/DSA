# Rank Query After Compress

## 1. Problem Statement
Teaching-lab — order queries on unique-sorted values via `upper_bound`.

## 2. Intuition
Compressed list = order-statistic dictionary.

## 3. Brute Force → Optimal
- Multiset online.

## 4. Data Structure / Approach Justification
**Chosen:** sort unique + binary search.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Build vals; query.

## 6. Dry Run
≤40 → 3 distinct.

## 7. Time & Space Complexity
**O(n log n)** build.

## 8. Trade-offs & Alternatives
Fenwick for multisets.

## 9. Common Mistakes / Edge Cases
lower vs upper.

## 10. Interview Follow-ups / Variations
k-th distinct.

## 11. Tags
`coordinate-compression`, `teaching-lab`, `difficulty:easy`

