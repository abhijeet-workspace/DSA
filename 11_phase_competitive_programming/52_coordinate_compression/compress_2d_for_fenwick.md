# Compress 2D for Fenwick

## 1. Problem Statement
Teaching-lab — independently compress x and y for 2D Fenwick indices.

## 2. Intuition
Dense axes for plane structures.

## 3. Brute Force → Optimal
- Two rank maps.

## 4. Data Structure / Approach Justification
**Chosen:** separate unique sorts.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Map each point.

## 6. Dry Run
`(1000,-5)→(2,1)` etc.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Joint pair compress sometimes.

## 9. Common Mistakes / Edge Cases
Shared x/y map bug.

## 10. Interview Follow-ups / Variations
2D range sums.

## 11. Tags
`coordinate-compression`, `2d`, `teaching-lab`, `difficulty:easy`

