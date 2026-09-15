# Find and Replace Pattern

## 1. Problem Statement
[LeetCode 890](https://leetcode.com/problems/find-and-replace-pattern/) — Return words that match `pattern` via a bijection on characters (same isomorphism as pattern).

- **Inputs:** `vector<string> words`, `string pattern`.
- **Output:** Matching words (any order).
- **Edges:** All letters same; 1-1 fails one direction; length mismatches excluded by constraints.

## 2. Intuition
Normalize by building a mutual mapping word↔pattern while scanning; reject conflicts.

## 3. Brute Force → Optimal
Generate all remappings — explosion. Linear bijection check.

## 4. Data Structure / Approach Justification
**Chosen:** two ASCII maps `w2p` / `p2w` as parallel frequency-style tables of assignments.

This is isomorphism via tables — related to counting/occurrence structure, not sliding window.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
For each word: clear maps; for each position, set or verify both directions of the mapping.

## 6. Dry Run
`abb` matches `mee` and `aqq`; `ccc` fails (all map to one pattern char incorrectly).

## 7. Time & Space Complexity
- **Time:** O(total characters)
- **Space:** O(1) per check (ASCII)

## 8. Trade-offs & Alternatives
Normalize word to a canonical pattern id string and compare.

## 9. Common Mistakes / Edge Cases
One-way map only (allows two letters → one).

## 10. Interview Follow-ups / Variations
LC 205 Isomorphic Strings; group words by pattern.

## 11. Tags
`string`, `mapping`, `frequency-structure`, `leetcode-890`, `difficulty:medium`
