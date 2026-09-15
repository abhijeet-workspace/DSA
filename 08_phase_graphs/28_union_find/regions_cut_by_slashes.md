# Regions Cut By Slashes

## 1. Problem Statement
[LeetCode 959](https://leetcode.com/problems/regions-cut-by-slashes/) — `n×n` grid; each cell is `' '`, `'/'`, or `'\\'`. Slashes divide the square into regions. Return the number of regions.

- **Inputs:** `vector<string> grid` length `n`, each string length `n`.
- **Output:** region count.
- **Edges:** all spaces (1 region); dense slashes; `n=1`.

## 2. Intuition
Model each cell as 4 triangles (N/E/S/W). Slashes decide which triangles merge inside the cell; adjacent cells merge across shared edges. DSU component count = regions.

## 3. Brute Force → Optimal
- **Brute:** rasterize to fine pixels and flood fill — heavier coding.
- **Optimal:** 4n² DSU nodes — O(n² α(n²)).

## 4. Data Structure / Approach Justification
**Chosen:** DSU with 4 nodes per cell + neighbor unions.

| Alternative | Why skip |
|-------------|---------|
| Upscale 3× grid + DFS | Valid; more memory and loops |
| Dual graph edges only | Easy to mis-index slash sides |

## 5. Logic Walkthrough
1. For `'/'`: union N–W and E–S; for `'\\'`: N–E and S–W; for `' '`: union all four.
2. Union this cell’s E with right’s W; S with below’s N.
3. Return DSU `components`.

## 6. Dry Run
`[" /","/ "]`: two diagonal regions → **2**.

## 7. Time & Space Complexity
- **Time:** O(n² α(n²))
- **Space:** O(n²)

## 8. Trade-offs & Alternatives
3× upscaling is more visual for debugging; DSU is cleaner once triangle indexing is fixed.

## 9. Common Mistakes / Edge Cases
Escaping `'\\'` in strings; swapping `/` vs `\\` unions; forgetting inter-cell merges.

## 10. Interview Follow-ups / Variations
Regions with both slash types in one cell forbidden; count region areas.

## 11. Tags
`union-find`, `grid`, `graph`, `leetcode-959`, `difficulty:medium`
