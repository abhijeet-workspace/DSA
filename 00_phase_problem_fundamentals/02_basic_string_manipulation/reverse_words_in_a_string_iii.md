# Reverse Words in a String III

## 1. Problem Statement
[LeetCode 557](https://leetcode.com/problems/reverse-words-in-a-string-iii/) — Reverse the characters of each word in a sentence. Words are separated by single spaces; do not reverse word order.

- **Inputs:** `string s`.
- **Output:** String with each word reversed.
- **Edges:** Single word; two words; punctuation attached to words (treated as letters here).

## 2. Intuition
Scan to find each word’s `[start, end)` span, reverse that span, then continue after the space.

## 3. Brute Force → Optimal
Split into a vector of words, reverse each, join — O(N) with extra allocations. In-place span reverses are O(N) time and O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** index `i` to start of word, `j` to first space/end; `reverse(i, j)`.

| Alternative | Why we skip leading with it |
|-------------|-----------------------------|
| `stringstream` split | Extra memory; hides index work |
| Naming `i`/`j` as “two pointers pattern” | Same mechanics; formal pattern is topic 7 |

This can look like a two-pointer solution, and a two-pointer formulation also works (and may even be more idiomatic once that pattern is formal). We solve it here via **direct position arithmetic / index scans** on purpose: this topic builds string scan-and-build fluency before the formal two-pointer pattern is introduced in topic 7.

## 5. Logic Walkthrough
1. `i = 0`.
2. Skip spaces; set `j` to end of word.
3. Reverse `[i, j)`; set `i = j`.
4. Repeat until the end.

## 6. Dry Run
`Let's take` → reverse `Let's` → `s'teL`, reverse `take` → `ekat`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) extra

## 8. Trade-offs & Alternatives
LC 151 (next medium) reverses *word order* and collapses spaces — related but stricter.

## 9. Common Mistakes / Edge Cases
Reversing the whole string; including spaces inside a reverse; off-by-one on `j`.

## 10. Interview Follow-ups / Variations
Reverse word order (LC 151); reverse only letters inside words.

## 11. Tags
`string`, `reverse`, `leetcode-557`, `difficulty:easy`
