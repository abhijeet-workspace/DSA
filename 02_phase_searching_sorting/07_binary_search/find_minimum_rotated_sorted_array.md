# Find Minimum in Rotated Sorted Array

## Problem Statement
[LeetCode 153](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) — distinct rotated ascending array; return the minimum value.

- **Inputs:** `vector<int> nums` rotated at unknown index.
- **Output:** minimum element (the pivot value).
- **Valid answer:** unique min.
- **Edges:** no rotation (already sorted); `n = 1`; min at ends.

## Intuition
Compare `nums[mid]` to `nums[hi]`: if mid is above hi, the rotation (and min) lies to the right; else min is at mid or left.

## Brute Force → Optimal
- **Brute:** linear min — O(N).
- **Optimal:** binary search on unsorted/sorted side — O(log N).

## Data Structure / Approach Justification
**Chosen:** `while (lo < hi)` with `hi = mid` / `lo = mid + 1` (no early return needed).

- **vs find pivot index then index:** same idea; value return is enough here.
- **vs linear:** unnecessary once rotation property is used.

## Logic Walkthrough
If `nums[mid] > nums[hi]`, set `lo = mid + 1`. Else `hi = mid`. Loop ends with `lo == hi` at the minimum.

## Dry Run
`[3,4,5,1,2]`:
- mid `5` > hi `2` → lo = mid+1
- settles on `1`

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: halve until lo==hi (section 4).

## Trade-offs & Alternatives
With duplicates (LC 154), comparing to `hi` may require `hi--` → O(N) worst case.

## Common Mistakes / Edge Cases
Using `lo <= hi` and returning wrong; comparing to `nums[lo]` instead of `nums[hi]` without care.

## Interview Follow-ups / Variations
Search in rotated array; min with duplicates.

## Tags
`binary-search`, `rotated-array`, `difficulty:medium`
