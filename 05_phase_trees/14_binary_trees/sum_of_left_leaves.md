# Sum of Left Leaves

## 1. Problem Statement
[LeetCode 404](https://leetcode.com/problems/sum-of-left-leaves/) — sum values of all **left leaves** (a leaf that is the left child of its parent).

- **Inputs:** `TreeNode* root`.
- **Output:** `int`.
- **Valid answer:** right leaves and non-leaves contribute 0.
- **Edges:** empty; root-only (0); left-skewed.

## 2. Intuition
When descending, know whether the next child is a left child; if it is a leaf, add it.

## 3. Brute Force → Optimal
- **Brute:** collect all leaves with a parent-side flag.
- **Optimal:** DFS checking `isLeaf(root->left)` then recurse.

## 4. Data Structure / Approach Justification
**Chosen:** recursive DFS with left-leaf check.

- **vs BFS:** same O(N); DFS is shorter.
- **vs summing all leaves:** wrong — excludes right leaves.

## 5. Logic Walkthrough
If left child is leaf, add its val; else recurse left. Always recurse right.

## 6. Dry Run
`[3,9,20,null,null,15,7]`: left leaf 9 + left leaf 15 = 24.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: visit each node once.

## 8. Trade-offs & Alternatives
Pass a `isLeft` boolean into DFS as an alternate style.

## 9. Common Mistakes / Edge Cases
Counting root as a left leaf; counting non-leaf left children.

## 10. Interview Follow-ups / Variations
Sum of root-to-leaf numbers (129); binary tree tilt (563).

## 11. Tags
`binary-tree`, `dfs`, `leaves`, `leetcode-404`, `difficulty:easy`
