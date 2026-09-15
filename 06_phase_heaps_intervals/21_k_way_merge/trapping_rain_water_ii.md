# Trapping Rain Water II

## 1. Problem Statement
[LeetCode 407](https://leetcode.com/problems/trapping-rain-water-ii/) — 3D bars on a grid; compute trapped rain water volume (cannot leak past lower boundary).

- **Inputs:** `heightMap` m×n.
- **Output:** total trapped water units.
- **Valid answer:** min-heap multi-source BFS from borders.
- **Edges:** flat; 1-row; bowl shape.

## 2. Intuition
Water level inside is governed by the lowest boundary on the path out. Process cells from lowest boundary inward with a min-heap.

## 3. Brute Force → Optimal
- **Brute:** per cell search — too slow.
- **Optimal:** heap BFS — O(MN log MN).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of boundary heights + visited.

- **Adjacent** best-first / multi-source heap (same toolkit as k-way).

## 5. Logic Walkthrough
Push all border cells. Pop lowest; for each unvisited neighbor, trap max(0, h-neighbor), push max(h, neighborHeight).

## 6. Dry Run
sample map traps **4**.

## 7. Time & Space Complexity
Time **O(MN log MN)**. Space **O(MN)**. Why: each cell once in heap (section 4).

## 8. Trade-offs & Alternatives
Hard classic; belongs next to k-way as advanced heap usage.

## 9. Common Mistakes / Edge Cases
Starting from interior; not taking max(h, nh) when pushing; double visit.

## 10. Interview Follow-ups / Variations
Trapping Rain Water I; Swim in Rising Water (elsewhere).

## 11. Tags
`heap`, `bfs`, `k-way-merge-adjacent`, `leetcode-407`, `difficulty:hard`
