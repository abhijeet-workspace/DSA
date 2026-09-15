# The Skyline Problem Full

## 1. Problem Statement
[LeetCode 218](https://leetcode.com/problems/the-skyline-problem/) — full critical points. Complements `sweep_skyline`.

## 2. Intuition
Enter/leave; multiset heights; emit on max change.

## 3. Brute Force → Optimal
- Discrete paint. Multiset O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** negative-height sort trick.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Sort; update multiset; compare max.

## 6. Dry Run
LC sample 7 points.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Cross-ref sweep_skyline.

## 9. Common Mistakes / Edge Cases
`erase(h)` vs `find`.

## 10. Interview Follow-ups / Variations
3D skyline.

## 11. Tags
`sweep-line`, `leetcode-218`, `difficulty:hard`

