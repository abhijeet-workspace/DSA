# Diameter of Binary Tree

## Problem Statement
[LeetCode 543](https://leetcode.com/problems/diameter-of-binary-tree/) — length of longest path (edges) between any two nodes.

- **Inputs:** `root`.
- **Output:** diameter in edges.
- **Valid answer:** max Lheight+Rheight over nodes.
- **Edges:** single node -> 0.

## Intuition
DFS height; update diameter with L+R.

## Brute Force → Optimal
- **Brute:** all pairs.
- **Optimal:** O(N).

## Data Structure / Approach Justification
**Chosen:** height DFS with global ans.

## Logic Walkthrough
height = 1+max(L,R).

## Dry Run
Sample -> **3**.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**.

## Trade-offs & Alternatives
Diameter in nodes vs edges.

## Common Mistakes / Edge Cases
Returning height as diameter.

## Interview Follow-ups / Variations
Max Path Sum (124).

## Tags
`tree-dp`, `leetcode-543`, `difficulty:easy`
