# BST Iterator

## Problem Statement
[LeetCode 173](https://leetcode.com/problems/binary-search-tree-iterator/) — implement an iterator over a BST’s in-order sequence.

- **Inputs:** `TreeNode* root` at construction.
- **Output:** `next()` → next smallest value; `hasNext()` → whether more remain.
- **Valid answer:** successive `next()` yields sorted ascending order of all nodes.
- **Edges:** skewed tree; single node; call `next` only when `hasNext` is true.

## Intuition
In-order is left → node → right. A stack can hold the unfinished left spine so each `next` pops one node and optionally pushes the right child’s left spine.

## Brute Force → Optimal
- **Brute:** full in-order into a vector at construct — O(N) time/space up front; `next` O(1).
- **Optimal:** controlled recursion with stack — O(H) space; `next` O(1) amortized.

## Data Structure / Approach Justification
**Chosen:** `stack<TreeNode*>` of ancestors on the current left path.

- **vs precompute array:** wastes memory and loses laziness for huge trees.
- **vs recursion:** stack makes pause/resume explicit for an iterator API.

## Logic Walkthrough
Construct: push all lefts from root. `next`: pop top; if it has a right child, push that child’s left spine; return popped value. `hasNext`: stack non-empty.

## Dry Run
Tree `7 / 3 \ 15 / 9 \ 20`:
- Init stack: `[7,3]`
- `next` → 3; push nothing → `[7]`
- `next` → 7; push lefts of 15 → `[15,9]`
- continues → 9, 15, 20

## Time & Space Complexity
`next` **O(1) amortized** (each node pushed/popped once). `hasNext` **O(1)**. Space **O(H)**. Why: left-spine stack (section 4).

## Trade-offs & Alternatives
Morris-style threading can claim O(1) space but mutates links — usually disallowed for iterators. Precompute if N is small and simplicity matters.

## Common Mistakes / Edge Cases
Forgetting to push the right child’s left path after a pop; calling `next` when empty; treating preorder/postorder as in-order.

## Interview Follow-ups / Variations
Bidirectional iterator? Flatten BST to sorted list (114)? kth next without full scan?

## Tags
`bst`, `iterator`, `stack`, `inorder`, `leetcode-173`, `difficulty:medium`
