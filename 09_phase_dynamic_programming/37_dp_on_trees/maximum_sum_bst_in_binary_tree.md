# Maximum Sum BST in Binary Tree

## Problem Statement
[LeetCode 1373](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/) — max sum of any subtree that is a BST (empty sum 0).

- **Inputs:** `root`.
- **Output:** max BST subtree sum.
- **Valid answer:** among valid BST subtrees.
- **Edges:** all invalid; negatives.

## Intuition
Post-order return {isBST, min, max, sum}; track global max sum.

## Brute Force → Optimal
- **Brute:** check each subtree.
- **Optimal:** O(N).

## Data Structure / Approach Justification
**Chosen:** struct Info from children.

## Logic Walkthrough
Valid if left/right BST and left.max < val < right.min.

## Dry Run
Sample -> **20**.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**.

## Trade-offs & Alternatives
Use sentinel min/max for null.

## Common Mistakes / Edge Cases
Not updating global on valid BST.

## Interview Follow-ups / Variations
Validate BST; tree DP.

## Tags
`tree-dp`, `leetcode-1373`, `difficulty:hard`
