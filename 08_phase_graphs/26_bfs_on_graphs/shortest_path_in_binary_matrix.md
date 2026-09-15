# Shortest Path in Binary Matrix

## 1. Problem Statement
[LeetCode 1091](https://leetcode.com/problems/shortest-path-in-binary-matrix/) — length of shortest clear path from top-left to bottom-right on a binary grid; move to any of 8 neighbors if cell is `0`.

- **Inputs:** `n×n` grid of `0`/`1`.
- **Output:** path length (cells visited), or `-1`.
- **Valid answer:** minimum number of cells in a clear path.
- **Edges:** blocked start/end; `n=1`; no path.

## 2. Intuition
Unweighted grid → BFS. Expand 8 directions; first time you reach the end is shortest.

## 3. Brute Force → Optimal
- **Brute:** DFS all paths — exponential.
- **Optimal:** 8-dir BFS — **O(n²)**.

## 4. Data Structure / Approach Justification
**Chosen:** BFS queue; overwrite grid with distance (or use visited).

- **vs Dijkstra:** unnecessary (all edges weight 1).
- **vs 4-dir only:** wrong — problem allows diagonals.

## 5. Logic Walkthrough
If corners blocked, `-1`. BFS from `(0,0)` with dist 1. For each of 8 neighbors that are `0`, set dist+1 and enqueue. Hit end → return.

## 6. Dry Run
`[[0,1],[1,0]]`: diagonal step `(0,0)→(1,1)` length `2`.

## 7. Time & Space Complexity
Time **O(n²)**. Space **O(n²)** queue. Why: each cell enqueued ≤ once (section 4).

## 8. Trade-offs & Alternatives
Separate visited matrix if grid must stay intact. A* with remaining chebyshev distance is optional polish.

## 9. Common Mistakes / Edge Cases
Using 4-dir; returning edge count instead of cell count; forgetting `n=1` → `1`.

## 10. Interview Follow-ups / Variations
4-dir only; obstacles with cost; k obstacle removals (1293).

## 11. Tags
`grid`, `bfs`, `shortest-path`, `leetcode-1091`, `difficulty:medium`
