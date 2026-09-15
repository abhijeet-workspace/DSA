# Car Pooling Sweep

## 1. Problem Statement
[LeetCode 1094](https://leetcode.com/problems/car-pooling/) — never exceed capacity.

## 2. Intuition
Passenger ±delta sweep / diff array.

## 3. Brute Force → Optimal
- Diff by location. Event sort if sparse.

## 4. Data Structure / Approach Justification
**Chosen:** ±passenger events.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Sort; accumulate; fail if >cap.

## 6. Dry Run
cap4 fail; cap5 ok.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Fixed diff when locs≤1000.

## 9. Common Mistakes / Edge Cases
Inclusive to bug.

## 10. Interview Follow-ups / Variations
Meeting rooms.

## 11. Tags
`sweep-line`, `leetcode-1094`, `difficulty:medium`

