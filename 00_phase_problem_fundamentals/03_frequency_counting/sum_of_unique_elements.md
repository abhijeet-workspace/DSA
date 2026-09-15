# Sum of Unique Elements

## 1. Problem Statement
[LeetCode 1748](https://leetcode.com/problems/sum-of-unique-elements/) — Sum elements that appear exactly once (`nums[i]` in `[1,100]`).

- **Inputs:** `vector<int> nums`.
- **Output:** Integer sum.
- **Edges:** All duplicates; all unique.

## 2. Intuition
Count occurrences; add values whose count is exactly 1.

## 3. Brute Force → Optimal
Nested scans. Dense count array is O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `freq[101]`.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count.
2. Sum `v` with `freq[v]==1`.

## 6. Dry Run
[1,2,3,2] → 1+3=4.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) under constraints

## 8. Trade-offs & Alternatives
Huge ranges → counting bag map (topic 6).

## 9. Common Mistakes / Edge Cases
Summing duplicates; index 100 off-by-one.

## 10. Interview Follow-ups / Variations
Sum of values appearing k times.

## 11. Tags
`array`, `frequency`, `leetcode-1748`, `difficulty:easy`
