# Maximum Level Sum of a Binary Tree

## 1. Problem Statement
[LeetCode 1161](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/) — return the **1-indexed** level with maximum sum (smallest level on ties).

- **Inputs:** `TreeNode* root`.
- **Output:** `int` level number.
- **Valid answer:** argmax of level sums.
- **Edges:** negatives; tie → smaller level; single node.

## 2. Intuition
BFS track level index and sum; keep best.

## 3. Brute Force → Optimal
- **Brute:** vector of sums then scan.
- **Optimal:** online during BFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** BFS with level counter.

| Alternative | Why it loses here |
|-------------|-------------------|
| DFS depth sums | Works |

## 5. Logic Walkthrough
Initialize `bestSum`, `bestLvl`; each level compare.

## 6. Dry Run
`[1,7,0,7,-8,null,null]` → level 2 sum 7+0=7 vs level 3 7-8=-1 → **2**.

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
`binary-tree`, `bfs`, `leetcode-1161`, `difficulty:medium`
