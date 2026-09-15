# Find Peak Element

## Problem Statement
[LeetCode 162](https://leetcode.com/problems/find-peak-element/) — return any peak index. A peak is greater than both neighbors (ends compared to one neighbor). `nums[i] != nums[i+1]`.

- **Inputs:** `vector<int> nums`.
- **Output:** index of any peak.
- **Valid answer:** any valid peak index is accepted.
- **Edges:** single element; strictly increasing/decreasing; multiple peaks.

## Intuition
Treat neighbors as a slope: if `nums[mid] < nums[mid+1]`, a peak must exist on the right (unimodal ascent continues); else a peak exists at `mid` or left.

## Brute Force → Optimal
- **Brute:** linear scan for local max — O(N).
- **Optimal:** binary search on slope — O(log N).

## Data Structure / Approach Justification
**Chosen:** lo/hi binary search comparing `mid` vs `mid+1`.

- **vs linear scan:** fine for small N; interview expects log N.
- **vs finding global max:** works (global max is a peak) but O(N).

## Logic Walkthrough
While `lo < hi`: if ascending at mid, `lo = mid+1`; else `hi = mid`. Return `lo`.

## Dry Run
`[1,2,3,1]`: mid=1 → 2<3 → lo=2; mid=2 → 3>1 → hi=2 → peak index 2.

`[1,2,1,3,5,6,4]`: search can land on index 1 or 5 depending on mids — both valid.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: halve the search range each step (section 4).

## Trade-offs & Alternatives
Any peak is OK — no need to find leftmost. Guaranteed existence because ends are −∞ conceptually on LC.

## Common Mistakes / Edge Cases
Using `<=` incorrectly when equals are forbidden; off-by-one with `hi = mid-1` when peak could be mid; empty array (not on LC).

## Interview Follow-ups / Variations
Peak Index in Mountain Array (852); find peak in 2D matrix (1901); all peaks.

## Tags
`binary-search`, `array`, `peak`, `leetcode-162`, `difficulty:medium`
