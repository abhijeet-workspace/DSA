# Lowest Common Ancestor of a Binary Tree

## Problem Statement
[LeetCode 236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) — find the LCA of `p` and `q` in a general binary tree (not necessarily a BST).

- **Inputs:** `TreeNode* root`, `TreeNode* p`, `TreeNode* q`.
- **Output:** `TreeNode*` LCA.
- **Valid answer:** deepest node that has both `p` and `q` as descendants (a node is a descendant of itself).
- **Edges:** one is ancestor of the other; `p`/`q` is root; both under same child.

## Intuition
Post-order DFS: if left and right both find a target, `root` is LCA; else bubble the non-null side.

## Brute Force → Optimal
- **Brute:** store root→p and root→q paths; last common — O(N) extra lists.
- **Optimal:** single DFS — O(N) time, O(H) space.

## Data Structure / Approach Justification
**Chosen:** recursive post-order returning found subtree hit.

- **vs parent map + ancestor set:** needs extra pass and memory.
- **vs BST LCA (235):** cannot use value comparisons here.

## Logic Walkthrough
Base: null / `root==p` / `root==q` → return `root`. Recurse both sides; both non-null → return `root`; else return left or right.

## Dry Run
Root `3`, left `5(6,2)`, right `1`; `p=5`, `q=2`:
- under `5`: left null for `p` match at `5` itself → returns `5` without needing both sides for this pair when `p` is ancestor of `q` → LCA `5`

## Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: may visit all nodes; call stack (section 4).

## Trade-offs & Alternatives
Assumes `p` and `q` exist. Parent pointers → climb with a set. Offline: Tarjan LCA.

## Common Mistakes / Edge Cases
Stopping at value match without searching both sides when both targets are needed below; treating as BST.

## Interview Follow-ups / Variations
Nodes may be missing? Parent pointers (1650)? LCA of BST (235)? k nodes?

## Tags
`binary-tree`, `dfs`, `lca`, `leetcode-236`, `difficulty:medium`
