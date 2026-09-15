# Unique Number of Occurrences

## 1. Problem Statement
[LeetCode 1207](https://leetcode.com/problems/unique-number-of-occurrences/) — Return true iff no two values share the same occurrence count.

- **Inputs:** `vector<int> arr`.
- **Output:** `bool`.
- **Edges:** All unique values; all equal; two values same count.

## 2. Intuition
Build value→count, then check that the multiset of counts has no duplicates.

## 3. Brute Force → Optimal
For each value recount — slow. One count pass + set of counts.

## 4. Data Structure / Approach Justification
**Chosen:** counting bag (`unordered_map`) then `unordered_set` of counts.

This uses a map as a **frequency bag** because keys are arbitrary ints — still the frequency-counting skill, not the hashmap *pattern problems* of topic 6 (Two Sum, Group Anagrams).

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count values.
2. Insert each count into a set; fail on collision.
3. Else true.

## 6. Dry Run
[1,2,2,1,1,3] → counts 3,2,1 — all distinct → true.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(U) unique values

## 8. Trade-offs & Alternatives
Sort the count list and check adjacent equals — no hash set.

## 9. Common Mistakes / Edge Cases
Comparing values instead of counts.

## 10. Interview Follow-ups / Variations
Allow at most k duplicated count values.

## 11. Tags
`array`, `frequency`, `leetcode-1207`, `difficulty:easy`
