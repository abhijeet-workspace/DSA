# Number of Islands

## 1. Problem Statement
[LeetCode 200](https://leetcode.com/problems/number-of-islands/) — count islands of `'1'`s (land) surrounded by `'0'`s (water); 4-directional connectivity.

- **Inputs:** `vector<vector<char>> grid`.
- **Output:** number of islands.
- **Valid answer:** count of connected land components.
- **Edges:** empty; all water; all land; single cell.

## 2. Intuition
Each unvisited `'1'` starts a new island; DFS/BFS floods the entire component so you don’t recount those cells.

## 3. Brute Force → Optimal
- **Brute:** Union-Find over land cells — also **O(RC)** with more code.
- **Optimal:** DFS sink or BFS — visit each cell once — **O(RC)**.

## 4. Data Structure / Approach Justification
**Chosen:** in-place DFS marking `'1'→'0'`.

- **vs BFS:** same complexity; queue uses heap memory.
- **vs separate visited matrix:** safer if grid must stay intact.

## 5. Logic Walkthrough
Scan cells; on `'1'`, `++count` and DFS four ways sinking land to `'0'`.

## 6. Dry Run
Two-block top-left + lone middle + bottom-right pair → three DFS starts → `3`.

## 7. Time & Space Complexity
Time **O(RC)**. Space **O(RC)** recursion worst case. Why: each cell ≤ once (section 4).

## 8. Trade-offs & Alternatives
Union-Find useful when islands merge online. Copy grid if mutation forbidden.

## 9. Common Mistakes / Edge Cases
Counting every `'1'` without flood; 8-dir vs 4-dir; empty `grid[0]` access.

## 10. Interview Follow-ups / Variations
Max area (695); number of closed islands (1254); distinct island shapes (694).

## 11. Tags
`grid`, `dfs`, `connected-components`, `leetcode-200`, `difficulty:medium`
