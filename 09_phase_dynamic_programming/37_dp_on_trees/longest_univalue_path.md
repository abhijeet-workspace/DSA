# Longest Univalue Path

## Problem Statement
[LeetCode 687](https://leetcode.com/problems/longest-univalue-path/) — longest path (edges) where all nodes have same value.

- **Inputs:** `root`.
- **Output:** edge length.
- **Valid answer:** max univalue arrow path.
- **Edges:** all distinct; all same.

## Intuition
DFS: length of univalue arrow down; combine both sides if equal val.

## Brute Force → Optimal
- **Brute:** all paths.
- **Optimal:** O(N).

## Data Structure / Approach Justification
**Chosen:** leftLen/rightLen only if child.val==node.val.

## Logic Walkthrough
Update ans with leftLen+rightLen.

## Dry Run
Sample -> **2**.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**.

## Trade-offs & Alternatives
Path need not pass root.

## Common Mistakes / Edge Cases
Counting nodes not edges.

## Interview Follow-ups / Variations
Diameter; Longest ZigZag.

## Tags
`tree-dp`, `leetcode-687`, `difficulty:medium`
