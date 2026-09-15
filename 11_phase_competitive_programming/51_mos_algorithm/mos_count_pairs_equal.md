# Mo Count Pairs Equal

## 1. Problem Statement
Teaching problem (Mo pattern) — count unordered pairs with equal values inside `[L,R]`.

- add: `pairs += freq[v]` then `++freq[v]`. remove: inverse.

## 2. Intuition
New element pairs with each existing equal occurrence.

## 3. Brute Force → Optimal
- Brute O(len²). Mo O(1) add/remove.

## 4. Data Structure / Approach Justification
**Chosen:** Mo frequency pair counter.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Maintain freq and pairs through Mo moves.

## 6. Dry Run
Matches brute.

## 7. Time & Space Complexity
**O((N+Q)√N)**.

## 8. Trade-offs & Alternatives
Can use (freq choose 2) sum if rebuilding; Mo keeps incremental.

## 9. Common Mistakes / Edge Cases
Wrong order of ++freq vs pairs+=.

## 10. Interview Follow-ups / Variations
Count pairs with difference K?

## 11. Tags
`mo-algorithm`, `pairs`, `teaching-lab`, `difficulty:medium`
