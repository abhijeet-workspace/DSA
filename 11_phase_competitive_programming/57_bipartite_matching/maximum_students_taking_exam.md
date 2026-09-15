# Maximum Students Taking Exam

## 1. Problem Statement
[LeetCode 1349](https://leetcode.com/problems/maximum-students-taking-exam/) — max students seated so nobody can cheat left/right/diagonal-left/right on adjacent rows.

- **Inputs:** seat grid `'#'` broken, `'.'` free.
- **Output:** maximum students.
- **Edges:** all broken; single row.

## 2. Intuition
Row masks with no adjacent bits; transitions forbid diagonal cheats with previous mask — DP. Equivalent hard instances reduce to independent set / matching on bipartite seat graphs.

## 3. Brute Force → Optimal
- **Brute:** subsets of seats.
- **Optimal:** bitmask DP O(R·4^C) with C≤8.

## 4. Data Structure / Approach Justification
**Chosen:** row bitmask DP.

| Alternative | Note |
|-------------|------|
| Bipartite matching on seats | Works; heavier modeling |
| Max independent set general | NP-hard |

## 5. Logic Walkthrough
Enumerate valid masks per row; transition from previous; maximize popcount sum.

## 6. Dry Run
LC sample → `4`.

## 7. Time & Space Complexity
Time **O(R·4^C)** roughly. Space **O(2^C)**.

## 8. Trade-offs & Alternatives
Shows when matching modeling vs bitmask DP is preferred.

## 9. Common Mistakes / Edge Cases
Allowing adjacent seats; ignoring diagonal constraints.

## 10. Interview Follow-ups / Variations
LC 1820 invitations (pure matching).

## 11. Tags
`leetcode-1349`, `bitmask-dp`, `bipartite-related`, `difficulty:hard`
