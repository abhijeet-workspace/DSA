# Maximal Rectangle

## Problem Statement
[LeetCode 85](https://leetcode.com/problems/maximal-rectangle/) — largest rectangle containing only '1's; return area.

- **Inputs:** binary char matrix.
- **Output:** max area.
- **Valid answer:** axis-aligned ones rectangle.
- **Edges:** empty; single row; all ones.

## Intuition
Treat each row as histogram base: heights of consecutive ones; largest rectangle in histogram per row.

## Brute Force → Optimal
- **Brute:** all sub-rectangles — O(M²N²).
- **Optimal:** O(M·N) heights + monotonic stack.

## Data Structure / Approach Justification
**Chosen:** height array + stack largest rectangle in histogram.

- **vs 2D DP only:** harder for arbitrary rectangles.

## Logic Walkthrough
Update heights; stack computes left/right smaller for area.

## Dry Run
Sample LC matrix → **6**.

## Time & Space Complexity
Time **O(M·N)**. Space **O(N)**. Why: each cell + stack amortized O(1) (section 4).

## Trade-offs & Alternatives
Maximal Square is simpler special case.

## Common Mistakes / Edge Cases
Not resetting height on '0'; stack off-by-one.

## Interview Follow-ups / Variations
Maximal Square (221); Largest Rectangle in Histogram (84).

## Tags
`grid-dp`, `stack`, `leetcode-85`, `difficulty:hard`
