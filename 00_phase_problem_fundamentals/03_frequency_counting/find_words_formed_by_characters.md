# Find Words That Can Be Formed by Characters

## 1. Problem Statement
[LeetCode 1160](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/) — Sum lengths of words that can be formed from `chars` (each char used at most as often as it appears).

- **Inputs:** `vector<string> words`, `string chars`.
- **Output:** Sum of lengths of “good” words.
- **Edges:** Empty chars; word longer than chars; exact use.

## 2. Intuition
Budget frequency of `chars`; each word needs a count that does not exceed budget.

## 3. Brute Force → Optimal
For each word, copy chars and delete — messier. Two count arrays.

## 4. Data Structure / Approach Justification
**Chosen:** budget `freq[26]` + per-word `need[26]`.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count `chars`.
2. For each word, count and compare to budget.
3. Add length if feasible.

## 6. Dry Run
`atach` forms `cat` and `hat` → lengths 3+3=6.

## 7. Time & Space Complexity
- **Time:** O(total characters)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Early exit when word length > chars length.

## 9. Common Mistakes / Edge Cases
Sharing one need array without reset; allowing overuse.

## 10. Interview Follow-ups / Variations
Return the words; maximize number of words not length.

## 11. Tags
`string`, `frequency`, `leetcode-1160`, `difficulty:easy`
