# Find Largest Value in Each Tree Row

## 1. Problem Statement
[LeetCode 515](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) — return the largest value in each level.

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<int>` max per level.
- **Valid answer:** one int per level.
- **Edges:** negatives; single node; skewed.

## 2. Intuition
BFS; track max while draining each level.

## 3. Brute Force → Optimal
- **Brute:** build levels then max_element.
- **Optimal:** online max during BFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** BFS per-level max.

| Alternative | Why it loses here |
|-------------|-------------------|
| DFS with depth→max map | Works; BFS simpler |

## 5. Logic Walkthrough
For each level initialize `mx` to first/`INT_MIN`; update; push children; append `mx`.

## 6. Dry Run
`[1,3,2,5,3,null,9]` → `[1,3,9]`.

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
`binary-tree`, `bfs`, `leetcode-515`, `difficulty:medium`
