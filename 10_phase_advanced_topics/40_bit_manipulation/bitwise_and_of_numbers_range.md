# Bitwise AND of Numbers Range

## 1. Problem Statement
[LeetCode 201](https://leetcode.com/problems/bitwise-and-of-numbers-range/) — compute bitwise AND of all integers in `[left, right]` inclusive.

- **Inputs:** `int left`, `int right` (`left ≤ right`).
- **Output:** AND of the range.
- **Valid answer:** exact AND.
- **Edges:** `left==right`; range crosses a power of two.

## 2. Intuition
Bits that flip anywhere in the range become 0 in the AND. Equivalently, find the common binary prefix of `left` and `right`.

## 3. Brute Force → Optimal
- **Brute:** AND-loop from left to right — TLE on large ranges.
- **Optimal:** right-shift both until equal; shift back — O(bits).

## 4. Data Structure / Approach Justification
**Chosen:** shift until `left==right`; result is common prefix.

- **vs clear lowest bits of right while right>left:** also O(bits).

## 5. Logic Walkthrough
`shift=0`; while left<right: left>>=1; right>>=1; ++shift; return left<<shift.

## 6. Dry Run
`[5,7]` → common prefix `4` → **4**. `[1,2147483647]` → **0**.

## 7. Time & Space Complexity
Time **O(32)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Brian-Kernighan clear on `right` is a nice alternate interview answer.

## 9. Common Mistakes / Edge Cases
Looping the full range; signed overflow concerns (use unsigned if needed).

## 10. Interview Follow-ups / Variations
Range OR; range XOR (prefix XOR).

## 11. Tags
`bit-manipulation`, `range`, `leetcode-201`, `difficulty:medium`
