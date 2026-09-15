# Symmetric Tree

## 1. Problem Statement
[LeetCode 101](https://leetcode.com/problems/symmetric-tree/) — return true if the binary tree is a mirror of itself (left/right reflection).

- **Inputs:** `TreeNode* root`.
- **Output:** `bool`.
- **Valid answer:** left subtree mirrors right subtree at every corresponding pair.
- **Edges:** empty; single node; same values but not mirrored structure.

## 2. Intuition
Mirror check is paired recursion: compare `a->left` with `b->right` and `a->right` with `b->left`, values equal.

## 3. Brute Force → Optimal
- **Brute:** build inverted copy then `isSameTree` — O(N) extra nodes.
- **Optimal:** simultaneous mirror DFS/BFS — O(N) time, O(H) space.

## 4. Data Structure / Approach Justification
**Chosen:** recursive `isMirror(a, b)`.

- **vs BFS two queues:** same asymptotics; recursion is clearer.
- **vs serialize + reverse:** more code, same cost.

## 5. Logic Walkthrough
Null/null → true; one null → false; else values equal and cross-children mirror.

## 6. Dry Run
`[1,2,2,3,4,4,3]`: root OK; (2,2) OK; (3,3) and (4,4) OK → true.
`[1,2,2,null,3,null,3]`: left's right 3 vs right's left null → false.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: each node pair visited once (section 4).

## 8. Trade-offs & Alternatives
Iterative stack of pairs avoids deep recursion on skewed trees.

## 9. Common Mistakes / Edge Cases
Comparing same-side children (same-tree instead of mirror); treating root-only as false.

## 10. Interview Follow-ups / Variations
Same tree (100); invert tree (226); is subtree (572).

## 11. Tags
`binary-tree`, `dfs`, `mirror`, `leetcode-101`, `difficulty:easy`
