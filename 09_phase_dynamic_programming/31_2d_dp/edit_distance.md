# Edit Distance

## Problem Statement
[LeetCode 72](https://leetcode.com/problems/edit-distance/) — minimum insert / delete / replace operations to convert `word1` into `word2`.

- **Inputs:** strings `word1`, `word2`.
- **Output:** non-negative integer distance.
- **Valid answer:** Levenshtein distance (unit cost per op).
- **Edges:** empty string; identical strings; one empty.

## Intuition
Align prefixes: equal last chars → copy diagonal; else take min of delete, insert, replace + 1.

## Brute Force → Optimal
- **Brute:** recurse on all three ops at each mismatch — exponential.
- **Optimal:** 2D DP on prefixes — O(NM) time, O(NM) space (or O(min) with rolling).

## Data Structure / Approach Justification
**Chosen:** `dp[i][j]` = edit distance of `word1[0..i)` and `word2[0..j)`.

- **vs BFS on states:** correct but heavier constant / harder coding.
- **vs LCS-based formula:** `n+m-2*LCS` only works when replace is not a single op (different cost model).

## Logic Walkthrough
Base: `dp[i][0]=i`, `dp[0][j]=j`. Match → diagonal; else `1+min(up,left,diag)`.

## Dry Run
`horse` → `ros`: replace `h→r`, delete `r`, delete `e` (one valid path) → **3**.

## Time & Space Complexity
Time **O(NM)**. Space **O(NM)** full table. Why: every prefix pair computed once (section 4).

## Trade-offs & Alternatives
Two-row / one-row DP saves space when reconstruction is not needed. Weighted edit ops change transitions only.

## Common Mistakes / Edge Cases
Off-by-one on bases; swapping insert/delete; assuming replace cost 2.

## Interview Follow-ups / Variations
One-edit distance (161); reconstruct operations; Damerau–Levenshtein (transpositions).

## Tags
`string-dp`, `2d-dp`, `edit-distance`, `leetcode-72`, `difficulty:medium`
