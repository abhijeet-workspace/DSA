# Maximal Rectangle

## 1. Problem Statement
[LeetCode 85](https://leetcode.com/problems/maximal-rectangle/) — given a rows×cols binary matrix of `'0'`/`'1'`, return the area of the largest rectangle containing only `'1'`s.

- **Inputs:** `vector<vector<char>> matrix`.
- **Output:** max area (int); `0` if empty.
- **Edges:** empty matrix; all zeros; single row/col; full ones rectangle.

## 2. Intuition
Treat each row as the base of a histogram: height[j] = consecutive ones ending at this row in column `j`. Then largest rectangle in histogram (monotonic stack) per row; take the global max.

## 3. Brute Force → Optimal
- **Brute:** enumerate all sub-rectangles — O(R²C²) checks.
- **DP / stack:** maintain heights; O(C) stack per row → **O(R·C)**.

## 4. Data Structure / Approach Justification
**Chosen:** height array + largest-rectangle monotonic stack (same as LC 84).

| Alternative | Why it loses here |
|-------------|-------------------|
| Enumerate corners | Far slower |
| Maximal square DP only | Solves LC 221, not arbitrary rectangles |

## 5. Logic Walkthrough
1. `heights` init 0.
2. For each row: `heights[j] = matrix[r][j]=='1' ? heights[j]+1 : 0`.
3. Run histogram largest rectangle on `heights`; update answer.
4. Histogram: increasing stack of indices; on pop, width from previous smaller to current.

## 6. Dry Run
Classic 4×5 example with a 2×3 block of ones → area **6**.

## 7. Time & Space Complexity
- **Time:** O(R·C) — each cell updates height once; each column index pushed/popped ≤ once per row.
- **Space:** O(C) heights + stack.

## 8. Trade-offs & Alternatives
Left/right smaller arrays instead of one stack pass; treat columns as bases instead of rows (same complexity).

## 9. Common Mistakes / Edge Cases
Forgetting to reset height on `'0'`; off-by-one histogram width; sentinel missing so trailing bars never flush; confusing with maximal square.

## 10. Interview Follow-ups / Variations
Largest rectangle in histogram (84); maximal square (221); trapping rain water (related stack basins).

## 11. Tags
`stack`, `monotonic-stack`, `histogram`, `matrix`, `leetcode-85`, `difficulty:hard`
