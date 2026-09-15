# Maximum Score Words Formed by Letters

## Problem Statement
[LeetCode 1255](https://leetcode.com/problems/maximum-score-words-formed-by-letters/) — max score of subset of words formable from letters (each letter once).

- **Inputs:** `words`, `letters`, `score[26]`.
- **Output:** max score.
- **Valid answer:** 0/1 subset under letter counts.
- **Edges:** empty; cannot form any.

## Intuition
Bitmask over words (n<=14): check counts feasible; max score.

## Brute Force → Optimal
- **Brute:** 2^n subsets.
- **Optimal:** O(2^n * n * L) fine for n<=14.

## Data Structure / Approach Justification
**Chosen:** enumerate masks; or DFS backtracking.

## Logic Walkthrough
For mask, aggregate letter need; if <= available, sum scores.

## Dry Run
Sample -> **23**.

## Time & Space Complexity
Time **O(2^n*n)**. Space **O(1)**. Why: small n (section 4).

## Trade-offs & Alternatives
Also classic 0/1 multi-dim knapsack.

## Common Mistakes / Edge Cases
Reusing letters beyond counts.

## Interview Follow-ups / Variations
Ones and Zeroes style.

## Tags
`bitmask-dp`, `leetcode-1255`, `difficulty:hard`
