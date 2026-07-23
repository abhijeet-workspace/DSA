# Mo's Range Sum

## Problem Statement
Offline range-sum queries on a static array via Mo's algorithm (teaching example; prefer prefix/Fenwick in practice).

- **Inputs:** array `a[0..N)`, queries `(L, R)` inclusive, all known upfront.
- **Output:** for each query, `sum(a[L..R])` in original query order.
- **Valid answer:** exact arithmetic sum of the inclusive range.
- **Edges:** single-element ranges; negatives; large `Q`; empty array avoided.

## Intuition
Maintain a sliding window sum. Mo's sorts queries into blocks so total `L`/`R` movement is about `O((N+Q)√N)`. Add/remove endpoints update the sum in `O(1)`.

## Brute Force → Optimal
- **Brute:** scan each range — `O(Q·N)`.
- **Optimal (Mo):** block-sort + window sum — `O((N+Q)√N)`. Prefer prefix sums `O(N+Q)` for static sum in production.

## Data Structure / Approach Justification
**Chosen:** Mo window with odd-block `R` reversal to cut pointer travel.

- **vs prefix sums:** prefix is strictly better for static sum.
- **vs Fenwick:** Fenwick wins when updates exist; Mo shines for non-prefixable aggregators (distinct, mode).

## Logic Walkthrough
Sort by `(L/B, R)` (zigzag `R` on odd blocks). Start with empty window `[0,-1]`. Expand/shrink with add/remove until `[curL,curR] == [L,R]`; store `sum` at `query.idx`.

## Dry Run
`a=[1,2,3,4,5]`, query `(1,3)`:
- expand to include indices `0..3`, then remove `0` → window sum `2+3+4=9`.

## Time & Space Complexity
Time **O((N+Q)√N)**. Space **O(N+Q)**. Why: block ordering bounds total endpoint moves (section 4).

## Trade-offs & Alternatives
Mo teaches the pattern but is worse than prefix for pure sums. Use Mo when the aggregator is not easily prefixable.

## Common Mistakes / Edge Cases
Using Mo for sums in interviews without noting prefix/Fenwick; off-by-one on `L`/`R`; wrong block comparator.

## Interview Follow-ups / Variations
When is Mo preferable to a segment tree? How do you choose block size `B`?

## Tags
`mo-algorithm`, `offline-queries`, `range-sum`, `sqrt-decomposition`, `difficulty:medium`
