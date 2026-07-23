# Network Delay Time

## Problem Statement
[LeetCode 743](https://leetcode.com/problems/network-delay-time/) — time for a signal from node `k` to reach all `n` nodes; return the max travel time, or `-1` if some node is unreachable.

- **Inputs:** `times` as `[u,v,w]`, `n`, source `k` (1-indexed).
- **Output:** max shortest-path distance from `k`, or `-1`.
- **Valid answer:** when the last node receives the signal.
- **Edges:** disconnected graph; single node; multiple edges.

## Intuition
Signal propagates along shortest paths. Dijkstra from `k`; the answer is the maximum finite distance.

## Brute Force → Optimal
- **Brute:** Bellman-Ford O(n·E).
- **Optimal:** Dijkstra O(E log V) with non-negative times.

## Data Structure / Approach Justification
**Chosen:** adj list + min-heap Dijkstra.

- **vs Floyd-Warshall:** O(n³), overkill for single source.
- **vs BFS:** wrong unless all weights equal.

## Logic Walkthrough
Build graph. Run Dijkstra. If any `dist[i]==INF` return `-1`; else return max `dist[i]`.

## Dry Run
`n=4`, `k=2`, edges `2→1,2→3,3→4` weight 1: distances `1,0,1,2` → answer 2.

## Time & Space Complexity
Time **O(E log V)**. Space **O(V+E)**. Why: standard heap Dijkstra (section 4).

## Trade-offs & Alternatives
Dense graphs may use O(V²) Dijkstra. Negative weights would need Bellman-Ford (not in this problem).

## Common Mistakes / Edge Cases
0-index vs 1-index nodes; returning sum instead of max; ignoring unreachable nodes.

## Interview Follow-ups / Variations
Path reconstruction; cheapest flights with K stops; count nodes reachable within T.

## Tags
`graph`, `dijkstra`, `shortest-path`, `leetcode-743`, `difficulty:medium`
