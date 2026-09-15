# Unique Sorted Map Lab

## 1. Problem Statement
Teaching-lab — `sort+unique+lower_bound` ranks ≡ `map` assignment.

## 2. Intuition
Same order-isomorphism to `1..U`.

## 3. Brute Force → Optimal
- map simpler; vector faster.

## 4. Data Structure / Approach Justification
**Chosen:** equivalence check.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Build both; compare.

## 6. Dry Run
`[5,1,5,2,9]→[3,1,3,2,4]`.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Hash remap.

## 9. Common Mistakes / Edge Cases
map order assumptions.

## 10. Interview Follow-ups / Variations
Compress pairs.

## 11. Tags
`coordinate-compression`, `teaching-lab`, `difficulty:easy`

