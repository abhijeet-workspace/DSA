# Geometry

## 1. Problem Statement
Computational geometry basics: point orientation (cross product), convex hull via Graham scan, and segment intersection (general + collinear cases).

- **Inputs:** point sets / two segments.
- **Output:** hull vertices in CCW order; boolean intersection.
- **Valid answer:** minimal convex polygon covering all points; true iff segments share a point.
- **Edges:** <3 points → empty hull; collinear overlaps; integer overflow on cross.

## 2. Intuition

Cross product sign gives turn direction. Graham scan sorts by polar angle; segments intersect via
orientations.

## 3. Brute Force → Optimal

- **Brute:** O(N³) hull edges.
- **Optimal:** Graham / Andrew O(N log N).

## 4. Data Structure / Approach Justification

**Chosen:** Point struct; Graham scan; orientation tests.

**Pedagogy:** toolkit teaching lab. Later files isolate LC geometry and Andrew hull / closest pair
labs.

## 5. Logic Walkthrough

Lowest pivot; polar sort; keep left turns. Intersect: four orientations + on-segment.

## 6. Dry Run

Classic samples in companion `.cpp`.

## 7. Time & Space Complexity

Hull **O(N log N)**; orientation **O(1)**.

## 8. Trade-offs & Alternatives

Andrew monotone chain often cleaner; Jarvis O(NH).

## 9. Common Mistakes / Edge Cases

Int overflow on cross; collinear overlap misses.

## 10. Interview Follow-ups / Variations

Closest pair; rotating calipers; polygon area.

## 11. Tags

`geometry`, `convex-hull`, `graham-scan`, `difficulty:medium`
