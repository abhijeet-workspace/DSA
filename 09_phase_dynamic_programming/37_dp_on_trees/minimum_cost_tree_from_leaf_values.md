# Minimum Cost Tree From Leaf Values

## Problem Statement
[LeetCode 1130](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) — build full binary tree from leaf array order; non-leaf = product of max leaves in children; min sum of non-leaves.

- **Inputs:** `arr` leaf values in order.
- **Output:** min cost sum.
- **Valid answer:** interval DP / mono stack.
- **Edges:** n=2.

## Intuition
Interval DP dp[i][j] min cost; or greedy stack.

## Brute Force → Optimal
- **Brute:** all BST-like structures.
- **Optimal:** O(N^3) DP or O(N) stack.

## Data Structure / Approach Justification
**Chosen:** interval DP with max table.

## Logic Walkthrough
dp[i][j] = min over k of dp[i][k]+dp[k+1][j]+maxL*maxR.

## Dry Run
[6,2,4] -> **32**.

## Time & Space Complexity
Time **O(N^3)**. Space **O(N^2)**.

## Trade-offs & Alternatives
Stack solution is interview follow-up.

## Common Mistakes / Edge Cases
Wrong max range.

## Interview Follow-ups / Variations
Burst Balloons interval DP.

## Tags
`tree-dp`, `interval-dp`, `leetcode-1130`, `difficulty:medium`
