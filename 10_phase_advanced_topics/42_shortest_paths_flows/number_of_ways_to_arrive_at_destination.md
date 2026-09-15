# Number of Ways to Arrive at Destination

## Problem Statement
[LeetCode 1976](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) — undirected weighted roads; count shortest paths from `0` to `n-1` modulo `10^9+7`.

- **Inputs:** `n`, `roads` `[u,v,time]`.
- **Output:** number of min-time paths mod `1e9+7`.
- **Valid answer:** count of distinct shortest routes.
- **Edges:** unique shortest; many equal; disconnected → `0`.

## Intuition
Run Dijkstra for distances. When relaxing: stricter distance resets `ways[v]=ways[u]`; equal distance adds `ways[u]` (mod).

## Brute Force → Optimal
- **Brute:** DFS all paths — exponential.
- **Optimal:** Dijkstra + ways — **O((V+E) log V)**.

## Data Structure / Approach Justification
**Chosen:** min-heap Dijkstra with `dist[]` and `ways[]`.

- **vs DP on DAG of shortest-path DAG:** needs extra pass after distances known.
- **vs BFS:** wrong unless all weights equal.

## Logic Walkthrough
`dist[0]=0`, `ways[0]=1`. Pop `u`; for edge `u→v` weight `w`: if `d+w < dist[v]` update + push; elif equal, add ways mod.

## Dry Run
LC sample `n=7`: four distinct shortest paths → `4`.

## Time & Space Complexity
Time **O((V+E) log V)**. Space **O(V+E)**. Why: heap Dijkstra (section 4).

## Trade-offs & Alternatives
Use `long long` for times (sums can exceed `int`). Process equal-dist additions carefully when using decrease-key variants.

## Common Mistakes / Edge Cases
`int` overflow on distance; forgetting modulo on add; double-counting via stale heap without `d > dist[u]` skip (ways still OK if only update on improve/equal from settled—stale can add twice; skip stale pops).

## Interview Follow-ups / Variations
Reconstruct one path; count paths with length ≤ k; directed graph.

## Tags
`graph`, `dijkstra`, `counting`, `leetcode-1976`, `difficulty:medium`
