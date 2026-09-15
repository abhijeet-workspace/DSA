# Coordinate Compress Snippet

## 1. Problem Statement
Teaching-lab — pasteable compression to 1-based dense ranks. Full topic: `52_coordinate_compression`.

## 2. Intuition
Only relative order matters for tree indices.

## 3. Brute Force → Optimal
- **map:** fine. **sort+unique+lower_bound:** cache-friendly batch.

## 4. Data Structure / Approach Justification
**Chosen:** sort unique vector.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

## 5. Logic Walkthrough
Copy→sort→unique; replace each value by rank.

## 6. Dry Run
`100,-5,100,7` → ranks `3,1,3,2`.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Hash map after unique for O(n) remap.

## 9. Common Mistakes / Edge Cases
Forgetting unique → duplicate ranks.

## 10. Interview Follow-ups / Variations
Compress pairs; online dynamic.

## 11. Tags
`compression`, `template`, `fenwick-prep`, `difficulty:easy`
