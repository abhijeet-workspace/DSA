# Mo's Range Distinct

## Problem Statement
Given array `a[0..N)` and offline queries `(L,R)`, count how many distinct values appear in `a[L..R]` (inclusive).

- **Inputs:** integer array, list of inclusive ranges known upfront.
- **Output:** distinct count per query, restored to original order via `idx`.
- **Valid answer:** number of unique values in the closed interval.
- **Edges:** `N=1`; `L=R`; all equal; all unique; `Q=0`.

## Intuition
Maintain frequencies in the current window. Distinct increases on freq `0→1` and decreases on `1→0`. Mo's block-sort bounds total pointer movement to ~`O(N√N)`.

## Brute Force → Optimal
- **Brute:** per query scan with a set/map — `O(Q·N)`.
- **Optimal:** Mo with `O(1)` add/remove on a freq table — `O((N+Q)√N)`.

## Data Structure / Approach Justification
**Chosen:** `freq[value]` + `distinct` counter under Mo ordering.

- **vs segtree of sets:** heavier constants / memory.
- **vs wavelet / merge-sort tree:** online capable but more complex.

## Logic Walkthrough
Block-sort queries. Expand/shrink `[curL,curR]` with add/remove. After alignment, `answers[idx] = distinct`.

## Dry Run
`a=[1,2,1,3,2]`:
- `(0,4)→3`, `(1,2)→2`, `(2,4)→3`, `(0,0)→1`.

## Time & Space Complexity
Time **O((N+Q)√N)** with `O(1)` add/remove. Space **O(N+Q+V)** for freq. Why: sorted order bounds total moves (section 4).

## Trade-offs & Alternatives
Mo needs offline queries. Fenwick/seg for sums is better when the aggregator is prefix-friendly; distinct needs this machinery (or heavier trees).

## Common Mistakes / Edge Cases
Forgetting to restore freq on remove; off-by-one on `L`/`R`; wrong block comparator; values needing compression if sparse/large.

## Interview Follow-ups / Variations
Odd-block `R` reversal benefit? Handle updates (time as 3rd dimension)? Hilbert-order Mo?

## Tags
`mo-algorithm`, `distinct-count`, `offline-queries`, `frequency`, `difficulty:medium`
