# Nested List Weight Sum

## 1. Problem Statement
[LeetCode 339](https://leetcode.com/problems/nested-list-weight-sum/) — sum each integer × its depth (outermost depth 1).

- **Inputs:** nested list of NestedInteger.
- **Output:** weighted sum.
- **Valid answer:** depth increases entering a list.
- **Edges:** flat list; deep single path; empty lists.

## 2. Intuition
DFS with depth parameter; multiply integers; recurse into lists with depth+1.

## 3. Brute Force → Optimal
- **Brute / Optimal:** one DFS or BFS by level — O(N) over all integers/lists.

## 4. Data Structure / Approach Justification
**Chosen:** recursive DFS.

- **vs BFS queue of (list, depth):** iterative equivalent.

## 5. Logic Walkthrough
`dfs(list, d)`: for each elem, add `val*d` or `dfs(child, d+1)`.

## 6. Dry Run
`[1,[4,[6]]]`: 1*1 + 4*2 + 6*3 = 27.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(D)** recursion depth.

## 8. Trade-offs & Alternatives
BFS levels if recursion depth worries.

## 9. Common Mistakes / Edge Cases
Starting depth at 0; counting list nodes.

## 10. Interview Follow-ups / Variations
Weight Sum II (364); flatten iterator (341).

## 11. Tags
`dfs`, `recursion`, `nested`, `leetcode-339`, `difficulty:medium`
