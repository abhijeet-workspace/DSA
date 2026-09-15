# Increasing Order Search Tree

## 1. Problem Statement
[LeetCode 897](https://leetcode.com/problems/increasing-order-search-tree/) — rearrange BST so it becomes a right-skewed increasing chain (inorder), all left null.

- **Inputs:** `TreeNode* root`.
- **Output:** new chain root (smallest).
- **Valid answer:** inorder values as right spine.
- **Edges:** empty; single; already skewed.

## 2. Intuition
Inorder traversal relinking: keep `tail` of the growing right chain.

## 3. Brute Force → Optimal
- **Brute:** collect values, build new chain — O(N) extra nodes.
- **Optimal:** inorder relink in place — O(N) time, O(H) stack.

## 4. Data Structure / Approach Justification
**Chosen:** inorder DFS with `tail` pointer / dummy head.

| Alternative | Why it loses here |
|-------------|-------------------|
| Rebuild from values | Extra allocations |
| Morris | Possible but complex |

## 5. Logic Walkthrough
Dummy → inorder: set `tail->right = node`, `node->left=null`, advance tail.

## 6. Dry Run
`[5,3,6,2,4,null,8]` → `2→3→4→5→6→8` right chain.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(H)
- Why: classic inorder visit.

## 8. Trade-offs & Alternatives
Collecting nodes in vector then linking is clearer for interviews under time pressure.

## 9. Common Mistakes / Edge Cases
Forgetting clear `left`; losing original right before recurse; wrong new root.

## 10. Interview Follow-ups / Variations
Flatten binary tree to list (114); BST to sorted DLL.

## 11. Tags
`bst`, `inorder`, `leetcode-897`, `difficulty:easy`
