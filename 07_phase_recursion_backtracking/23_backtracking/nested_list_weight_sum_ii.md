# Nested List Weight Sum II

## Problem Statement
[LeetCode 364](https://leetcode.com/problems/nested-list-weight-sum-ii/) — weight each integer by `maxDepth - depth + 1` (deepest leaves weight 1).

- **Inputs:** nested list.
- **Output:** inverse weighted sum.
- **Valid answer:** maxDepth is deepest integer nesting.
- **Edges:** flat; single deep path.

## Intuition
Find maxDepth, then DFS with weight `maxDepth - depth + 1`.

## Brute Force → Optimal
- **Two-pass DFS:** O(N) — clear.
- **One-pass trick:** BFS accumulate unweighted sums then reweight — also O(N).

## Data Structure / Approach Justification
**Chosen:** maxDepth pass + weighted DFS.

- **vs single BFS:** fewer lines sometimes, same complexity.

## Logic Walkthrough
Compute max depth of structure; second DFS applies inverse weights.

## Dry Run
`[1,[4,[6]]]` maxD=3 → 1*3 + 4*2 + 6*1 = 17.

## Time & Space Complexity
Time **O(N)**. Space **O(D)**.

## Trade-offs & Alternatives
Level BFS without knowing maxDepth a priori using running totals.

## Common Mistakes / Edge Cases
Using max list depth excluding empty; off-by-one weight.

## Interview Follow-ups / Variations
Weight Sum I (339).

## Tags
`dfs`, `recursion`, `nested`, `leetcode-364`, `difficulty:medium`
