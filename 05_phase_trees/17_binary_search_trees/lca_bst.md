# Lowest Common Ancestor of a BST

## Problem Statement
[LeetCode 235](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) — find the LCA of nodes `p` and `q` in a BST (both exist).

- **Inputs:** `TreeNode* root`, `TreeNode* p`, `TreeNode* q`.
- **Output:** pointer to the LCA node.
- **Valid answer:** deepest node that is an ancestor of both (a node may be ancestor of itself).
- **Edges:** one is ancestor of the other; LCA is root; `p`/`q` anywhere under root.

## Intuition
While both targets lie strictly left (or right) of `curr`, descend. The first node where they split — or one equals `curr` — is the LCA.

## Brute Force → Optimal
- **Brute:** general binary-tree LCA (LC 236) — O(N).
- **Optimal:** iterative BST walk using ordering — O(H) time, O(1) space.

## Data Structure / Approach Justification
**Chosen:** iterative pointer walk on BST ranges.

- **vs recursive same logic:** identical asymptotics; recursion uses O(H) stack.
- **vs path-to-root intersect:** works on any tree but extra memory.

## Logic Walkthrough
Loop: if both values `< curr`, go left; if both `>`, go right; else return `curr`.

## Dry Run
`root=6`, `p=2`, `q=4`:
- Both `< 6` → go left to 2
- Not both `< 2` and not both `> 2` → LCA = 2

## Time & Space Complexity
Time **O(H)**. Space **O(1)** iterative. Why: single descent using BST order (section 4).

## Trade-offs & Alternatives
On a non-BST you must use LC 236. Recursive form is shorter to write but not constant-space.

## Common Mistakes / Edge Cases
Using BST walk on a non-BST; forgetting a node can be its own ancestor; comparing nodes by pointer instead of value when values are unique.

## Interview Follow-ups / Variations
LCA in general binary tree? With parent pointers? Multiple queries offline?

## Tags
`bst`, `lca`, `iterative`, `leetcode-235`, `difficulty:medium`
