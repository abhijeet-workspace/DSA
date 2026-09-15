# Discrete Events Compress

## 1. Problem Statement
Teaching-lab — compress sparse event times, difference-array sweep for max overlap.

## 2. Intuition
Only event abscissae matter.

## 3. Brute Force → Optimal
- Sort events raw. Compression enables array/BIT indices.

## 4. Data Structure / Approach Justification
**Chosen:** unique times + diff.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Collect; compress; ±1; scan.

## 6. Dry Run
Max overlap 2.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
vs multiset sweep.

## 9. Common Mistakes / Edge Cases
Open/closed ends.

## 10. Interview Follow-ups / Variations
Meeting rooms.

## 11. Tags
`coordinate-compression`, `teaching-lab`, `difficulty:easy`

