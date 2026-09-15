# Mo Add/Remove Parity

## 1. Problem Statement
Teaching problem (Mo pattern) — count how many values have **odd** frequency in `a[L..R]`.

- Demonstrates O(1) add/remove flipping a parity counter.

## 2. Intuition
Each add toggles that value's contribution to the odd-count.

## 3. Brute Force → Optimal
- Brute maps. Mo O(1) toggle.

## 4. Data Structure / Approach Justification
**Chosen:** Mo + freq parity flips.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
On add: if was even → oddCount++; else --. Increment freq. Remove inverse.

## 6. Dry Run
Matches brute on sample.

## 7. Time & Space Complexity
**O((N+Q)√N)**.

## 8. Trade-offs & Alternatives
XOR-of-all-elements is different (doesn't need Mo).

## 9. Common Mistakes / Edge Cases
Wrong toggle order relative to ++/-- freq.

## 10. Interview Follow-ups / Variations
Count even frequencies; xor-hash of set.

## 11. Tags
`mo-algorithm`, `parity`, `teaching-lab`, `difficulty:easy`
