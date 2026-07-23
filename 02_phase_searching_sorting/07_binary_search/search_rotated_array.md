# Search in Rotated Sorted Array

## Problem Statement
[LeetCode 33](https://leetcode.com/problems/search-in-rotated-sorted-array/) — distinct ascending array rotated at unknown pivot; return index of `target` or `-1`.

- **Inputs:** `vector<int> nums` (rotated once), `int target`.
- **Output:** index or `-1`.
- **Valid answer:** unique match if present.
- **Edges:** no rotation; target at pivot; not present; `n = 1`.

## Intuition
At least one half of `[left, mid]` / `[mid, right]` is sorted. Decide which half is sorted, then test whether `target` lies inside that half’s range.

## Brute Force → Optimal
- **Brute:** linear scan — O(N).
- **Optimal:** one modified binary search — O(log N).

## Data Structure / Approach Justification
**Chosen:** identify sorted half via `nums[left] <= nums[mid]`, then range-check `target`.

- **vs find pivot then BS twice:** same asymptotics; more code / edge cases.
- **vs linear:** fails interview time targets.

## Logic Walkthrough
If left half sorted and `target` in `[nums[left], nums[mid])`, shrink right; else go left. Symmetric for right half. Equal mid → return.

## Dry Run
`nums = [4,5,6,7,0,1,2]`, `target = 0`:
- mid `7` (idx 3); left half sorted; `0` not in `[4,7)` → left = 4
- mid `1`; right half path lands on `0` at index 4

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: still halves each step (section 4).

## Trade-offs & Alternatives
With duplicates (LC 81), may need `left++` when `nums[left] == nums[mid]` — degrades to O(N) worst case.

## Common Mistakes / Edge Cases
Wrong inclusive bounds on the sorted-half check; assuming both halves unsorted; off-by-one around the pivot.

## Interview Follow-ups / Variations
Find minimum in rotated array; search with duplicates.

## Tags
`binary-search`, `rotated-array`, `difficulty:medium`
