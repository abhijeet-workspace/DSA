# Last Stone Weight II

## Problem Statement
[LeetCode 1049](https://leetcode.com/problems/last-stone-weight-ii/) — smash two stones; replace with difference; minimize final stone (or 0).

- **Inputs:** `stones` weights.
- **Output:** min possible last stone.
- **Valid answer:** partition into two piles minimizing |2*S1 - total|.
- **Edges:** one stone; equal partition possible.

## Intuition
Equivalent to subset-sum closest to total/2 (0/1 knapsack).

## Brute Force → Optimal
- **Brute:** all smash orders — exponential.
- **Optimal:** boolean knapsack to target total/2.

## Data Structure / Approach Justification
**Chosen:** `dp[w]` reachable sum ≤ target.

- **vs priority queue simulation:** greedy smash ≠ optimal for II.

## Logic Walkthrough
Fill reachable sums; best = total - 2*closest.

## Dry Run
[2,7,4,1,8,1] → **1**.

## Time & Space Complexity
Time **O(N·Σ)**. Space **O(Σ)**. Why: subset sum DP (section 4).

## Trade-offs & Alternatives
Same as minimum subset sum difference teaching problem.

## Common Mistakes / Edge Cases
Using LC 1046 greedy for this problem.

## Interview Follow-ups / Variations
Partition Equal Subset Sum (416); Target Sum (494).

## Tags
`knapsack`, `subset-sum`, `leetcode-1049`, `difficulty:medium`
