# Convex Hull — Andrew Monotone Chain — Teaching Lab

## 1. Problem Statement
**Teaching lab:** compute convex hull via Andrew's monotone chain (lower + upper hull).

- **Inputs:** point set.
- **Output:** CCW hull without duplicate endpoints.
- **Edges:** <3 points; collinear.

## 2. Intuition
Sort by x; build lower with left turns; build upper similarly from right.

## 3. Brute Force → Optimal
- **Brute:** O(n³).
- **Optimal:** O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** Andrew chain with cross < 0 strict (exclude collinear mid).

**Pedagogy:** teaching lab alternative to Graham in `geometry` toolkit; related to LC587 which keeps collinear.

## 5. Logic Walkthrough
Sort; lower while cross≤0 pop (variant); concatenate.

## 6. Dry Run
Square corners → 4 hull points.

## 7. Time & Space Complexity
Time **O(n log n)**.

## 8. Trade-offs & Alternatives
Graham polar sort; Jarvis.

## 9. Common Mistakes / Edge Cases
Not removing last duplicate of lower/upper.

## 10. Interview Follow-ups / Variations
Dynamic hull; 3D.

## 11. Tags
`convex-hull`, `andrew`, `teaching-lab`, `difficulty:medium`
