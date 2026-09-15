# Spiral Matrix II

## 1. Problem Statement
[LeetCode 59](https://leetcode.com/problems/spiral-matrix-ii/) — Given `n`, generate an `n×n` matrix filled with `1..n²` in spiral order (right, down, left, up), layer by layer.

- **Inputs:** `int n`.
- **Output:** `vector<vector<int>>` of size `n×n`.
- **Edges:** `n = 1`; even `n`; odd `n` (center cell).

## 2. Intuition
Maintain boundaries `top/bottom/left/right`. Walk each ring in four legs, then shrink the ring inward.

## 3. Brute Force → Optimal
Simulation with a visited matrix and direction deltas also works (O(n²) time/space extra for visited). Boundary shrinking fills in-place without a visited grid.

## 4. Data Structure / Approach Justification
**Chosen:** four bounds + sequential writes of `val = 1..n²`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Direction array + visited | Extra O(n²) marks; more moving parts |
| Closed-form cell formula | Exists but opaque |

This is layered **2D write traversal** — the write counterpart to reshape’s flat mapping.

## 5. Logic Walkthrough
1. Allocate `n×n` zeros; `val = 1`.
2. While bounds are valid: fill top row → right col → bottom row → left col, shrinking bounds after each leg.
3. Guard bottom/left legs when the ring collapses to a single row/column.
4. Return matrix.

## 6. Dry Run
`n=3` → ring1 fills 1..8 around the border; center gets `9` → `[[1,2,3],[8,9,4],[7,6,5]]`.

## 7. Time & Space Complexity
- **Time:** O(n²)
- **Space:** O(n²) output (O(1) extra)

## 8. Trade-offs & Alternatives
Visited+directions is easier to generalize to Spiral Matrix I (read existing matrix). Bounds style is tighter for fill-from-scratch.

## 9. Common Mistakes / Edge Cases
Missing the `top<=bottom` / `left<=right` checks before reverse legs (double-writing a row/col); off-by-one when shrinking.

## 10. Interview Follow-ups / Variations
Spiral Matrix I (read); spiral order starting upward; generate spiral for non-square.

## 11. Tags
`array`, `matrix`, `simulation`, `leetcode-59`, `difficulty:medium`
