# Minimum Obstacle Removal to Reach Corner

## Problem Statement
[LeetCode 2290](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/) — grid `0` empty / `1` obstacle. Moving 4-dir; removing an obstacle costs `1`. Min removals to go from `(0,0)` to `(m-1,n-1)`.

- **Inputs:** binary `grid`.
- **Output:** minimum removals.
- **Valid answer:** shortest path treating obstacles as weight-1 edges.
- **Edges:** clear path → `0`; start/end obstacle; dense walls.

## Intuition
0-1 BFS: step onto `0` costs 0, onto `1` costs 1. Deque orders by current removals.

## Brute Force → Optimal
- **Brute:** Dijkstra — OK.
- **Optimal:** 0-1 BFS — **O(RC)**.

## Data Structure / Approach Justification
**Chosen:** deque + `dist` = min removals to cell.

- **vs BFS layers by removals:** equivalent idea.
- **vs DFS:** not optimal for shortest.

## Logic Walkthrough
Init `dist[0][0]=grid[0][0]`. Relax neighbors with `+grid[nr][nc]`; push_front if cost 0 else push_back.

## Dry Run
`[[0,1,1],[1,1,0],[1,1,0]]`: need remove `2`. Second sample has a clear corridor → `0`.

## Time & Space Complexity
Time **O(RC)**. Space **O(RC)**. Why: 0-1 BFS (section 4).

## Trade-offs & Alternatives
Dijkstra if future costs become arbitrary. Binary search on removals + BFS also works.

## Common Mistakes / Edge Cases
Charging cost on leaving instead of entering; ignoring start cell obstacle.

## Interview Follow-ups / Variations
Shortest path in binary matrix (1091); k obstacle removals (1293); arrow grid (1368).

## Tags
`grid`, `0-1-bfs`, `shortest-path`, `leetcode-2290`, `difficulty:hard`
