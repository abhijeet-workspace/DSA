# Find the City With the Smallest Number of Neighbors at a Threshold Distance

## 1. Problem Statement
[LeetCode 1334](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) — undirected weighted graph. For each city, count others within `distanceThreshold` (shortest path). Return the city with the smallest such count; if tie, the largest city label.

- **Inputs:** `n`, `edges`, `distanceThreshold`.
- **Output:** city id.
- **Valid answer:** Floyd-Warshall or n Dijkstras then scan.
- **Edges:** disconnected; ties.

## 2. Intuition
All-pairs shortest paths, then count neighbors per row under threshold; pick min count with max index on ties.

## 3. Brute Force → Optimal
- **Brute:** Dijkstra from each node O(n(E log n)).
- **Optimal for dense:** Floyd O(n³).

## 4. Data Structure / Approach Justification
**Chosen:** Floyd-Warshall matrix.

- **vs n×Dijkstra:** better for sparse large n.

## 5. Logic Walkthrough
Init dist INF/0/edges. Triple loop relax via k. Count and select city.

## 6. Dry Run
Sample threshold 4 → city **3**.

## 7. Time & Space Complexity
Time **O(n³)**. Space **O(n²)**. Why: Floyd (section 4).

## 8. Trade-offs & Alternatives
Dijkstra per source when n is large and E small.

## 9. Common Mistakes / Edge Cases
Wrong tie-break (need largest label); directed edges; threshold exclusive.

## 10. Interview Follow-ups / Variations
Network delay; find the celebrity; eccentricity of graph.

## 11. Tags
`floyd-warshall`, `shortest-path`, `leetcode-1334`, `difficulty:medium`
