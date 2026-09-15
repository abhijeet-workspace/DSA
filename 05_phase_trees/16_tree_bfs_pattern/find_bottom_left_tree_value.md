# Find Bottom Left Tree Value

## 1. Problem Statement
[LeetCode 513](https://leetcode.com/problems/find-bottom-left-tree-value/) — return the leftmost value in the last row of the tree.

- **Inputs:** `TreeNode* root` (non-empty on LC).
- **Output:** `int`.
- **Valid answer:** first node of the deepest level in left-to-right order.
- **Edges:** single node; left-skewed; right-skewed deepest leaf.

## 2. Intuition
BFS left-to-right; last level’s first dequeued node is the answer — or track the last node if enqueue right then left.

## 3. Brute Force → Optimal
- **Brute:** compute height then scan.
- **Optimal:** BFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** BFS; record first node of each level; last record wins.

| Alternative | Why it loses here |
|-------------|-------------------|
| DFS depth tracking | Need careful leftmost update |

## 5. Logic Walkthrough
Each level: first popped node updates `ans`; enqueue left then right.

## 6. Dry Run
`[1,2,3,4,null,5,6,null,null,7]` → bottom-left **7**.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(W) for the queue (W = max width)
- Why: classic level-order visit-each-node-once.

## 8. Trade-offs & Alternatives
DFS with depth parameter also works for many “per level” aggregations; BFS makes level boundaries obvious.

## 9. Common Mistakes / Edge Cases
Forgetting level-size snapshot; off-by-one on depth; empty root.

## 10. Interview Follow-ups / Variations
Related level-order variants (zigzag, right side, vertical).

## 11. Tags
`binary-tree`, `bfs`, `leetcode-513`, `difficulty:medium`
