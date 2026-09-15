# Ones and Zeroes

## Problem Statement
[LeetCode 474](https://leetcode.com/problems/ones-and-zeroes/) — max number of strings from `strs` formable with at most `m` zeros and `n` ones (each string ≤1).

- **Inputs:** `strs`, `m`, `n`.
- **Output:** max subset size.
- **Valid answer:** 0/1 knapsack with 2D capacity (zeros, ones).
- **Edges:** empty strs; m=n=0.

## Intuition
2D 0/1 knapsack: capacities are counts of 0 and 1.

## Brute Force → Optimal
- **Brute:** subsets — exponential.
- **Optimal:** DP descending over (zeros,ones) O(|S|·m·n).

## Data Structure / Approach Justification
**Chosen:** `dp[i][j]` = max strings with ≤i zeros and ≤j ones.

- **vs greedy shortest strings:** suboptimal.

## Logic Walkthrough
Count 0/1 per string; update dp descending.

## Dry Run
strs=[10,0001,111001,1,0], m=5, n=3 → **4**.

## Time & Space Complexity
Time **O(|S|·m·n)**. Space **O(m·n)**. Why: classic 0/1 (section 4).

## Trade-offs & Alternatives
Same pattern as multi-dimensional weight knapsack.

## Common Mistakes / Edge Cases
Ascending loops (reuse); miscounting bits.

## Interview Follow-ups / Variations
Last Stone Weight II; Profit Schemes.

## Tags
`knapsack`, `0-1-knapsack`, `leetcode-474`, `difficulty:medium`
