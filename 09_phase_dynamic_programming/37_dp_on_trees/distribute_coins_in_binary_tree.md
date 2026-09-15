# Distribute Coins in Binary Tree

## Problem Statement
[LeetCode 979](https://leetcode.com/problems/distribute-coins-in-binary-tree/) — move coins along edges so each node has 1; min moves.

- **Inputs:** `root` with coin counts.
- **Output:** min moves.
- **Valid answer:** total |excess| flowing over edges.
- **Edges:** already balanced; all coins at one node.

## Intuition
Excess = val-1 + left_excess + right_excess; moves += |child excess|.

## Brute Force → Optimal
- **Brute:** simulate moves.
- **Optimal:** O(N) DFS.

## Data Structure / Approach Justification
**Chosen:** post-order excess return.

## Logic Walkthrough
moves accumulate abs(left)+abs(right).

## Dry Run
[3,0,0] -> **2**.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**.

## Trade-offs & Alternatives
Excess can be negative (deficit).

## Common Mistakes / Edge Cases
Forgetting val-1.

## Interview Follow-ups / Variations
Tree DP flow.

## Tags
`tree-dp`, `leetcode-979`, `difficulty:medium`
