# Car Pooling

## Problem Statement
Given trips `[numPassengers, from, to]` and car `capacity`, return whether passenger load never exceeds capacity. Passengers board at `from` and leave at `to`.

LeetCode: [1094. Car Pooling](https://leetcode.com/problems/car-pooling/)

**Inputs:** `trips`, `capacity`. Locations in `[0,1000]` on LC.  
**Valid answer:** `true` iff load ≤ capacity at every stop.  
**Edges:** capacity exact; empty trips; single stop span.

## Intuition
Treat the timeline as a difference array: +passengers at pickup, −passengers at dropoff. Prefix of deltas is concurrent load.

## Brute Force → Optimal
- **Brute:** simulate each kilometer with nested loops.
- **Optimal:** difference array / event sort — O(N + MAX) or O(N log N).

## Data Structure / Approach Justification (REQUIRED)
Difference array on stops (`diff[1001]` for LC bounds).
- **vs sorting pickup/dropoff events:** more general for large/sparse coordinates; same idea.
- **vs per-trip nested scan:** too slow when trips and range grow.

## Logic Walkthrough
For each trip: `diff[from]+=p`, `diff[to]-=p`. Sweep stops accumulating `current`; fail if `current > capacity`.

## Dry Run
`[[2,1,5],[3,3,7]]`, cap 4: at stop 3 load becomes 5 → **false**. Cap 5 → **true**.

## Time & Space Complexity
**O(N + MAX_STOP)** time, **O(MAX_STOP)** space. Why: N updates on fixed timeline, one sweep (section 4).

## Trade-offs & Alternatives
Diff array needs bounded location range. Event sort is better for sparse/large coordinates.

## Common Mistakes / Edge Cases
Dropping at `to` inclusive incorrectly (passengers leave at `to`, so `-=` at `to`). Off-by-one on ride interval.

## Interview Follow-ups / Variations
Return max concurrent passengers? Generalize to meeting rooms / resource booking.

## Tags
`difference-array`, `sweep-line`, `prefix-sum`, `medium`, `lc-1094`
