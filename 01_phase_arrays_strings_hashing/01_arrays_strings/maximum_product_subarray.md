# Maximum Product Subarray

## Problem Statement
[LeetCode 152](https://leetcode.com/problems/maximum-product-subarray/) — contiguous subarray with largest product; return that product.

- **Inputs:** non-empty `vector<int> nums`.
- **Output:** maximum product (integer).
- **Valid answer:** at least one element.
- **Edges:** zeros reset; single element; all negatives.

## Intuition
Track running max and min products; a negative flips min↔max. Extreme products at `i` depend only on extremes at `i-1` and `nums[i]`.

## Brute Force → Optimal
- **Brute:** all subarrays — O(N²).
- **Optimal:** one-pass max/min — O(N)/O(1).

## Data Structure / Approach Justification
**Chosen:** dual running products (`curMax`, `curMin`) with swap-on-negative.

- **vs prefix/suffix products:** also O(N), needs two arrays or two passes carefully around zeros.
- **vs DP arrays:** clearer transitions, O(N) space unnecessary here.

## Logic Walkthrough
On negative `x`, swap `curMax`/`curMin`. Then `curMax = max(x, curMax*x)`, `curMin = min(x, curMin*x)`, update `best`.

## Dry Run
`[2,3,-2,4]`: products build to max **6** from `[2,3]` (negative `-2` then `4` does not beat it).

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: only previous extremes needed (section 4).

## Trade-offs & Alternatives
Swap-on-negative is compact; computing three candidates (`x`, `curMax*x`, `curMin*x`) without swap is equivalent.

## Common Mistakes / Edge Cases
Tracking only max (misses negative×negative recovery); zeros splitting runs; int overflow on large products (problem constraints usually OK).

## Interview Follow-ups / Variations
Return subarray bounds; max sum instead (53).

## Tags
`array`, `kadane-variant`, `dp`, `difficulty:medium`
