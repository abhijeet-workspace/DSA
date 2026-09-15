# Range Sum of BST

## 1. Problem Statement
[LeetCode 938](https://leetcode.com/problems/range-sum-of-bst/) — sum values of all nodes with `low ≤ val ≤ high`.

- **Inputs:** `TreeNode* root`, `int low`, `int high`.
- **Output:** `int` sum.
- **Valid answer:** sum over inclusive range.
- **Edges:** empty range match; all nodes inside; none inside.

## 2. Intuition
BST prune: if `val < low` skip left; if `val > high` skip right; else add val and search both.

## 3. Brute Force → Optimal
- **Brute:** visit all nodes — O(N).
- **Optimal:** pruned DFS — O(N) worst, often less.

## 4. Data Structure / Approach Justification
**Chosen:** recursive range prune.

| Alternative | Why it loses here |
|-------------|-------------------|
| Full traversal | Wastes pruned subtrees |
| Inorder + binary search ends | More code |

## 5. Logic Walkthrough
Null→0; if val in range add; recurse needed sides only.

## 6. Dry Run
`[10,5,15,3,7,null,18]`, low=7,high=15 → 10+7+15=**32**.

## 7. Time & Space Complexity
- **Time:** O(N) worst
- **Space:** O(H)
- Why: pruned when possible.

## 8. Trade-offs & Alternatives
Iterative stack same prune rules.

## 9. Common Mistakes / Edge Cases
Exclusive bounds; always recursing both sides; int overflow (use long if needed).

## 10. Interview Follow-ups / Variations
Trim BST; count nodes in range.

## 11. Tags
`bst`, `dfs`, `leetcode-938`, `difficulty:easy`
