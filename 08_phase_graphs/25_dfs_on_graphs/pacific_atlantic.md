# Pacific Atlantic Water Flow

## Problem Statement
[LeetCode 417](https://leetcode.com/problems/pacific-atlantic-water-flow/) — return coordinates from which water can flow to **both** Pacific (top/left) and Atlantic (bottom/right). Flow is to equal-or-lower 4-neighbors.

- **Inputs:** `heights[m][n]`.
- **Output:** list of `[r,c]` reaching both oceans.
- **Valid answer:** any order of valid cells.
- **Edges:** 1×1; flat grid; strictly decreasing toward one ocean only.

## Intuition
Reverse the problem: start from ocean borders and walk **inland** to cells with height ≥ previous. Intersection of Pacific-reachable and Atlantic-reachable is the answer.

## Brute Force → Optimal
- **Brute:** from every cell DFS toward oceans — **O((MN)²)**.
- **Optimal:** two multi-source DFS/BFS from borders; intersect — **O(MN)**.

## Data Structure / Approach Justification
**Chosen:** two `visited` grids + DFS from borders.

- **vs BFS multi-source:** same asymptotics; queue may be clearer.
- **vs per-cell search:** too slow for interview constraints.

## Logic Walkthrough
Seed Pacific from top+left, Atlantic from bottom+right. DFS only to unvisited cells with `height >= prev`. Collect cells in both sets.

## Dry Run
Classic 5×5 sample yields 7 cells including `[0,4]`, `[1,3]`, `[1,4]`, `[2,2]`, …

## Time & Space Complexity
Time **O(MN)**. Space **O(MN)**. Why: each cell visited ≤ twice (section 4).

## Trade-offs & Alternatives
Reverse thinking is the interview insight. BFS equivalent; diagonals usually disallowed.

## Common Mistakes / Edge Cases
Flowing downhill from cells instead of uphill from oceans; forgetting a border; off-by-one on last row/col.

## Interview Follow-ups / Variations
Count only; allow diagonals; 3D / multiple oceans.

## Tags
`grid`, `dfs`, `multi-source`, `leetcode-417`, `difficulty:medium`
