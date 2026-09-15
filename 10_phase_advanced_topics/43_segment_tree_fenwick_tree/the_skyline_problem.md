# The Skyline Problem

## 1. Problem Statement
[LeetCode 218](https://leetcode.com/problems/the-skyline-problem/) — given buildings `[L,R,H]`, return the skyline key points.

- **Inputs:** list of buildings.
- **Output:** list of `[x, height]` key points.
- **Valid answer:** critical outline points left→right.
- **Edges:** touching buildings; same L; nested; empty.

## 2. Intuition
Sweep line on L/R edges; multiset of active heights; emit a point when max height changes.

## 3. Brute Force → Optimal
- **Brute:** discretize x and scan max — heavy.
- **Optimal:** sweep + multiset — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** events `(L,-H)`, `(R,H)` sorted; multiset of heights.

- **vs segment tree on x:** also valid; multiset is the classic interview solution.

## 5. Logic Walkthrough
Sort events. Process: insert/remove height; if max≠prev, push `[x,max]`.

## 6. Dry Run
`[[2,9,10],[3,7,15],…]` → classic skyline sample keypoints.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Segment tree on compressed x teaches range-max updates; more code.

## 9. Common Mistakes / Edge Cases
Wrong event sort order; forgetting height 0 sentinel; duplicate x points.

## 10. Interview Follow-ups / Variations
Falling Squares (699); soft shadows / 3D skyline.

## 11. Tags
`sweep-line`, `multiset`, `leetcode-218`, `difficulty:hard`
