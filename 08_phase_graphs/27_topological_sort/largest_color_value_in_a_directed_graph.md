# Largest Color Value in a Directed Graph

## 1. Problem Statement
[LeetCode 1857](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/) — directed graph, node colors `a-z`. A path's color value is the max frequency of a single color on it. Return the largest color value among all paths, or `-1` if a cycle exists.

- **Inputs:** `colors`, `edges`.
- **Output:** max color value or -1.
- **Valid answer:** DP on DAG topo; cycle → -1.
- **Edges:** single node; cycle; long path same color.

## 2. Intuition
Kahn topo while maintaining for each node the best count of each color along any path ending at that node.

## 3. Brute Force → Optimal
- **Brute:** enumerate paths — exponential.
- **Optimal:** topo DP O((n+E)·26).

## 4. Data Structure / Approach Justification
**Chosen:** Kahn + `dp[u][26]`.

- **vs DFS with states:** also detects cycles; DP similar.

## 5. Logic Walkthrough
Process zero-indegree nodes; increment own color; push maxima to children; if not all nodes processed, cycle.

## 6. Dry Run
Sample `"abaca"` → largest value **3**.

## 7. Time & Space Complexity
Time **O((n+E)·26)**. Space **O(n·26)**. Why: topo DP (section 4).

## 8. Trade-offs & Alternatives
DFS memo with 3-color cycle marking.

## 9. Common Mistakes / Edge Cases
Not detecting cycles; resetting dp instead of taking max; 0-index edges.

## 10. Interview Follow-ups / Variations
Longest path in DAG; maximum path quality.

## 11. Tags
`topological-sort`, `dp`, `leetcode-1857`, `difficulty:hard`
