# Nested List Weight Sum

## Problem Statement
[LeetCode 339](https://leetcode.com/problems/nested-list-weight-sum/) — sum each integer × its depth (outermost depth 1).

- **Inputs:** nested list of NestedInteger.
- **Output:** weighted sum.
- **Valid answer:** depth increases entering a list.
- **Edges:** flat list; deep single path; empty lists.

## Intuition
DFS with depth parameter; multiply integers; recurse into lists with depth+1.

## Brute Force → Optimal
- **Brute / Optimal:** one DFS or BFS by level — O(N) over all integers/lists.

## Data Structure / Approach Justification
**Chosen:** recursive DFS.

- **vs BFS queue of (list, depth):** iterative equivalent.

## Logic Walkthrough
`dfs(list, d)`: for each elem, add `val*d` or `dfs(child, d+1)`.

## Dry Run
`[1,[4,[6]]]`: 1*1 + 4*2 + 6*3 = 27.

## Time & Space Complexity
Time **O(N)**. Space **O(D)** recursion depth.

## Trade-offs & Alternatives
BFS levels if recursion depth worries.

## Common Mistakes / Edge Cases
Starting depth at 0; counting list nodes.

## Interview Follow-ups / Variations
Weight Sum II (364); flatten iterator (341).

## Tags
`dfs`, `recursion`, `nested`, `leetcode-339`, `difficulty:medium`
