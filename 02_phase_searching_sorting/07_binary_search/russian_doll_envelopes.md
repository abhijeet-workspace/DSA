# Russian Doll Envelopes

## Problem Statement
[LeetCode 354](https://leetcode.com/problems/russian-doll-envelopes/) — envelopes `[w,h]`; nest A in B iff both dimensions strictly smaller. Max chain length.

- **Inputs:** `vector<vector<int>> envelopes`.
- **Output:** `int` length.
- **Valid answer:** LIS after a careful 2D sort.
- **Edges:** all same size; nested chain of 1.

## Intuition
Sort width increasing. On equal width, sort height decreasing so equal widths cannot both enter the LIS. Then LIS on heights.

## Brute Force → Optimal
- **Brute:** O(N²) pair DP.
- **Optimal:** sort + patience LIS — O(N log N).

## Data Structure / Approach Justification
**Chosen:** reduces 2D nesting to 1D LIS.

- **vs DP on both dimensions:** too slow for N=1e5
- **vs sorting both increasing:** equal widths would nest illegally

## Logic Walkthrough
Sort `(w asc, h desc)`. `lower_bound` LIS on h.

## Dry Run
`[[5,4],[6,4],[6,7],[2,3]]` → `[2,3] ⊂ [5,4] ⊂ [6,7]` length 3.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort plus LIS tails.

## Trade-offs & Alternatives
This is the hard follow-up to 300 in the study plan.

## Common Mistakes / Edge Cases
Not reversing heights on width ties; using non-strict LIS.

## Interview Follow-ups / Variations
LIS (300); box stacking.

## Tags
`binary-search`, `sorting`, `lis`, `leetcode-354`, `difficulty:hard`
