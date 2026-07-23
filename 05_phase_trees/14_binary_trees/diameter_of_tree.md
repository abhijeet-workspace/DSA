# Diameter of Binary Tree

## Problem Statement
[LeetCode 543](https://leetcode.com/problems/diameter-of-binary-tree/) — return the length of the diameter (number of **edges** on the longest path between any two nodes).

- **Inputs:** `TreeNode* root`.
- **Output:** `int` edge count.
- **Valid answer:** max over all nodes of `height(left) + height(right)`.
- **Edges:** empty → 0; single node → 0; diameter not through root.

## Intuition
Any path’s highest node is a “bend.” At each node, `lh + rh` is a candidate diameter; also return height for the parent.

## Brute Force → Optimal
- **Brute:** for each node, compute left/right heights separately — O(N²).
- **Optimal:** one DFS that returns height and updates a global max — O(N).

## Data Structure / Approach Justification
**Chosen:** postorder DFS with a shared `maxDia` accumulator.

- **vs all-pairs paths:** exponential / unnecessary.
- **vs two BFS farthest-node trick:** works on trees but heavier for binary-tree interviews.

## Logic Walkthrough
`height(null)=0`. Recurse; set `maxDia = max(maxDia, lh+rh)`; return `1+max(lh,rh)`. Answer is `maxDia` in edges.

## Dry Run
Tree `1` with left `2(4,5)` and right `3`:
- at `2`: `lh=1,rh=1` → candidate 2
- at `1`: `lh=2,rh=1` → candidate 3 → diameter 3 (e.g. `4-2-1-3` or `4-2-5`)

## Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: each node contributes height once (section 4).

## Trade-offs & Alternatives
Global/mutable max is simple; returning `pair<height,dia>` is more functional. Remember answer is edges, not nodes.

## Common Mistakes / Edge Cases
Returning nodes instead of edges; assuming diameter always through root; not resetting max between calls.

## Interview Follow-ups / Variations
Diameter of N-ary tree; longest zig-zag path (1372); max path sum (124).

## Tags
`binary-tree`, `dfs`, `diameter`, `leetcode-543`, `difficulty:easy`
