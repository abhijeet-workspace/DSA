# Non-overlapping Intervals

## 1. Problem Statement
[LeetCode 435](https://leetcode.com/problems/non-overlapping-intervals/) — return the minimum number of intervals to remove so the rest are non-overlapping.

- **Inputs:** `vector<vector<int>> intervals` of `[start, end)`.
- **Output:** `int` = min removals.
- **Valid answer:** `n -` size of a maximum non-overlapping subset.
- **Edges:** all overlap; none overlap; identical; touching (`end == next.start` OK).

## 2. Intuition
Activity selection: sort by end time; greedily keep an interval if its start ≥ last kept end. Removals = `n - keep`.

## 3. Brute Force → Optimal
- **Brute:** try all removal subsets — exponential.
- **Optimal:** greedy keep-max by earliest end — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sort by `end`, track `end` of last kept interval, count `keep`.

- **vs DP like LIS on intervals:** O(N²), correct but slower.
- **vs sort by start:** does not maximize remaining set; wrong greedy.

## 5. Logic Walkthrough
Sort by end. `keep=0`, `end=INT_MIN`. For each interval, if `start >= end`, keep and set `end = this.end`. Return `n - keep`.

## 6. Dry Run
`[[1,2],[2,3],[3,4],[1,3]]` sorted by end: `[1,2],[1,3],[2,3],[3,4]`:
- keep `[1,2]` → keep `[2,3]` → keep `[3,4]`; skip `[1,3]`
- keep 3 → removals **1**

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra (aside from sort). Why: earliest-end greedy is optimal for unweighted intervals (section 4).

## 8. Trade-offs & Alternatives
Greedy is optimal and interview-standard. Weighted intervals need DP / weighted activity selection.

## 9. Common Mistakes / Edge Cases
Sorting by start; treating touch as overlap; off-by-one on half-open intervals; empty input.

## 10. Interview Follow-ups / Variations
Max non-overlapping count? Weighted intervals? Meeting Rooms connection?

## 11. Tags
`intervals`, `greedy`, `activity-selection`, `leetcode-435`, `difficulty:medium`
