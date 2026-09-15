# Merge Intervals Compressed Coords

## 1. Problem Statement
Teaching-lab — merge on compressed endpoints then restore. Related [LC 56](https://leetcode.com/problems/merge-intervals/).

## 2. Intuition
Monotone ranks preserve order.

## 3. Brute Force → Optimal
- Raw merge fine; compression for grid/BIT variants.

## 4. Data Structure / Approach Justification
**Chosen:** map→merge→unmap.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Compress; merge ranks; restore.

## 6. Dry Run
`[1,6],[100,110]`.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Skip compress in interviews.

## 9. Common Mistakes / Edge Cases
Wrong restore index.

## 10. Interview Follow-ups / Variations
Intersections.

## 11. Tags
`coordinate-compression`, `teaching-lab`, `difficulty:easy`

