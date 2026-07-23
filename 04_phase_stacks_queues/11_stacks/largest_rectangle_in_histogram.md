# Largest Rectangle in Histogram

## Problem Statement
[LeetCode 84](https://leetcode.com/problems/largest-rectangle-in-histogram/) — given bar heights of width 1, return the largest rectangle area in the histogram.

- **Inputs:** `vector<int> heights`.
- **Output:** max area (int).
- **Valid answer:** max over all contiguous ranges of `min(height) * width`.
- **Edges:** empty; single bar; all equal; strictly increasing/decreasing.

## Intuition
For each bar as the shortest in a rectangle, need nearest smaller bars left and right to know width — monotonic stack finds those boundaries in amortized O(1) each.

## Brute Force → Optimal
- **Brute:** for each pair (L,R) take min height — O(N²).
- **Optimal:** increasing stack of indices + sentinel 0 — O(N).

## Data Structure / Approach Justification
**Chosen:** monotonic non-decreasing stack of indices; dummy height 0 at end.

- **vs two explicit NSE arrays:** same idea, more passes/memory.
- **vs segment tree:** heavier constant factors.

## Logic Walkthrough
Scan `i`; while top height ≥ `heights[i]`, pop `h`, width = `i` or `i-top-1`, update max; push `i`. Sentinel forces final flush.

## Dry Run
`[2,1,5,6,2,3]` (+0): rectangle height 5 width 2 (bars 5,6) → area 10 is max.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: each index enters/leaves stack once (section 4).

## Trade-offs & Alternatives
Mutating input with sentinel is convenient; copy if immutability required. Related: maximal rectangle in binary matrix (85).

## Common Mistakes / Edge Cases
Width off-by-one; forgetting sentinel; using `>` instead of `>=` with equal heights.

## Interview Follow-ups / Variations
Maximal rectangle (85); trapping rain water; sum of subarray minimums.

## Tags
`stack`, `monotonic-stack`, `histogram`, `leetcode-84`, `difficulty:hard`
