# Single Number

## 1. Problem Statement
[LeetCode 136](https://leetcode.com/problems/single-number/) — every element appears twice except one; find that one in linear time and constant space.

- **Inputs:** `vector<int> nums`.
- **Output:** the unique integer.
- **Valid answer:** the singleton value.
- **Edges:** singleton is first/last; negatives; length 1.

## 2. Intuition
`a^a=0` and `a^0=a`, so XOR of the whole array cancels pairs and leaves the unique number.

## 3. Brute Force → Optimal
- **Brute:** hash set / sort — O(N) space or O(N log N) time.
- **Optimal:** fold XOR — O(N) time, O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** running XOR accumulator.

- **vs hash map:** violates O(1) space.
- **vs math sum(set)*2 - sum(arr):** overflow risk.

## 5. Logic Walkthrough
`x=0`; for each `n`, `x^=n`; return `x`.

## 6. Dry Run
`[4,1,2,1,2]`: `4^1^2^1^2` → **4**.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: XOR pairwise cancellation (section 4).

## 8. Trade-offs & Alternatives
Fails if the “twice” assumption breaks — see Single Number II/III.

## 9. Common Mistakes / Edge Cases
Assuming sorting is required; using `+` with overflow; empty input (not in problem).

## 10. Interview Follow-ups / Variations
Appears thrice (137); two uniques (260); missing number in `0..n`.

## 11. Tags
`bit-manipulation`, `xor`, `difficulty:easy`
