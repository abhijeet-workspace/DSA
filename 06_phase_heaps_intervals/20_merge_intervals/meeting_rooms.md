# Meeting Rooms

## 1. Problem Statement
[LeetCode 252](https://leetcode.com/problems/meeting-rooms/) (premium) — return whether a person can attend all meetings (no two overlap).

- **Inputs:** `vector<vector<int>> intervals` of `[start, end]`.
- **Output:** `true` if no overlaps, else `false`.
- **Valid answer:** boolean feasibility.
- **Edges:** empty; single; touching endpoints (`end == next.start` OK); nested.

## 2. Intuition
Sort by start. After sorting, the first conflict (if any) is between adjacent meetings — check `start_i < end_{i-1}`.

## 3. Brute Force → Optimal
- **Brute:** compare every pair — O(N²).
- **Optimal:** sort + adjacent check — O(N log N) time, O(1) extra space.

## 4. Data Structure / Approach Justification
**Chosen:** in-place sort of intervals, then linear scan of neighbors.

- **vs sweep line (+1/-1 events):** works but heavier for a boolean answer.
- **vs nested loops:** correct but fails large-N interview targets.

## 5. Logic Walkthrough
Sort intervals. For each `i ≥ 1`, if `intervals[i][0] < intervals[i-1][1]`, return false. Else true.

## 6. Dry Run
`[[0,30],[5,10],[15,20]]`:
- sorted same order
- `5 < 30` → conflict → `false`

`[[7,10],[2,4]]` → sorted `[[2,4],[7,10]]`, `7 >= 4` → `true`

## 7. Time & Space Complexity
Time **O(N log N)** (sort). Space **O(1)** extra (aside from sort). Why: only adjacent pairs matter after sort (section 4).

## 8. Trade-offs & Alternatives
Sort-check is enough for yes/no. Need room count → Meeting Rooms II (253) with heap or sweep.

## 9. Common Mistakes / Edge Cases
Treating `end == next.start` as overlap; forgetting empty/single; sorting by end instead of start (still works for this check if careful, but start-sort is standard).

## 10. Interview Follow-ups / Variations
Minimum rooms (253)? Max concurrent meetings? Can you attend if one meeting can be moved?

## 11. Tags
`intervals`, `sorting`, `greedy`, `leetcode-252`, `difficulty:easy`
