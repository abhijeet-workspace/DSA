# LCA Deepest Leaves

## 1. Problem Statement
[LeetCode 1123](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/) — LCA of all deepest leaves.

## 2. Intuition
Return (subtree answer, height); if heights equal, current node is LCA of deepest in both.

## 3. Brute Force → Optimal
- Find depth then LCA of all deepest. One DFS combines.

## 4. Data Structure / Approach Justification
**Chosen:** height-paired DFS.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
Compare child heights; pick deeper side or self.

## 6. Dry Run
Sample → 2.

## 7. Time & Space Complexity
**O(n)**.

## 8. Trade-offs & Alternatives
Related to subtree Euler for CP queries.

## 9. Common Mistakes / Edge Cases
Off-by-one height.

## 10. Interview Follow-ups / Variations
LC 865 similar.

## 11. Tags
`lca`, `leetcode-1123`, `difficulty:medium`

