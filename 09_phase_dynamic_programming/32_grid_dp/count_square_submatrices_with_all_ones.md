# Count Square Submatrices with All Ones

## Problem Statement
[LeetCode 1277](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) — count all square submatrices filled with 1.

- **Inputs:** binary matrix.
- **Output:** count of squares.
- **Valid answer:** every size/position ones-square.
- **Edges:** empty; all ones; all zeros.

## Intuition
Same DP as Maximal Square: dp[i][j] = max side ending at cell; add that side to answer.

## Brute Force → Optimal
- **Brute:** check each square — heavy.
- **Optimal:** O(M·N) DP.

## Data Structure / Approach Justification
**Chosen:** maximal-square DP; accumulate dp[i][j] into ans.

- **vs enumerating sides:** slower.

## Logic Walkthrough
On 1: dp = 1+min(left,up,diag); ans += dp.

## Dry Run
[[0,1,1,1],[1,1,1,1],[0,1,1,1]] → **15**.

## Time & Space Complexity
Time **O(M·N)**. Space **O(1)** extra in-place. Why: each cell once (section 4).

## Trade-offs & Alternatives
In-place if allowed to overwrite matrix ints.

## Common Mistakes / Edge Cases
Only counting maximal squares.

## Interview Follow-ups / Variations
Maximal Square (221).

## Tags
`grid-dp`, `leetcode-1277`, `difficulty:medium`
