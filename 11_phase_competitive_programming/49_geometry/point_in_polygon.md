# Point in Polygon — Teaching Lab

## 1. Problem Statement
**Teaching lab:** determine if a point is inside a simple polygon (ray casting / winding). Demo ray casting: count crossings of a horizontal ray to +∞.

- **Inputs:** polygon vertices CCW/CW, query point.
- **Output:** inside bool (boundary optional).
- **Edges:** point on edge; vertices touching ray.

## 2. Intuition
Odd crossings ⇒ inside (Jordan curve).

## 3. Brute Force → Optimal
- **Brute:** angle sum winding.
- **Chosen:** ray casting O(n).

## 4. Data Structure / Approach Justification
**Chosen:** crossings test with careful edge rules.

**Pedagogy:** teaching lab classic CG; not a single LC.

## 5. Logic Walkthrough
For each edge, if straddles y of point and intersection x > qx, flip.

## 6. Dry Run
Square (0,0)-(2,2), point (1,1) → inside.

## 7. Time & Space Complexity
Time **O(n)**.

## 8. Trade-offs & Alternatives
Winding number for nonsimple.

## 9. Common Mistakes / Edge Cases
Boundary double-count; horizontal edges.

## 10. Interview Follow-ups / Variations
Multiple queries offline.

## 11. Tags
`point-in-polygon`, `teaching-lab`, `difficulty:medium`
