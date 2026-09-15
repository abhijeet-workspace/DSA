# Minimum Subset Sum Difference

## Problem Statement
Teaching partition problem — split array into two subsets minimizing |sum(S1)-sum(S2)|. Same core as Last Stone Weight II (1049).

- **Inputs:** `nums`.
- **Output:** minimum difference.
- **Valid answer:** total - 2*closest_subset_to_total/2.
- **Edges:** one element; already balanced.

## Intuition
0/1 subset-sum reachability up to total/2.

## Brute Force → Optimal
- **Brute:** all partitions.
- **Optimal:** boolean knapsack O(N·Σ).

## Data Structure / Approach Justification
**Chosen:** `dp[w]` reachable; scan down from total/2.

- **vs meet-in-the-middle:** when Σ huge and N small.

## Logic Walkthrough
Fill reachable; return total-2*best.

## Dry Run
[1,6,11,5] → **1**.

## Time & Space Complexity
Time **O(N·Σ)**. Space **O(Σ)**. Why: subset sum (section 4).

## Trade-offs & Alternatives
Identical engine to LC 1049.

## Common Mistakes / Edge Cases
Returning total/2 directly; int overflow on sum.

## Interview Follow-ups / Variations
Last Stone Weight II (1049); Partition Equal (416).

## Tags
`knapsack`, `subset-sum`, `classic`, `difficulty:medium`
