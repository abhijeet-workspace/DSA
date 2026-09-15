# Flood Fill

## Problem Statement
[LeetCode 733](https://leetcode.com/problems/flood-fill/) — starting at `(sr, sc)`, replace the 4-connected same-color region with `color`.

- **Inputs:** `image` grid, `sr`, `sc`, `color`.
- **Output:** modified image.
- **Valid answer:** only the connected component of the start pixel recolored.
- **Edges:** start already `color` (no-op); 1×1; whole image same color.

## Intuition
DFS/BFS from the seed, recoloring every cell equal to the original color. If `oldColor == color`, stop immediately to avoid infinite recursion.

## Brute Force → Optimal
- **Brute:** scan whole grid repeatedly — wrong connectivity or O((RC)²).
- **Optimal:** one DFS/BFS visiting each cell once — **O(RC)**.

## Data Structure / Approach Justification
**Chosen:** recursive DFS in-place.

- **vs BFS:** same complexity; queue uses heap.
- **vs visited matrix:** unnecessary if you recolor immediately.

## Logic Walkthrough
Read `oldColor`. If equals `color`, return. Else DFS four ways; recolor when cell equals `oldColor`.

## Dry Run
Start `(1,1)` color `1` → paint to `2`: floods the contiguous `1`s → `[[2,2,2],[2,2,0],[2,0,1]]`.

## Time & Space Complexity
Time **O(RC)**. Space **O(RC)** recursion worst case. Why: each cell ≤ once (section 4).

## Trade-offs & Alternatives
BFS if recursion depth is a concern. Copy image if mutation of input forbidden.

## Common Mistakes / Edge Cases
Missing `oldColor == color` guard (infinite loop); 8-dir instead of 4-dir.

## Interview Follow-ups / Variations
Number of islands; paint bucket with diagonal; return size of filled region.

## Tags
`grid`, `dfs`, `bfs`, `leetcode-733`, `difficulty:easy`
