# 01 Matrix

## Problem Statement
[LeetCode 542](https://leetcode.com/problems/01-matrix/) — given a binary matrix, return a matrix where each cell holds the distance to the nearest `0`.

- **Inputs:** `mat[m][n]` of 0/1.
- **Output:** `dist[m][n]` with non-negative distances.
- **Valid answer:** Manhattan distance on the grid graph to closest zero.
- **Edges:** all zeros; single one surrounded; large blocks of ones.

## Intuition
Distance from many sources = multi-source BFS: enqueue every `0` at distance 0, expand outward updating neighbors with `dist+1`.

## Brute Force → Optimal
- **Brute:** from every `1`, BFS to nearest `0` — **O((MN)²)**.
- **Optimal:** one multi-source BFS — **O(MN)**.

## Data Structure / Approach Justification
**Chosen:** queue + `dist` init `INT_MAX`, zeros seeded at 0.

- **vs DP two-pass:** also **O(MN)**; BFS is the graph view.
- **vs per-cell BFS:** too slow.

## Logic Walkthrough
Seed all zeros. Pop cell; if neighbor’s dist can improve to `dist+1`, update and push.

## Dry Run
`[[0,0,0],[0,1,0],[1,1,1]]` → center `1` gets 1; bottom-middle gets 2.

## Time & Space Complexity
Time **O(MN)**. Space **O(MN)** for queue/dist. Why: each cell enqueued bounded times (section 4).

## Trade-offs & Alternatives
Two-pass DP uses less queue memory. Same pattern as rotting oranges / walls-and-gates.

## Common Mistakes / Edge Cases
Starting BFS only from ones; not initializing zeros to 0; overflow if using a small sentinel.

## Interview Follow-ups / Variations
Nearest exit; walls and gates (286); 01 matrix with obstacles.

## Tags
`grid`, `bfs`, `multi-source`, `leetcode-542`, `difficulty:medium`
