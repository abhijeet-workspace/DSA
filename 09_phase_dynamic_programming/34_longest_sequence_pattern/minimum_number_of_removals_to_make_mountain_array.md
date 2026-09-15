# Minimum Number of Removals to Make Mountain Array

## Problem Statement
[LeetCode 1671](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) — min removals so remaining is a mountain array.

- **Inputs:** `nums`.
- **Output:** min removals.
- **Valid answer:** n - max mountain subsequence length.
- **Edges:** already mountain; no peak.

## Intuition
LIS from left + LDS from right; max lis[i]+lds[i]-1 for valid peaks.

## Brute Force → Optimal
- **Brute:** choose peak + sides.
- **Optimal:** O(N^2) lis/lds.

## Data Structure / Approach Justification
**Chosen:** O(N^2) lis/lds arrays.

## Logic Walkthrough
Require both >=2 at peak i.

## Dry Run
[1,3,1] -> **0**; [2,1,1,5,6,2,3,1] -> **3**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N)**. Why: LIS twice (section 4).

## Trade-offs & Alternatives
Peak cannot be endpoint.

## Common Mistakes / Edge Cases
Allowing non-strict.

## Interview Follow-ups / Variations
LIS (300).

## Tags
`lis`, `leetcode-1671`, `difficulty:hard`
