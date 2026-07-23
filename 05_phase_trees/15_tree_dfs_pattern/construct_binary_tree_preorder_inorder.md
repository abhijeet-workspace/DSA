# Construct Binary Tree from Preorder and Inorder

## Problem Statement
[LeetCode 105](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) — rebuild the unique binary tree from `preorder` and `inorder` (distinct values).

- **Inputs:** `vector<int> preorder`, `vector<int> inorder`.
- **Output:** `TreeNode*` root.
- **Valid answer:** tree whose traversals match the inputs.
- **Edges:** empty; single node; skewed left/right.

## Intuition
`preorder[0]` is the root; its index in inorder splits left vs right subtree ranges. Recurse with a shared preorder cursor.

## Brute Force → Optimal
- **Brute:** scan inorder for each root — O(N²).
- **Optimal:** hash `value → inorder index` + shared `i` — O(N).

## Data Structure / Approach Justification
**Chosen:** `unordered_map` for O(1) split + recursive range build.

- **vs linear scan each time:** correct but quadratic on skewed trees.
- **vs postorder+inorder (106):** same idea; root is last of postorder segment.

## Logic Walkthrough
`build(pre, i, L, R)`: if `L>R` return null; take `pre[i++]` as root; split at `pos[v]`; build left `[L,m-1]` then right `[m+1,R]`.

## Dry Run
`pre=[3,9,20,15,7]`, `in=[9,3,15,20,7]`:
- root `3`, `m` splits left `[9]` / right `[15,20,7]`
- left → node `9`; right → `20` with children `15`,`7`

## Time & Space Complexity
Time **O(N)**. Space **O(N)** map + recursion. Why: each node once; index map (section 4).

## Trade-offs & Alternatives
Map is interview-expected for linear time. Without distinct values, reconstruction is ambiguous.

## Common Mistakes / Edge Cases
Wrong left-size; advancing `i` after both children; building right before left.

## Interview Follow-ups / Variations
Postorder+inorder (106); level-order+inorder; serialize/deserialize (297).

## Tags
`binary-tree`, `dfs`, `divide-conquer`, `hash-map`, `leetcode-105`, `difficulty:medium`
