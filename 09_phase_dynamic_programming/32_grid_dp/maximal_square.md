# Maximal Square

## Problem Statement
[LeetCode 221](https://leetcode.com/problems/maximal-square/) — largest square of `'1'`s in binary matrix; return **area**.

- **Inputs:** `vector<vector<char>> matrix`.
- **Output:** area of largest square.
- **Valid answer:** side² of max contiguous ones square.
- **Edges:** empty; all zeros; single `1`.

## Intuition
`dp[i][j]` = side of largest square with bottom-right at `(i,j)`; = 1+min(left,up,diag) if `'1'`.

## Brute Force → Optimal
- **Brute:** check every cell/side — O(M·N·min²).
- **Optimal:** O(M·N) DP.

## Data Structure / Approach Justification
**Chosen:** 2D (or 1D) side-length DP; track max side.

- **vs histogram largest rectangle:** different shape (rectangle vs square).

## Logic Walkthrough
On `'1'`: take min of three neighbors + 1. Area = maxSide².

## Dry Run
Matrix with a 2×2 ones block → area **4**.

## Time & Space Complexity
Time **O(M·N)**. Space **O(M·N)** or **O(N)**. Why: one pass (section 4).

## Trade-offs & Alternatives
Maximal Rectangle (85) for non-square.

## Common Mistakes / Edge Cases
Returning side not area; off-by-one indexing on first row/col.

## Interview Follow-ups / Variations
Count Square Submatrices (1277); Maximal Rectangle.

## Tags
`2d-dp`, `grid-dp`, `leetcode-221`, `difficulty:medium`
