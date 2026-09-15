# Fenwick Template

## 1. Problem Statement
Teaching-lab — 1-based Fenwick for point add + prefix/range sum. Demo fills `1..5`, queries `[2,4]→9`.

## 2. Intuition
Binary indexed tree stores partial sums along lowest-set-bit jumps.

## 3. Brute Force → Optimal
- **Brute:** array rebuild. **Optimal:** O(log n) updates/queries.

## 4. Data Structure / Approach Justification
**Chosen:** classic BIT.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

Deep dives in segment-tree/Fenwick topic.

## 5. Logic Walkthrough
`add` walks up; `sumPrefix` walks down clearing LSBs.

## 6. Dry Run
Values 1+2+3+4+5; range 2..4 = 9.

## 7. Time & Space Complexity
Time **O(log n)** per op. Space **O(n)**.

## 8. Trade-offs & Alternatives
SegTree for non-sum ops; difference array + BIT for range add.

## 9. Common Mistakes / Edge Cases
0-based index mistakes; querying l=0.

## 10. Interview Follow-ups / Variations
2D BIT; order-statistic via BIT (see order_statistic_fenwick_lab).

## 11. Tags
`fenwick`, `bit`, `template`, `difficulty:easy`
