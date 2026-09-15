# Minimum Area Rectangle (LC 939)

## 1. Problem Statement
[LeetCode 939 — Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/): among points, find axis-aligned? Actually any rectangle aligned to axes formed by points — LC939 is axis-aligned rectangles. Return min area or 0.

- **Inputs:** points.
- **Output:** min area.
- **Edges:** no rectangle → 0.

## 2. Intuition
Enumerate pairs as diagonals (axis-aligned ⇒ x and y both differ); check other two corners exist.

## 3. Brute Force → Optimal
- **Brute:** all 4-tuples.
- **Optimal:** O(n²) pair check with set.

## 4. Data Structure / Approach Justification
**Chosen:** set of points + diagonal pairs.

**Pedagogy:** rectangle geometry via point set queries.

## 5. Logic Walkthrough
For each pair with x1≠x2 and y1≠y2, if (x1,y2) and (x2,y1) exist, area=|x1-x2|*|y1-y2|.

## 6. Dry Run
`[[1,1],[1,3],[3,1],[3,3],[2,2]]` → **4**.

## 7. Time & Space Complexity
Time **O(n²)**, space **O(n)**.

## 8. Trade-offs & Alternatives
LC963 allows rotated rectangles (harder).

## 9. Common Mistakes / Edge Cases
Using same x or y as diagonal incorrectly.

## 10. Interview Follow-ups / Variations
Largest rectangle; histogram.

## 11. Tags
`geometry`, `leetcode-939`, `difficulty:medium`
