# Number of Subsequences That Satisfy the Given Sum Condition

## Problem Statement
[LeetCode 1498](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/) — count non-empty subsequences whose min+max ≤ target, modulo 1e9+7.

- **Inputs:** `nums`, `target`.
- **Output:** `int` count.
- **Valid answer:** order of subsequence does not matter → sort is valid.
- **Edges:** all pairs too big; duplicates; large n needing fast pow2.

## Intuition
After sorting, fix the minimum at i. The farthest j with `nums[i]+nums[j] ≤ target` lets every subset of `(i, j]` pair with i → `2^(j-i)` subsequences (including {i} via 2^0 when j=i).

## Brute Force → Optimal
- **Brute:** enumerate subsequences — exponential.
- **Optimal:** sort + binary search + precomputed pow2 — O(N log N).

## Data Structure / Approach Justification
**Chosen:** binary search as a counting tool after sort.

- **vs two pointers:** O(N) after sort; equivalent
- **vs DP:** overkill

## Logic Walkthrough
Precompute `pow2`. For each i, rightmost j with sum ≤ target; add `2^(j-i)`.

## Dry Run
`[3,5,6,7]`, target 9 → 4 subsequences.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)** for powers. Why: sort plus N searches; modular doubling table.

## Trade-offs & Alternatives
Two pointers from both ends is the usual contest version.

## Common Mistakes / Edge Cases
Counting subsets as `j-i` instead of `2^(j-i)`; overflow without MOD.

## Interview Follow-ups / Variations
Successful pairs; two sum less than k.

## Tags
`binary-search`, `math`, `leetcode-1498`, `difficulty:medium`
