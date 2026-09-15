# Remove Covered Intervals Sweep

## 1. Problem Statement
[LeetCode 1288](https://leetcode.com/problems/remove-covered-intervals/) — count non-covered intervals.

## 2. Intuition
Sort by start; track max end (1D sweep).

## 3. Brute Force → Optimal
- Brute O(n²). Sort O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** sort + maxR.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Survive if end > maxR.

## 6. Dry Run
Samples → 2 and 1.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Intervals folder twin.

## 9. Common Mistakes / Edge Cases
Equal-start tie-break.

## 10. Interview Follow-ups / Variations
Merge intervals.

## 11. Tags
`sweep-line`, `leetcode-1288`, `difficulty:medium`

