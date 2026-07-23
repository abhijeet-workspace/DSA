# Binary Tree DFS Traversals

## Problem Statement
Classic DFS orders on a binary tree — return node values in inorder (L-Root-R), preorder (Root-L-R), and postorder (L-R-Root). Related: [LC 94](https://leetcode.com/problems/binary-tree-inorder-traversal/), [144](https://leetcode.com/problems/binary-tree-preorder-traversal/), [145](https://leetcode.com/problems/binary-tree-postorder-traversal/).

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<int>` per traversal.
- **Valid answer:** visit every node exactly once in the chosen order.
- **Edges:** empty; single node; only left/right child; skewed.

## Intuition
Recursion mirrors the tree: the only difference is when you record the current node relative to left/right recursion.

## Brute Force → Optimal
- **Brute:** convert tree to array then permute — unnecessary work.
- **Optimal:** recursive DFS (or iterative stack) — O(N) time, O(H) stack.

## Data Structure / Approach Justification
**Chosen:** recursive helpers writing into a shared `vector`.

- **vs iterative stack:** same asymptotics; useful when recursion depth is a concern.
- **vs Morris traversal:** O(1) extra space but mutates links temporarily.

## Logic Walkthrough
Base: null → return. Inorder: left → val → right. Preorder: val → left → right. Postorder: left → right → val.

## Dry Run
Tree `1` with right `2` and `2.left=3`:
- Inorder: `1,3,2`
- Preorder: `1,2,3`
- Postorder: `3,2,1`

## Time & Space Complexity
Time **O(N)** each. Space **O(H)** recursion (+ O(N) for output). Why: one visit per node (section 4).

## Trade-offs & Alternatives
Recursion is clearest for teaching. Interviewers often ask iterative inorder with an explicit stack. Morris for O(1) aux space.

## Common Mistakes / Edge Cases
Confusing the three orders; forgetting null base case; leaking allocated demo nodes.

## Interview Follow-ups / Variations
Iterative versions; level-order BFS; reconstruct tree from preorder+inorder.

## Tags
`binary-tree`, `dfs`, `inorder`, `preorder`, `postorder`, `difficulty:easy`
