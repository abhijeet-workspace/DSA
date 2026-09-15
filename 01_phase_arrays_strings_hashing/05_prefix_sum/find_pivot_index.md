# Find Pivot Index

## Problem Statement
[LeetCode 724](https://leetcode.com/problems/find-pivot-index/) — return the leftmost pivot index where the sum of all numbers strictly to the left equals the sum strictly to the right. Return `-1` if none.

- **Input:** `vector<int> nums`
- **Output:** leftmost pivot index or `-1`
- **Edges:** pivot at 0 (left sum 0); pivot at last; negatives; single element (index 0)

## Intuition
Know the total once. At index `i`, `right = total - left - nums[i]`. Compare `left` to `right`, then add `nums[i]` into `left`.

## Brute Force → Optimal
- **Brute:** for each i, sum left and right ranges — O(N²).
- **Optimal:** one total sum + one left pass — O(N).

## Data Structure / Approach Justification
Scalar running left sum — no explicit prefix array required (though equivalent).

| Alternative | Why it loses here |
|-------------|-------------------|
| Prefetch prefix[i] array | Extra O(N) space, same time |
| Two pointers from ends | Harder with negatives / unequal sides |

## Logic Walkthrough
1. `total = sum(nums)`, `left = 0`.
2. For each i: if `left == total - left - nums[i]` return i; else `left += nums[i]`.
3. Return `-1`.

## Dry Run
`[1,7,3,6,5,6]`: at i=3, left=1+7+3=11, right=5+6=11 → **3**.

## Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)
- Why: two linear passes (or one after accumulate).

## Trade-offs & Alternatives
Build full prefix array if many pivot queries on same array. Same as “Equilibrium Index.”

## Common Mistakes / Edge Cases
Including `nums[i]` in left or right; returning rightmost instead of leftmost; overflow on large sums (use `long` if needed).

## Interview Follow-ups / Variations
Find Middle Index (1991) — identical; multiple pivots; 2D equilibrium.

## Tags
`prefix-sum`, `array`, `leetcode-724`, `easy`
