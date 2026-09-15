# Convert Sorted Array to Binary Search Tree

## 1. Problem Statement
[LeetCode 108](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) — build a height-balanced BST from ascending `nums`.

- **Inputs:** sorted `vector<int>`.
- **Output:** `TreeNode*` balanced BST.
- **Valid answer:** inorder equals `nums`; height-balanced.
- **Edges:** empty; single; even length (either mid OK).

## 2. Intuition
Mid of range is root → left/right halves become balanced subtrees (like binary search).

## 3. Brute Force → Optimal
- **Brute:** insert sequentially — skewed O(N) height.
- **Optimal:** mid-as-root divide & conquer — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** recursive build on `[lo, hi]`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Sequential insert | Unbalanced |
| Random pivot | Not height-guaranteed |

## 5. Logic Walkthrough
`lo>hi` → null; `mid=(lo+hi)/2`; node=nums[mid]; recurse left/right.

## 6. Dry Run
`[-10,-3,0,5,9]` → root 0; left mid -3; right mid 5/9 depending on mid choice.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(H)=O(log N) recursion for balanced
- Why: each index used once as a node.

## 8. Trade-offs & Alternatives
Choose left or right mid on even lengths — both accepted.

## 9. Common Mistakes / Edge Cases
`lo + (hi-lo)/2` overflow-safe mid; off-by-one ranges; mutating array.

## 10. Interview Follow-ups / Variations
Sorted list to BST (109); balance any BST.

## 11. Tags
`bst`, `divide-conquer`, `leetcode-108`, `difficulty:easy`
