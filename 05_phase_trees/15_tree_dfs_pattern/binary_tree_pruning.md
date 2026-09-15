# Binary Tree Pruning

## 1. Problem Statement
[LeetCode 814](https://leetcode.com/problems/binary-tree-pruning/) — prune every subtree that contains no `1`; return the new root.

- **Inputs:** `TreeNode*` with values 0/1.
- **Output:** pruned `TreeNode*`.
- **Valid answer:** every remaining subtree contains ≥ one `1`.
- **Edges:** all zeros → null; root is 0 but child has 1; already all ones.

## 2. Intuition
Postorder: prune children first; if node is 0 and both children null, delete node (return null).

## 3. Brute Force → Optimal
- **Brute:** compute “contains one” separately then cut — two passes.
- **Optimal:** one postorder returning possibly-null subtree — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** recursive prune returning new child pointers.

| Alternative | Why it loses here |
|-------------|-------------------|
| Parent pointer deletion | More mutation bookkeeping |
| Build new tree of ones | Extra allocations |

## 5. Logic Walkthrough
1. Null → null.
2. `left = prune(left)`, `right = prune(right)`.
3. If `val==0 && !left && !right` → null; else return node.

## 6. Dry Run
`[1,0,1,0,0,0,1]` → left zero-subtree removed; right keeps path to 1.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(H)
- Why: each node visited once.

## 8. Trade-offs & Alternatives
Same pattern as “delete leaves with value” / filter subtrees.

## 9. Common Mistakes / Edge Cases
Pruning before recursing children; keeping a 0 that still has a 1 descendant incorrectly deleted.

## 10. Interview Follow-ups / Variations
Delete leaves with given value (1325); trim BST (669).

## 11. Tags
`binary-tree`, `dfs`, `prune`, `leetcode-814`, `difficulty:medium`
