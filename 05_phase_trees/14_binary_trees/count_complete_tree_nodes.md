# Count Complete Tree Nodes

## 1. Problem Statement
[LeetCode 222](https://leetcode.com/problems/count-complete-tree-nodes/) — return the number of nodes in a **complete** binary tree.

- **Inputs:** `TreeNode* root` (complete).
- **Output:** `int` count.
- **Valid answer:** exact node count.
- **Edges:** empty; perfect tree; last level partially filled.

## 2. Intuition
If left-spine height equals right-spine height, the subtree is perfect → `2^h - 1`. Else recurse on children.

## 3. Brute Force → Optimal
- **Brute:** visit every node — O(N).
- **Optimal:** height probes + recurse — O(log² N) on complete trees.

## 4. Data Structure / Approach Justification
**Chosen:** left/right height check then divide-and-conquer.

- **vs full DFS count:** simpler but O(N); suboptimal for the complete guarantee.
- **vs binary search last level:** also O(log² N); similar idea.

## 5. Logic Walkthrough
Compute lh, rh. If equal return `(1<<lh)-1`. Else `1 + count(left) + count(right)`.

## 6. Dry Run
Perfect height-2 tree: lh=rh=2 → 3. Complete 6-node: lh≠rh → 1+count(left)+count(right).

## 7. Time & Space Complexity
Time **O(log² N)**. Space **O(log N)**. Why: O(log N) height work per level of recursion depth O(log N).

## 8. Trade-offs & Alternatives
Bit shift assumes height fits in int range for LC constraints.

## 9. Common Mistakes / Edge Cases
Using this formula on non-complete trees; off-by-one on height definition.

## 10. Interview Follow-ups / Variations
Check completeness (958); count nodes in any tree (trivial DFS).

## 11. Tags
`binary-tree`, `complete-tree`, `binary-search`, `leetcode-222`, `difficulty:easy`
