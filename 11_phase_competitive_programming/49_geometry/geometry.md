# Geometry

## Problem Statement
Computational geometry basics: point orientation (cross product), convex hull via Graham scan, and segment intersection (general + collinear cases).

- **Inputs:** point sets / two segments.
- **Output:** hull vertices in CCW order; boolean intersection.
- **Valid answer:** minimal convex polygon covering all points; true iff segments share a point.
- **Edges:** <3 points → empty hull; collinear overlaps; integer overflow on cross.

## Intuition
Cross product sign gives turn direction. Graham scan sorts by polar angle around the lowest point, then keeps only left turns. Segments intersect if endpoints lie on opposite sides of each other (with collinear on-segment checks).

## Brute Force → Optimal
- **Brute:** check all point triples for hull edges — O(N³); geometric libraries heavy.
- **Optimal:** Graham / Andrew monotone chain — O(N log N); orientation tests O(1).

## Data Structure / Approach Justification
**Chosen:** `Point` struct; global pivot for polar sort; stack-like hull vector.

- **vs Andrew monotone chain:** similar complexity; often fewer floats / cleaner.
- **vs Jarvis march:** O(NH) better only for tiny hull size H.

## Logic Walkthrough
Find lowest (then leftmost) pivot; sort by CCW angle (closer first if collinear); drop same-angle intermediates; push while not CCW turn. Intersect: four orientations + four collinear on-segment fallbacks.

## Dry Run
Points include `(0,0),(0,3),(3,1),(4,4),…`. Hull extremes typically `(0,0),(3,1),(4,4),(0,3)`.
Segments `(1,1)-(10,1)` and `(1,2)-(10,2)`: orientations never opposite → **no** intersect.

## Time & Space Complexity
Hull **O(N log N)** time (sort), **O(N)** space. Orientation/intersect **O(1)**. Why: sort dominates (section 4).

## Trade-offs & Alternatives
Integer cross avoids float angles but needs 64-bit. For online hull or dynamic points, use other structures.

## Common Mistakes / Edge Cases
Int overflow on `(q.y-p.y)*(r.x-q.x)`; wrong turn test (`!=2` vs `==1`); forgetting collinear segment overlap; mutating input order unexpectedly.

## Interview Follow-ups / Variations
Closest pair; polygon area / point-in-polygon; line sweep intersections; rotating calipers diameter.

## Tags
`geometry`, `convex-hull`, `graham-scan`, `orientation`, `segments`, `difficulty:medium`
