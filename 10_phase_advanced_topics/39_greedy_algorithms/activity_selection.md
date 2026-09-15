# Activity Selection

## 1. Problem Statement
Classic interval scheduling (max keep) / [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) (min removals = `n − keep`).

- **Inputs:** intervals `intervals[i] = [start, end]` (`vector<vector<int>>`).
- **Output (LC 435):** minimum intervals to remove so the rest are non-overlapping.
- **Note:** touching endpoints (`end == next.start`) are non-overlapping.
- **Edges:** all overlap; identical intervals; already non-overlapping.

## 2. Intuition
Always take the interval that finishes earliest among remaining — it leaves the most room for future choices (exchange argument).

## 3. Brute Force → Optimal
- **Brute:** try all subsets — exponential.
- **Optimal:** sort by end time; greedily take non-overlapping — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sort by `end`, scan once keeping `lastEnd`.

- **vs DP LIS-style:** O(N²) correct but slower.
- **vs sort by start:** not always optimal.

## 5. Logic Walkthrough
Sort by `end` ascending. Greedily keep if `start >= lastEnd`; answer = `n − keep`.

## 6. Dry Run
`[[1,2],[2,3],[3,4],[1,3]]` → keep `[1,2],[2,3],[3,4]` → remove `1`.

## 7. Time & Space Complexity
Time **O(N log N)** sort. Space **O(1)** extra (aside from sort). Why: greedy after ordering by finish (section 4).

## 8. Trade-offs & Alternatives
Unweighted greedy is optimal; weighted activity selection needs DP.

## 9. Common Mistakes / Edge Cases
Sorting by start instead of end; treating touching endpoints as overlap when `>=` is allowed.

## 10. Interview Follow-ups / Variations
Weighted intervals → DP. Min removals to make non-overlapping (LC 435).

## 11. Tags
`greedy`, `intervals`, `sorting`, `difficulty:medium`
