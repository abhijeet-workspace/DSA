# Longest ZigZag Path in a Binary Tree

## Problem Statement
[LeetCode 1372](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/) — longest zigzag path (alternating left/right) in edges.

- **Inputs:** `root`.
- **Output:** max zigzag length.
- **Valid answer:** max alternating direction path.
- **Edges:** single node -> 0.

## Intuition
DFS returns best zigzag ending going left/right from node.

## Brute Force → Optimal
- **Brute:** all paths.
- **Optimal:** O(N).

## Data Structure / Approach Justification
**Chosen:** dfs returns {leftZig, rightZig}; update global.

## Logic Walkthrough
To go left child: 1 + child.rightZig.

## Dry Run
Sample -> **3**.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**.

## Trade-offs & Alternatives
Direction must alternate.

## Common Mistakes / Edge Cases
Restarting zig incorrectly.

## Interview Follow-ups / Variations
Longest Univalue Path.

## Tags
`tree-dp`, `leetcode-1372`, `difficulty:medium`
