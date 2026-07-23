# Spiral Matrix

## Problem Statement
[LeetCode 54](https://leetcode.com/problems/spiral-matrix/) — return all matrix elements in spiral order (clockwise from top-left).

- **Inputs:** `m × n` matrix.
- **Output:** `vector<int>` of length `m*n` in spiral order.
- **Valid answer:** each cell once, clockwise layers.
- **Edges:** 1×N; M×1; single cell; non-square.

## Intuition
Peel layers — right, down, left, up — while shrinking bounds. Each layer is a rectangle cycle; bounds prevent revisits.

## Brute Force → Optimal
- **Brute:** direction vectors + visited matrix — O(MN) extra space.
- **Optimal:** four bounds without visited — O(1) extra (excluding output).

## Data Structure / Approach Justification
**Chosen:** bounds `t,b,l,r` shrinking after each side.

- **vs dir+visited:** same time, more space and bookkeeping.
- **vs recursion by layer:** elegant but stack/index overhead.

## Logic Walkthrough
While `t<=b && l<=r`: traverse top L→R (`++t`), right T→B (`--r`), bottom R→L if row remains (`--b`), left B→T if col remains (`++l`).

## Dry Run
3×3 → `1 2 3 6 9 8 7 4 5`.

## Time & Space Complexity
Time **O(MN)** (visit each cell once). Space **O(1)** extra excluding output. Why: bounds replace visited set (section 4).

## Trade-offs & Alternatives
Bounds method needs careful empty-row/col guards; visited simulation is harder to get wrong.

## Common Mistakes / Edge Cases
Leftward/upward pass without checking `t<=b` / `l<=r` (double-counting middle row/col).

## Interview Follow-ups / Variations
Generate spiral matrix (59); anti-clockwise spiral.

## Tags
`matrix`, `simulation`, `bounds`, `difficulty:medium`
