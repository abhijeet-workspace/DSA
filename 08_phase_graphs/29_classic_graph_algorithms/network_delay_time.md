# Network Delay Time

## 1. Problem Statement
[LeetCode 743](https://leetcode.com/problems/network-delay-time/) — directed weighted edges `times[i]=[u,v,w]`. Send signal from node `k`. Return how long until all `n` nodes receive it (max over shortest paths), or `-1` if impossible.

- **Inputs:** `times`, `n`, `k`.
- **Output:** max shortest-path distance from k, or -1.
- **Valid answer:** Dijkstra/Bellman-Ford single-source.
- **Edges:** unreachable node; zero weights; dense graph.

## 2. Intuition
Shortest paths from `k`; answer is the maximum finite distance among nodes 1..n.

## 3. Brute Force → Optimal
- **Brute:** Bellman-Ford O(nE).
- **Optimal:** Dijkstra O((n+E) log n) with non-negative weights.

## 4. Data Structure / Approach Justification
**Chosen:** binary-heap Dijkstra + adj list.

- **vs Floyd:** O(n³) all-pairs overkill.
- **vs BFS:** wrong for positive varying weights.

## 5. Logic Walkthrough
Init dist[k]=0. PQ relaxes edges. Track max dist; if any INF return -1.

## 6. Dry Run
Sample from 2 → times to all → **2**.

## 7. Time & Space Complexity
Time **O((n+E) log n)**. Space **O(n+E)**. Why: Dijkstra (section 4).

## 8. Trade-offs & Alternatives
Dial's algorithm for small weights; SPFA (not preferred).

## 9. Common Mistakes / Edge Cases
1-index nodes; not skipping stale PQ entries; negative weights (invalid for Dijkstra).

## 10. Interview Follow-ups / Variations
Cheapest flights within K stops; path with max probability.

## 11. Tags
`dijkstra`, `shortest-path`, `leetcode-743`, `difficulty:medium`
