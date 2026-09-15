# As Far from Land as Possible

## 1. Problem Statement
[LeetCode 1162](https://leetcode.com/problems/as-far-from-land-as-possible/) — n×n grid of land `1` and water `0`. Distance is Manhattan via 4-moves. Return the maximum distance from a water cell to the nearest land, or `-1` if no water or no land.

- **Inputs:** `grid`.
- **Output:** max min-distance, or -1.
- **Valid answer:** farthest water from any land.
- **Edges:** all land / all water → -1.

## 2. Intuition
Multi-source BFS from all lands simultaneously; the last water filled has the maximum distance.

## 3. Brute Force → Optimal
- **Brute:** for each water, BFS to land — O(n⁴).
- **Optimal:** multi-source BFS O(n²).

## 4. Data Structure / Approach Justification
**Chosen:** queue seeded with all lands.

- **vs DP 2-pass Manhattan:** also O(n²).

## 5. Logic Walkthrough
Enqueue all lands. BFS into waters, marking visited. Track level; final level is answer.

## 6. Dry Run
Sample → farthest water distance **2**.

## 7. Time & Space Complexity
Time **O(n²)**. Space **O(n²)**. Why: each cell once (section 4).

## 8. Trade-offs & Alternatives
Two-pass DP without queue for pure Manhattan on grid.

## 9. Common Mistakes / Edge Cases
Returning 0 instead of -1 for uniform grids; off-by-one on last layer.

## 10. Interview Follow-ups / Variations
01 Matrix; rotting oranges; shortest bridge.

## 11. Tags
`bfs`, `multi-source`, `leetcode-1162`, `difficulty:medium`
