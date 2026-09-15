# Rectangle Area (LC 223)

## 1. Problem Statement
[LeetCode 223 — Rectangle Area](https://leetcode.com/problems/rectangle-area/): compute total area covered by two axis-aligned rectangles (union).

- **Inputs:** two rectangles as (ax1,ay1,ax2,ay2), (bx1,...).
- **Output:** union area.
- **Edges:** no overlap; full containment.

## 2. Intuition
areaA+areaB−intersection; intersection width/height clamped at ≥0.

## 3. Brute Force → Optimal
- **Brute:** discretize grid.
- **Optimal:** O(1) formula.

## 4. Data Structure / Approach Justification
**Chosen:** long long areas with overlap intervals.

**Pedagogy:** AABB geometry classic.

## 5. Logic Walkthrough
overlapX = max(0, min(ax2,bx2)-max(ax1,bx1)) similarly Y.

## 6. Dry Run
Sample LC → 45.

## 7. Time & Space Complexity
Time **O(1)**.

## 8. Trade-offs & Alternatives
Inclusion for many rects harder (sweep).

## 9. Common Mistakes / Edge Cases
int overflow; inverted corners.

## 10. Interview Follow-ups / Variations
Rectangle overlap LC836; skyline.

## 11. Tags
`geometry`, `leetcode-223`, `difficulty:medium`
