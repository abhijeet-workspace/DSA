# Mo Hilbert Order Demo

## 1. Problem Statement
Teaching-lab — same distinct-count Mo answers, but queries sorted by a **Hilbert curve** key instead of blocks.

- Often reduces constants vs odd-even block sort on random queries.

## 2. Intuition
Hilbert locality keeps consecutive queries geometrically close in (L,R) space.

## 3. Brute Force → Optimal
- Block sort: classic. Hilbert: often faster in practice.

## 4. Data Structure / Approach Justification
**Chosen:** Hilbert order + standard distinct Mo add/remove.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Assign hilbert(L,R); sort; slide window as usual.

## 6. Dry Run
Distinct answers `3 2 3 1` match block Mo.

## 7. Time & Space Complexity
Same asymptotics; better locality constants.

## 8. Trade-offs & Alternatives
Block Mo simpler to code in contests under time pressure.

## 9. Common Mistakes / Edge Cases
Broken Hilbert transform → wrong order still correct answers but slower.

## 10. Interview Follow-ups / Variations
Time Mo (with updates) also benefits from good orders.

## 11. Tags
`mo-algorithm`, `hilbert`, `teaching-lab`, `difficulty:medium`
