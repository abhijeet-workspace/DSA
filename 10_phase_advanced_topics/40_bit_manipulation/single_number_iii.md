# Single Number III

## 1. Problem Statement
[LeetCode 260](https://leetcode.com/problems/single-number-iii/) — every element appears twice except two; return those two unique numbers.

- **Inputs:** `vector<int> nums`.
- **Output:** the two singles (any order).
- **Valid answer:** the two values that appear once.
- **Edges:** negatives; singles at ends; one single is 0.

## 2. Intuition
XOR of all is `a^b` (nonzero). A set bit in that mask separates `a` and `b` into two XOR groups.

## 3. Brute Force → Optimal
- **Brute:** hash counts — O(N) space.
- **Optimal:** two-pass XOR with bitmask — O(N) time, O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** `mask = xor & -xor` (lowest set bit); partition XORs.

- **vs sort:** O(N log N), more space for uniqueness checks.

## 5. Logic Walkthrough
Compute total XOR. Split nums by `mask` bit into two running XORs; each collapses to one single.

## 6. Dry Run
`[1,2,1,3,2,5]` → total XOR `3^5=6`; bit separates → **3** and **5**.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: constant XOR state (section 4).

## 8. Trade-offs & Alternatives
Hash map is clearer if O(1) space is not required.

## 9. Common Mistakes / Edge Cases
Using `mask = xor` fully instead of one bit; returning sorted when not asked.

## 10. Interview Follow-ups / Variations
Single Number I/II; find all singles when others appear k times.

## 11. Tags
`bit-manipulation`, `xor`, `leetcode-260`, `difficulty:medium`
