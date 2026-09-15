# Maximum Binary Tree

## 1. Problem Statement
[LeetCode 654](https://leetcode.com/problems/maximum-binary-tree/) — build a maximum tree from array: root is max element; left subtree from left subarray; right from right.

- **Inputs:** `vector<int> nums` (distinct).
- **Output:** `TreeNode*` root.
- **Valid answer:** recursive Cartesian-tree construction.
- **Edges:** single element; increasing/decreasing arrays (skewed).

## 2. Intuition
Each recursive call finds the max index in range, makes it root, splits left/right ranges.

## 3. Brute Force → Optimal
- **Brute:** scan for max each call — O(N²) worst.
- **Optimal enough here:** same scan (N small on LC); stack Cartesian tree is O(N).

## 4. Data Structure / Approach Justification
**Chosen:** recursive build on `[lo, hi)`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Monotonic stack O(N) | Faster but more code |
| Priority queue of indices | Heavier |

## 5. Logic Walkthrough
1. Empty range → null.
2. Find `mid = argmax nums[lo..hi)`.
3. `node->left = build(lo,mid)`, `right = build(mid+1,hi)`.

## 6. Dry Run
`[3,2,1,6,0,5]`: max 6 root; left `[3,2,1]` → 3; right `[0,5]` → 5 with left 0.

## 7. Time & Space Complexity
- **Time:** O(N²) worst scan / O(N) with stack
- **Space:** O(N) tree + O(H) recursion
- Why: each range scans its span in the simple version.

## 8. Trade-offs & Alternatives
Monotonic decreasing stack builds parents in one pass — interview follow-up.

## 9. Common Mistakes / Edge Cases
Off-by-one on ranges; mutating shared arrays incorrectly; assuming sorted input.

## 10. Interview Follow-ups / Variations
Cartesian tree; maximum binary tree II (998).

## 11. Tags
`binary-tree`, `dfs`, `divide-conquer`, `leetcode-654`, `difficulty:medium`
