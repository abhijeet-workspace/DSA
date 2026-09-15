# Perfect Rectangle

## 1. Problem Statement
[LeetCode 391](https://leetcode.com/problems/perfect-rectangle/) — exact cover without gaps/overlaps.

## 2. Intuition
Area = bbox and corner multiplicities.

## 3. Brute Force → Optimal
- Heavy geometry. Corner trick O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** area + corner map.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Accumulate; validate corners.

## 6. Dry Run
LC samples true/false.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Area alone insufficient.

## 9. Common Mistakes / Edge Cases
Odd internal corners.

## 10. Interview Follow-ups / Variations
Rectangle area II.

## 11. Tags
`sweep-line`, `leetcode-391`, `difficulty:hard`

