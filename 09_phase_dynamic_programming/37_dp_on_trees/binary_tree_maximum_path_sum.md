# Binary Tree Maximum Path Sum

## Problem Statement
[LeetCode 124](https://leetcode.com/problems/binary-tree-maximum-path-sum/) — max path sum of any node-to-node path (may not pass root).

- **Inputs:** `root` (values may be negative).
- **Output:** max path sum.
- **Valid answer:** best path.
- **Edges:** all negative -> max node.

## Intuition
DFS return max gain upward; update global with L+R+val.

## Brute Force → Optimal
- **Brute:** all paths.
- **Optimal:** O(N).

## Data Structure / Approach Justification
**Chosen:** gain = val + max(0, childGain).

## Logic Walkthrough
Global considers both children.

## Dry Run
Sample -> **42**.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**.

## Trade-offs & Alternatives
Must handle negatives with max(0,).

## Common Mistakes / Edge Cases
Forcing path through root only.

## Interview Follow-ups / Variations
Diameter style DP.

## Tags
`tree-dp`, `leetcode-124`, `difficulty:hard`
