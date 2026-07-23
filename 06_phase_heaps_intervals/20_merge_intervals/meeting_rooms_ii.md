# Meeting Rooms II

## Problem Statement
[LeetCode 253](https://leetcode.com/problems/meeting-rooms-ii/) (premium) — find the minimum number of conference rooms needed for all meetings.

- **Inputs:** `vector<vector<int>> intervals` of `[start, end]`.
- **Output:** `int` = min rooms.
- **Valid answer:** max concurrent meetings over time.
- **Edges:** empty → 0; all sequential → 1; all overlap → N.

## Intuition
Sort by start. A min-heap of end times tracks rooms in use; if the next meeting starts after the earliest end, reuse that room; else allocate another.

## Brute Force → Optimal
- **Brute:** simulate room assignment lists — O(N²) checks.
- **Optimal:** sort + min-heap of ends, or sweep line — O(N log N).

## Data Structure / Approach Justification
**Chosen:** `priority_queue` min-heap of end times; heap size = rooms in use.

- **vs chronological +1/−1 sweep:** same complexity; sweep maxes a running counter.
- **vs sorting starts and ends separately:** classic sweep variant; easy to mishandle ties.

## Logic Walkthrough
Sort by start. Push first end. For each later meeting: if `start >= ends.top()`, pop (reuse). Push current end. Answer is heap size.

## Dry Run
`[[0,30],[5,10],[15,20]]`:
- heap `[30]`; `5 < 30` → push 10 → `[10,30]`
- `15 >= 10` → pop → push 20 → `[20,30]` → rooms **2**

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)** heap. Why: sort + heap ops track concurrency (section 4).

## Trade-offs & Alternatives
Heap is intuitive (“reuse earliest free room”). Sweep is elegant and same big-O. Prefer sweep if you already think in events.

## Common Mistakes / Edge Cases
Sorting ends independently without correct event ordering; treating `start == end` as conflict; empty input.

## Interview Follow-ups / Variations
Return room assignment schedule? Max concurrent (same answer). Online arrivals?

## Tags
`intervals`, `heap`, `sweep-line`, `leetcode-253`, `difficulty:medium`
