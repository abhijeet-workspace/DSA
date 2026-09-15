# Number of Enclaves

## 1. Problem Statement
[LeetCode 1020](https://leetcode.com/problems/number-of-enclaves/) — binary grid: `1` land, `0` sea. A move is 4-directional onto land. Return the number of land cells that cannot walk off the boundary of the grid.

- **Inputs:** `grid`.
- **Output:** count of enclosed land cells.
- **Valid answer:** lands not connected to any border land.
- **Edges:** all border land; no land; single cell.

## 2. Intuition
Flood-fill (DFS/BFS) from all border lands, sinking them. Remaining `1`s are enclaves.

## 3. Brute Force → Optimal
- **Brute:** for each land, DFS if can reach border — O((RC)²).
- **Optimal:** multi-source flood from border — O(RC).

## 4. Data Structure / Approach Justification
**Chosen:** DFS from border, mutate grid to 0.

- **vs BFS:** same; DFS is short.
- **vs Union-Find with virtual border:** heavier.

## 5. Logic Walkthrough
DFS/clear all lands on first/last row/col. Sum remaining ones.

## 6. Dry Run
Example leaves three interior lands → **3**.

## 7. Time & Space Complexity
Time **O(RC)**. Space **O(RC)** recursion worst. Why: each cell once (section 4).

## 8. Trade-offs & Alternatives
Iterative stack if recursion depth is a concern.

## 9. Common Mistakes / Edge Cases
Forgetting all four borders; counting seas; 8-direction moves.

## 10. Interview Follow-ups / Variations
Surrounded regions; number of closed islands; pacific atlantic.

## 11. Tags
`dfs`, `grid`, `leetcode-1020`, `difficulty:medium`
