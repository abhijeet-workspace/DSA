# Check If It Is a Straight Line (LC 1232)

## 1. Problem Statement
[LeetCode 1232 — Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/): return true iff all points lie on one line.

- **Inputs:** coordinates.
- **Output:** bool.
- **Edges:** 2 points → true.

## 2. Intuition
All points share orientation 0 vs first segment (cross product 0).

## 3. Brute Force → Optimal
- **Brute:** slopes pairwise floats.
- **Optimal:** O(n) integer crosses.

## 4. Data Structure / Approach Justification
**Chosen:** fix points[0],points[1]; test rest.

**Pedagogy:** collinearity batch check.

## 5. Logic Walkthrough
dx,dy from first edge; for each p cross with dx,dy == 0.

## 6. Dry Run
Collinear sample → true; one off → false.

## 7. Time & Space Complexity
Time **O(n)**.

## 8. Trade-offs & Alternatives
Vertical/horizontal handled naturally.

## 9. Common Mistakes / Edge Cases
Overflow without long long.

## 10. Interview Follow-ups / Variations
Regression line fit (different problem).

## 11. Tags
`geometry`, `leetcode-1232`, `difficulty:easy`
