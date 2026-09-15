# Closest Pair of Points — Teaching Lab

## 1. Problem Statement
**Teaching lab:** find the minimum Euclidean distance among n points (divide and conquer O(n log n)).

- **Inputs:** points.
- **Output:** min distance (double).
- **Edges:** n=2.

## 2. Intuition
Sort by x; recurse left/right; then strip of width δ around mid checked in y-order.

## 3. Brute Force → Optimal
- **Brute:** O(n²) all pairs.
- **Optimal:** O(n log n) DivConq.

## 4. Data Structure / Approach Justification
**Chosen:** classic closest-pair DivConq (also provide brute for n small).

**Pedagogy:** teaching lab classic CG algorithm.

## 5. Logic Walkthrough
δ=min(left,right); sort strip by y; check next ≤7 neighbors.

## 6. Dry Run
Points (0,0),(3,4) → 5.

## 7. Time & Space Complexity
Time **O(n log n)**.

## 8. Trade-offs & Alternatives
Brute for n≤40; integer squared distances to compare.

## 9. Common Mistakes / Edge Cases
Not sorting strip; wrong strip width.

## 10. Interview Follow-ups / Variations
bichromatic closest pair.

## 11. Tags
`closest-pair`, `divide-conquer`, `teaching-lab`, `difficulty:hard`
