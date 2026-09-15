# Mo Range XOR

## 1. Problem Statement
Teaching-lab — range XOR via Mo add/remove (`x ^= a[i]` both ways).

**Pedagogy:** contests should use prefix XOR `pref[r]^pref[l-1]`. Included to show an O(1) removable aggregator and contrast with Mo-necessary problems (distinct/mex).

## 2. Intuition
XOR is its own inverse, so add and remove are identical.

## 3. Brute Force → Optimal
- **Optimal contest:** prefix XOR. Mo is pedagogical here.

## 4. Data Structure / Approach Justification
**Chosen:** Mo XOR window for symmetry with sum Mo.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Slide window XORing values in/out.

## 6. Dry Run
Full XOR 1..5 = 1; subranges match.

## 7. Time & Space Complexity
**O((N+Q)√N)** vs prefix **O(N+Q)**.

## 8. Trade-offs & Alternatives
Always prefer prefix for XOR/sum.

## 9. Common Mistakes / Edge Cases
Using Mo in a timed contest for XOR.

## 10. Interview Follow-ups / Variations
Sparse table for idempotent ops.

## 11. Tags
`mo-algorithm`, `xor`, `teaching-lab`, `difficulty:easy`
