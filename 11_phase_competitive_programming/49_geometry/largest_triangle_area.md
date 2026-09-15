# Largest Triangle Area (LC 812)

## 1. Problem Statement
[LeetCode 812 — Largest Triangle Area](https://leetcode.com/problems/largest-triangle-area/): max area of triangle formed by any 3 points.

- **Inputs:** points.
- **Output:** area as double.
- **Edges:** collinear triples area 0.

## 2. Intuition
Shoelace / cross product absolute / 2.

## 3. Brute Force → Optimal
- **Brute:** O(n³) all triples — OK for n≤50.
- **Optimal enough** under LC constraints.

## 4. Data Structure / Approach Justification
**Chosen:** triple loop + shoelace.

**Pedagogy:** area via cross; convex hull diameter optional speedup.

## 5. Logic Walkthrough
area = 0.5*|x1(y2-y3)+…|.

## 6. Dry Run
Sample → 2.00000.

## 7. Time & Space Complexity
Time **O(n³)**.

## 8. Trade-offs & Alternatives
Hull + rotating calipers for larger n.

## 9. Common Mistakes / Edge Cases
Integer overflow before abs.

## 10. Interview Follow-ups / Variations
Polygon area; 3D tetra.

## 11. Tags
`geometry`, `leetcode-812`, `difficulty:easy`
