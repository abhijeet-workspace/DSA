# Merge Intervals

## Problem Statement
[LeetCode 56](https://leetcode.com/problems/merge-intervals/) — merge all overlapping intervals and return the non-overlapping cover.

- **Inputs:** `vector<vector<int>> intervals` of `[start, end]`.
- **Output:** merged list, sorted by start.
- **Valid answer:** unique minimal cover of the union.
- **Edges:** empty; single; nested; touching endpoints; reverse-sorted input.

## Intuition
Sort by start. Only the last merged interval can overlap the next — extend its end while `next.start <= last.end`, else append a new interval.

## Brute Force → Optimal
- **Brute:** repeatedly scan for any overlapping pair and merge — poor constants / up to O(N²).
- **Optimal:** sort once + linear merge — O(N log N).

## Data Structure / Approach Justification
**Chosen:** sort intervals, then build `merged` vector extending `merged.back()`.

- **vs sweep line:** same complexity; sort+merge is the interview default.
- **vs interval tree:** overkill for one-shot merge.

## Logic Walkthrough
If empty, return `{}`. Sort. Seed `merged` with first. For each later interval: if overlaps/touches last, `end = max(ends)`; else push.

## Dry Run
`[[1,3],[2,6],[8,10],[15,18]]`:
- `[2,6]` overlaps `[1,3]` → `[1,6]`
- `[8,10]` after 6 → append
- `[15,18]` after 10 → append → `[[1,6],[8,10],[15,18]]`

## Time & Space Complexity
Time **O(N log N)** (sort dominates). Space **O(N)** output (plus sort). Why: after sort, one linear pass merges (section 4).

## Trade-offs & Alternatives
Sorting dominates cost; output space is unavoidable. Prefer insert-interval (57) when only one new range is added to a sorted list.

## Common Mistakes / Edge Cases
Using `<` instead of `<=` (touching should merge); forgetting empty/single; mutating while iterating carelessly.

## Interview Follow-ups / Variations
Insert Interval (57); Meeting Rooms; Employee Free Time; merge with a stream of inserts.

## Tags
`intervals`, `sorting`, `merge`, `leetcode-56`, `difficulty:medium`
