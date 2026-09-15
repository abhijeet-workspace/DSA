# Design Tic-Tac-Toe

## Problem Statement
[LeetCode 348](https://leetcode.com/problems/design-tic-tac-toe/) — design `n×n` Tic-Tac-Toe; `move(row,col,player)` returns winner or 0. Assume valid moves / at most one winner.

- **Inputs:** board size `n`; sequence of moves.
- **Output:** 0 or winning player id.
- **Valid answer:** win by full row/col/diag/anti-diag.
- **Edges:** n=1; win on last cell; no win.

## Intuition
Maintain counters per row/col/diag; player1 +1, player2 -1; win when abs==n.

## Brute Force → Optimal
- **Brute:** scan board each move — O(n²).
- **Optimal:** counters — O(1) move, O(n) space.

## Data Structure / Approach Justification
**Chosen:** `rows`, `cols`, `diag`, `anti` counters.

- **vs full board:** unnecessary for win check only.

## Logic Walkthrough
Apply delta to affected lines; if any abs equals n, return player.

## Dry Run
Player 1 fills bottom row → `rows[2]==3` → return 1.

## Time & Space Complexity
Time **O(1)** per move. Space **O(n)**.

## Trade-offs & Alternatives
Store board if you also need to print state.

## Common Mistakes / Edge Cases
Forgetting anti-diagonal; using same delta for both players.

## Interview Follow-ups / Variations
Connect-k; undo moves; multiplayer.

## Tags
`design`, `array`, `leetcode-348`, `difficulty:medium`
