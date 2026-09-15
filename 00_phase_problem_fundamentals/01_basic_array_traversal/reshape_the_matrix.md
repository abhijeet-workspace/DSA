# Reshape the Matrix

## 1. Problem Statement
[LeetCode 566](https://leetcode.com/problems/reshape-the-matrix/) — Reshape `mat` (`m×n`) into `r×c` in row-major order. If impossible (`m*n != r*c`), return original `mat`.

- **Inputs:** `vector<vector<int>> mat`, `int r`, `int c`.
- **Output:** Reshaped matrix or original.
- **Edges:** Same shape; impossible reshape; `1×N` ↔ `N×1`.

## 2. Intuition
Row-major flat index `k = i*n + j` lands at `(k/c, k%c)` in the new layout. One nested scan copies every cell.

## 3. Brute Force → Optimal
Must touch every element once — O(mn). Flattening into a temporary 1D vector then rebuilding is the same asymptotics with more memory.

## 4. Data Structure / Approach Justification
**Chosen:** direct flat-index mapping while scanning the source.

| Alternative | Why it loses here |
|-------------|-------------------|
| Explicit 1D buffer then refill | Extra O(mn) space |
| Column-major tricks | Wrong order vs problem statement |

This is the clean introduction to **flat ↔ 2D index math** without simulation neighbors (unlike Game of Life).

## 5. Logic Walkthrough
1. If `m*n != r*c`, return `mat`.
2. Allocate `ans[r][c]`.
3. For each `(i,j)`, `k = i*n+j`, write `ans[k/c][k%c] = mat[i][j]`.
4. Return `ans`.

## 6. Dry Run
`[[1,2],[3,4]]` → `r=1,c=4` → flat `k=0..3` → `[[1,2,3,4]]`.

## 7. Time & Space Complexity
- **Time:** O(mn)
- **Space:** O(rc) for output (O(1) extra beyond that)

## 8. Trade-offs & Alternatives
Returning the original on failure avoids allocation; some APIs prefer an error — follow the problem contract.

## 9. Common Mistakes / Edge Cases
Using `k/r` / `k%r` swapped; forgetting the impossibility check; empty matrix (constraints usually non-empty).

## 10. Interview Follow-ups / Variations
Reshape with column-major order; sparse matrix reshape.

## 11. Tags
`array`, `matrix`, `indexing`, `leetcode-566`, `difficulty:easy`
