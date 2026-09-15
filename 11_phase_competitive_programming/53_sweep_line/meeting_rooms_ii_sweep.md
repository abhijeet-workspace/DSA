# Meeting Rooms II Sweep

## 1. Problem Statement
[LeetCode 253](https://leetcode.com/problems/meeting-rooms-ii/) — min rooms = max concurrent meetings.

## 2. Intuition
+1 start, −1 end; track depth.

## 3. Brute Force → Optimal
- Heap of ends. Sweep events classic.

## 4. Data Structure / Approach Justification
**Chosen:** event sort; ends before starts at equal time.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Sort; maintain cur/max.

## 6. Dry Run
Samples → 2 and 1.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Also in intervals folder.

## 9. Common Mistakes / Edge Cases
Starts before ends at same time.

## 10. Interview Follow-ups / Variations
Car pooling.

## 11. Tags
`sweep-line`, `leetcode-253`, `difficulty:medium`

