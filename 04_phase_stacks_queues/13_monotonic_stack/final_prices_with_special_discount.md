# Final Prices With a Special Discount in a Shop

## 1. Problem Statement
[LeetCode 1475](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/) — for each item, discount is the first price to the right that is ≤ current; pay `price - discount` (no discount → full price).

- **Inputs:** `vector<int> prices`.
- **Output:** final prices after discounts.
- **Edges:** strictly increasing (no discounts); all equal; single item.

## 2. Intuition
Classic **next smaller-or-equal** via a monotonic increasing stack of indices. When a cheap enough later price appears, it discounts all waiting larger-or-equal tops.

## 3. Brute Force → Optimal
- **Brute:** for each `i`, scan right for first `<=` — O(N²).
- **Optimal:** monotonic stack — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** increasing stack of indices; mutate a copy of `prices` in place for the answer.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested right scan | Quadratic |
| Next-greater stack | Wrong relation (need smaller-or-equal) |

## 5. Logic Walkthrough
1. For each index `i`, while `prices[top] >= prices[i]`, apply discount `prices[top] -= prices[i]` and pop.
2. Push `i`. Unresolved indices keep original prices.

## 6. Dry Run
`[8,4,6,2,3]`:
- `4` discounts `8` → `4`; `2` discounts `6` then `4` → `4,2`; result `4 2 4 2 3`.

## 7. Time & Space Complexity
- **Time:** O(N).
- **Space:** O(N) stack.

## 8. Trade-offs & Alternatives
Separate answer array avoids mutating input. Strict `<` would be next strictly smaller (different problem).

## 9. Common Mistakes / Edge Cases
Using `>` instead of `>=`; applying discount more than once; confusing with next greater / daily temperatures.

## 10. Interview Follow-ups / Variations
Daily temperatures (next greater distance); next greater element; stock span (previous ≤).

## 11. Tags
`stack`, `monotonic-stack`, `next-smaller`, `leetcode-1475`, `difficulty:easy`
