# Maximum Depth of Binary Tree

## 1. Problem Statement
[LeetCode 104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) — return the maximum depth (number of **nodes** on the longest root-to-leaf path).

- **Inputs:** `TreeNode* root`.
- **Output:** `int`.
- **Valid answer:** `0` if empty; else `1 + max(depth(left), depth(right))`.
- **Edges:** empty; single node; left- or right-skewed; balanced.

## 2. Intuition
Depth is defined recursively on subtrees: a leaf has depth 1; empty has depth 0.

## 3. Brute Force → Optimal
- **Brute:** must visit all nodes for exact max — no sublinear exact algorithm.
- **Optimal:** DFS recursion or BFS level count — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** recursive DFS returning `1 + max(L, R)`.

- **vs BFS:** answer = number of levels; better for avoiding deep recursion.
- **vs storing depths in a map:** unnecessary memory.

## 5. Logic Walkthrough
Null → 0. Else return `1 + max(maxDepth(left), maxDepth(right))`.

## 6. Dry Run
`[3,9,20,null,null,15,7]`:
- leaves `9,15,7` → depth 1 from themselves
- `20` → `1+max(1,1)=2`
- `3` → `1+max(1,2)=3`

## 7. Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: one visit per node (section 4).

## 8. Trade-offs & Alternatives
DFS is shortest. BFS avoids stack overflow on skewed trees. Clarify nodes vs edges with the interviewer.

## 9. Common Mistakes / Edge Cases
Off-by-one (edges vs nodes); returning 1 for empty; not handling null children.

## 10. Interview Follow-ups / Variations
Min depth (111); diameter (543); balanced check (110).

## 11. Tags
`binary-tree`, `dfs`, `depth`, `leetcode-104`, `difficulty:easy`
