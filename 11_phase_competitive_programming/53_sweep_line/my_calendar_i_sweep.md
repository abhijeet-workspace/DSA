# My Calendar I Sweep

## 1. Problem Statement
[LeetCode 729](https://leetcode.com/problems/my-calendar-i/) — book iff no overlap.

## 2. Intuition
Ordered set = dynamic active intervals.

## 3. Brute Force → Optimal
- List O(n). Set O(log n).

## 4. Data Structure / Approach Justification
**Chosen:** set of pairs; check neighbors.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
lower_bound; conflict; insert.

## 6. Dry Run
10-20 ok; 15-25 fail; 20-30 ok.

## 7. Time & Space Complexity
**O(log n)**/book.

## 8. Trade-offs & Alternatives
Intervals folder twin.

## 9. Common Mistakes / Edge Cases
Half-open ends.

## 10. Interview Follow-ups / Variations
Calendar II/III.

## 11. Tags
`sweep-line`, `leetcode-729`, `difficulty:medium`

