# Rectangle Union Area Sweep

## 1. Problem Statement
Teaching-lab — union area of AABBs via vertical sweep + covered y-length. Related [LC 850](https://leetcode.com/problems/rectangle-area-ii/).

## 2. Intuition
Between x-events, area += Δx · covered y.

## 3. Brute Force → Optimal
- Inclusion-exclusion. Sweep + y compress.

## 4. Data Structure / Approach Justification
**Chosen:** compress y; cover counts.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Update cover; accumulate.

## 6. Dry Run
Two offset squares → 7.

## 7. Time & Space Complexity
**O(n²)** naive y.

## 8. Trade-offs & Alternatives
Segtree for y measure.

## 9. Common Mistakes / Edge Cases
y open/closed.

## 10. Interview Follow-ups / Variations
LC 850.

## 11. Tags
`sweep-line`, `geometry`, `teaching-lab`, `difficulty:hard`

