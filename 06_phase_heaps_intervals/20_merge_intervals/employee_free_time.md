# Employee Free Time

## 1. Problem Statement
[LeetCode 759](https://leetcode.com/problems/employee-free-time/) — each employee has sorted busy intervals; return common free time as open gaps in the global busy union (finite gaps only).

- **Inputs:** list of interval lists.
- **Output:** free intervals `[start,end)`.
- **Valid answer:** times when nobody is busy.
- **Edges:** touching intervals; nested; no gap.

## 2. Intuition
Merge all busy intervals like Merge Intervals; every gap between merged blocks is free time.

## 3. Brute Force → Optimal
- **Brute:** sweep all endpoints — OK but heavier.
- **Optimal:** flatten + sort + merge scan — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** vector of all intervals + sort by start.

- **vs k-way merge with heap:** better when lists are already sorted and huge.

## 5. Logic Walkthrough
Sort by start; track running `end`; if next.start > end, emit free `[end, next.start]`.

## 6. Dry Run
Busy covers [1,3] and [4,10] → free `[3,4]`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Line sweep with +1/-1 counts.

## 9. Common Mistakes / Edge Cases
Treating touching intervals as free; including infinite rays.

## 10. Interview Follow-ups / Variations
Meeting Rooms II; My Calendar.

## 11. Tags
`intervals`, `sorting`, `merge`, `leetcode-759`, `difficulty:hard`
