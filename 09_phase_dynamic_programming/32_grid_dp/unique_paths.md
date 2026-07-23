# Unique Paths

## Problem Statement
[LeetCode 62](https://leetcode.com/problems/unique-paths/) — robot on `m×n` grid starts top-left; only right/down; count paths to bottom-right.

- **Inputs:** `int m`, `int n`.
- **Output:** number of unique paths.
- **Valid answer:** combinatorial / DP count.
- **Edges:** `m=1` or `n=1` → 1; `m=n=1` → 1.

## Intuition
`paths[i][j] = paths[i-1][j] + paths[i][j-1]`. First row/col are all 1s. Roll into 1D.

## Brute Force → Optimal
- **Brute:** recurse both moves — exponential.
- **Optimal:** O(M·N) DP or `C(m+n-2, m-1)`.

## Data Structure / Approach Justification
**Chosen:** `vector<int> dp(n, 1)` rolling.

- **vs full 2D:** clearer, O(MN) memory.
- **vs binomial:** fewer ops; careful overflow / modular arithmetic in variants.

## Logic Walkthrough
Init `dp` to 1s. For each extra row, for `j=1…n-1`: `dp[j] += dp[j-1]`. Return `dp[n-1]`.

## Dry Run
`m=3,n=2`: paths via middle → **3**. `m=3,n=7` → **28**.

## Time & Space Complexity
Time **O(M·N)**. Space **O(N)**. Why: each cell updated once (section 4).

## Trade-offs & Alternatives
DP is robust for obstacles (63). Combinatorics wins when no obstacles and large dims with bigints.

## Common Mistakes / Edge Cases
Starting `dp` at 0; swapping m/n; int overflow on large grids (use long long if needed).

## Interview Follow-ups / Variations
Unique Paths II (63); min path sum (64); diagonal moves allowed?

## Tags
`grid-dp`, `unique-paths`, `leetcode-62`, `difficulty:medium`
