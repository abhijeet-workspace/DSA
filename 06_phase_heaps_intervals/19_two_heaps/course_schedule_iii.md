# Course Schedule III

## 1. Problem Statement
[LeetCode 630](https://leetcode.com/problems/course-schedule-iii/) — courses `[duration, lastDay]`; take as many as possible finishing by each course's lastDay (start at day 0, sequential).

- **Inputs:** `courses` of `[duration, lastDay]`.
- **Output:** max number of courses.
- **Valid answer:** greedy by deadline + replace longest.
- **Edges:** none fit; all fit; swap improves count.

## 2. Intuition
Sort by deadline. Take a course if it fits; if not, replace the longest already-taken duration when that helps finish earlier.

## 3. Brute Force → Optimal
- **Brute:** subsets — exponential.
- **Optimal:** sort + max-heap of durations — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** max-heap of taken course durations.

- **vs DP on days:** lastDay can be large.
- **vs two heaps:** single max-heap suffices for “drop longest”.

## 5. Logic Walkthrough
Sort by lastDay. For each course: if time+dur≤last, take; else if heap top > dur, replace top with dur and adjust time.

## 6. Dry Run
`[[100,200],[200,1300],[1000,1250],[2000,3200]]` → **3** courses.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort + heap (section 4).

## 8. Trade-offs & Alternatives
Adjacent single-heap greedy in the two-heaps practice set — same “maintain best set under time pressure” theme.

## 9. Common Mistakes / Edge Cases
Sorting by duration; forgetting time adjustment on swap; off-by-one on lastDay.

## 10. Interview Follow-ups / Variations
Course Schedule I/II (graph); Single-Threaded CPU.

## 11. Tags
`heap`, `greedy`, `scheduling`, `leetcode-630`, `difficulty:hard`
