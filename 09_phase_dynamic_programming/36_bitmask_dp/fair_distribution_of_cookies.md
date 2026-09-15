# Fair Distribution of Cookies

## Problem Statement
[LeetCode 2305](https://leetcode.com/problems/fair-distribution-of-cookies/) — distribute bags to k children; minimize unfairness (max load).

- **Inputs:** `cookies`, `k`.
- **Output:** min max load.
- **Valid answer:** optimal assignment of bags.
- **Edges:** k=n; k=1.

## Intuition
DFS assign each bag to a child with pruning; or bitmask DP for small n.

## Brute Force → Optimal
- **Brute:** k^n.
- **Optimal:** backtracking prune / DP O(k*3^n).

## Data Structure / Approach Justification
**Chosen:** DFS with sorted bags + prune on current max.

## Logic Walkthrough
Try place bag i into each child bucket.

## Dry Run
[8,15,10,20,8], k=2 -> **31**.

## Time & Space Complexity
Time exponential with prune. Space **O(k)**.

## Trade-offs & Alternatives
Bitmask DP when n<=10.

## Common Mistakes / Edge Cases
Not pruning; wrong unfairness def.

## Interview Follow-ups / Variations
Partition problems.

## Tags
`bitmask-dp`, `backtracking`, `leetcode-2305`, `difficulty:medium`
