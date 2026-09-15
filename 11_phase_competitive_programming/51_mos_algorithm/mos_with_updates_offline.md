# Mo With Updates Offline

## 1. Problem Statement
Teaching-lab — **time Mo** (3D Mo): offline range distinct with point updates.

- Each query carries `t` = #updates already applied. Sort by time-block then (L,R).

## 2. Intuition
Treat time as a third pointer; apply/revert updates when moving `curT`.

## 3. Brute Force → Optimal
- Rebuild array per query. **Time Mo** ~ O(N^{5/3}) with cube-root blocks.

## 4. Data Structure / Approach Justification
**Chosen:** simplified time Mo for distinct.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
Move time, then L/R; when updating an index inside the window, adjust freqs.

## 6. Dry Run
Sample: before/after a[1]=5 distinct answers match brute timelines.

## 7. Time & Space Complexity
Roughly **O(N^{5/3})** with cube-root block (teaching).

## 8. Trade-offs & Alternatives
Persistent segtree / CDQ for some update+query problems.

## 9. Common Mistakes / Edge Cases
Forgetting to revert updates; updating freq when pos outside window.

## 10. Interview Follow-ups / Variations
Hilbert in 3D; Mo on trees with updates.

## 11. Tags
`mo-algorithm`, `updates`, `time-mo`, `teaching-lab`, `difficulty:hard`
