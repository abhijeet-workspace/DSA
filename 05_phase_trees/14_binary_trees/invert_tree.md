# Invert Binary Tree

## 1. Problem Statement
[LeetCode 226](https://leetcode.com/problems/invert-binary-tree/) — mirror a binary tree by swapping every node’s left and right children; return the root.

- **Inputs:** `TreeNode* root`.
- **Output:** inverted tree root.
- **Valid answer:** structure is the mirror of the original.
- **Edges:** empty; single node; skewed; full tree.

## 2. Intuition
A mirror is recursive: invert both subtrees, then swap the child pointers (or swap then invert — same result).

## 3. Brute Force → Optimal
- **Brute:** must visit all nodes anyway — no cheaper exact solution.
- **Optimal:** DFS or BFS swap — O(N) time, O(H) or O(W) space.

## 4. Data Structure / Approach Justification
**Chosen:** post-order-ish DFS: invert children, then swap.

- **vs BFS queue:** same complexity; avoids deep recursion.
- **vs copying into a new tree:** wastes allocations when in-place is allowed.

## 5. Logic Walkthrough
Null → null. Recurse left/right, assign `root->left = right`, `root->right = left`, return root.

## 6. Dry Run
`4` with left `2`, right `7`:
- invert leaves → still leaves
- swap at `4` → left `7`, right `2`
- preorder: `4 7 2`

## 7. Time & Space Complexity
Time **O(N)**. Space **O(H)** recursion. Why: one visit + swap per node (section 4).

## 8. Trade-offs & Alternatives
Recursion is 3–5 lines; BFS preferred for very deep skewed trees. In-place mutation vs returning a new tree.

## 9. Common Mistakes / Edge Cases
Losing a child pointer before saving both; swapping only at the root; forgetting empty base case.

## 10. Interview Follow-ups / Variations
Symmetric tree (101); check if one tree is mirror of another; invert N-ary tree.

## 11. Tags
`binary-tree`, `dfs`, `recursion`, `leetcode-226`, `difficulty:easy`
