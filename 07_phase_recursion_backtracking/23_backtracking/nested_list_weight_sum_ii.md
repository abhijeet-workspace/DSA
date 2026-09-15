# Nested List Weight Sum II

## 1. Problem Statement
[LeetCode 364](https://leetcode.com/problems/nested-list-weight-sum-ii/) — weight each integer by `maxDepth - depth + 1` (deepest leaves weight 1).

- **Inputs:** nested list.
- **Output:** inverse weighted sum.
- **Valid answer:** maxDepth is deepest integer nesting.
- **Edges:** flat; single deep path.

## 2. Intuition
Find maxDepth, then DFS with weight `maxDepth - depth + 1`.

## 3. Brute Force → Optimal
- **Two-pass DFS:** O(N) — clear.
- **One-pass trick:** BFS accumulate unweighted sums then reweight — also O(N).

## 4. Data Structure / Approach Justification
**Chosen:** maxDepth pass + weighted DFS.

- **vs single BFS:** fewer lines sometimes, same complexity.

## 5. Logic Walkthrough
Compute max depth of structure; second DFS applies inverse weights.

## 6. Dry Run
`[1,[4,[6]]]` maxD=3 → 1*3 + 4*2 + 6*1 = 17.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(D)**.

## 8. Trade-offs & Alternatives
Level BFS without knowing maxDepth a priori using running totals.

## 9. Common Mistakes / Edge Cases
Using max list depth excluding empty; off-by-one weight.

## 10. Interview Follow-ups / Variations
Weight Sum I (339).

## 11. Tags
`dfs`, `recursion`, `nested`, `leetcode-364`, `difficulty:medium`
