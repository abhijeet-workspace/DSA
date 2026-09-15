# LCA Binary Tree IV

## 1. Problem Statement
[LeetCode 1676](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/) — LCA of a **set** of nodes (all guaranteed present).

## 2. Intuition
Same recursion as 236; treat any set member as a 'found' base case.

## 3. Brute Force → Optimal
- Reduce to pairwise LCAs. One DFS is enough.

## 4. Data Structure / Approach Justification
**Chosen:** multi-node recursive LCA.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
If node in set return it; combine left/right.

## 6. Dry Run
LCA({6,2,0})=3.

## 7. Time & Space Complexity
**O(n)**.

## 8. Trade-offs & Alternatives
Must ensure all nodes exist (problem guarantee).

## 9. Common Mistakes / Edge Cases
Returning too early without covering all.

## 10. Interview Follow-ups / Variations
LC 1123 deepest leaves.

## 11. Tags
`lca`, `leetcode-1676`, `difficulty:medium`

