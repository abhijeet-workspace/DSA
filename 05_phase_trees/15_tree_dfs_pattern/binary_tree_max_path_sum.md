# Binary Tree Maximum Path Sum

## Problem Statement
[LeetCode 124](https://leetcode.com/problems/binary-tree-maximum-path-sum/) — max sum of any non-empty path (any node to any node along parent–child edges).

- **Inputs:** `TreeNode* root`.
- **Output:** `int` maximum path sum.
- **Valid answer:** path may bend at a node (use both children) but cannot fork; nodes used at most once.
- **Edges:** all-negative tree; single node; negative children that should be dropped.

## Intuition
At each node, the best *answer* path can use `val + leftGain + rightGain`. What you return to the parent can use only one child side.

## Brute Force → Optimal
- **Brute:** enumerate all paths — exponential.
- **Optimal:** post-order DFS with a global `best` — O(N) time, O(H) space.

## Data Structure / Approach Justification
**Chosen:** recursive DFS + reference `best`; clamp child gains with `max(0, ·)`.

- **vs graph max-path:** overkill; tree is already a DAG toward leaves.
- **vs returning both children upward:** invalid path shape (would fork).

## Logic Walkthrough
`dfs` returns gain to parent: `val + max(leftGain, rightGain)`. Before return, update `best` with path through node using both gains.

## Dry Run
`[-10,9,20,null,null,15,7]`:
- at `20`: gains `15`,`7` → path `42` updates `best`; returns `35`
- at `-10`: left `9`, right `35` → path `34`; `best` stays `42`

## Time & Space Complexity
Time **O(N)**. Space **O(H)** recursion. Why: each node once; height stack (section 4).

## Trade-offs & Alternatives
Clamping negatives is required for correctness of upward gain. Iterative post-order possible but noisier.

## Common Mistakes / Edge Cases
Returning both children to parent; forgetting `INT_MIN` init (all-negative); not clamping.

## Interview Follow-ups / Variations
Path must go through root? Max path *length* (edges)? Max sum path that is root-to-leaf only (112/113).

## Tags
`binary-tree`, `dfs`, `post-order`, `leetcode-124`, `difficulty:hard`
