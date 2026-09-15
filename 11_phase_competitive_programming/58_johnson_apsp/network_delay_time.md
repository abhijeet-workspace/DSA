# Network Delay Time

## 1. Problem Statement
[LeetCode 743](https://leetcode.com/problems/network-delay-time/) — time for signal from node `k` to reach all nodes (max over shortest paths), or `-1`.

**Pedagogy:** single-source Dijkstra — the inner engine Johnson runs once per vertex after reweighting.

- **Inputs:** `times` `[u,v,w]`, `n`, `k`.
- **Output:** max shortest-path time or `-1`.
- **Edges:** unreachable node; single node.

## 2. Intuition
Dijkstra from `k`; answer max finite distance.

## 3. Brute Force → Optimal
- **Brute:** Bellman–Ford.
- **Optimal:** Dijkstra O(E log V) nonnegative.

## 4. Data Structure / Approach Justification
**Chosen:** binary-heap Dijkstra.

| Alternative | Note |
|-------------|------|
| Floyd | APSP overkill |
| Johnson | Needed if negatives |

## 5. Logic Walkthrough
Relax via priority queue; scan max dist.

## 6. Dry Run
Sample from 2 → answer `2`.

## 7. Time & Space Complexity
Time **O(E log V)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Nonnegative weights required; else use BF / Johnson.

## 9. Common Mistakes / Edge Cases
1-based nodes; returning sum instead of max.

## 10. Interview Follow-ups / Variations
Count nodes reached by time T.

## 11. Tags
`leetcode-743`, `dijkstra`, `sssp`, `difficulty:medium`
