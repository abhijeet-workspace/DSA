# Swim in Rising Water

## 1. Problem Statement
[LeetCode 778](https://leetcode.com/problems/swim-in-rising-water/) — n×n grid of unique heights. At time `t` you can enter cells ≤ t. You move 4-dir. Return least time to reach bottom-right (equals max height on the best path).

- **Inputs:** `grid`.
- **Output:** minimum t.
- **Valid answer:** minimax height on a path from start to end.
- **Edges:** n=1; increasing path.

## 2. Intuition
Path cost = max cell on path. Dijkstra/best-first expands by smallest height; track running max.

## 3. Brute Force → Optimal
- **Brute:** all paths.
- **Optimal:** Dijkstra or binary search + BFS / Union-Find on t.

## 4. Data Structure / Approach Justification
**Chosen:** min-heap on cell height (like Prim/Dijkstra on grid).

- **vs UF sorted by height:** elegant for unique heights.

## 5. Logic Walkthrough
PQ push start. Pop smallest height; ans=max(ans,h). When reach end, return ans. Push unseen neighbors.

## 6. Dry Run
`[[0,2],[1,3]]` → **3**.

## 7. Time & Space Complexity
Time **O(n² log n)**. Space **O(n²)**. Why: heap on cells (section 4).

## 8. Trade-offs & Alternatives
Binary search t with BFS connectivity.

## 9. Common Mistakes / Edge Cases
Using sum; moving only to ≤ current time without lifting t; forgetting start height.

## 10. Interview Follow-ups / Variations
Path with minimum effort; trap rain water II.

## 11. Tags
`dijkstra`, `binary-search`, `leetcode-778`, `difficulty:hard`
