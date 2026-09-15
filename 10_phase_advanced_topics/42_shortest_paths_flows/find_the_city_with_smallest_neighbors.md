# Find the City With the Smallest Number of Neighbors

## Problem Statement
[LeetCode 1334](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) — undirected weighted graph; for each city count others within `distanceThreshold` shortest-path distance. Return the city with the smallest count; ties → largest city id.

- **Inputs:** `n`, `edges` `[u,v,w]`, `distanceThreshold`.
- **Output:** city index.
- **Valid answer:** argmin of reachable counts (max id on tie).
- **Edges:** disconnected cities; threshold `0`; dense small `n`.

## Intuition
Need all-pairs distances. Floyd-Warshall is ideal for small `n` (≤100). Then scan counts.

## Brute Force → Optimal
- **Brute:** Dijkstra from each node — **O(n·(E log V))**; fine too.
- **Optimal for small n:** Floyd **O(n³)**.

## Data Structure / Approach Justification
**Chosen:** Floyd-Warshall distance matrix.

- **vs n× Dijkstra:** better when graph dense / `n` tiny.
- **vs Bellman per source:** slower with nonneg weights.

## Logic Walkthrough
Init `dist` INF, zeros on diagonal, undirected edges. Triple loop `k,i,j` relax. Count `dist[i][j]≤threshold`; track min count / max id.

## Dry Run
Sample `n=4`, threshold `4`: city `3` has fewest neighbors in range.

## Time & Space Complexity
Time **O(n³)**. Space **O(n²)**. Why: classic Floyd (section 4).

## Trade-offs & Alternatives
Prefer multi-source Dijkstra if `n` large and sparse.

## Common Mistakes / Edge Cases
Forgetting undirected double insert; tie-break smallest id; overflow — use large INF carefully.

## Interview Follow-ups / Variations
Directed version; count exactly at distance; reconstruct paths.

## Tags
`graph`, `floyd-warshall`, `shortest-path`, `leetcode-1334`, `difficulty:medium`
