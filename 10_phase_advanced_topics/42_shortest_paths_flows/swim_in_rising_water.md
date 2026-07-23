# Swim in Rising Water

## Problem Statement
[LeetCode 778](https://leetcode.com/problems/swim-in-rising-water/) — on an `n×n` elevation grid, you wait until time `t` to enter cells with height ≤ `t`. Find the least `t` to reach `(n-1,n-1)` from `(0,0)`.

- **Inputs:** `grid[i][j]` distinct elevations `0..n²-1` (typical constraint).
- **Output:** minimum feasible time `t`.
- **Valid answer:** min over paths of the max height on the path (including start).
- **Edges:** `n=1`; must visit high cells; 4-directional moves.

## Intuition
Least time equals minimize the bottleneck (max elevation) on a path. Dijkstra/best-first expands the path with smallest current bottleneck.

## Brute Force → Optimal
- **Brute:** try all paths — exponential.
- **Binary search + BFS:** O(N² log N) on threshold.
- **Optimal here:** Dijkstra on bottleneck — O(N² log N).

## Data Structure / Approach Justification
**Chosen:** min-heap of `(maxHeightSoFar, r, c)` + visited.

- **vs binary search + BFS:** same complexity; BS is also interview-common.
- **vs Kruskal on sorted cells:** MST / union-find variant also works.

## Logic Walkthrough
Push `(grid[0][0],0,0)`. Pop smallest `t`; if at end return. Push unseen neighbors with `max(t, grid[nr][nc])`.

## Dry Run
`[[0,2],[1,3]]`: path must eventually take 3 → answer 3 (cannot avoid the max cell in any path to end).

## Time & Space Complexity
Time **O(N² log N)**. Space **O(N²)**. Why: each cell pushed once into heap (section 4).

## Trade-offs & Alternatives
Binary search + BFS may feel simpler. Union-find adding cells by increasing height is elegant.

## Common Mistakes / Edge Cases
Using sum of heights instead of max; marking visited too late (reprocessing).

## Interview Follow-ups / Variations
Path with minimum bottleneck in general graphs; Pac/Atlantic water flow; trap rain water II.

## Tags
`graph`, `dijkstra`, `grid`, `leetcode-778`, `difficulty:hard`
