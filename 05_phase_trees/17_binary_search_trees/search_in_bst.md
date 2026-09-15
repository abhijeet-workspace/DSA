# Search in a Binary Search Tree

## 1. Problem Statement
[LeetCode 700](https://leetcode.com/problems/search-in-a-binary-search-tree/) — return the subtree rooted at the node with value `val`, or null.

- **Inputs:** `TreeNode* root`, `int val`.
- **Output:** `TreeNode*`.
- **Valid answer:** BST search path.
- **Edges:** empty; val at root; missing value.

## 2. Intuition
BST invariant: go left if `val < root->val`, else right; equal → found.

## 3. Brute Force → Optimal
- **Brute:** DFS entire tree — O(N).
- **Optimal:** BST walk — O(H).

## 4. Data Structure / Approach Justification
**Chosen:** iterative or recursive BST descent.

| Alternative | Why it loses here |
|-------------|-------------------|
| Full scan | Ignores BST order |

## 5. Logic Walkthrough
While node: if equal return; if val < node go left else right.

## 6. Dry Run
`[4,2,7,1,3]`, val=2 → return subtree rooted at 2.

## 7. Time & Space Complexity
- **Time:** O(H)
- **Space:** O(1) iterative / O(H) recursive
- Why: one path root→target.

## 8. Trade-offs & Alternatives
Recursion is shorter; iteration avoids stack overflow on skewed trees.

## 9. Common Mistakes / Edge Cases
Using `<=` incorrectly; returning node without subtree; searching as if unsorted.

## 10. Interview Follow-ups / Variations
Insert/delete BST; closest BST value.

## 11. Tags
`bst`, `search`, `leetcode-700`, `difficulty:easy`
