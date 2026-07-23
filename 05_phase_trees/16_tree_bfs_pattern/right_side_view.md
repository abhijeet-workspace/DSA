# Binary Tree Right Side View

## Problem Statement
[LeetCode 199](https://leetcode.com/problems/binary-tree-right-side-view/) — values visible from the right side, top to bottom (one per depth).

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<int>` rightmost node per level.
- **Valid answer:** left subtree can appear if no right sibling at that depth.
- **Edges:** empty; left-only chain; right-only chain.

## Intuition
Level-order BFS: the last node processed in each level is the rightmost.

## Brute Force → Optimal
- **Brute:** full level lists then take `back()` — O(N) time, more temp memory.
- **Optimal:** same BFS, record only when `i == levelSize - 1`.

## Data Structure / Approach Justification
**Chosen:** `queue` + level-size loop, append last index.

- **vs DFS prefer-right:** also O(N); record first visit per depth when exploring right first.
- **vs store full levels:** wasteful if only right view needed.

## Logic Walkthrough
BFS levels left→right. For each level index `i`, if last, push `curr->val`. Enqueue left then right.

## Dry Run
`1 / 2,3 / _,5 , _,4`: levels end with 1, 3, 4 → `[1,3,4]`.

## Time & Space Complexity
Time **O(N)**. Space **O(W)** queue. Why: visit every node once (section 4).

## Trade-offs & Alternatives
DFS right-first records first hit per depth with O(H) stack — nicer if W ≫ H.

## Common Mistakes / Edge Cases
Taking first of level (left view); skipping deeper left-only nodes; empty root.

## Interview Follow-ups / Variations
Left side view; boundary traversal; vertical order; bottom view.

## Tags
`binary-tree`, `bfs`, `queue`, `level-order`, `leetcode-199`, `difficulty:medium`
