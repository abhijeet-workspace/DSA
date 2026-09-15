# Rotating Calipers — Diameter — Teaching Lab

## 1. Problem Statement
**Teaching lab:** compute the diameter (farthest pair) of a point set via convex hull + rotating calipers (antipodal pairs).

- **Inputs:** points.
- **Output:** max distance.
- **Edges:** ≤1 point → 0.

## 2. Intuition
Farthest pair lies on hull. Calipers rotate maintaining antipodal edges.

## 3. Brute Force → Optimal
- **Brute:** O(n²) or O(h²) on hull.
- **Optimal:** O(n log n + h).

## 4. Data Structure / Approach Justification
**Chosen:** Andrew hull then O(h) two-pointer antipodes.

**Pedagogy:** teaching lab; skipped self-crossing LC as uncertain/hard without clear demo value.

## 5. Logic Walkthrough
Hull; i,j antipodes advance by cross comparison of edges.

## 6. Dry Run
Square side 1 → diameter √2.

## 7. Time & Space Complexity
Time **O(n log n)**.

## 8. Trade-offs & Alternatives
Width (min calipers) similar.

## 9. Common Mistakes / Edge Cases
Wrong hull orientation.

## 10. Interview Follow-ups / Variations
Minimum width; enclosing rectangle.

## 11. Tags
`rotating-calipers`, `teaching-lab`, `difficulty:hard`
