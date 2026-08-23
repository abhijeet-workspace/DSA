# Find Right Interval

## Problem Statement
[LeetCode 436](https://leetcode.com/problems/find-right-interval/) — for each interval, find the index of the interval with the smallest start that is `>=` its end (or `-1`).

- **Inputs:** `vector<vector<int>> intervals` as `[start, end]`. Starts are unique.
- **Output:** `vector<int>` of indices.
- **Valid answer:** lower bound on starts, mapped back to original index.
- **Edges:** single interval; right interval is itself (`start == end`); none exist.

## Intuition
Lower-bound search on sorted starts answers “smallest start ≥ end_i”.

## Brute Force → Optimal
- **Brute:** for each i scan all starts — O(N²).
- **Optimal:** sort starts + binary search — O(N log N).

## Data Structure / Approach Justification
**Chosen:** pairs `{start, originalIndex}` sorted by start.

- **vs map/tree:** same log factor; vector + BS is simpler
- **vs scanning:** too slow for N=2e4

## Logic Walkthrough
Sort starts. For each interval, lower-bound `end`; store that pair’s index or `-1`.

## Dry Run
`[[3,4],[2,3],[1,2]]` → answers `[-1,0,1]`.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort plus N binary searches.

## Trade-offs & Alternatives
Same as TimeMap / snapshot queries: sort then lower bound.

## Common Mistakes / Edge Cases
Returning the start value instead of index; unstable sort losing indices.

## Interview Follow-ups / Variations
Find first and last position; time-based KV store.

## Tags
`binary-search`, `sorting`, `interval`, `leetcode-436`, `difficulty:medium`
