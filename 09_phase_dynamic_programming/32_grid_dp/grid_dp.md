# Grid DP

## Problem Statement
Grid DP demos: [Unique Paths (62)](https://leetcode.com/problems/unique-paths/), [Min Path Sum (64)](https://leetcode.com/problems/minimum-path-sum/), [Maximal Square (221)](https://leetcode.com/problems/maximal-square/).

- **Inputs:** grid dims / cost grid / binary `char` matrix.
- **Output:** path count / min sum / largest square **area**.
- **Valid answer:** only right+down for 62/64; contiguous `'1'` square for 221.
- **Edges:** 1×N / M×1; empty matrix; all zeros.

## Intuition
Grids are DAGs under standard moves. Each cell = combine from top/left (or neighbors for square).

## Brute Force → Optimal
- **Brute:** recurse all paths — exponential.
- **Optimal:** O(M·N) DP; roll to O(N) for path problems.

## Data Structure / Approach Justification
**Chosen:** 1D rolling for paths/sums; 2D side-length table for square.

- **vs combinatorics for 62:** `C(m+n-2, m-1)` — O(min(m,n)), mention as follow-up.
- **vs full 2D always:** clearer but more memory.

## Logic Walkthrough
**62:** `dp[j] += dp[j-1]` per row. **64:** `dp[j] = grid + min(above, left)`. **221:** side = `1 + min(top,left,diag)` on `'1'`; area = side².

## Dry Run
3×7 paths → **28**. Cost grid `[[1,3,1],[1,5,1],[4,2,1]]` → path `1-3-1-1-1` = **7**. Square side 2 → area **4**.

## Time & Space Complexity
Time **O(M·N)** each. Space **O(N)** paths/sums, **O(M·N)** square (1D possible). Why: one fill per cell (section 4).

## Trade-offs & Alternatives
1D is interview-friendly. Obstacles (63) need a blocked-cell zeroing rule.

## Common Mistakes / Edge Cases
Init first row/col wrong; returning side instead of area; mutating input grid in place without care.

## Interview Follow-ups / Variations
Unique Paths II (63); Cherry Pickup; dungeon game (174).

## Tags
`grid-dp`, `unique-paths`, `min-path-sum`, `maximal-square`, `difficulty:medium`
