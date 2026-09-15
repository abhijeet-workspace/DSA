# Longest Increasing Path in a Matrix

## 1. Problem Statement
[LeetCode 329](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) — from any cell, move 4-directionally to a strictly greater neighbor. Return the length of the longest increasing path.

- **Inputs:** `matrix`.
- **Output:** path length (cells).
- **Valid answer:** longest strictly increasing path.
- **Edges:** 1×1; strictly decreasing; plateaus.

## 2. Intuition
DFS from each cell with memoization: LIP(cell)=1+max LIP(greater neighbors). Matrix moves form a DAG by value.

## 3. Brute Force → Optimal
- **Brute:** DFS without memo exponential.
- **Optimal:** memoized DFS / topo DP — O(RC).

## 4. Data Structure / Approach Justification
**Chosen:** DFS + memo matrix.

- **vs Kahn topo on cells:** also O(RC); more setup.

## 5. Logic Walkthrough
If memoized, return. Else try 4 neighbors with greater value; store best length.

## 6. Dry Run
Sample matrix path length **4** (e.g. 1→2→6→9).

## 7. Time & Space Complexity
Time **O(RC)**. Space **O(RC)**. Why: each cell computed once (section 4).

## 8. Trade-offs & Alternatives
Topological DP by sorting cells by value.

## 9. Common Mistakes / Edge Cases
Allowing non-strict increases; missing memo; revisiting without memo.

## 10. Interview Follow-ups / Variations
Path with difference ≤k; count paths; decreasing path.

## 11. Tags
`dfs`, `memoization`, `matrix`, `leetcode-329`, `difficulty:hard`
