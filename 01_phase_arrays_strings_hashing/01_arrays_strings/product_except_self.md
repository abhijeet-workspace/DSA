# Product of Array Except Self

## Problem Statement
[LeetCode 238](https://leetcode.com/problems/product-of-array-except-self/) — return `answer` where `answer[i]` is product of all elements except `nums[i]`. Division not allowed.

- **Inputs:** `vector<int> nums` (length ≥ 2).
- **Output:** `vector<int>` same length.
- **Valid answer:** exact products; zeros handled without division.
- **Edges:** one or many zeros; negatives; length 2.

## Intuition
`answer[i] = (product left of i) * (product right of i)`. Separate left/right products avoid division.

## Brute Force → Optimal
- **Brute:** for each `i` multiply all other indices — O(N²).
- **Optimal:** prefix pass then suffix multiply into result — O(N), O(1) extra (excluding output).

## Data Structure / Approach Justification
**Chosen:** single output array used as left-prefix buffer, then fold right products in-place.

- **vs two arrays L[i], R[i]:** clearer, uses O(N) extra memory.
- **vs total-product / division:** forbidden and breaks on zeros.

## Logic Walkthrough
Left pass: `ans[i]=left`, then `left*=nums[i]`. Right pass: `ans[i]*=right`, then `right*=nums[i]`.

## Dry Run
`nums=[1,2,3,4]`:
- left into ans → `[1,1,2,6]`
- right fold → `[24,12,8,6]`

## Time & Space Complexity
Time **O(N)** (two passes). Space **O(1)** extra excluding output. Why: left/right products reuse `ans` (section 4).

## Trade-offs & Alternatives
Explicit L/R arrays are easier to debug; in-place suffix fold is preferred when O(1) extra is required.

## Common Mistakes / Edge Cases
Using division by total product; forgetting zeros; off-by-one on left/right init (`left=1`, `right=1`).

## Interview Follow-ups / Variations
Streaming / online product queries; modulo arithmetic variant.

## Tags
`array`, `prefix-product`, `suffix-product`, `difficulty:medium`
