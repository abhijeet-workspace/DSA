# Count Good Nodes in Binary Tree

## Problem Statement
[LeetCode 1448](https://leetcode.com/problems/count-good-nodes-in-binary-tree/) — count nodes that are “good”: value ≥ every ancestor on the path from root.

- **Inputs:** `TreeNode* root`.
- **Output:** `int` count of good nodes.
- **Valid answer:** root alone counts; equal-to-max on path counts as good.
- **Edges:** empty; single node; negatives; left/right skewed.

## Intuition
A node is good iff its value is ≥ the running max from root to that node. Pass `mx` down the recursion.

## Brute Force → Optimal
- **Brute:** for each node, walk path to root and check max — O(N·H).
- **Optimal:** DFS (or BFS with state) carrying `maxSoFar` — O(N).

## Data Structure / Approach Justification
**Chosen:** DFS with `mx` parameter — O(1) extra per call beyond recursion stack.

- **vs store full path:** unnecessary memory.
- **vs BFS `{node, maxSoFar}`:** also O(N); DFS is simpler here (path state is natural).

## Logic Walkthrough
At `n`: if `n->val >= mx`, count 1. Update `mx = max(mx, n->val)`. Recurse left/right; sum counts.

## Dry Run
Tree `3 / 1,4 / 3 , 1,5`:
- `3` (≥3) → good; mx=3
- `1` (<3) → not; `3` (≥3) → good
- `4` (≥3) → good; mx=4; `1` not; `5` (≥4) → good → total 4

## Time & Space Complexity
Time **O(N)**. Space **O(H)** recursion (H = height). Why: each node visited once with O(1) work (section 4).

## Trade-offs & Alternatives
DFS is natural for path aggregates; iterative stack/BFS with pair state avoids recursion depth on skewed trees.

## Common Mistakes / Edge Cases
Using `>` instead of `>=`; forgetting root is always good; initializing `mx` to 0 (breaks negatives).

## Interview Follow-ups / Variations
Count good nodes with parent only? Path sum variants; max path product with running constraints.

## Tags
`binary-tree`, `dfs`, `path-state`, `leetcode-1448`, `difficulty:medium`
