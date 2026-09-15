# Max Area of Island

## 1. Problem Statement
[LeetCode 695](https://leetcode.com/problems/max-area-of-island/) — in a 0/1 grid, an island is a 4-connected group of `1`s; return the maximum island area (0 if none).

- **Inputs:** `vector<vector<int>> grid`.
- **Output:** `int` max area.
- **Valid answer:** size of largest connected land component.
- **Edges:** empty/all water → 0; single cell; whole grid land.

## 2. Intuition
Flood-fill each unvisited land cell, counting cells as you sink them to `0`. Track the global max count.

## 3. Brute Force → Optimal
- **Brute:** from every land cell DFS without marking — exponential / repeated work.
- **Optimal:** mark visited (in-place) — each cell once — **O(MN)**.

## 4. Data Structure / Approach Justification
**Chosen:** recursive DFS mutating the grid.

- **vs BFS queue:** same asymptotics; iterative safer on huge islands.
- **vs Union-Find:** also **O(MN)**; heavier code for area tracking.

## 5. Logic Walkthrough
`area`: OOB or water → 0; else set 0, return 1 + four directions. Scan grid; update `best`.

## 6. Dry Run
Land at `(0,2),(1,2),(1,3),(2,3)` — one DFS yields 4; `best=4`.

## 7. Time & Space Complexity
Time **O(MN)**. Space **O(MN)** recursion worst case. Why: each cell visited ≤1 (section 4).

## 8. Trade-offs & Alternatives
In-place mutation is interview-friendly; copy grid if immutability required. Iterative stack avoids stack overflow.

## 9. Common Mistakes / Edge Cases
8-directional by mistake; not resetting visited; returning count of islands instead of area.

## 10. Interview Follow-ups / Variations
Number of islands (200); max area with diagonal; closed islands (1254).

## 11. Tags
`grid`, `dfs`, `flood-fill`, `leetcode-695`, `difficulty:medium`
