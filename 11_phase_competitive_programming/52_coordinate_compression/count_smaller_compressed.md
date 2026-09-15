# Count Smaller Compressed

## 1. Problem Statement
[LeetCode 315](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) — count smaller to the right.

## 2. Intuition
Right-to-left: query `<rank` then insert.

## 3. Brute Force → Optimal
- Brute O(n²). BIT O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** compress + Fenwick.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Unique sort; scan from right.

## 6. Dry Run
`[5,2,6,1]→[2,1,1,0]`.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
SegTree equivalent.

## 9. Common Mistakes / Edge Cases
No compression on large values.

## 10. Interview Follow-ups / Variations
Reverse pairs.

## 11. Tags
`coordinate-compression`, `leetcode-315`, `difficulty:hard`

