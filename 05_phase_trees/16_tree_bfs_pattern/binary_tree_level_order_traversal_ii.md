# Binary Tree Level Order Traversal II

## 1. Problem Statement
[LeetCode 107](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) — return level order from **bottom to top** (left to right within level).

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<vector<int>>`.
- **Valid answer:** deepest level first.
- **Edges:** empty; single node; skewed.

## 2. Intuition
Standard BFS levels, then reverse the result (or push_front).

## 3. Brute Force → Optimal
- **Brute:** BFS then `reverse` — O(N).
- **Optimal:** same.

## 4. Data Structure / Approach Justification
**Chosen:** BFS + reverse vector of levels.

| Alternative | Why it loses here |
|-------------|-------------------|
| DFS insert at front per depth | More awkward |
| Deque of levels | Equivalent |

## 5. Logic Walkthrough
1. BFS collect levels top→bottom.
2. `reverse(ans)`.

## 6. Dry Run
`[3,9,20,null,null,15,7]` → `[[15,7],[9,20],[3]]`.

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
`binary-tree`, `bfs`, `leetcode-107`, `difficulty:medium`
