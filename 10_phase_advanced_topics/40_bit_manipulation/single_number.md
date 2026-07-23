# Single Number

## Problem Statement
[LeetCode 136](https://leetcode.com/problems/single-number/) — every element appears twice except one; find that one in linear time and constant space.

- **Inputs:** `vector<int> nums`.
- **Output:** the unique integer.
- **Valid answer:** the singleton value.
- **Edges:** singleton is first/last; negatives; length 1.

## Intuition
`a^a=0` and `a^0=a`, so XOR of the whole array cancels pairs and leaves the unique number.

## Brute Force → Optimal
- **Brute:** hash set / sort — O(N) space or O(N log N) time.
- **Optimal:** fold XOR — O(N) time, O(1) space.

## Data Structure / Approach Justification
**Chosen:** running XOR accumulator.

- **vs hash map:** violates O(1) space.
- **vs math sum(set)*2 - sum(arr):** overflow risk.

## Logic Walkthrough
`x=0`; for each `n`, `x^=n`; return `x`.

## Dry Run
`[4,1,2,1,2]`: `4^1^2^1^2` → **4**.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: XOR pairwise cancellation (section 4).

## Trade-offs & Alternatives
Fails if the “twice” assumption breaks — see Single Number II/III.

## Common Mistakes / Edge Cases
Assuming sorting is required; using `+` with overflow; empty input (not in problem).

## Interview Follow-ups / Variations
Appears thrice (137); two uniques (260); missing number in `0..n`.

## Tags
`bit-manipulation`, `xor`, `difficulty:easy`
