# Maximum XOR of Two Numbers in an Array

## 1. Problem Statement
[LeetCode 421](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) — return the maximum `nums[i] XOR nums[j]` for any pair.

- **Inputs:** `vector<int> nums` (non-empty).
- **Output:** max XOR value.
- **Valid answer:** the maximum pairwise XOR.
- **Edges:** N=1; duplicates; all equal.

## 2. Intuition
XOR is bit-greedy from MSB: at each bit prefer the opposite branch if it exists in a binary trie of numbers.

## 3. Brute Force → Optimal
- **Brute:** all pairs — O(N²).
- **Optimal:** 32-bit binary trie insert+query — O(32N).

## 4. Data Structure / Approach Justification
**Chosen:** trie of bits (high→low); query best partner then insert.

- **vs hash of bit prefixes:** same asymptotics; trie is the usual interview form.

## 5. Logic Walkthrough
For each num, walk trie preferring `!bit` when present; then insert its bits.

## 6. Dry Run
`[3,10,5,25,2,8]` → **28** (`5^25`).

## 7. Time & Space Complexity
Time **O(32N)**. Space **O(32N)** nodes. Why: fixed bit depth (section 4).

## 8. Trade-offs & Alternatives
Prefix hash sets use less pointer overhead; trie clarifies opposite-bit greed.

## 9. Common Mistakes / Edge Cases
Querying before any insert when N=1; LSB-first bit order; unsafe signed shifts.

## 10. Interview Follow-ups / Variations
Max XOR with another array; maximum XOR subarray (prefix trie).

## 11. Tags
`trie`, `bit-manipulation`, `xor`, `leetcode-421`, `difficulty:medium`
