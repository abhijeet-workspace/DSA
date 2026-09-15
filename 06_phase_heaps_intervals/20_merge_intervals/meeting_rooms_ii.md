# Meeting Rooms II

## 1. Problem Statement
[LeetCode 253](https://leetcode.com/problems/meeting-rooms-ii/) (premium) — find the minimum number of conference rooms needed for all meetings.

- **Inputs:** `vector<vector<int>> intervals` of `[start, end]`.
- **Output:** `int` = min rooms.
- **Valid answer:** max concurrent meetings over time.
- **Edges:** empty → 0; all sequential → 1; all overlap → N.

## 2. Intuition
Sort by start. A min-heap of end times tracks rooms in use; if the next meeting starts after the earliest end, reuse that room; else allocate another.

## 3. Brute Force → Optimal
- **Brute:** simulate room assignment lists — O(N²) checks.
- **Optimal:** sort + min-heap of ends, or sweep line — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** `priority_queue` min-heap of end times; heap size = rooms in use.

- **vs chronological +1/−1 sweep:** same complexity; sweep maxes a running counter.
- **vs sorting starts and ends separately:** classic sweep variant; easy to mishandle ties.

## 5. Logic Walkthrough
Sort by start. Push first end. For each later meeting: if `start >= ends.top()`, pop (reuse). Push current end. Answer is heap size.

## 6. Dry Run
`[[0,30],[5,10],[15,20]]`:
- heap `[30]`; `5 < 30` → push 10 → `[10,30]`
- `15 >= 10` → pop → push 20 → `[20,30]` → rooms **2**

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)** heap. Why: sort + heap ops track concurrency (section 4).

## 8. Trade-offs & Alternatives
Heap is intuitive (“reuse earliest free room”). Sweep is elegant and same big-O. Prefer sweep if you already think in events.

## 9. Common Mistakes / Edge Cases
Sorting ends independently without correct event ordering; treating `start == end` as conflict; empty input.

## 10. Interview Follow-ups / Variations
Return room assignment schedule? Max concurrent (same answer). Online arrivals?

## 11. Tags
`intervals`, `heap`, `sweep-line`, `leetcode-253`, `difficulty:medium`
