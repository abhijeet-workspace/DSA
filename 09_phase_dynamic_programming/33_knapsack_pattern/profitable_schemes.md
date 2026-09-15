# Profitable Schemes

## Problem Statement
[LeetCode 879](https://leetcode.com/problems/profitable-schemes/) — count subsets of crimes with ≤ `n` members and profit ≥ `minProfit` (mod 1e9+7).

- **Inputs:** `n`, `minProfit`, `group[]`, `profit[]`.
- **Output:** number of schemes.
- **Valid answer:** each crime 0/1; members sum ≤ n; profit sum ≥ minProfit.
- **Edges:** minProfit=0 (empty counts); n small.

## Intuition
3D 0/1 knapsack: dp[people][profit] ways; cap profit at minProfit.

## Brute Force → Optimal
- **Brute:** subsets — exponential.
- **Optimal:** DP O(#crimes · n · minProfit).

## Data Structure / Approach Justification
**Chosen:** rolling `dp[j][p]` ways with j members and capped profit p.

- **vs unbounded:** each crime once.

## Logic Walkthrough
For each crime, descending update members/profit.

## Dry Run
n=5, minProfit=3, group=[2,2], profit=[2,3] → **2**.

## Time & Space Complexity
Time **O(K·n·P)**. Space **O(n·P)**. Why: 0/1 knapsack (section 4).

## Trade-offs & Alternatives
Cap profit dimension at minProfit to shrink state.

## Common Mistakes / Edge Cases
Not capping profit; ascending reuse; forgetting empty scheme when minProfit=0.

## Interview Follow-ups / Variations
Ones and Zeroes (474); knapsack counting.

## Tags
`knapsack`, `counting-dp`, `leetcode-879`, `difficulty:hard`
