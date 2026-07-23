# Minimum Size Subarray Sum

## Problem Statement
Find the smallest length of a contiguous subarray whose sum is ≥ `target`. Return `0` if none.

LeetCode: [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

**Inputs:** `target`, `nums` with **positive** integers.  
**Valid answer:** minimal window length, or `0`.  
**Edges:** no valid window; single element ≥ target; exact match.

## Intuition
With positives, window sum is monotonic as you expand/shrink. Grow right until valid, then shrink left to minimize length.

## Brute Force → Optimal
- **Brute:** all subarrays O(N²).
- **Optimal:** two pointers / sliding window O(N) when all `nums > 0`.

## Data Structure / Approach Justification (REQUIRED)
Sliding window (`left`, `right`, `windowSum`) — no extra DS beyond scalars.
- **vs binary search on prefix sums:** O(N log N); valid for positives but slower constant/log factor.
- **vs hashmap prefix (LC 560 style):** unnecessary here; we need minimal *length*, not count, and positives enable window.

## Logic Walkthrough
Expand `right`, add to `windowSum`. While `windowSum >= target`, update `minLen` and subtract `nums[left++]`.

## Dry Run
`[2,3,1,2,4,3]`, `target=7` → minimal window `[4,3]` length **2**.

## Time & Space Complexity
**O(N)** time, **O(1)** space. Why: each index enters/leaves the window at most once (section 4).

## Trade-offs & Alternatives
Requires non-negative nums. Negatives need prefix + different search (map / modified approaches).

## Common Mistakes / Edge Cases
Using this window on arrays with negatives (incorrect). Returning `INT_MAX` instead of `0` when impossible.

## Interview Follow-ups / Variations
What if nums can be negative? (prefix + map / other techniques)

## Tags
`sliding-window`, `two-pointers`, `prefix-sum`, `medium`, `lc-209`
