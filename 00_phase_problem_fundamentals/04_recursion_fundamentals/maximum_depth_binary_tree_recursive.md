# Maximum Depth of Binary Tree (Recursive)

## 1. Problem Statement
[LeetCode 104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) — Return the maximum depth (longest root→leaf path length in nodes) of a binary tree.

- **Inputs:** `TreeNode* root`.
- **Output:** Depth as `int`.
- **Edges:** Empty tree; single node; skewed tree.

## 2. Intuition
Depth = 1 + max(depth(left), depth(right)).

## 3. Brute Force → Optimal
BFS level count also works. Recursion is the natural tree definition.

## 4. Data Structure / Approach Justification
**Chosen:** recursive DFS on `TreeNode`.

Tree topics later cover DFS/BFS patterns in depth. **Focus here is recursion** as “problem size shrinks to subtrees.”

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. Null → 0.
2. Else `1 + max(maxDepth(L), maxDepth(R))`.

## 6. Dry Run
Root 3 with right subtree depth 2 → total 3.

## 7. Time & Space Complexity
- **Time:** O(n)
- **Space:** O(h) stack

## 8. Trade-offs & Alternatives
Iterative BFS/stack DFS same asymptotics.

## 9. Common Mistakes / Edge Cases
Counting edges vs nodes; forgetting empty → 0.

## 10. Interview Follow-ups / Variations
Min depth; diameter; balanced check.

## 11. Tags
`recursion`, `tree`, `dfs`, `leetcode-104`, `difficulty:easy`
