# Binary Tree Level Order Traversal

## Problem Statement
[LeetCode 102](https://leetcode.com/problems/binary-tree-level-order-traversal/) — return node values grouped by level, left to right.

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<vector<int>>` — outer index = depth.
- **Valid answer:** empty tree → `{}`; single node → `{{val}}`.
- **Edges:** empty; skewed; wide balanced levels.

## Intuition
FIFO queue visits nodes in breadth order. Snapshot `q.size()` before the inner loop to isolate one level.

## Brute Force → Optimal
- **Brute / alt:** DFS push into `result[depth]` — also O(N).
- **Optimal for this API:** classic level-size BFS — O(N) time, O(W) queue.

## Data Structure / Approach Justification
**Chosen:** `queue<TreeNode*>` with per-level size loop.

- **vs DFS depth lists:** same asymptotics; BFS matches “level by level” naturally.
- **vs two-queue ping-pong:** equivalent; size snapshot is simpler.

## Logic Walkthrough
Push root. While queue non-empty: take `size`, collect `size` nodes’ values, enqueue their children, append level to result.

## Dry Run
`[3,9,20,null,null,15,7]`:
- level0: `[3]` → enqueue 9,20
- level1: `[9,20]` → enqueue 15,7
- level2: `[15,7]`

## Time & Space Complexity
Time **O(N)**. Space **O(W)** queue + output (W = max width). Why: each node enqueued/dequeued once (section 4).

## Trade-offs & Alternatives
BFS uses O(W) frontier; DFS uses O(H) stack but needs explicit depth indexing into result.

## Common Mistakes / Edge Cases
Not capturing size before the inner loop (levels merge); null root; forgetting to enqueue both children.

## Interview Follow-ups / Variations
Zigzag (103); right side view (199); average of levels (637); connect next pointers (116/117).

## Tags
`binary-tree`, `bfs`, `queue`, `level-order`, `leetcode-102`, `difficulty:medium`
