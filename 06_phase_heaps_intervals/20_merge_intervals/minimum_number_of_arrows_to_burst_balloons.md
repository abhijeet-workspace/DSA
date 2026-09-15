# Minimum Number of Arrows to Burst Balloons

## 1. Problem Statement
[LeetCode 452](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) — balloons as intervals; one arrow at x bursts all covering x; return min arrows to burst all.

- **Inputs:** `points[i]=[xstart,xend]`.
- **Output:** minimum arrows.
- **Valid answer:** greedy by earliest end.
- **Edges:** touching endpoints (must burst both if exclusive? inclusive — touch shares arrow); single; nested.

## 2. Intuition
Same as non-overlapping activity selection: sort by end; shoot at current end; skip all balloons that start ≤ end.

## 3. Brute Force → Optimal
- **Brute:** set cover style — hard.
- **Optimal:** sort by end + greedy — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sort by end, track last arrow position.

- **vs non-overlapping intervals (435):** arrows = max non-overlapping count (dual).

## 5. Logic Walkthrough
Sort by end. arrows=1, end=first.end. If next.start > end, new arrow at next.end.

## 6. Dry Run
`[[10,16],[2,8],[1,6],[7,12]]` → arrows **2**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra. Why: sort + scan (section 4).

## 8. Trade-offs & Alternatives
Interview twin of 435; watch inclusive endpoints (use `>` not `>=` when start==end arrow still hits).

## 9. Common Mistakes / Edge Cases
Sorting by start; treating touch as needing new arrow incorrectly; INT overflow on ends.

## 10. Interview Follow-ups / Variations
Non-overlapping Intervals (435); Meeting Rooms.

## 11. Tags
`intervals`, `greedy`, `sorting`, `leetcode-452`, `difficulty:medium`
