# Check if the Sentence Is Pangram

## 1. Problem Statement
[LeetCode 1832](https://leetcode.com/problems/check-if-the-sentence-is-pangram/) — A pangram contains every letter of the English alphabet at least once. Return whether `sentence` (lowercase letters) is a pangram.

- **Inputs:** `string sentence`.
- **Output:** `bool`.
- **Edges:** Missing one letter; exact 26 unique; repeats.

## 2. Intuition
Track which of the 26 letters have appeared. A fixed-size presence table keyed by `c - 'a'` is enough.

## 3. Brute Force → Optimal
For each letter `a..z`, scan the whole string — O(26N). One pass marking a table is O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `bool seen[26]` + count of newly seen letters.

| Alternative | Why we skip leading with it |
|-------------|-----------------------------|
| `unordered_set<char>` | Works; general hashmap pattern is topic 6 |
| Bitmask `int` with 26 bits | Fine optimization; table is clearer first |

**This is not jumping ahead to topic 6.** Topic 6 teaches *general-key* hash maps/sets (arbitrary keys, collisions, average O(1) dictionaries). Here the alphabet is a **fixed 26-slot array** — index = letter offset. Same “presence” idea, different mental model: dense table vs hash table. We call that distinction out so a learner does not confuse the two.

## 5. Logic Walkthrough
1. Zero `seen[26]`, `got = 0`.
2. For each `c`, if unseen, mark and `++got`; early-return at 26.
3. Return `got == 26`.

## 6. Dry Run
`thequickbrownfoxjumpsoverthelazydog` fills all 26 → true. `leetcode` misses many → false.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) (26 slots)

## 8. Trade-offs & Alternatives
Bitmask fits in one `int`; sets are fine once hashing is formal. Prefer the table while learning alphabet indexing.

## 9. Common Mistakes / Edge Cases
Assuming uppercase (problem is lowercase); forgetting early exit; using a map “because presence.”

## 10. Interview Follow-ups / Variations
First missing letter; pangram with Unicode scripts; count letters needed.

## 11. Tags
`string`, `counting`, `alphabet-table`, `leetcode-1832`, `difficulty:easy`
