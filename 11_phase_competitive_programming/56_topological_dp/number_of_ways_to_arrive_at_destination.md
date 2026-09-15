# Number of Ways to Arrive at Destination

## 1. Problem Statement
[LeetCode 1976](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) — count shortest paths from `0` to `n-1` modulo `10^9+7`.

**Note:** not LC 1977; ways-on-shortest-paths (Dijkstra DP), adjacent to topo path counting on DAGs of settling order.

- **Inputs:** `n`, undirected weighted `roads`.
- **Output:** ways mod 1e9+7.
- **Edges:** unique shortest path; disconnected → 0.

## 2. Intuition
When Dijkstra finds equal-cost edge into `v`, add ways; on strict improvement, reset ways.

## 3. Brute Force → Optimal
- **Brute:** enumerate simple paths.
- **Optimal:** Dijkstra + ways — O(E log V).

## 4. Data Structure / Approach Justification
**Chosen:** binary-heap Dijkstra with `ways[]`.

| Alternative | Note |
|-------------|------|
| DAG of only shortest-path edges + topo | Equivalent second pass |

## 5. Logic Walkthrough
Relax; on `<` reset ways; on `==` add ways mod.

## 6. Dry Run
LC sample → `4`.

## 7. Time & Space Complexity
Time **O(E log V)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
After Dijkstra, shortest-path subgraph is a DAG — topo DP recovers the same count.

## 9. Common Mistakes / Edge Cases
Adding ways on `>` edges; missing modulo.

## 10. Interview Follow-ups / Variations
Count paths within factor of shortest.

## 11. Tags
`leetcode-1976`, `dijkstra`, `path-counting`, `difficulty:medium`
