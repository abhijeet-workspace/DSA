# Unique Paths

## 1. Problem Statement
[LeetCode 62](https://leetcode.com/problems/unique-paths/) — robot on m×n grid, only right/down; count paths from top-left to bottom-right.

## 2. Intuition
Paths = C(m+n-2, m-1): choose down-moves among total moves.

## 3. Brute Force → Optimal
- **Brute:** DFS recurse.
- **Optimal:** combinatorics or DP.

## 4. Data Structure / Approach Justification
**Chosen:** multiplicative formula for nCr.

- **Pedagogy:** combinatorics framing; grid DP topic teaches the DP table view of the same count.

## 5. Logic Walkthrough
Compute C(m+n-2, m-1) with iterative multiply/divide to avoid overflow where possible.

## 6. Dry Run
m=3,n=7 → 28.

## 7. Time & Space Complexity
Time **O(min(m,n))**. Space **O(1)**.

## 8. Trade-offs & Alternatives
DP is clearer with obstacles (LC 63).

## 9. Common Mistakes / Edge Cases
Integer overflow; choosing wrong binomial argument.

## 10. Interview Follow-ups / Variations
Unique Paths II; 3D grids.

## 11. Tags
`combinatorics`, `binomial`, `leetcode-62`, `difficulty:medium`
