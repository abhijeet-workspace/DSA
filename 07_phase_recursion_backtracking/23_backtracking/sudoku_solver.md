# Sudoku Solver

## 1. Problem Statement
[LeetCode 37](https://leetcode.com/problems/sudoku-solver/) — fill empty `'.'` cells of a 9×9 board so rows, columns, and 3×3 boxes each contain `'1'`–`'9'` once.

- **Inputs:** `vector<vector<char>> board` (partially filled, guaranteed solvable).
- **Output:** modify board in place to a complete valid solution.
- **Valid answer:** any correct completion (unique under LeetCode constraints).
- **Edges:** nearly full board; cell with a single candidate; deep backtracks.

## 2. Intuition
Find next `'.'`, try digits that keep row/col/box valid, recurse; on failure clear the cell and try the next digit.

## 3. Brute Force → Optimal
- **Brute:** try all fillings of empty cells — 9^E.
- **Optimal:** backtracking with constraint checks; bitmasks / candidate sets prune harder; MRV (fewest candidates first) speeds practice solvers.

## 4. Data Structure / Approach Justification
**Chosen:** scan board for next empty + O(1)-ish validity loop over 9.

- **vs row/col/box bitsets:** O(1) place checks, more setup code.
- **vs dancing links (DLX):** overkill for interview; excellent for exact cover.

## 5. Logic Walkthrough
`solve`: locate first `'.'`; for `c` in `'1'..'9'`, if valid set cell, recurse; if recurse succeeds return true else undo. No empty → true. No digit works → false.

## 6. Dry Run
Classic LC board first empty at `(0,2)`:
- try digits; `'4'` is valid → place, continue filling…
- conflicts force undo until unique completion (row 0 becomes `534678912`)

## 7. Time & Space Complexity
Time **O(9^E)** worst (E = empty cells), heavily pruned. Space **O(E)** recursion depth (board is O(1) size). Why: branching ≤9 per empty with constraint prune (section 4).

## 8. Trade-offs & Alternatives
Simple scan is interview-standard. Bitmasks + MRV for production solvers. Validate Sudoku (36) is the check-only sibling.

## 9. Common Mistakes / Edge Cases
Wrong box index math; forgetting to return false when no digit fits; not restoring `'.'` after failed branch.

## 10. Interview Follow-ups / Variations
Validate only (36). Generate puzzles. Larger grids. Count solutions.

## 11. Tags
`backtracking`, `matrix`, `constraint-satisfaction`, `leetcode-37`, `difficulty:hard`
