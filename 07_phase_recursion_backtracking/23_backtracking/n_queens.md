# N-Queens

## Problem Statement
[LeetCode 51](https://leetcode.com/problems/n-queens/) — place `n` queens on an `n×n` board so no two attack; return all distinct board configurations.

- **Inputs:** `int n` (board size / queen count).
- **Output:** `vector<vector<string>>` — each board uses `'Q'` / `'.'`.
- **Valid answer:** every solution; order of boards does not matter.
- **Edges:** `n=1` → `[["Q"]]`; `n=2,3` → no solutions; `n=4` → 2 solutions.

## Intuition
Place one queen per row. For each row, try columns that do not conflict with earlier queens (column + both diagonals), then recurse; undo on failure.

## Brute Force → Optimal
- **Brute:** try all placements of n queens — huge; most invalid early.
- **Optimal:** row-by-row backtracking with O(n) conflict checks (or bitsets / boolean arrays for O(1) checks).

## Data Structure / Approach Justification
**Chosen:** `vector<string>` board + scan-up validation.

- **vs boolean col/diag arrays:** same search; arrays make `isValid` O(1).
- **vs generating all permutations of columns:** equivalent search space with different pruning style.

## Logic Walkthrough
At row `r`, for each `col`, if safe: set `board[r][col]='Q'`, recurse `r+1`, then clear to `'.'`. When `r==n`, push a copy of the board.

## Dry Run
`n=4`, start row 0:
- try col 0 → place Q, continue; eventually dead-ends force backtrack
- one valid board: `[".Q..","...Q","Q...","..Q."]`; another: `["..Q.","Q...","...Q",".Q.."]`

## Time & Space Complexity
Time **O(N!)** roughly (pruned permutations of columns). Space **O(N²)** for the board / solutions, **O(N)** recursion depth. Why: one queen per row × column choices with pruning (section 4).

## Trade-offs & Alternatives
Scan-up is simple to code. Prefer col/diag bitmasks when N is larger or you need tighter constants. Count-only variant (52) skips storing boards.

## Common Mistakes / Edge Cases
Forgetting diagonal checks; not restoring `'.'` after recurse; mutating one shared board without copying into `result`.

## Interview Follow-ups / Variations
N-Queens II (count only). Use bitmasks. Place k queens / other pieces. Print only one solution.

## Tags
`backtracking`, `constraint-satisfaction`, `leetcode-51`, `difficulty:hard`
