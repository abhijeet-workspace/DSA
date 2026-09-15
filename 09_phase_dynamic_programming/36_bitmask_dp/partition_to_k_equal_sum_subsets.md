# Partition to K Equal Sum Subsets

## Problem Statement
[LeetCode 698](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) — can array be partitioned into `k` subsets with equal sum?

- **Inputs:** `nums`, `k`.
- **Output:** bool.
- **Valid answer:** disjoint subsets each summing to total/k.
- **Edges:** total % k ≠ 0; k=1; singles > target.

## Intuition
Backtracking with sorted pruning; or DP on bitmask when n≤16.

## Brute Force → Optimal
- **Brute:** assign each element to a bucket — exponential.
- **Optimal:** DFS + pruning; bitmask DP O(N·2^N) for small N.

## Data Structure / Approach Justification
**Chosen:** sort descending + DFS fill buckets (practical).

- **vs bitmask DP:** great when n≤16 (also bitmask folder).

## Logic Walkthrough
Target = total/k; try place each num into a subset under target; recurse.

## Dry Run
[4,3,2,3,5,2,1], k=4 → **true**.

## Time & Space Complexity
Time exponential with pruning; bitmask **O(N·2^N)**. Space **O(N)** DFS.

## Trade-offs & Alternatives
Bitmask DP cleaner for interviews with tiny n.

## Common Mistakes / Edge Cases
Not checking total%k; not sorting.

## Interview Follow-ups / Variations
Matchsticks to Square (473); Bitmask DP variants.

## Tags
`knapsack`, `backtracking`, `leetcode-698`, `difficulty:medium`
