# Mo's Range Mode

## 1. Problem Statement
Teaching problem (Mo pattern) — offline queries for the **mode** (most frequent value) in `a[L..R]`. Ties → smallest value.

- **Inputs:** array with small alphabet, offline ranges.
- **Output:** mode per query.
- **Edges:** all unique; all equal; single element.

## 2. Intuition
Track frequencies and frequency-of-frequencies; Mo slides the window.

## 3. Brute Force → Optimal
- **Brute:** count per query O(Q·N).
- **Optimal:** Mo + freq tables ~O((N+Q)√N · α).

## 4. Data Structure / Approach Justification
**Chosen:** Mo with `freq` / `freqOfFreq` and mode repair on remove.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Block-sort; add/remove update freq tables; on remove, rescan alphabet if max freq drops (OK for small V).

## 6. Dry Run
`a=[1,2,2,1,3,2]`; answers match brute modes.

## 7. Time & Space Complexity
Time **O((N+Q)√N + Q·V_small)** worst on mode repair. Space **O(N+V)**.

## 8. Trade-offs & Alternatives
For large alphabets use Mo + segment tree of freqs, or Hilbert order.

## 9. Common Mistakes / Edge Cases
Broken tie-break; forgetting freqOfFreq when removing.

## 10. Interview Follow-ups / Variations
Range majority (≥n/2)?; online mode?

## 11. Tags
`mo-algorithm`, `mode`, `frequency`, `teaching-lab`, `difficulty:hard`
