# Sparse Matrix Multiplication

## Problem Statement
[LeetCode 311](https://leetcode.com/problems/sparse-matrix-multiplication/) — compute `C = A × B` where A and B are sparse.

- **Inputs:** matrices `A` (m×k), `B` (k×n).
- **Output:** dense `C` (m×n).
- **Valid answer:** standard matrix product.
- **Edges:** all-zero rows/cols; 1×1; negatives.

## Intuition
Skip zero contributions: only multiply non-zero A entries with non-zero B row entries.

## Brute Force → Optimal
- **Brute:** triple loop over all i,t,j — O(mkn).
- **Optimal:** compress B rows to non-zero lists; skip zero A cells — much faster when sparse.

## Data Structure / Approach Justification
**Chosen:** list of `(col, value)` per B row.

- **vs CSR for A and B:** same idea, more setup.
- **vs dense multiply:** wastes work on zeros.

## Logic Walkthrough
Build `bSparse[t]`. For each `A[i][t] ≠ 0`, add `A[i][t] * B[t][j]` into `C[i][j]` for each nonzero in that B row.

## Dry Run
A row0 has 1 at col0 → contributes 7 to C[0][0].

## Time & Space Complexity
Time **O(mkn)** worst, better with sparsity. Space **O(nnz(B) + mn)** for result.

## Trade-offs & Alternatives
Full CSR/CSC libraries for production; interview wants skipping zeros.

## Common Mistakes / Edge Cases
Wrong dimensions; mutating A/B; forgetting negatives.

## Interview Follow-ups / Variations
Dot product of sparse vectors (1570); block sparse multiply.

## Tags
`matrix`, `sparse`, `leetcode-311`, `difficulty:medium`
