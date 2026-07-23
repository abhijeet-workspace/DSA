# Surrounded Regions

## Problem Statement
[LeetCode 130](https://leetcode.com/problems/surrounded-regions/) — capture all `'O'` regions that are **fully** 4-surrounded by `'X'`. Any `'O'` connected to the border cannot be captured.

- **Inputs:** `board[m][n]` of `'X'`/`'O'`.
- **Output:** board mutated in place.
- **Valid answer:** surrounded `'O'` → `'X'`; border-connected `'O'` unchanged.
- **Edges:** empty; all `'O'` on border; single cell.

## Intuition
Anything that can “escape” to the border is safe. Mark safe `'O'`s from the border first (`'E'`), then flip remaining `'O'`→`'X'` and restore `'E'`→`'O'`.

## Brute Force → Optimal
- **Brute:** for every `'O'`, DFS if it can reach border — repeated work.
- **Optimal:** reverse — DFS from border `'O'`s once — **O(MN)**.

## Data Structure / Approach Justification
**Chosen:** boundary DFS + temporary marker `'E'`.

- **vs BFS from border:** identical asymptotics.
- **vs Union-Find with virtual border node:** clever but heavier.

## Logic Walkthrough
DFS from every border `'O'` marking `'E'`. Sweep: `'O'`→`'X'`, `'E'`→`'O'`.

## Dry Run
Inner cluster connected only through interior becomes `'X'`; `'O'` on bottom edge stays `'O'`.

## Time & Space Complexity
Time **O(MN)**. Space **O(MN)** recursion. Why: each cell processed constantly (section 4).

## Trade-offs & Alternatives
Marker char avoids a second visited grid. Iterative BFS if recursion depth worries you.

## Common Mistakes / Edge Cases
Flipping border `'O'`s; only checking immediate neighbors of border; forgetting restore pass.

## Interview Follow-ups / Variations
Number of enclaves (1020); closed islands (1254); paint fill variants.

## Tags
`grid`, `dfs`, `boundary`, `leetcode-130`, `difficulty:medium`
