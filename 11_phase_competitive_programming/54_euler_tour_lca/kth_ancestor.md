# Kth Ancestor

## 1. Problem Statement
[LeetCode 1483](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/) — binary lifting `getKthAncestor(node,k)`.

## 2. Intuition
`up[j][v]` = 2^j-th parent; walk bits of k.

## 3. Brute Force → Optimal
- Climb parent k times. Binary lifting O(log n).

## 4. Data Structure / Approach Justification
**Chosen:** parent table doubling. Template twin in `50_cp_templates`.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
Fill up[0]; DP; query bits.

## 6. Dry Run
LC-style sample checks.

## 7. Time & Space Complexity
Prep **O(n log n)**; query **O(log n)**.

## 8. Trade-offs & Alternatives
Also enables LCA.

## 9. Common Mistakes / Edge Cases
k larger than depth → -1.

## 10. Interview Follow-ups / Variations
Jump game on tree.

## 11. Tags
`binary-lifting`, `lca`, `leetcode-1483`, `difficulty:hard`

