# Count Elements With Maximum Frequency

## 1. Problem Statement
[LeetCode 3005](https://leetcode.com/problems/count-elements-with-maximum-frequency/) — Return the total number of elements that have the maximum frequency (sum of those frequencies).

- **Inputs:** `vector<int> nums` (values in `[1,100]`).
- **Output:** Integer.
- **Edges:** All unique; one value dominates; ties for max frequency.

## 2. Intuition
Find max frequency M; sum frequencies equal to M (equivalently count how many values hit M, times M).

## 3. Brute Force → Optimal
Map counts then scan. Dense array fits constraints.

## 4. Data Structure / Approach Justification
**Chosen:** `freq[101]`.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count while tracking `best`.
2. Sum all `freq[v]==best`.

## 6. Dry Run
[1,2,2,3,1,4] → max freq 2 (for 1 and 2) → 2+2=4.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
If ties matter differently, return the set of modes.

## 9. Common Mistakes / Edge Cases
Returning `best` instead of total elements; counting distinct modes only.

## 10. Interview Follow-ups / Variations
Return the mode values themselves.

## 11. Tags
`array`, `frequency`, `leetcode-3005`, `difficulty:easy`
