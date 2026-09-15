# Binary Tree Zigzag Level Order Traversal

## 1. Problem Statement
[LeetCode 103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) — level order alternating L→R and R→L each level.

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<vector<int>>` zigzag levels.
- **Valid answer:** children still enqueued left-then-right; only output order flips.
- **Edges:** empty; single node; two levels; skewed.

## 2. Intuition
Normal BFS order of dequeue is always L→R. Fill a pre-sized level array at index `i` or `size-1-i` based on a flip flag.

## 3. Brute Force → Optimal
- **Brute:** build normal levels then reverse odd ones — O(N) with extra reverse passes.
- **Optimal:** write directly into positions while dequeuing — one pass per node.

## 4. Data Structure / Approach Justification
**Chosen:** `queue` + `bool leftToRight` + indexed `vector` of size `levelSize`.

- **vs deque push_front/back:** also fine; index math avoids direction-dependent inserts.
- **vs reverse after collect:** clearer but slightly more work.

## 5. Logic Walkthrough
BFS with size snapshot. For index `i` in level, write at `leftToRight ? i : size-1-i`. Flip flag after each level.

## 6. Dry Run
`[3,9,20,null,null,15,7]`:
- L→R: `[3]`
- R→L: dequeue 9 then 20 → write `[20,9]`
- L→R: `[15,7]`

## 7. Time & Space Complexity
Time **O(N)**. Space **O(W)** queue + level buffers. Why: each node once (section 4).

## 8. Trade-offs & Alternatives
Reverse-after-build is easier to explain; index placement avoids mutating mid-level vectors.

## 9. Common Mistakes / Edge Cases
Flipping enqueue order (breaks next level); off-by-one on `size-1-i`; empty root.

## 10. Interview Follow-ups / Variations
Standard level order (102); spiral with two stacks; print vertical zigzag.

## 11. Tags
`binary-tree`, `bfs`, `queue`, `zigzag`, `leetcode-103`, `difficulty:medium`
