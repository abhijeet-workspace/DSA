# Deepest Leaves Sum

## 1. Problem Statement
[LeetCode 1302](https://leetcode.com/problems/deepest-leaves-sum/) — return the sum of values of the deepest leaves.

- **Inputs:** `TreeNode* root`.
- **Output:** `int` sum.
- **Valid answer:** sum of all nodes at maximum depth.
- **Edges:** single node; one deepest leaf; many on last level.

## 2. Intuition
BFS; replace running sum each new level; final level sum is answer.

## 3. Brute Force → Optimal
- **Brute:** find max depth then sum leaves at that depth.
- **Optimal:** single BFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** BFS overwriting per-level sum.

| Alternative | Why it loses here |
|-------------|-------------------|
| Two-pass DFS | Extra traversal |

## 5. Logic Walkthrough
Each level recompute `sum`; after BFS ends, `sum` is deepest.

## 6. Dry Run
`[1,2,3,4,5,null,6,7,null,null,null,null,8]` → 7+8=**15**.

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
`binary-tree`, `bfs`, `leetcode-1302`, `difficulty:medium`
