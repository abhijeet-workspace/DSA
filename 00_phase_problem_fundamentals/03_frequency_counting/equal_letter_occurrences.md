# Check if All Characters Have Equal Number of Occurrences

## 1. Problem Statement
[LeetCode 1941](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/) — Return true if every character that appears in `s` has the same frequency.

- **Inputs:** `string s` (lowercase).
- **Output:** `bool`.
- **Edges:** One distinct letter; two letters unequal counts.

## 2. Intuition
Count letters; ignore zeros; check remaining counts are equal.

## 3. Brute Force → Optimal
Same as optimal after counting.

## 4. Data Structure / Approach Justification
**Chosen:** `freq[26]`.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count.
2. Capture first non-zero count as `need`.
3. All other non-zeros must equal `need`.

## 6. Dry Run
`abacbc` → a,b,c each twice → true.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Put non-zero counts in a set; size must be 1.

## 9. Common Mistakes / Edge Cases
Treating missing letters as count 0 that must match.

## 10. Interview Follow-ups / Variations
At most two distinct frequencies (LC 2423-related ideas).

## 11. Tags
`string`, `frequency`, `leetcode-1941`, `difficulty:easy`
