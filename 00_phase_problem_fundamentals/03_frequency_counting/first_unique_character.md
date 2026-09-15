# First Unique Character in a String

## 1. Problem Statement
[LeetCode 387](https://leetcode.com/problems/first-unique-character-in-a-string/) — Find the first non-repeating character in `s` and return its index, or `-1`.

- **Inputs:** `string s` (lowercase).
- **Output:** Index or `-1`.
- **Edges:** All repeats; unique at end; single char.

## 2. Intuition
Two passes: count frequencies, then scan for the first count-1 letter.

## 3. Brute Force → Optimal
For each index, scan the rest — O(N²). Count table then scan — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `int freq[26]` then linear scan.

| Alternative | Why we skip leading with it |
|-------------|-----------------------------|
| `unordered_map<char,int>` | Fine; general hashmap is topic 6 |

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count each letter.
2. Left-to-right, return first index with freq 1.
3. Else `-1`.

## 6. Dry Run
`loveleetcode` — `l`/`o` repeat; `v` at index 2 is first unique.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) (26)

## 8. Trade-offs & Alternatives
One-pass with stored first-index in the table is a common variant.

## 9. Common Mistakes / Edge Cases
Assuming uppercase; returning the character instead of the index.

## 10. Interview Follow-ups / Variations
Last unique; k-th unique.

## 11. Tags
`string`, `frequency`, `alphabet-table`, `leetcode-387`, `difficulty:easy`
