# Cherry Pickup II

## Problem Statement
[LeetCode 1463](https://leetcode.com/problems/cherry-pickup-ii/) — two robots start top corners, move down (±1 col); collect cherries; same cell once.

- **Inputs:** `rows×cols` grid.
- **Output:** max cherries.
- **Valid answer:** both reach bottom row.
- **Edges:** cols=2; overlapping cells.

## Intuition
DP on (row, col1, col2); both move down each step.

## Brute Force → Optimal
- **Brute:** joint DFS — exponential.
- **Optimal:** O(R·C²) memo.

## Data Structure / Approach Justification
**Chosen:** memo dp[r][c1][c2].

- **vs Cherry Pickup I:** one-way two robots, not round trip.

## Logic Walkthrough
At row r, try 3×3 next columns; add cell cherries with dedupe.

## Dry Run
Sample grid → **24**.

## Time & Space Complexity
Time **O(R·C²)**. Space **O(R·C²)**. Why: states × 9 moves (section 4).

## Trade-offs & Alternatives
Bottom-up from last row upward is iterative-friendly.

## Common Mistakes / Edge Cases
Double-counting; allowing out-of-bound cols.

## Interview Follow-ups / Variations
Cherry Pickup (741).

## Tags
`grid-dp`, `leetcode-1463`, `difficulty:hard`
