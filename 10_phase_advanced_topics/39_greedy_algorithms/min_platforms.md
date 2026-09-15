# Minimum Platforms

## 1. Problem Statement
Given arrival and departure times, find the minimum platforms so no train waits (classic; same idea as Meeting Rooms II).

- **Inputs:** arrival[], departure[] of equal length.
- **Output:** max concurrent trains = min platforms.
- **Valid answer:** exact max overlap count.
- **Edges:** all sequential; all overlap; equal arrival/departure times.

## 2. Intuition
Sort both arrays and sweep: an arrival increases concurrency; a departure decreases it. Track the peak.

## 3. Brute Force → Optimal
- **Brute:** check all pairs for overlap — O(N²).
- **Optimal:** two-pointer sweep after sorting — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** two sorted arrays + two indices.

- **vs min-heap of departures:** also O(N log N); natural for Meeting Rooms II.
- **vs timeline events:** equivalent with +1/−1 events.

## 5. Logic Walkthrough
While both pointers valid: if next arrival ≤ next departure, `++cur` and update `best`; else `--cur`.

## 6. Dry Run
arr `900,940,...` dep `910,1200,...` → concurrency rises to **3** at peak.

## 7. Time & Space Complexity
Time **O(N log N)** sorts. Space **O(1)** extra. Why: max overlap of intervals (section 4).

## 8. Trade-offs & Alternatives
Heap approach assigns platforms explicitly more easily. Event sort is cleaner for mixed event streams.

## 9. Common Mistakes / Edge Cases
Not sorting both arrays; using `<` vs `<=` when arrival equals departure (same platform may free — problem-dependent).

## 10. Interview Follow-ups / Variations
Return an actual platform assignment? Online arrivals?

## 11. Tags
`greedy`, `intervals`, `two-pointers`, `sorting`, `difficulty:medium`
