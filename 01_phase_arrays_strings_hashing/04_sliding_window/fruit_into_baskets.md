# Fruit Into Baskets

## Problem Statement
[LeetCode 904](https://leetcode.com/problems/fruit-into-baskets/) — you have two baskets; each holds only one fruit type. Pick contiguous fruits from a row, maximizing count, while using at most two types.

- **Input:** `fruits[i]` = type at position i
- **Output:** max number of fruits collectible
- **Edges:** one type; alternating three types; entire array ≤ 2 types

## Intuition
Equivalent to **longest subarray with at most 2 distinct integers**. Sliding window + frequency map enforces the constraint.

## Brute Force → Optimal
- **Brute:** every subarray, count distinct — O(N²).
- **Optimal:** expand/shrink window keeping ≤ 2 types — O(N).

## Data Structure / Approach Justification
`unordered_map` (or fixed-size map if types are bounded) of type → count inside the window.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested loops | Quadratic |
| Last-two-types indices without map | Works but easier to bug on ties |

## Logic Walkthrough
1. Add `fruits[right]` to map.
2. While map has > 2 keys, decrement/erase `fruits[left]` and `++left`.
3. Track max `right - left + 1`.

## Dry Run
`[1,2,3,2,2]`: when 3 enters, drop type 1 → window `[2,3,2,2]` length **4**.

## Time & Space Complexity
- **Time:** O(N) average with hash map
- **Space:** O(1) distinct types in window (≤ 3 before shrink)
- Why: amortized one pass; map size bounded by 3.

## Trade-offs & Alternatives
Generalizes to “at most K types” (longest substring with K distinct). Array of last indices for two types is O(1) space without hashing.

## Common Mistakes / Edge Cases
Forgetting to `erase` when count hits 0; allowing 3 types briefly without shrinking; non-contiguous pick (problem requires contiguous).

## Interview Follow-ups / Variations
Longest substring with at most K distinct (340); fruit with 3 baskets.

## Tags
`sliding-window`, `hash-map`, `at-most-k-distinct`, `leetcode-904`, `medium`
