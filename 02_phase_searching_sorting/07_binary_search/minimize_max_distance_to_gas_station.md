# Minimize Max Distance to Gas Station

## Problem Statement
[LeetCode 774](https://leetcode.com/problems/minimize-max-distance-to-gas-station/) — stations on a line; add `k` new stations (anywhere on the line). Minimize the max adjacent distance. Premium.

- **Inputs:** `stations`, `k`.
- **Output:** `double` (1e-6 error allowed).
- **Valid answer:** smallest D such that extra stations can cut every gap to ≤ D.
- **Edges:** k=0; many extras in one large gap.

## Intuition
Smaller D needs more extra stations (monotone). Binary search the real-valued answer.

## Brute Force → Optimal
- **Brute:** heuristic placement without search.
- **Optimal:** 80-iteration binary search on doubles — O(N log(range/eps)).

## Data Structure / Approach Justification
**Chosen:** floating search-on-answer. Gap `g` needs `ceil(g/D)-1` extra stations.

- **vs integer scaled search:** possible if you multiply by 1e6
- **vs greedy heap of gaps:** classic alternative

## Logic Walkthrough
If total extras needed ≤ k, try smaller D.

## Dry Run
`1..10` with 9 extras → 0.5.

## Time & Space Complexity
Time **O(N · I)** with I≈80. Space **O(1)**. Why: constant iterations of a linear gap scan.

## Trade-offs & Alternatives
A max-heap of current gaps is the discrete greedy view.

## Common Mistakes / Edge Cases
Using floor instead of ceil-1; infinite loop with a too-small epsilon.

## Interview Follow-ups / Variations
Divide chocolate; magnetic force between balls.

## Tags
`binary-search`, `floating`, `premium`, `leetcode-774`, `difficulty:hard`
