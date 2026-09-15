# Erect the Fence (LC 587)

## 1. Problem Statement
[LeetCode 587 — Erect the Fence](https://leetcode.com/problems/erect-the-fence/): outermost trees form the convex hull (include collinear boundary points).

- **Inputs:** points on trees.
- **Output:** hull vertices (any order).
- **Edges:** <3 points; all collinear.

## 2. Intuition
Andrew monotone chain / Graham; keep collinear by using ≤0 turn test carefully.

## 3. Brute Force → Optimal
- **Brute:** check edges.
- **Optimal:** O(n log n) hull.

## 4. Data Structure / Approach Justification
**Chosen:** Andrew monotone chain including collinear.

**Pedagogy:** LC framing of convex hull (toolkit uses Graham).

## 5. Logic Walkthrough
Sort; build lower/upper; cross ≤0 pop to keep boundary collinear variants per LC.

## 6. Dry Run
Sample trees → outer fence points.

## 7. Time & Space Complexity
Time **O(n log n)**.

## 8. Trade-offs & Alternatives
Jarvis march for small hull size.

## 9. Common Mistakes / Edge Cases
Missing collinear boundary; duplicate points.

## 10. Interview Follow-ups / Variations
Diameter; layers of onion peeling.

## 11. Tags
`convex-hull`, `leetcode-587`, `difficulty:hard`
