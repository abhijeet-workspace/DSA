# Trim a Binary Search Tree

## 1. Problem Statement
[LeetCode 669](https://leetcode.com/problems/trim-a-binary-search-tree/) — trim BST so all nodes lie in `[low, high]`.

- **Inputs:** `TreeNode* root`, `int low`, `int high`.
- **Output:** trimmed `TreeNode*`.
- **Valid answer:** BST of values inside inclusive range.
- **Edges:** all trimmed; root out of range; empty.

## 2. Intuition
If root `< low`, entire left is too small → return trim(right). If root `> high`, return trim(left). Else trim both children.

## 3. Brute Force → Optimal
- **Brute:** collect valid values rebuild — O(N).
- **Optimal:** in-place recursive trim — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** BST-guided prune recursion.

| Alternative | Why it loses here |
|-------------|-------------------|
| Full rebuild | Extra allocations |
| Ignoring BST order | Wrong cuts |

## 5. Logic Walkthrough
Null→null; out-of-range → recurse only viable side; else fix left/right pointers.

## 6. Dry Run
`[1,0,2]`, low=1,high=2 → drop 0; root 1 with right 2.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(H)
- Why: each node visited ≤ once.

## 8. Trade-offs & Alternatives
Same idea as delete-out-of-range keys.

## 9. Common Mistakes / Edge Cases
Deleting root without relinking; exclusive bounds; not trimming both sides when root valid.

## 10. Interview Follow-ups / Variations
Delete node BST; range sum BST.

## 11. Tags
`bst`, `prune`, `leetcode-669`, `difficulty:medium`
