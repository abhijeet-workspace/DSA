# Flatten Binary Tree to Linked List

## Problem Statement
[LeetCode 114](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) — flatten binary tree in-place to a linked list following preorder; use `right` as next, `left` null.

- **Inputs:** tree root.
- **Output:** mutated tree as right spine.
- **Valid answer:** preorder order of values.
- **Edges:** empty; only left children; skewed.

## Intuition
Morris-like: for node with left, attach original right to rightmost of left subtree, then move left to right.

## Brute Force → Optimal
- **Brute:** preorder copy values rebuild — extra space.
- **Optimal:** in-place pointer rewiring — O(1) extra.

## Data Structure / Approach Justification
**Chosen:** iterative predecessor linking.

- **vs reverse postorder recursion:** also common O(N) stack.

## Logic Walkthrough
While curr: if left, find pred, pred.right = curr.right; curr.right = curr.left; left=null; advance right.

## Dry Run
At 1: left subtree 2-3-4; wire 4→5; right becomes 2.

## Time & Space Complexity
Time **O(N)**. Space **O(1)** extra.

## Trade-offs & Alternatives
Recursive reverse-preorder with prev pointer is shorter.

## Common Mistakes / Edge Cases
Losing right subtree before rewiring; not nulling left.

## Interview Follow-ups / Variations
Flatten to doubly linked list; recover tree.

## Tags
`tree`, `dfs`, `linked-list`, `leetcode-114`, `difficulty:medium`
