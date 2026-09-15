# Mo on Trees Path Demo

## 1. Problem Statement
Teaching-lab — **path distinct** on a tree (prelude to tree Mo).

Full tree Mo flattens an Euler tour and toggles nodes on second visit; this lab validates the path-distinct oracle via LCA climbs so the pattern is clear before the heavy machinery.

## 2. Intuition
Path u–v = u↑LCA + v↑LCA; distinct values on that node set.

## 3. Brute Force → Optimal
- Full tree Mo for many offline path queries. Climb OK for tiny demos.

## 4. Data Structure / Approach Justification
**Chosen:** LCA climb distinct (teaching). Mention Euler+Mo as contest upgrade.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Compute LCA; collect values to root; unique count.

## 6. Dry Run
`(3,4)→3`, `(3,1)→2`, `(4,2)→2`, `(3,3)→1`.

## 7. Time & Space Complexity
Climb **O(N)** per query; tree Mo ~O(N√N) for many queries.

## 8. Trade-offs & Alternatives
Binary lifting LCA + Mo on Euler for real contests.

## 9. Common Mistakes / Edge Cases
Double-counting LCA value; edge vs node values.

## 10. Interview Follow-ups / Variations
Path sums with Euler difference arrays.

## 11. Tags
`mo-algorithm`, `trees`, `lca`, `teaching-lab`, `difficulty:hard`
