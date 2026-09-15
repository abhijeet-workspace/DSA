# Lowest Common Ancestor BST

## 1. Problem Statement
[LeetCode 235](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) — LCA using BST order.

## 2. Intuition
Walk down until split (or hit p/q).

## 3. Brute Force → Optimal
- General tree LCA O(n). BST O(h).

## 4. Data Structure / Approach Justification
**Chosen:** iterative BST walk.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
While both less/greater, step; else return.

## 6. Dry Run
LCA(2,8)=6.

## 7. Time & Space Complexity
**O(h)**.

## 8. Trade-offs & Alternatives
Cross-folder BST topic.

## 9. Common Mistakes / Edge Cases
Using 236 recursion without exploiting BST.

## 10. Interview Follow-ups / Variations
LC 236.

## 11. Tags
`lca`, `bst`, `leetcode-235`, `difficulty:medium`

