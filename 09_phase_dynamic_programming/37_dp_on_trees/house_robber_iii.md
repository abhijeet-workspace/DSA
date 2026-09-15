# House Robber III

## Problem Statement
[LeetCode 337](https://leetcode.com/problems/house-robber-iii/) — max money from binary tree houses; cannot rob adjacent (parent-child).

- **Inputs:** `TreeNode* root`.
- **Output:** max loot.
- **Valid answer:** optimal rob/skip choices.
- **Edges:** empty; single node.

## Intuition
DFS returns {rob, skip} for subtree.

## Brute Force → Optimal
- **Brute:** all assignments.
- **Optimal:** O(N) tree DP.

## Data Structure / Approach Justification
**Chosen:** pair return rob = val+skipL+skipR; skip = max of children.

## Logic Walkthrough
Post-order combine.

## Dry Run
Sample tree -> **7**.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: one visit (section 4).

## Trade-offs & Alternatives
Map memo by node pointer also works.

## Common Mistakes / Edge Cases
Robbing parent and child.

## Interview Follow-ups / Variations
House Robber I/II.

## Tags
`tree-dp`, `leetcode-337`, `difficulty:medium`
