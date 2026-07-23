# 2D Array Basics

## 1. Problem Statement
Practice declaring 2D arrays, indexing a cell, and recovering `rows` / `columns` from `sizeof` on a live matrix object.

- **Input:** none
- **Output:** `arr[1][3]`, two `matrix2` cells, then sizing diagnostics
- **Valid answer:** prints `8`, then `2`, `4`, then dimensions for a 3×2 matrix
- **Edges:** partial row init zero-fills; `sizeof` tricks fail after array-to-pointer decay

## 2. Intuition
`T a[R][C]` is R contiguous rows of C elements. `a[r][c]` selects row `r`, then column `c`.

## 3. Brute Force → Optimal
- **Naive:** memorize literal `3` and `2` without connecting them to memory sizes.
- **This approach:** compute dimensions from byte sizes so layout becomes tangible.

## 4. Data Structure / Approach Justification
Stack-allocated 2D C arrays.

| Alternative | Why it loses here |
|-------------|-------------------|
| Dynamic `new int*[r]` jagged arrays | Manual cleanup; harder first lesson |
| `vector<vector<unsigned>>` | Flexible, but hides contiguous row layout |

## 5. Logic Walkthrough
1. `arr` is 2×5; print `arr[1][3]` → 8.
2. `matrix` shows partial initialization (remaining zeros).
3. On `matrix2` (3×2), compute:
   - `total_size_in_bytes = sizeof(matrix2)`
   - `rows = total / sizeof(row)`
   - `columns = sizeof(row) / sizeof(element)`
4. Print sample cells and the derived metrics.

## 6. Dry Run
`arr`:

|  | 0 | 1 | 2 | 3 | 4 |
|--|---|---|---|---|---|
| 0 | 0 | 1 | 2 | 3 | 4 |
| 1 | 5 | 6 | 7 | **8** | 9 |

`matrix2`: rows=3, columns=2, total_element_count=6.

## 7. Time & Space Complexity
- **Time:** O(1) for this demo (constant prints)
- **Space:** O(R*C) for the matrices
- Why: no traversal loops in this file

## 8. Trade-offs & Alternatives
- Combine with nested loops (see `arrays_basics`) for full traversal practice.
- Prefer contiguous flat storage for performance-critical grids.
- Prefer containers when dimensions are runtime inputs.

## 9. Common Mistakes / Edge Cases
- Swapping row/column indices
- Out-of-bounds access
- Using `sizeof` on a function parameter that decayed to a pointer
- Assuming uninitialized leftover elements are zero (only true with aggregate init)

## 10. Interview Follow-ups / Variations
- Implement matrix transpose in-place vs out-of-place
- Cache effects of row-major vs column-major scans
- Map 2D `(r,c)` to 1D index

## 11. Tags
`cpp-basics`, `2d-arrays`, `sizeof`, `beginner`
