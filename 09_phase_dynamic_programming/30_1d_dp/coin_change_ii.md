# Coin Change II

## 1. Problem Statement
[LeetCode 518](https://leetcode.com/problems/coin-change-ii/) — number of **combinations** (order irrelevant) to make `amount` with unlimited coins.

- **Inputs:** `int amount`, `vector<int> coins`.
- **Output:** count of combinations.
- **Valid answer:** combinations, not permutations.
- **Edges:** `amount=0` → 1; empty coins with amount>0 → 0.

## 2. Intuition
Unbounded knapsack counting: outer loop over coins, inner over amounts so each combination is counted once.

## 3. Brute Force → Optimal
- **Brute:** recurse partitions — exponential / overcounts order.
- **Optimal:** 1D DP with coins outer — O(N · amount).

## 4. Data Structure / Approach Justification
**Chosen:** `dp[a]` = ways to make `a`; `dp[0]=1`.

- **vs amounts outer then coins:** counts permutations (wrong for this problem).
- **vs 2D DP:** clearer but O(N · amount) space.

## 5. Logic Walkthrough
For each coin `c`, for `a=c..amount`: `dp[a] += dp[a-c]`. Return `dp[amount]`.

## 6. Dry Run
`amount=5`, `coins=[1,2,5]`:
- after 1: all 1s; after 2: adds 2-coin mixes; after 5: `dp[5]=4` → `{5},{2,2,1},{2,1,1,1},{1×5}`

## 7. Time & Space Complexity
Time **O(N · amount)**. Space **O(amount)**. Why: one add per (coin, amount) (section 4).

## 8. Trade-offs & Alternatives
2D table aids debugging. Loop order is the critical correctness detail.

## 9. Common Mistakes / Edge Cases
Swapping loops (permutations); int overflow on large counts; `amount=0`.

## 10. Interview Follow-ups / Variations
Min coins (322); limited supply (bounded knapsack).

## 11. Tags
`1d-dp`, `combinations`, `unbounded-knapsack`, `leetcode-518`, `difficulty:medium`
