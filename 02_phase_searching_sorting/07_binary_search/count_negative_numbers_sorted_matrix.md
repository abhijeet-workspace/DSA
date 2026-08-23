# Count Negative Numbers in a Sorted Matrix

## Problem Statement
[LeetCode 1351](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) — m×n matrix sorted non-increasing in every row and column; return the count of negatives.

- **Inputs:** `vector<vector<int>> grid`.
- **Output:** `int` count.
- **Valid answer:** number of entries `< 0`.
- **Edges:** no negatives; entire row negative; 1×1.

## Intuition
Each row is sorted, so the first negative splits the suffix of negatives. Binary search that split per row.

## Brute Force → Optimal
- **Brute:** scan all cells — O(MN).
- **Optimal:** binary search each row — O(M log N). Staircase from bottom-left is O(M+N).

## Data Structure / Approach Justification
**Chosen:** per-row first-negative binary search (study-plan pattern).

- **vs staircase O(M+N):** faster when M≈N large; not pure binary search
- **vs flatten:** rows are independent; flattening loses the sort

## Logic Walkthrough
For each row, find smallest index with `row[i] < 0`; add `n - index`.

## Dry Run
Row `[4,3,2,-1]` → first negative at index 3 → 1 negative.

## Time & Space Complexity
Time **O(M log N)**. Space **O(1)**. Why: M rows, log N per row.

## Trade-offs & Alternatives
Use staircase if the interviewer wants the tighter bound.

## Common Mistakes / Edge Cases
Searching for `<= 0` (zeros are not negative); assuming ascending rows.

## Interview Follow-ups / Variations
Search a 2D matrix (74); kth smallest in sorted matrix.

## Tags
`binary-search`, `matrix`, `leetcode-1351`, `difficulty:easy`
