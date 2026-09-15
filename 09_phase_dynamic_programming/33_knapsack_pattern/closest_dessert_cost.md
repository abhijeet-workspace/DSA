# Closest Dessert Cost

## Problem Statement
[LeetCode 1774](https://leetcode.com/problems/closest-dessert-cost/) — one base + each topping 0/1/2 times; cost closest to `target` (ties → lower cost).

- **Inputs:** `baseCosts`, `toppingCosts`, `target`.
- **Output:** closest dessert cost.
- **Valid answer:** min |cost-target|, tie → smaller cost.
- **Edges:** base alone; overshoot.

## Intuition
DFS/backtracking over toppings with pruning; try each base.

## Brute Force → Optimal
- **Brute:** 3^T per base.
- **Optimal:** backtracking (T≤10) / precompute topping sums.

## Data Structure / Approach Justification
**Chosen:** DFS on toppings updating global best; try each base.

- **vs full knapsack of all combos:** fine for T≤10.

## Logic Walkthrough
Recurse topping index with count 0..2; update answer by closeness rule.

## Dry Run
base=[1,7], topping=[3,4], target=10 → **10**.

## Time & Space Complexity
Time **O(B·3^T)**. Space **O(T)**. Why: small T (section 4).

## Trade-offs & Alternatives
Precompute all topping sums then binary search per base.

## Common Mistakes / Edge Cases
Allowing >2 of a topping; wrong tie-break.

## Interview Follow-ups / Variations
Minimize difference (1981); bounded knapsack.

## Tags
`knapsack`, `backtracking`, `leetcode-1774`, `difficulty:medium`
