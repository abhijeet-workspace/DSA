# Binary Tree to DLL

## Problem Statement
GFG classic — convert a binary tree into a **doubly linked list** in **inorder** sequence. Reuse tree links: `left` becomes previous, `right` becomes next. Return the head of the DLL.

- **Inputs:** `TreeNode* root`.
- **Output:** `TreeNode*` head of the inorder DLL (`left`/`right` as prev/next).
- **Valid answer:** inorder values form a doubly linked chain; forward and reverse walks match.
- **Edges:** empty tree; single node; skewed left/right; balanced.

## Intuition
Inorder already visits nodes in sorted-BST order (and “left-root-right” order for any BT). While visiting, stitch the current node to the previously visited node.

## Brute Force → Optimal
- **Brute:** inorder into a vector of nodes, then wire adjacent pairs — O(N) extra vector.
- **Optimal:** one inorder DFS with a `prev` pointer — O(N) time, O(H) stack, no extra node list.

## Data Structure / Approach Justification
**Chosen:** recursive inorder + `prev`/`head` references mutating `left`/`right` in place.

- **vs collect-then-link:** same asymptotics but uses O(N) extra storage for pointers.
- **vs LC 114 flatten-to-linked-list:** that produces a **right-skewed preorder** list, not an inorder DLL — different problem.

## Logic Walkthrough
Recurse left. If `prev` is null, set `head = node`; else set `prev->right = node` and `node->left = prev`. Set `prev = node`. Recurse right.

## Dry Run
Tree `4` with left `2(1,3)` and right `5`:
- Visit `1`: head=`1`, prev=`1`
- Visit `2`: `1⇄2`, prev=`2`
- Visit `3`: `2⇄3`, prev=`3`
- Visit `4`: `3⇄4`, prev=`4`
- Visit `5`: `4⇄5`
- Forward: `1 2 3 4 5`; backward from tail: `5 4 3 2 1`

## Time & Space Complexity
Time **O(N)**. Space **O(H)** recursion (output reuses nodes). Why: each node visited once; only call stack beyond the DLL itself (section 4).

## Trade-offs & Alternatives
In-place destroys the original tree shape — copy nodes first if the tree must be preserved. Iterative inorder with an explicit stack avoids deep recursion on skewed trees.

## Common Mistakes / Edge Cases
Forgetting to set `head` on the first visit; wiring only one direction; confusing with LC 114 flatten; null root.

## Interview Follow-ups / Variations
Preserve original tree? Circular DLL? BST-only constraints? Flatten to linked list (LC 114)?

## Tags
`binary-tree`, `dll`, `inorder`, `dfs`, `gfg`, `difficulty:medium`
