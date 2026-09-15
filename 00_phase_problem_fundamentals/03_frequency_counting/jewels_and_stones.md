# Jewels and Stones

## 1. Problem Statement
[LeetCode 771](https://leetcode.com/problems/jewels-and-stones/) — `jewels` are types; `stones` are what you have. Count how many stones are jewels (case-sensitive).

- **Inputs:** `string jewels`, `stones`.
- **Output:** Count.
- **Edges:** No overlap; all jewels; mixed case.

## 2. Intuition
Mark jewel characters, then count marked stones.

## 3. Brute Force → Optimal
For each stone, scan jewels — O(N·M). Presence table — O(N+M).

## 4. Data Structure / Approach Justification
**Chosen:** `bool isJewel[128]`.

| Alternative | Why we skip leading with it |
|-------------|-----------------------------|
| `unordered_set<char>` | Idiomatic in topic 6 |

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Mark each jewel.
2. Count stones that are marked.

## 6. Dry Run
`aA` / `aAAbbbb` → 3.

## 7. Time & Space Complexity
- **Time:** O(|jewels|+|stones|)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Set is clearer for huge alphabets.

## 9. Common Mistakes / Edge Cases
Ignoring case-sensitivity; using a frequency map when presence suffices.

## 10. Interview Follow-ups / Variations
Weighted jewels.

## 11. Tags
`string`, `frequency`, `presence-table`, `leetcode-771`, `difficulty:easy`
