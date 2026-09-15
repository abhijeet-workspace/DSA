# Mo Sum of Distinct

## 1. Problem Statement
Teaching problem (Mo pattern) — sum of **unique** values in `a[L..R]` (each value once).

Related spirit to SPOJ DQUERY (distinct count) — here we sum the distinct keys.

## 2. Intuition
On 0→1 add value to sum; on 1→0 subtract.

## 3. Brute Force → Optimal
- Brute set sum. Mo O(1).

## 4. Data Structure / Approach Justification
**Chosen:** Mo freq + running sumDist.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Same pointer moves as distinct Mo; maintain sum instead of count.

## 6. Dry Run
`[0,4]→6`, `[1,2]→3`, etc.

## 7. Time & Space Complexity
**O((N+Q)√N)**.

## 8. Trade-offs & Alternatives
vs distinct count (already in folder).

## 9. Common Mistakes / Edge Cases
Adding value every time instead of only 0→1.

## 10. Interview Follow-ups / Variations
Weighted distinct?

## 11. Tags
`mo-algorithm`, `distinct`, `teaching-lab`, `difficulty:medium`
