# Interval List Intersections

## Problem Statement
[LeetCode 986](https://leetcode.com/problems/interval-list-intersections/) — return the intersection of two lists of closed intervals. Each list is pairwise disjoint and sorted by start.

- **Inputs:** `firstList`, `secondList` of `[start, end]`.
- **Output:** all non-empty intersections, sorted.
- **Valid answer:** every pairwise overlap as a closed interval.
- **Edges:** empty list; point overlaps; touching endpoints; one list fully covering the other.

## Intuition
Both lists are sorted and disjoint internally. Two pointers: intersection is `[max(starts), min(ends)]` when that range is valid; advance the interval that finishes first.

## Brute Force → Optimal
- **Brute:** check every pair — O(NM).
- **Optimal:** two pointers exploiting sort — O(N + M).

## Data Structure / Approach Justification
**Chosen:** two-pointer sweep on sorted lists.

- **vs nested scan:** wastes order information.
- **vs sweep line events:** heavier for the same linear result.

## Logic Walkthrough
While both indices in range: compute `lo`/`hi`. If `lo <= hi`, push. Advance the list whose current interval has the smaller end.

## Dry Run
`[0,2]` ∩ `[1,5]` → `[1,2]`; advance first. `[5,10]` ∩ `[1,5]` → `[5,5]`; advance second. Continue → `[8,10]`, `[15,23]`, `[24,24]`, `[25,25]`.

## Time & Space Complexity
Time **O(N + M)**. Space **O(K)** output. Why: each interval advanced once (section 4).

## Trade-offs & Alternatives
Works only because inputs are sorted and internally disjoint. Unsorted inputs need sort first.

## Common Mistakes / Edge Cases
Using `<` instead of `<=` (point intersections valid); advancing both when ends equal incorrectly; forgetting empty lists.

## Interview Follow-ups / Variations
Merge Intervals (56); Employee Free Time; intersection of K lists.

## Tags
`intervals`, `two-pointers`, `leetcode-986`, `difficulty:medium`
