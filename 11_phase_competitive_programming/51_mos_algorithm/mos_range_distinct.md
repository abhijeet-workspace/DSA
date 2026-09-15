# Mo's Range Distinct

## 1. Problem Statement
Given array `a[0..N)` and offline queries `(L,R)`, count how many distinct values appear in `a[L..R]` (inclusive).

- **Inputs:** integer array, list of inclusive ranges known upfront.
- **Output:** distinct count per query, restored to original order via `idx`.
- **Valid answer:** number of unique values in the closed interval.
- **Edges:** `N=1`; `L=R`; all equal; all unique; `Q=0`.

## 2. Intuition
Maintain frequencies in the current window. Distinct increases on freq `0→1` and decreases on `1→0`. Mo's block-sort bounds total pointer movement to ~`O(N√N)`.

## 3. Brute Force → Optimal
- **Brute:** per query scan with a set/map — `O(Q·N)`.
- **Optimal:** Mo with `O(1)` add/remove on a freq table — `O((N+Q)√N)`.

## 4. Data Structure / Approach Justification

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows).
Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(
polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

**Chosen:** `freq[value]` + `distinct` counter under Mo ordering.

- **vs segtree of sets:** heavier constants / memory.
- **vs wavelet / merge-sort tree:** online capable but more complex.

## 5. Logic Walkthrough
Block-sort queries. Expand/shrink `[curL,curR]` with add/remove. After alignment, `answers[idx] = distinct`.

## 6. Dry Run
`a=[1,2,1,3,2]`:
- `(0,4)→3`, `(1,2)→2`, `(2,4)→3`, `(0,0)→1`.

## 7. Time & Space Complexity
Time **O((N+Q)√N)** with `O(1)` add/remove. Space **O(N+Q+V)** for freq. Why: sorted order bounds total moves (section 4).

## 8. Trade-offs & Alternatives
Mo needs offline queries. Fenwick/seg for sums is better when the aggregator is prefix-friendly; distinct needs this machinery (or heavier trees).

## 9. Common Mistakes / Edge Cases
Forgetting to restore freq on remove; off-by-one on `L`/`R`; wrong block comparator; values needing compression if sparse/large.

## 10. Interview Follow-ups / Variations
Odd-block `R` reversal benefit? Handle updates (time as 3rd dimension)? Hilbert-order Mo?

## 11. Tags
`mo-algorithm`, `distinct-count`, `offline-queries`, `frequency`, `difficulty:medium`
