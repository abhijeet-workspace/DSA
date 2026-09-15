# Count Sub Islands

## 1. Problem Statement
[LeetCode 1905](https://leetcode.com/problems/count-sub-islands/) — two binary grids. An island in `grid2` is a sub-island if every one of its land cells is land in `grid1`. Return the number of sub-islands.

- **Inputs:** `grid1`, `grid2` same shape.
- **Output:** count.
- **Valid answer:** islands of grid2 fully covered by grid1 land.
- **Edges:** identical grids; no overlap; single cell.

## 2. Intuition
DFS each island in grid2; track whether every visited cell is 1 in grid1; sink grid2 lands while traversing.

## 3. Brute Force → Optimal
- **Brute/Optimal:** one DFS per island O(RC).

## 4. Data Structure / Approach Justification
**Chosen:** destructive DFS on grid2 with boolean AND coverage check.

- **vs marking visited separately:** more memory.

## 5. Logic Walkthrough
For each unvisited land in grid2, DFS returns whether all cells covered; increment if true.

## 6. Dry Run
LC sample → **3** sub-islands.

## 7. Time & Space Complexity
Time **O(RC)**. Space **O(RC)** recursion. Why: each cell once (section 4).

## 8. Trade-offs & Alternatives
BFS flood fill; first mark invalid islands that touch grid1 water.

## 9. Common Mistakes / Edge Cases
Counting if any cell matches instead of all; not sinking visited lands.

## 10. Interview Follow-ups / Variations
Number of islands; max area; island perimeter.

## 11. Tags
`dfs`, `grid`, `leetcode-1905`, `difficulty:medium`
