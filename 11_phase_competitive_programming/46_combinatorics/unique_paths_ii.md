# Unique Paths II

## 1. Problem Statement
[LeetCode 63](https://leetcode.com/problems/unique-paths-ii/) — same as Unique Paths but grid may contain obstacles.

## 2. Intuition
DP: dp[i][j] = paths from start; zero on obstacles.

## 3. Brute Force → Optimal
- **Brute:** DFS.
- **Optimal:** O(mn) DP.

## 4. Data Structure / Approach Justification
**Chosen:** in-place / 1D DP.

- **Pedagogy:** shows when pure binomial fails (obstacles); still housed here as the obstructed companion to unique_paths.

## 5. Logic Walkthrough
First row/col prefix until obstacle; then dp[j] += dp[j-1] style.

## 6. Dry Run
[[0,0,0],[0,1,0],[0,0,0]] → 2.

## 7. Time & Space Complexity
Time **O(mn)**. Space **O(n)**.

## 8. Trade-offs & Alternatives
Combinatorics alone cannot handle obstacles.

## 9. Common Mistakes / Edge Cases
Not zeroing after obstacle in first row.

## 10. Interview Follow-ups / Variations
Count with exactly k obstacles touched.

## 11. Tags
`combinatorics`, `dp`, `leetcode-63`, `difficulty:medium`
