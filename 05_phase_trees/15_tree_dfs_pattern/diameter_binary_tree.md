# Diameter of Binary Tree

## Problem Statement
[LeetCode 543](https://leetcode.com/problems/diameter-of-binary-tree/) — length of the longest path between any two nodes (number of **edges**).

- **Inputs:** `TreeNode* root`.
- **Output:** `int` diameter.
- **Valid answer:** path need not pass through the root.
- **Edges:** empty/null; single node (0); skewed chain.

## Intuition
At each node, a candidate path uses `leftHeight + rightHeight` edges. Recurse heights while tracking a global max.

## Brute Force → Optimal
- **Brute:** for every node, compute left/right heights separately — O(N²).
- **Optimal:** one post-order pass returning height and updating diameter — O(N).

## Data Structure / Approach Justification
**Chosen:** DFS returning height; `diameter` by reference.

- **vs two separate height calls per node:** quadratic on skewed trees.
- **vs BFS levels:** harder to express “any path through node.”

## Logic Walkthrough
`heightAndDiameter`: recurse left/right; `diameter = max(diameter, leftH+rightH)`; return `1+max(leftH,rightH)`.

## Dry Run
Tree `1` with left `2(4,5)` and right `3`:
- at `2`: heights `1,1` → diameter `2`; height `2`
- at `1`: heights `2,1` → diameter `3`; done

## Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: each node once; recursion depth (section 4).

## Trade-offs & Alternatives
Same skeleton as max-path-sum (gains vs heights). Diameter in *nodes* is edges+1 — interview trap.

## Common Mistakes / Edge Cases
Returning node count instead of edges; forgetting global update at every node; null root.

## Interview Follow-ups / Variations
Diameter of N-ary tree; weighted edges; longest zig-zag path (1372).

## Tags
`binary-tree`, `dfs`, `height`, `leetcode-543`, `difficulty:easy`
