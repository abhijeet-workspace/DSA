# Employee Free Time Sweep

## 1. Problem Statement
[LeetCode 759](https://leetcode.com/problems/employee-free-time/) — gaps in union of all busy intervals.

## 2. Intuition
Flatten→merge→gaps.

## 3. Brute Force → Optimal
- Active-count sweep also works.

## 4. Data Structure / Approach Justification
**Chosen:** merge-all then gaps.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Sort/merge; emit holes.

## 6. Dry Run
`[3,4]` only.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Intervals folder twin.

## 9. Common Mistakes / Edge Cases
Touching intervals empty gaps.

## 10. Interview Follow-ups / Variations
Meeting rooms.

## 11. Tags
`sweep-line`, `leetcode-759`, `difficulty:hard`

