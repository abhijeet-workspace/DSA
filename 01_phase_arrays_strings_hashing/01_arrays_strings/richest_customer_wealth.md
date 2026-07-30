# Richest Customer Wealth

## Problem Statement
[LeetCode 1672](https://leetcode.com/problems/richest-customer-wealth/) — `accounts[i][j]` is money of customer `i` in bank `j`; return the maximum customer wealth (row sum).

- **Inputs:** `vector<vector<int>> accounts`.
- **Output:** max row sum.
- **Edges:** one customer; one bank; zeros.

## Intuition
Wealth of a customer is the sum of their row. Answer is the max over rows.

## Brute Force → Optimal
Must read every cell once — O(rows·cols) is optimal.

## Data Structure / Approach Justification
**Chosen:** nested loops / `accumulate` per row. No extra structure.

## Logic Walkthrough
For each row, sum cells; track `best = max(best, rowSum)`.

## Dry Run
`[[1,2,3],[3,2,1]]` → both wealth 6 → **6**.

## Time & Space Complexity
Time **O(M·N)**. Space **O(1)**.

## Trade-offs & Alternatives
None — linear scan of the matrix is required.

## Common Mistakes / Edge Cases
Initializing `best` to 0 when negative wealth is allowed (here non-negative per constraints).

## Interview Follow-ups / Variations
Column-wise max; k richest customers.

## Tags
`matrix`, `array`, `leetcode-1672`, `difficulty:easy`
