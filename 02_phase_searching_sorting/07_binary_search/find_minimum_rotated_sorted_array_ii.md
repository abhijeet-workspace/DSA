# Find Minimum in Rotated Sorted Array II

## Problem Statement
[LeetCode 154](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) — rotated non-decreasing array that may contain duplicates; return the minimum.

- **Inputs:** `vector<int> nums`.
- **Output:** `int` min value.
- **Valid answer:** the rotation pivot (or `nums[0]` if unrotated).
- **Edges:** all equal; min at either end; duplicates around the pivot.

## Intuition
Same as 153 unless `nums[mid] == nums[hi]`, which hides the sorted half — then drop `hi`.

## Brute Force → Optimal
- **Brute:** linear min — O(N).
- **Optimal:** binary search with duplicate shrink — average O(log N), worst O(N).

## Data Structure / Approach Justification
**Chosen:** compare mid to hi; `--hi` on equality.

- **vs 153:** duplicates force the linear worst case
- **vs sort:** destroys the rotation structure and is slower

## Logic Walkthrough
If mid > hi, min is to the right. If mid < hi, min is at mid or left. Else `--hi`.

## Dry Run
`[2,2,2,0,1]` → eventually `hi` lands on `0`.

## Time & Space Complexity
Time **O(N)** worst, **O(log N)** typical. Space **O(1)**. Why: all-equal array forces n shrinks.

## Trade-offs & Alternatives
Search in rotated array II (81) uses the same duplicate shrink.

## Common Mistakes / Edge Cases
Using 153 logic unchanged; overflowing when `lo`/`hi` meet.

## Interview Follow-ups / Variations
Find min I (153); search rotated II (81).

## Tags
`binary-search`, `rotated-array`, `duplicates`, `leetcode-154`, `difficulty:hard`
