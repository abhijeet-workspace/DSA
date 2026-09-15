# Best Time to Buy and Sell Stock with Cooldown

## 1. Problem Statement
[LeetCode 309](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) — max profit with one share; after selling, one cooldown day before next buy.

- **Inputs:** `vector<int> prices`.
- **Output:** max profit (0 if no transaction).
- **Valid answer:** optimal sequence of buy/sell with cooldown.
- **Edges:** length 1; strictly decreasing; buy-sell-cooldown-buy.

## 2. Intuition
Machine with states: `hold` (own share), `sold` (sold today), `rest` (idle / cooldown finished). Transitions encode cooldown.

## 3. Brute Force → Optimal
- **Brute:** try all buy/sell day pairs with cooldown — exponential / high poly.
- **Optimal:** O(N) state DP with three rolling vars.

## 4. Data Structure / Approach Justification
**Chosen:** three ints updated per day (need `prev_sold` temporary).

- **vs full day×state table:** same logic, O(N) space.
- **vs no-cooldown stock DP:** fewer states; cooldown adds the `rest` lag.

## 5. Logic Walkthrough
Each price: `sold = hold + p`; `hold = max(hold, rest - p)`; `rest = max(rest, prev_sold)`. Answer `max(sold, rest)`.

## 6. Dry Run
`[1,2,3,0,2]`:
- path buy@1, sell@2, cooldown@3, buy@0, sell@2 → profit 3

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: constant states per day (section 4).

## 8. Trade-offs & Alternatives
Table DP aids debugging transitions. Careful with update order (need previous sold).

## 9. Common Mistakes / Edge Cases
Buying on the day after sell; initializing `hold` to 0 instead of −∞; empty prices.

## 10. Interview Follow-ups / Variations
Fee instead of cooldown (714); at most k transactions (188).

## 11. Tags
`1d-dp`, `state-machine`, `stock`, `leetcode-309`, `difficulty:medium`
