# Triangle

## Problem Statement
[LeetCode 120](https://leetcode.com/problems/triangle/) — min path sum from top to bottom; move to adjacent numbers in the row below.

- **Inputs:** `vector<vector<int>> triangle`.
- **Output:** minimum path sum.
- **Valid answer:** top→bottom with adjacent indices.
- **Edges:** one row; negatives.

## Intuition
Bottom-up: each cell += min of two children; answer at apex.

## Brute Force → Optimal
- **Brute:** recurse both children — exponential.
- **Optimal:** O(N²) bottom-up in-place.

## Data Structure / Approach Justification
**Chosen:** mutate upward in-place.

- **vs top-down memo:** same complexity.

## Logic Walkthrough
From row n-2 down to 0: tri[r][c] += min(tri[r+1][c], tri[r+1][c+1]).

## Dry Run
[[2],[3,4],[6,5,7],[4,1,8,3]] → **11**.

## Time & Space Complexity
Time **O(N²)**. Space **O(1)** in-place. Why: each cell once (section 4).

## Trade-offs & Alternatives
1D when triangle immutable.

## Common Mistakes / Edge Cases
Wrong adjacency; top-down without memo.

## Interview Follow-ups / Variations
Min Falling Path Sum (931).

## Tags
`grid-dp`, `leetcode-120`, `difficulty:medium`
