# Sum of Distances in Tree

## Problem Statement
[LeetCode 834](https://leetcode.com/problems/sum-of-distances-in-tree/) — for each node, sum of distances to all others in undirected tree.

- **Inputs:** `n`, `edges`.
- **Output:** `ans[i]` sum distances from i.
- **Valid answer:** rerooting DP.
- **Edges:** n=1; line tree.

## Intuition
Two DFS: subtree sizes + root answer; reroot to children.

## Brute Force → Optimal
- **Brute:** BFS from each O(N^2).
- **Optimal:** O(N) reroot.

## Data Structure / Approach Justification
**Chosen:** count[sub], ans[0], then ans[child]=ans[parent]-count[child]+(n-count[child]).

## Logic Walkthrough
Build adj; postorder then preorder.

## Dry Run
n=6 sample -> [8,12,6,10,10,10].

## Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## Trade-offs & Alternatives
Classic rerooting template.

## Common Mistakes / Edge Cases
Wrong count update.

## Interview Follow-ups / Variations
Tree reroot DP.

## Tags
`tree-dp`, `reroot`, `leetcode-834`, `difficulty:hard`
