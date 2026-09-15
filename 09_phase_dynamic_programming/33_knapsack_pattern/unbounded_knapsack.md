# Unbounded Knapsack

## Problem Statement
Classic unbounded knapsack — maximize value with capacity `W`; each item usable unlimited times. Teaching pattern (same as Coin Change / Complete Knapsack).

- **Inputs:** capacity `W`, weights `wt[]`, values `val[]`.
- **Output:** max value.
- **Valid answer:** optimal multiset of items.
- **Edges:** W=0; item heavier than W.

## Intuition
Ascending capacity loop reuses items (complete knapsack).

## Brute Force → Optimal
- **Brute:** recursion on remaining capacity — exponential.
- **Optimal:** 1D DP ascending O(N·W).

## Data Structure / Approach Justification
**Chosen:** `dp[w] = max(dp[w], dp[w-wt]+val)` with `w` ascending.

- **vs 0/1:** descending loop forbids reuse.

## Logic Walkthrough
For each item, for w=wt…W update take.

## Dry Run
val=[10,40,50,70], wt=[1,3,4,5], W=8 → **110**.

## Time & Space Complexity
Time **O(N·W)**. Space **O(W)**. Why: complete knapsack (section 4).

## Trade-offs & Alternatives
Coin Change is min-count unbounded; this is max-value.

## Common Mistakes / Edge Cases
Using descending loop; mixing with 0/1.

## Interview Follow-ups / Variations
Coin Change (322); Coin Change II (518).

## Tags
`knapsack`, `unbounded`, `classic`, `difficulty:medium`
