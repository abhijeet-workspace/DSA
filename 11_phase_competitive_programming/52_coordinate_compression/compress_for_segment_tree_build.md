# Compress for Segment Tree Build

## 1. Problem Statement
Teaching-lab — compress then frequency segtree on ranks for value-range counts.

## 2. Intuition
SegTree domain must be O(U)≤n.

## 3. Brute Force → Optimal
- Implicit/dynamic segtree avoids compress.

## 4. Data Structure / Approach Justification
**Chosen:** explicit compress + segtree.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Insert by rank; query rank interval.

## 6. Dry Run
Values in `[50,100]` → 3 occurrences (`50` once, `100` twice; `1` excluded).

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Fenwick for prefixes.

## 9. Common Mistakes / Edge Cases
Building on INT_MAX domain.

## 10. Interview Follow-ups / Variations
Wavelet tree.

## 11. Tags
`coordinate-compression`, `segment-tree`, `teaching-lab`, `difficulty:medium`

