# Remove Covered Intervals

## 1. Problem Statement
[LeetCode 1288](https://leetcode.com/problems/remove-covered-intervals/) — return how many intervals remain after removing every interval covered by another. `A` covers `B` iff `A[0] <= B[0]` and `A[1] >= B[1]`.

- **Inputs:** `vector<vector<int>> intervals`.
- **Output:** count of uncovered intervals.
- **Valid answer:** number left after all covered removals.
- **Edges:** identical intervals; nested; same start different ends; single interval.

## 2. Intuition
Sort by start ascending; for equal starts put larger end first. Then a later interval is covered iff its end ≤ the running max end among previous keepers.

## 3. Brute Force → Optimal
- **Brute:** for each interval check all others for coverage — O(N²).
- **Optimal:** sort + one pass tracking `max_end` — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** custom sort then linear scan.

- **vs nested checks:** correct but quadratic.
- **vs sweep line:** unnecessary for cover-count only.

## 5. Logic Walkthrough
Sort. Initialize `max_end = -1`, `count = 0`. For each interval: if `end > max_end`, it is not covered → increment and update `max_end`.

## 6. Dry Run
`[[1,4],[3,6],[2,8]]` sorted → `[1,4],[2,8],[3,6]`. Keep `[1,4]` (max_end=4), keep `[2,8]` (max_end=8), drop `[3,6]` → count 2.

`[[1,2],[1,4],[3,4]]` → sort puts `[1,4]` before `[1,2]` → keep only `[1,4]` → 1.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra (sort may use O(log N)). Why: sort dominates (section 4).

## 8. Trade-offs & Alternatives
Same-start longer-first is essential; without it equal-start nested cases fail.

## 9. Common Mistakes / Edge Cases
Sorting only by start; counting removals instead of remaining; treating touching as cover incorrectly.

## 10. Interview Follow-ups / Variations
Actually return the uncovered list; merge intervals; remove duplicates.

## 11. Tags
`intervals`, `sorting`, `greedy`, `leetcode-1288`, `difficulty:medium`
