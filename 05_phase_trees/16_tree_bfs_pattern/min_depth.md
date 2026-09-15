# Minimum Depth of Binary Tree

## 1. Problem Statement
[LeetCode 111](https://leetcode.com/problems/minimum-depth-of-binary-tree/) — length (node count) of the shortest root-to-leaf path.

- **Inputs:** `TreeNode* root`.
- **Output:** `int` min depth; empty tree → 0.
- **Valid answer:** a leaf has no left and no right child.
- **Edges:** empty; single node; one child only (not a leaf until true leaf).

## 2. Intuition
BFS finds the nearest leaf first — stop at the first node with no children.

## 3. Brute Force → Optimal
- **Brute / DFS:** recurse both sides, take min at leaves — O(N), may explore deep side first.
- **Optimal early-exit:** BFS by depth — often fewer nodes on unbalanced trees.

## 4. Data Structure / Approach Justification
**Chosen:** `queue<pair<TreeNode*,int>>` carrying depth.

- **vs pure DFS:** correct but no early stop on wide shallow leaves.
- **vs level-size BFS without depth field:** same idea; increment depth per level.

## 5. Logic Walkthrough
Enqueue `{root,1}`. Dequeue; if leaf return depth; else enqueue children with `depth+1`.

## 6. Dry Run
`3 / 9,20 / _,_ ,15,7`: dequeue 3 → enqueue 9@2, 20@2; dequeue 9 (leaf) → return 2.

## 7. Time & Space Complexity
Time **O(N)** worst. Space **O(W)** queue. Why: stop at first leaf; may still visit many nodes (section 4).

## 8. Trade-offs & Alternatives
DFS is shorter code; BFS wins when min leaf is shallow and tree is deep elsewhere.

## 9. Common Mistakes / Edge Cases
Treating a one-child node as a leaf; returning height instead of leaf depth; empty root.

## 10. Interview Follow-ups / Variations
Max depth (104); min depth in graph/grid BFS; count leaves at min depth.

## 11. Tags
`binary-tree`, `bfs`, `queue`, `shortest-path`, `leetcode-111`, `difficulty:easy`
