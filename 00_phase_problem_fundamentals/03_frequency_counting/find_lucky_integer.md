# Find Lucky Integer in an Array

## 1. Problem Statement
[LeetCode 1394](https://leetcode.com/problems/find-lucky-integer-in-an-array/) — A lucky integer equals its frequency. Return the largest lucky integer, or `-1`.

- **Inputs:** `vector<int> arr` (values in `[1,500]`).
- **Output:** Largest lucky int or `-1`.
- **Edges:** None lucky; multiple lucky; single element 1.

## 2. Intuition
Count, then scan values high→low for `freq[v]==v`.

## 3. Brute Force → Optimal
For each distinct value recount. Dense table is linear.

## 4. Data Structure / Approach Justification
**Chosen:** `freq[501]`.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count.
2. From 500 down to 1, return first `freq[v]==v`.
3. Else `-1`.

## 6. Dry Run
[1,2,2,3,3,3] → 3 is lucky and largest.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) under constraints

## 8. Trade-offs & Alternatives
Map + track max while iterating counts.

## 9. Common Mistakes / Edge Cases
Returning smallest lucky; confusing value with index.

## 10. Interview Follow-ups / Variations
All lucky integers sorted.

## 11. Tags
`array`, `frequency`, `leetcode-1394`, `difficulty:easy`
