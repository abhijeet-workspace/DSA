# Valid Sudoku

## Problem Statement
[LeetCode 36](https://leetcode.com/problems/valid-sudoku/) — determine if a 9×9 board is valid: each row, column, and 3×3 box contains digits `1–9` at most once (empty cells are `'.'`).

- **Input:** `vector<vector<char>> board` (9×9)
- **Output:** `true` if currently valid (need not be solvable)
- **Edges:** all empty; single duplicate in box only; filled valid partial board

## Intuition
A digit is invalid if it already appeared in its row, column, or box. Track membership with sets/bitmasks while scanning once.

## Brute Force → Optimal
- **Brute:** for each cell, scan its whole row/col/box — O(1) board size but O(9) extra per cell.
- **Optimal:** one pass; mark seen digits in three arrays of 9 bitmasks — O(81).

## Data Structure / Approach Justification
Bitmasks (or `bool[9][10]` / hash sets) per row, column, and box index `(r/3)*3+(c/3)`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested rescans | More constant work, same idea |
| Full Sudoku solver | Overkill — validity ≠ solvability |

## Logic Walkthrough
1. For each filled cell, compute bit for digit and box id.
2. If bit already set in row, col, or box → invalid.
3. Else set the bit in all three trackers.

## Dry Run
Valid sample board: each `5`/`3`/… appears once per constraint → **true**. Change `board[0][0]` to `8` while `board[3][0]` is `8` → row/col clash → **false**.

## Time & Space Complexity
- **Time:** O(1) for fixed 9×9 (O(N²) if generalized)
- **Space:** O(1) (three length-9 int arrays)
- Why: single pass over a constant-size board.

## Trade-offs & Alternatives
Hash sets are clearer; bitmasks are denser. Do not require a complete solution — only no conflicts among filled cells.

## Common Mistakes / Edge Cases
Checking solvability; wrong box index; treating `'.'` as a digit; forgetting boxes while checking only rows/cols.

## Interview Follow-ups / Variations
Sudoku Solver (37); Valid Sudoku with N×N / larger boxes; report conflicting cells.

## Tags
`hash-set`, `matrix`, `bitmask`, `leetcode-36`, `medium`
