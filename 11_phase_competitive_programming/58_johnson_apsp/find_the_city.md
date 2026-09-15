# Find the City

## 1. Problem Statement
[LeetCode 1334](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) — among cities reachable within `distanceThreshold`, return the city with fewest such neighbors (ties → largest id).

- **Inputs:** `n`, weighted undirected edges, threshold.
- **Output:** city id.
- **Edges:** disconnected; threshold 0.

## 2. Intuition
APSP then count neighbors per row under threshold.

## 3. Brute Force → Optimal
- **Brute:** Dijkstra from each city.
- **This file:** Floyd O(n³) (n≤100).
- **Sparse:** Johnson.

## 4. Data Structure / Approach Justification
**Chosen:** Floyd–Warshall for dense small n.

| Alternative | Note |
|-------------|------|
| n×Dijkstra | Sparse |
| Johnson | Negatives + sparse |

## 5. Logic Walkthrough
Fill dist matrix; Floyd; count; track min count with max id.

## 6. Dry Run
LC sample → city `3`.

## 7. Time & Space Complexity
Time **O(n³)**. Space **O(n²)**.

## 8. Trade-offs & Alternatives
Motivates choosing Floyd vs Johnson by density.

## 9. Common Mistakes / Edge Cases
Using `<` instead of `≤` threshold; wrong tie-break.

## 10. Interview Follow-ups / Variations
Directed version; dynamic edges.

## 11. Tags
`leetcode-1334`, `floyd-warshall`, `apsp`, `difficulty:medium`
