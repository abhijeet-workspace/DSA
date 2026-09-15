# Valid Boomerang (LC 1037)

## 1. Problem Statement
[LeetCode 1037 — Valid Boomerang](https://leetcode.com/problems/valid-boomerang/): three points form a boomerang iff they are distinct and not collinear.

- **Inputs:** points[3][2].
- **Output:** bool.
- **Edges:** duplicates; vertical lines.

## 2. Intuition
Area via cross product ≠ 0 ⇔ not collinear.

## 3. Brute Force → Optimal
- **Brute:** slopes compare floats.
- **Optimal:** integer cross O(1).

## 4. Data Structure / Approach Justification
**Chosen:** (b−a)×(c−a) ≠ 0 and points distinct.

**Pedagogy:** orientation micro-drill from geometry toolkit.

## 5. Logic Walkthrough
cross = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1).

## 6. Dry Run
`[[1,1],[2,3],[3,2]]` → true.

## 7. Time & Space Complexity
Time **O(1)**.

## 8. Trade-offs & Alternatives
Use long long for large coords.

## 9. Common Mistakes / Edge Cases
Treating duplicates as valid.

## 10. Interview Follow-ups / Variations
Polygon simple check.

## 11. Tags
`geometry`, `leetcode-1037`, `difficulty:easy`
