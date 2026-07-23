# Minimum Platforms

## Problem Statement
Given arrival and departure times, find the minimum platforms so no train waits (classic; same idea as Meeting Rooms II).

- **Inputs:** arrival[], departure[] of equal length.
- **Output:** max concurrent trains = min platforms.
- **Valid answer:** exact max overlap count.
- **Edges:** all sequential; all overlap; equal arrival/departure times.

## Intuition
Sort both arrays and sweep: an arrival increases concurrency; a departure decreases it. Track the peak.

## Brute Force → Optimal
- **Brute:** check all pairs for overlap — O(N²).
- **Optimal:** two-pointer sweep after sorting — O(N log N).

## Data Structure / Approach Justification
**Chosen:** two sorted arrays + two indices.

- **vs min-heap of departures:** also O(N log N); natural for Meeting Rooms II.
- **vs timeline events:** equivalent with +1/−1 events.

## Logic Walkthrough
While both pointers valid: if next arrival ≤ next departure, `++cur` and update `best`; else `--cur`.

## Dry Run
arr `900,940,...` dep `910,1200,...` → concurrency rises to **3** at peak.

## Time & Space Complexity
Time **O(N log N)** sorts. Space **O(1)** extra. Why: max overlap of intervals (section 4).

## Trade-offs & Alternatives
Heap approach assigns platforms explicitly more easily. Event sort is cleaner for mixed event streams.

## Common Mistakes / Edge Cases
Not sorting both arrays; using `<` vs `<=` when arrival equals departure (same platform may free — problem-dependent).

## Interview Follow-ups / Variations
Return an actual platform assignment? Online arrivals?

## Tags
`greedy`, `intervals`, `two-pointers`, `sorting`, `difficulty:medium`
