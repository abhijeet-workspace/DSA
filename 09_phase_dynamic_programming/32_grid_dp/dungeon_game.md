# Dungeon Game

## Problem Statement
[LeetCode 174](https://leetcode.com/problems/dungeon-game/) — knight needs min initial HP to reach princess; cells add/subtract HP; HP must stay ≥ 1.

- **Inputs:** `vector<vector<int>> dungeon`.
- **Output:** min initial health.
- **Valid answer:** smallest start HP so every prefix of an optimal path stays ≥ 1.
- **Edges:** single cell; all positive; large negatives.

## Intuition
Work backward from princess: `need[i][j]` = HP required entering cell to survive optimally onward.

## Brute Force → Optimal
- **Brute:** try all paths forward tracking min HP — exponential.
- **Optimal:** reverse DP O(M·N).

## Data Structure / Approach Justification
**Chosen:** `dp[i][j]` = min HP needed before entering `(i,j)`.

- **vs forward DP:** hard because future deficits matter.
- **vs binary search on start HP + check:** also O(MN log), valid interview alt.

## Logic Walkthrough
From bottom-right: `need = max(1, 1 - dungeon[i][j] + min(right, down))`.

## Dry Run
`[[-2,-3,3],[-5,-10,1],[10,30,-5]]` → start **7**.

## Time & Space Complexity
Time **O(M·N)**. Space **O(M·N)** (or O(N) rolling). Why: each cell once (section 4).

## Trade-offs & Alternatives
Binary search on answer + simulation is clearer for some interviews.

## Common Mistakes / Edge Cases
Using 0 instead of max(1,…); iterating forward without care.

## Interview Follow-ups / Variations
Min path sum (64); binary-search-on-answer patterns.

## Tags
`2d-dp`, `grid-dp`, `leetcode-174`, `difficulty:hard`
