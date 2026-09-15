# Lowest Common Ancestor Binary Tree

## 1. Problem Statement
[LeetCode 236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) — LCA in a general binary tree.

- Also in tree-DFS topic; here paired with CP Euler/RMQ LCA variants.

## 2. Intuition
Postorder: if both sides nonempty, root is LCA.

## 3. Brute Force → Optimal
- Parent map + depth climb. Recursive divide is classic interview.

## 4. Data Structure / Approach Justification
**Chosen:** recursive LCA.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
Search left/right; combine.

## 6. Dry Run
LCA(5,1)=3.

## 7. Time & Space Complexity
**O(n)**.

## 8. Trade-offs & Alternatives
Euler+RMQ for many queries on static trees.

## 9. Common Mistakes / Edge Cases
Assuming BST property.

## 10. Interview Follow-ups / Variations
LC 235 BST; LC 1676 IV.

## 11. Tags
`lca`, `binary-tree`, `leetcode-236`, `difficulty:medium`

