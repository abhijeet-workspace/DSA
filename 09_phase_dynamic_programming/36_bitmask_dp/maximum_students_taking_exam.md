# Maximum Students Taking Exam

## Problem Statement
[LeetCode 1349](https://leetcode.com/problems/maximum-students-taking-exam/) — seat students on seats; no cheating left-right/diagonal; maximize.

- **Inputs:** `seats` char grid (# wall, . seat).
- **Output:** max students.
- **Valid answer:** valid seating max.
- **Edges:** all walls; single row.

## Intuition
Bitmask DP per row: valid masks; transition with prev row.

## Brute Force → Optimal
- **Brute:** 2^(m*n).
- **Optimal:** O(R * 2^{2C}).

## Data Structure / Approach Justification
**Chosen:** dp[row][mask] max students.

## Logic Walkthrough
Skip invalid masks (adjacent bits / walls); check diagonal vs prev.

## Dry Run
Sample -> **4**.

## Time & Space Complexity
Time **O(R*4^C)**. Space **O(2^C)**. Why: row masks (section 4).

## Trade-offs & Alternatives
C<=8 typical.

## Common Mistakes / Edge Cases
Allowing adjacent seats; ignoring #.

## Interview Follow-ups / Variations
Bitmask grid DP.

## Tags
`bitmask-dp`, `leetcode-1349`, `difficulty:hard`
