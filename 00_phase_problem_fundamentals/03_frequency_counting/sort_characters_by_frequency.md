# Sort Characters By Frequency

## 1. Problem Statement
[LeetCode 451](https://leetcode.com/problems/sort-characters-by-frequency/) — Sort characters in `s` by decreasing frequency (any valid order on ties).

- **Inputs:** `string s`.
- **Output:** Rearranged string.
- **Edges:** All unique; one char dominates; ties.

## 2. Intuition
Count, then emit characters in order of count.

## 3. Brute Force → Optimal
Priority queue of (freq,char) — fine; sort pairs is enough.

## 4. Data Structure / Approach Justification
**Chosen:** ASCII `freq[128]` + sort pairs.

Bucket sort by frequency is a nice follow-up. This is still frequency-first; heap/top-k framing is topic 22.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count.
2. Collect non-zero (freq,char); sort by freq desc.
3. Append `char` repeated `freq` times.

## 6. Dry Run
`tree` → e appears twice → `eert` / `eetr`.

## 7. Time & Space Complexity
- **Time:** O(N + K log K) K≤128
- **Space:** O(K)

## 8. Trade-offs & Alternatives
Bucket list `vector<string> buckets(n+1)` is O(N).

## 9. Common Mistakes / Edge Cases
Sorting the string alphabetically only; forgetting to repeat characters.

## 10. Interview Follow-ups / Variations
Stable tie-break; top-k frequent characters (topic 22).

## 11. Tags
`string`, `frequency`, `sorting`, `leetcode-451`, `difficulty:medium`
