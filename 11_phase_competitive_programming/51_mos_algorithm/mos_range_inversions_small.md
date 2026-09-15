# Mo Range Inversions Small

## 1. Problem Statement
Teaching problem (Mo pattern) — count inversions inside `[L,R]` for small values using Fenwick inside add/remove.

- Left vs right expand need different BIT updates.

## 2. Intuition
Inversions are pairs; Mo maintains a dynamic multiset of values via BIT.

## 3. Brute Force → Optimal
- Brute O(len²). Mo + BIT O(√N log V) per move amortized total.

## 4. Data Structure / Approach Justification
**Chosen:** Mo with asymmetric addLeft/addRight.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Expand right: add count of greater; expand left: add count of smaller.

## 6. Dry Run
Matches brute inversions.

## 7. Time & Space Complexity
**O((N+Q)√N log V)**.

## 8. Trade-offs & Alternatives
Merge-sort tree / CDQ for online variants.

## 9. Common Mistakes / Edge Cases
Using same add for both sides.

## 10. Interview Follow-ups / Variations
Compress large values first.

## 11. Tags
`mo-algorithm`, `inversions`, `fenwick`, `teaching-lab`, `difficulty:hard`
