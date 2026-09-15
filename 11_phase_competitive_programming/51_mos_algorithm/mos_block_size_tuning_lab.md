# Mo Block Size Tuning Lab

## 1. Problem Statement
Teaching-lab — compare Mo pointer **move counts** for block sizes `1`, `√N`, and `N` on synthetic queries.

- Illustrates why `B≈√N` balances L-block changes vs R movement.

## 2. Intuition
Cost ≈ (N/B)·N + Q·B style; minimize near √N.

## 3. Brute Force → Optimal
- Theory suggests √N; practice may use N/√Q.

## 4. Data Structure / Approach Justification
**Chosen:** count |ΔL|+|ΔR| under different B.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Generate queries; sort with each B; sum pointer travel.

## 6. Dry Run
Expect √N moves ≤ extreme B=1 and B=N on this set.

## 7. Time & Space Complexity
Lab only — not a problem statement.

## 8. Trade-offs & Alternatives
Hilbert order can beat tuned block sort.

## 9. Common Mistakes / Edge Cases
Using wall-clock without fixed seed.

## 10. Interview Follow-ups / Variations
Auto-tune B from Q.

## 11. Tags
`mo-algorithm`, `tuning`, `teaching-lab`, `difficulty:easy`
