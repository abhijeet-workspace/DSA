# Sweep Max Overlap

## Problem Statement
Find the maximum number of intervals that overlap at any single point (meeting-rooms / max concurrency). Related: [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/).

- **Inputs:** intervals `(start, end)` treated as closed at start, open at end for ties.
- **Output:** maximum concurrent overlap count.
- **Valid answer:** max active depth during the sweep.
- **Edges:** empty; touching endpoints (not overlap here); nested; zero-length.

## Intuition
`+1` at each start, `-1` at each end. Sort events; track running `active`. Extrema occur only at event coordinates.

## Brute Force → Optimal
- **Brute:** for each critical point test all intervals — `O(N²)`.
- **Optimal:** sweep events — `O(N log N)`.

## Data Structure / Approach Justification
**Chosen:** event list with end-before-start tie-break.

- **vs two pointers on sorted starts/ends:** equivalent classic.
- **vs min-heap of end times:** natural when assigning room IDs.

## Logic Walkthrough
Build `±1` events; sort; scan updating `active` and `best`.

## Dry Run
`[0,30],[5,10],[15,20]`:
- events `+` at 0,5,15; `-` at 10,20,30 → max active = **2**.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort + linear scan; active equals coverage at current x (section 4).

## Trade-offs & Alternatives
Sweep is uniform for many geometry problems; heap is natural when assigning rooms.

## Common Mistakes / Edge Cases
Wrong tie-break (counting touching as overlap or vice versa).

## Interview Follow-ups / Variations
Return the point of max overlap? Assign room IDs?

## Tags
`sweep-line`, `intervals`, `overlap`, `meeting-rooms`, `difficulty:medium`
