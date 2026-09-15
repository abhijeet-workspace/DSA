# Divide Array Into Equal Pairs

## 1. Problem Statement
[LeetCode 2206](https://leetcode.com/problems/divide-array-into-equal-pairs/) — `nums` length is even. Return true iff you can pair elements into `n/2` pairs of equal values.

- **Inputs:** `vector<int> nums`.
- **Output:** `bool`.
- **Edges:** All pairs same value; one odd count.

## 2. Intuition
Every value’s frequency must be even.

## 3. Brute Force → Optimal
Sort and check adjacent pairs — O(N log N). Counting is O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `freq[501]` (constraint-friendly).

Sorting is fine but teaches less about frequency. A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count.
2. Fail if any count is odd.

## 6. Dry Run
[3,2,3,2,2,2] → all even counts → true.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) under constraints

## 8. Trade-offs & Alternatives
Sort approach needs no frequency table.

## 9. Common Mistakes / Edge Cases
Checking total length only; XOR tricks that miss multi-odd cases.

## 10. Interview Follow-ups / Variations
Pairs summing to k (different problem).

## 11. Tags
`array`, `frequency`, `leetcode-2206`, `difficulty:easy`
