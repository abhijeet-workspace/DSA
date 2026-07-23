# Longest Increasing Path in a Matrix

## Problem Statement
[LeetCode 329](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) — longest strictly increasing path length; moves 4-directionally.

- **Inputs:** `vector<vector<int>> matrix`.
- **Output:** `int` path length (cells).
- **Valid answer:** max over starts; neighbors must be strictly greater.
- **Edges:** 1×1 → 1; all equal → 1; plateaus.

## Intuition
Strict increases make the grid a DAG. Memoized DFS: from each cell, take `1 + max` over valid neighbors.

## Brute Force → Optimal
- **Brute:** DFS without memo — exponential overlap.
- **Optimal:** DFS + memo each cell once — O(M·N).

## Data Structure / Approach Justification
**Chosen:** `memo[i][j]` = best path starting at `(i,j)`.

- **vs topological DP on indegrees:** same O(MN); more boilerplate.
- **vs plain BFS:** harder because path length depends on value order, not level.

## Logic Walkthrough
If memoized, return. Else try 4 neighbors with larger value; store `1 + max`. Launch from every cell; track global max.

## Dry Run
`[[9,9,4],[6,6,8],[2,1,1]]`: path `1→2→6→9` length **4**.

## Time & Space Complexity
Time **O(MN)**. Space **O(MN)** memo (+ recursion). Why: each cell computed once (section 4).

## Trade-offs & Alternatives
Memo DFS is standard. Topo Kahn-style DP avoids deep recursion on large grids.

## Common Mistakes / Edge Cases
Allowing non-strict increases; forgetting memo; treating as contiguous subsequence in one row only.

## Interview Follow-ups / Variations
Print one such path; obstacles; k-increasing path constraints.

## Tags
`grid-dp`, `dfs-memo`, `dag`, `leetcode-329`, `difficulty:hard`
