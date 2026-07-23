# 0/1 Knapsack

## Problem Statement
Classic 0/1 knapsack — maximize value with capacity `W`; each item taken at most once.

- **Inputs:** capacity `W`, weights `wt[]`, values `val[]`.
- **Output:** max achievable value ≤ `W`.
- **Valid answer:** optimal among all 0/1 selections.
- **Edges:** `W=0`; item heavier than `W`; all items fit; empty lists.

## Intuition
For each capacity, decide take or skip the current item. Descending weight loop reuses one array without reusing an item.

## Brute Force → Optimal
- **Brute:** all subsets — O(2^N).
- **Optimal:** DP `dp[w] = max(dp[w], dp[w-wt]+val)` descending — O(N · W), space O(W).

## Data Structure / Approach Justification
**Chosen:** 1D `vector<int> dp(W+1)`.

- **vs 2D `dp[i][w]`:** clearer transitions, O(N·W) memory.
- **Ascending loop:** unbounded knapsack (item reused) — wrong for 0/1.
- **vs fractional knapsack:** greedy by density; not valid when items are atomic.

## Logic Walkthrough
Init `dp` to 0. For each item `i`, for `w = W … wt[i]`: update with take. Return `dp[W]`.

## Dry Run
`val={60,100,120}`, `wt={10,20,30}`, `W=50`:
- items 20+30 → value 100+120 = **220** (optimal).

## Time & Space Complexity
Time **O(N · W)**. Space **O(W)**. Why: N items × W capacities (section 4).

## Trade-offs & Alternatives
Pseudo-polynomial in W — fine when W is moderate. Meet-in-the-middle for large W / small N.

## Common Mistakes / Edge Cases
Ascending weight loop; off-by-one on `W+1`; mixing 0/1 with unbounded rules.

## Interview Follow-ups / Variations
Unbounded / complete knapsack; bounded (count limits); Partition Equal Subset Sum (416).

## Tags
`dp`, `0-1-knapsack`, `classic`, `difficulty:medium`
