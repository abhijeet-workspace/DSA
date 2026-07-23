# Arrays Basics

## 1. Problem Statement
Demonstrate 1D array initialization/traversal and a 2D matrix with `sizeof`-based dimension discovery, mutation, and nested printing.

- **Input:** none
- **Output:** 1D sizes/traversals, then 2D sizing stats and matrix dumps
- **Valid answer:** after mutation, 1D middle element is 99; `matrix[1][1]` becomes 60
- **Edges:** partial init zeros remaining slots; `sizeof` length only works on real arrays (not decayed pointers)

## 2. Intuition
Arrays store homogeneous elements contiguously. 1D uses one index; 2D uses `[row][col]` and is stored in row-major order in memory.

## 3. Brute Force → Optimal
- **Naive:** print each element with separate statements; hardcode `3` and `2` without understanding layout.
- **This approach:** index loops + `sizeof` arithmetic to derive `rows`/`columns` from the live array object.

## 4. Data Structure / Approach Justification
C-style `int arr[5]` and `unsigned int matrix[3][2]`.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `std::vector` / `vector<vector<>>` | Better dynamic sizing; heavier for first array lesson |
| `std::array` | Safer fixed wrapper — good immediate follow-up |
| Flat `int flat[6]` with manual indexing | Same memory idea; less readable for matrices |

## 5. Logic Walkthrough
1. Build `arr`, `partial_arr`, `zero_arr`; compute `n` via `sizeof`.
2. Set `arr[2] = 99`; traverse with index `for` and range-based `for`.
3. Build `matrix`; derive `rows`, `columns`, counts from `sizeof` ratios.
4. Print sample cells; set `matrix[1][1] = 60`; nest loops for labeled and tabular views.

## 6. Dry Run
1D after mutation: `10 20 99 40 50`

2D initial:

|  | c0 | c1 |
|--|----|----|
| r0 | 1 | 2 |
| r1 | 3 | 4 |
| r2 | 5 | 6 |

After `matrix[1][1] = 60`, cell (1,1) is 60. `rows=3`, `columns=2`.

## 7. Time & Space Complexity
- **Time:** O(n) for 1D; O(rows * columns) for 2D traversal
- **Space:** O(n) / O(rows * columns) for the arrays themselves
- Why: linear scans over contiguous storage

## 8. Trade-offs & Alternatives
- Prefer `std::vector` when size is runtime-dynamic.
- Prefer flat 1D indexing (`r * cols + c`) for cache-friendly contest code.
- Avoid VLAs; keep sizes as compile-time constants or use containers.

## 9. Common Mistakes / Edge Cases
- Out-of-bounds index access
- Using `sizeof` on a pointer parameter and treating it as length
- Confusing rows vs columns in nested loops
- Assuming column-major layout (C++ is row-major)

## 10. Interview Follow-ups / Variations
- How is `matrix[r][c]` addressed in memory?
- Pass 2D arrays to functions — what decays?
- When choose `vector<vector<int>>` vs flat vector?

## 11. Tags
`cpp-basics`, `arrays`, `2d-arrays`, `traversal`, `beginner`
