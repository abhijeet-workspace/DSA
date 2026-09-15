# Average of Levels in Binary Tree

## 1. Problem Statement
[LeetCode 637](https://leetcode.com/problems/average-of-levels-in-binary-tree/) — return the average value of nodes on each level.

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<double>` averages top → bottom.
- **Valid answer:** one average per non-empty level.
- **Edges:** single node; skewed; large values (use `double`/`long long` sum).

## 2. Intuition
Level-order; for each level sum values and divide by count.

## 3. Brute Force → Optimal
- **Brute:** gather levels then average — fine.
- **Optimal:** same BFS in one pass — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** BFS with per-level sum/count.

| Alternative | Why it loses here |
|-------------|-------------------|
| DFS depth lists | Extra vectors; BFS is natural |
| Running online only | Need all levels anyway |

## 5. Logic Walkthrough
1. Queue root.
2. While queue: snapshot `sz`; sum `sz` nodes; push children; append `sum/sz`.

## 6. Dry Run
`[3,9,20,null,null,15,7]` → `[3, 14.5, 11]`.

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
`binary-tree`, `bfs`, `leetcode-637`, `difficulty:easy`
