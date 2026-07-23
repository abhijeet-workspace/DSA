# Set Matrix Zeroes

## Problem Statement
[LeetCode 73](https://leetcode.com/problems/set-matrix-zeroes/) — if an element is 0, set its entire row and column to 0 (in-place).

- **Inputs:** `m × n` matrix of ints.
- **Output:** matrix mutated per zero rules.
- **Valid answer:** all rows/cols that contained a zero become all zeros.
- **Edges:** first cell 0; single row/col; already all zeros.

## Intuition
Use first row/col as markers; remember whether first col had a zero separately so markers are not destroyed early.

## Brute Force → Optimal
- **Brute / clearer:** extra O(M+N) marker arrays.
- **Optimal:** constant-space markers in the matrix itself.

## Data Structure / Approach Justification
**Chosen:** first row + first column as marker storage + `firstCol` flag.

- **vs boolean row/col arrays:** O(M+N) space, fewer edge-case bugs.
- **vs full matrix copy:** O(MN) space, simplest correctness.

## Logic Walkthrough
1. Scan, mark `a[i][0]` / `a[0][j]` for zeros (track `firstCol`).
2. Zero inner cells from markers.
3. Zero first row if `a[0][0]==0`, then first col if `firstCol`.

## Dry Run
`[[1,1,1],[1,0,1],[1,1,1]]` → middle row/col zeroed → `[[1,0,1],[0,0,0],[1,0,1]]`.

## Time & Space Complexity
Time **O(MN)**. Space **O(1)** extra. Why: markers live in-matrix (section 4).

## Trade-offs & Alternatives
O(1) space is the classic follow-up; O(M+N) markers are safer in production code reviews.

## Common Mistakes / Edge Cases
Zeroing first row too early and wiping column markers; forgetting separate `firstCol` flag.

## Interview Follow-ups / Variations
Sparse matrix representation; set to sentinel instead of zero.

## Tags
`matrix`, `in-place`, `markers`, `difficulty:medium`
