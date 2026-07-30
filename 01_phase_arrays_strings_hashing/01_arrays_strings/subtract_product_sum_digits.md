# Subtract the Product and Sum of Digits of an Integer

## Problem Statement
[LeetCode 1281](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/) — given `n`, return (product of digits) − (sum of digits).

- **Inputs:** positive `int n`.
- **Output:** int difference.
- **Edges:** single digit; zeros in digits (product becomes 0).

## Intuition
Pop digits with `%10` / `/10`; maintain running product and sum.

## Brute Force → Optimal
Only one pass over digits is needed — already optimal O(log n).

## Data Structure / Approach Justification
**Chosen:** arithmetic digit extraction (same family as reverse integer).

## Logic Walkthrough
Init `prod=1`, `sum=0`. While `n`: take digit, update prod/sum, `n/=10`. Return `prod - sum`.

## Dry Run
`234` → digits 4,3,2 → prod=24, sum=9 → **15**.

## Time & Space Complexity
Time **O(log n)**. Space **O(1)**.

## Trade-offs & Alternatives
String conversion is fine for teaching but slower and heavier.

## Common Mistakes / Edge Cases
Initializing product to 0; forgetting zeros zero the product.

## Interview Follow-ups / Variations
Digit DP; sum/product under constraints.

## Tags
`math`, `digits`, `difficulty:easy`
