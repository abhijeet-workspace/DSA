# Line Segment Intersection — Teaching Lab

## 1. Problem Statement
**Teaching lab:** decide whether two closed segments properly intersect or overlap (including endpoints).

- **Inputs:** segments AB, CD.
- **Output:** bool.
- **Edges:** collinear overlap; T-junction.

## 2. Intuition
General case: orientations differ on both segments. Collinear: on-segment projections.

## 3. Brute Force → Optimal
- **Brute:** parametric solve floats.
- **Optimal:** integer orientations O(1).

## 4. Data Structure / Approach Justification
**Chosen:** orientation + onSegment.

**Pedagogy:** focused lab of routines also sketched in `geometry` toolkit.

## 5. Logic Walkthrough
ori(A,B,C) etc.; proper intersection or collinear on-seg.

## 6. Dry Run
Crossing segments true; parallel disjoint false.

## 7. Time & Space Complexity
Time **O(1)**.

## 8. Trade-offs & Alternatives
Sweep for many segments.

## 9. Common Mistakes / Edge Cases
Overflow; missing collinear overlap.

## 10. Interview Follow-ups / Variations
Intersection point coordinates.

## 11. Tags
`segments`, `teaching-lab`, `difficulty:medium`
