# Shortest Bridge

## 1. Problem Statement
[LeetCode 934](https://leetcode.com/problems/shortest-bridge/) — binary grid with exactly two islands. Flip the minimum number of `0`s to `1`s so the islands connect (4-dir).

- **Inputs:** `grid`.
- **Output:** minimum flips.
- **Valid answer:** shortest water distance between islands.
- **Edges:** islands already adjacent → 0? (constraints say separated by water usually); distance 1.

## 2. Intuition
DFS-paint one island into a multi-source queue, then BFS through water until hitting the other island; levels = flips.

## 3. Brute Force → Optimal
- **Brute:** all pairs of cells between islands — O((RC)²).
- **Optimal:** multi-source BFS O(RC).

## 4. Data Structure / Approach Justification
**Chosen:** DFS collect island A + BFS expansion.

- **vs two-pointer geometry:** not for 4-connected shapes.

## 5. Logic Walkthrough
Find first `1`, DFS mark as `2` and enqueue. BFS: expand to `0`s; when neighbor is `1`, return current distance.

## 6. Dry Run
`[[0,1],[1,0]]` → flip one cell → **1**.

## 7. Time & Space Complexity
Time **O(RC)**. Space **O(RC)**. Why: each cell once (section 4).

## 8. Trade-offs & Alternatives
Mark visited separately if you must preserve grid.

## 9. Common Mistakes / Edge Cases
Starting BFS distance off-by-one; expanding into same island; diagonal bridges.

## 10. Interview Follow-ups / Variations
As Far from Land; shortest bridge with costs; more than two islands.

## 11. Tags
`bfs`, `dfs`, `grid`, `leetcode-934`, `difficulty:medium`
