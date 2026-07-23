# Binary Tree Zigzag Level Order Traversal

## Problem Statement
[LeetCode 103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) — level order alternating L→R and R→L each level.

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<vector<int>>` zigzag levels.
- **Valid answer:** children still enqueued left-then-right; only output order flips.
- **Edges:** empty; single node; two levels; skewed.

## Intuition
Normal BFS order of dequeue is always L→R. Fill a pre-sized level array at index `i` or `size-1-i` based on a flip flag.

## Brute Force → Optimal
- **Brute:** build normal levels then reverse odd ones — O(N) with extra reverse passes.
- **Optimal:** write directly into positions while dequeuing — one pass per node.

## Data Structure / Approach Justification
**Chosen:** `queue` + `bool leftToRight` + indexed `vector` of size `levelSize`.

- **vs deque push_front/back:** also fine; index math avoids direction-dependent inserts.
- **vs reverse after collect:** clearer but slightly more work.

## Logic Walkthrough
BFS with size snapshot. For index `i` in level, write at `leftToRight ? i : size-1-i`. Flip flag after each level.

## Dry Run
`[3,9,20,null,null,15,7]`:
- L→R: `[3]`
- R→L: dequeue 9 then 20 → write `[20,9]`
- L→R: `[15,7]`

## Time & Space Complexity
Time **O(N)**. Space **O(W)** queue + level buffers. Why: each node once (section 4).

## Trade-offs & Alternatives
Reverse-after-build is easier to explain; index placement avoids mutating mid-level vectors.

## Common Mistakes / Edge Cases
Flipping enqueue order (breaks next level); off-by-one on `size-1-i`; empty root.

## Interview Follow-ups / Variations
Standard level order (102); spiral with two stacks; print vertical zigzag.

## Tags
`binary-tree`, `bfs`, `queue`, `zigzag`, `leetcode-103`, `difficulty:medium`
