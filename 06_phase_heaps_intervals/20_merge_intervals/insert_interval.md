# Insert Interval

## Problem Statement
[LeetCode 57](https://leetcode.com/problems/insert-interval/) — given sorted non-overlapping `intervals` and `newInterval`, insert and merge so the result stays sorted and non-overlapping.

- **Inputs:** `vector<vector<int>> intervals`, `vector<int> newInterval` (`[start, end]`).
- **Output:** merged interval list.
- **Valid answer:** unique cover after insert+merge.
- **Edges:** empty list; insert before/after all; covers everything; touches endpoints.

## Intuition
Three phases on a sorted list: copy intervals ending before the new start, merge every overlapping interval into `newInterval`, then append the rest.

## Brute Force → Optimal
- **Brute:** push `newInterval`, then run full merge-intervals — O(N log N).
- **Optimal:** one linear three-phase scan — O(N) time, O(N) space for output.

## Data Structure / Approach Justification
**Chosen:** result vector + index walk; expand `neu` while overlaps.

- **vs binary search bounds:** same asymptotic; three-phase is clearer in interviews.
- **vs full re-merge:** wastes a sort when input is already ordered.

## Logic Walkthrough
While `intervals[i].end < neu.start`, push. While `intervals[i].start <= neu.end`, expand `neu`. Push `neu`, then push remaining intervals.

## Dry Run
`[[1,3],[6,9]]` + `[2,5]`:
- `[1,3]` overlaps → `neu=[1,5]`
- `[6,9]` starts after 5 → append
- result `[[1,5],[6,9]]`

## Time & Space Complexity
Time **O(N)**. Space **O(N)** output. Why: one pass over sorted intervals (section 4).

## Trade-offs & Alternatives
Linear three-phase is clearest. If intervals were unsorted, sort first then merge (becomes 56).

## Common Mistakes / Edge Cases
Stopping after first overlap (miss chained merges); treating touch as non-overlap incorrectly; forgetting empty input.

## Interview Follow-ups / Variations
Intervals not pre-sorted? Online stream of inserts? Merge Intervals (56).

## Tags
`intervals`, `merge`, `linear-scan`, `leetcode-57`, `difficulty:medium`
