# Online Stock Span

## 1. Problem Statement
[LeetCode 901](https://leetcode.com/problems/online-stock-span/) — online: on each day's `price`, return the **span** = consecutive days ending today with price ≤ today's price.

- **Inputs:** stream of `next(price)` calls.
- **Output:** integer span per call.
- **Edges:** strictly decreasing (all spans 1); strictly increasing (spans 1,2,3,…); plateaus (`<=` counts).

## 2. Intuition
Previous days with smaller-or-equal price can never restart a larger future span past today. Collapse them into today's span on a monotonic decreasing stack of `{price, span}`.

## 3. Brute Force → Optimal
- **Brute:** store all prices; scan left until a greater price — O(N) per query, O(N²) total.
- **Optimal:** amortized O(1) per `next` via monotonic stack.

## 4. Data Structure / Approach Justification
**Chosen:** stack of pairs `{price, span}` in strictly decreasing price order.

| Alternative | Why it loses here |
|-------------|-------------------|
| Full price history + scan | Quadratic online cost |
| Segment tree / sparse table | Overkill for consecutive left span |

## 5. Logic Walkthrough
1. `span = 1`.
2. While top price `<= price`, add top's span and pop.
3. Push `{price, span}`; return `span`.

## 6. Dry Run
Prices `100,80,60,70,60,75,85`:
- `70` absorbs `60` → span `2`; `75` absorbs `60,70,60` → `4`; `85` absorbs `75,80` → `6`.

## 7. Time & Space Complexity
- **Time:** O(1) amortized per `next` (each day pushed/popped ≤ once).
- **Space:** O(N) worst case (strictly decreasing stream).

## 8. Trade-offs & Alternatives
Storing indices and computing `i - prev_greater_index` is equivalent. Offline version is the classic previous-greater problem.

## 9. Common Mistakes / Edge Cases
Using `<` instead of `<=` (equal prices must count); forgetting to accumulate popped spans; resetting span incorrectly after pops.

## 10. Interview Follow-ups / Variations
Daily temperatures (forward next-greater); previous greater element; design with getMin span queries.

## 11. Tags
`stack`, `monotonic-stack`, `design`, `leetcode-901`, `difficulty:medium`
