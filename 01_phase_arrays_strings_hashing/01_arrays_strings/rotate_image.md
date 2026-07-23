# Rotate Image

## Problem Statement
[LeetCode 48](https://leetcode.com/problems/rotate-image/) — rotate `n × n` matrix 90° clockwise in-place.

- **Inputs:** square `vector<vector<int>>`.
- **Output:** matrix mutated; `(i,j) → (j, n-1-i)`.
- **Valid answer:** in-place (O(1) extra preferred).
- **Edges:** 1×1; 2×2.

## Intuition
Transpose then reverse each row equals the clockwise map `(i,j) → (j, n-1-i)`.

## Brute Force → Optimal
- **Brute:** copy to new matrix — O(N²) space.
- **Optimal:** transpose + reverse / layer 4-cycles — O(1) space.

## Data Structure / Approach Justification
**Chosen:** in-place transpose + row reverse — easiest algebraic composition to remember.

- **vs layer cycle swaps:** also O(1) space; more index arithmetic.
- **vs extra matrix:** trivial but fails follow-up space constraint.

## Logic Walkthrough
Swap upper triangle for transpose. Then `reverse` each row.

## Dry Run
`[[1,2,3],[4,5,6],[7,8,9]]` → transpose `[[1,4,7],[2,5,8],[3,6,9]]` → reverse rows → `[[7,4,1],[8,5,2],[9,6,3]]`.

## Time & Space Complexity
Time **O(N²)** (touch every cell). Space **O(1)** extra. Why: two in-place transforms (section 4).

## Trade-offs & Alternatives
Transpose method is easiest to remember. Cycle method avoids an explicit second pass mindset.

## Common Mistakes / Edge Cases
Reversing columns instead of rows (counterclockwise-ish); swapping full matrix including diagonal twice.

## Interview Follow-ups / Variations
Rotate counterclockwise; anti-diagonal flip; rotate by 180°.

## Tags
`matrix`, `in-place`, `transpose`, `difficulty:medium`
