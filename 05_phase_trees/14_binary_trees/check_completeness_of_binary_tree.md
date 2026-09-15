# Check Completeness of a Binary Tree

## 1. Problem Statement
[LeetCode 958](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) — return true if the binary tree is **complete** (every level full except possibly the last, filled left-to-right).

- **Inputs:** `TreeNode* root`.
- **Output:** `bool`.
- **Valid answer:** BFS order has no node after the first null gap.
- **Edges:** empty; single node; missing left but present right; last level sparse left-aligned.

## 2. Intuition
In level-order of a complete tree, once a null child appears, every later node must also be null (no more real nodes).

## 3. Brute Force → Optimal
- **Brute:** compute heights/positions and verify index rules — more bookkeeping.
- **Optimal:** BFS; after first null, reject any subsequent non-null — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** queue BFS with a `seenNull` flag.

| Alternative | Why it loses here |
|-------------|-------------------|
| Index-array mapping | Correct but heavier |
| DFS only | Harder to enforce left-to-right last level |

## 5. Logic Walkthrough
1. Push root; while queue: pop `u`.
2. If `u` is null → set `seenNull`; continue.
3. If `seenNull` already → return false.
4. Push `u->left` and `u->right` (including nulls).
5. Exhaust queue → true.

## 6. Dry Run
`[1,2,3,4,5,6]`: nulls only after last real nodes → true.
`[1,2,3,4,5,null,7]`: after null under 3-left, later 7 appears → false.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(W) queue width
- Why: each node (and sentinel nulls) processed once.

## 8. Trade-offs & Alternatives
Stop early on failure. Count nodes + max index check is equivalent.

## 9. Common Mistakes / Edge Cases
Not enqueueing nulls; treating perfect trees only; allowing right child without left.

## 10. Interview Follow-ups / Variations
Count complete tree nodes (222); heap-index mapping; serialize completeness.

## 11. Tags
`binary-tree`, `bfs`, `completeness`, `leetcode-958`, `difficulty:medium`
