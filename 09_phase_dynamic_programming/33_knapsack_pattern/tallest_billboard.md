# Tallest Billboard

## Problem Statement
[LeetCode 956](https://leetcode.com/problems/tallest-billboard/) — split rods into two supports of equal height; maximize that height (unused rods allowed).

- **Inputs:** `rods`.
- **Output:** max equal height (0 if impossible).
- **Valid answer:** two disjoint subsets with equal sum, maximize that sum.
- **Edges:** empty; all unused.

## Intuition
DP on difference: dp[diff] = max taller height achieving that diff.

## Brute Force → Optimal
- **Brute:** assign each rod left/right/none — 3^N.
- **Optimal:** DP on diff O(N·Σ).

## Data Structure / Approach Justification
**Chosen:** map/diff: for each rod update new diffs from a copy.

- **vs two subset sums:** difference DP is compact.

## Logic Walkthrough
Start dp[0]=0; for each rod expand add-to-taller / add-to-shorter.

## Dry Run
[1,2,3,6] → **6**.

## Time & Space Complexity
Time **O(N·Σ)**. Space **O(Σ)**. Why: diff states bounded by sum (section 4).

## Trade-offs & Alternatives
Meet-in-the-middle for larger constraints.

## Common Mistakes / Edge Cases
Forcing use of all rods; mutating map while iterating.

## Interview Follow-ups / Variations
Last Stone II; partition variants.

## Tags
`knapsack`, `leetcode-956`, `difficulty:hard`
