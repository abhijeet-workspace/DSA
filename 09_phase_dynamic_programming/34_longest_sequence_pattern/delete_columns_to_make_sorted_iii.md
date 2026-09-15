# Delete Columns to Make Sorted III

## Problem Statement
[LeetCode 960](https://leetcode.com/problems/delete-columns-to-make-sorted-iii/) — delete min columns so each row is non-decreasing among kept cols.

- **Inputs:** `strs` equal-length.
- **Output:** min deletions.
- **Valid answer:** n - LIS of columns under all-rows non-decreasing.
- **Edges:** already sorted; all delete.

## Intuition
Columns as sequence; keep LIS where for all rows strs[r][i]<=strs[r][j].

## Brute Force → Optimal
- **Brute:** subsets of columns.
- **Optimal:** O(N^2*R) LIS on columns.

## Data Structure / Approach Justification
**Chosen:** dp[j] = max kept ending at column j.

## Logic Walkthrough
For j, for i<j if all rows ok: dp[j]=max(dp[j],dp[i]+1).

## Dry Run
strs=[babca,bbazb] -> **3** deletions.

## Time & Space Complexity
Time **O(N^2*R)**. Space **O(N)**. Why: LIS (section 4).

## Trade-offs & Alternatives
Answer = n - max(dp).

## Common Mistakes / Edge Cases
Comparing only one row.

## Interview Follow-ups / Variations
LIS (300).

## Tags
`lis`, `leetcode-960`, `difficulty:hard`
