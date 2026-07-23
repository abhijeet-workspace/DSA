# Best Time to Buy and Sell Stock

## Problem Statement
[LeetCode 121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) — one buy and one sell; maximize profit (sell after buy). Return 0 if no profit.

- **Inputs:** `prices[i]` = stock price on day `i`.
- **Output:** max profit integer.
- **Valid answer:** sell day strictly after buy day; profit ≥ 0.
- **Edges:** strictly decreasing; length 1; all equal.

## Intuition
Track min price so far; at each day `profit = price - minSoFar`. Optimal buy for a sell day is the cheapest day before it.

## Brute Force → Optimal
- **Brute:** try every buy/sell pair — O(N²).
- **Optimal:** single-pass min-tracking — O(N).

## Data Structure / Approach Justification
**Chosen:** two scalars (`minPrice`, `best`) — no extra arrays.

- **vs Kadane on adjacent differences:** equivalent formulation; same asymptotics.
- **vs DP array of best-so-far:** wastes O(N) space for the same answer.

## Logic Walkthrough
Initialize `minPrice=INT_MAX`, `best=0`. For each `p`: update `minPrice`, then `best = max(best, p - minPrice)`.

## Dry Run
`[7,1,5,3,6,4]`: min=7 → day1 min=1 → day5 profit=4 → day6 profit=5 → answer **5**.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one forward scan with constant state (section 4).

## Trade-offs & Alternatives
One-pass is optimal. DP array versions waste space with no asymptotic gain.

## Common Mistakes / Edge Cases
Allowing sell before buy; updating min after profit incorrectly; returning negative profit.

## Interview Follow-ups / Variations
Unlimited transactions (122); cooldown (309); transaction fee (714).

## Tags
`array`, `greedy`, `one-pass`, `difficulty:easy`
