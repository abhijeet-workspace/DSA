# Maximum Compatibility Score Sum

## 1. Problem Statement
[LeetCode 1947](https://leetcode.com/problems/maximum-compatibility-score-sum/) — assign each student to one mentor to maximize sum of agreement scores.

- **Inputs:** `students`, `mentors` binary questionnaires.
- **Output:** max total score.
- **Edges:** m=1; identical answers.

## 2. Intuition
Maximum-weight assignment on complete bipartite graph; m≤8 ⇒ permute or DP/Hungarian.

## 3. Brute Force → Optimal
- **Brute:** m! permutations (this file).
- **Optimal for larger m:** Hungarian / min-cost matching.

## 4. Data Structure / Approach Justification
**Chosen:** score matrix + `next_permutation` (matches constraints).

| Alternative | Note |
|-------------|------|
| Bitmask DP | O(m²·2^m) |
| Hungarian | General |

## 5. Logic Walkthrough
Build compatibility matrix; maximize trace over permutations.

## 6. Dry Run
LC sample → `8`.

## 7. Time & Space Complexity
Time **O(m!·m)** here. Space **O(m²)**.

## 8. Trade-offs & Alternatives
Gateway to assignment / Hungarian in this folder.

## 9. Common Mistakes / Edge Cases
Reusing mentors; scoring XOR wrong.

## 10. Interview Follow-ups / Variations
LC 1066 Campus Bikes II.

## 11. Tags
`leetcode-1947`, `assignment`, `bipartite`, `difficulty:medium`
