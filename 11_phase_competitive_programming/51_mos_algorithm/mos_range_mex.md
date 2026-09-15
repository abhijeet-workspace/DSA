# Mo's Range MEX

## 1. Problem Statement
Teaching problem (Mo pattern) — MEX (smallest missing non-negative) on offline ranges; values in a small `0..K`.

- **Edges:** full set present → mex=K+1; empty not queried.

## 2. Intuition
Maintain counts of each small value; mex rises on fill and drops when a smaller value hits 0.

## 3. Brute Force → Optimal
- **Brute:** per query scan. **Mo:** O(1) add/remove with care on mex pointer.

## 4. Data Structure / Approach Justification
**Chosen:** Mo + freq[0..K] + mex cursor.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Add increments; while freq[mex]>0 bump. Remove may set mex down to v.

## 6. Dry Run
Verified against brute on sample queries.

## 7. Time & Space Complexity
**O((N+Q)√N)** with O(1) add/remove.

## 8. Trade-offs & Alternatives
Large values need compression or segtree-of-missing.

## 9. Common Mistakes / Edge Cases
Updating mex only upward; missing the drop on remove.

## 10. Interview Follow-ups / Variations
Online MEX with segtree?

## 11. Tags
`mo-algorithm`, `mex`, `teaching-lab`, `difficulty:medium`
