# Word Filter

## 1. Problem Statement
[LeetCode 745](https://leetcode.com/problems/prefix-and-suffix-search/) — given prefix and suffix, return the largest index of a word matching both.

- **Inputs:** dictionary `words`; queries `(pref, suff)`.
- **Output:** max matching index, or `-1`.
- **Valid answer:** largest index among matches.
- **Edges:** empty pref/suff; duplicates; no match.

## 2. Intuition
Encode keys `suffix + '#' + word` for every suffix of each word; query path `suff + '#' + pref`.

## 3. Brute Force → Optimal
- **Brute:** scan all words per query — O(N·L).
- **Optimal:** one trie of wrapped keys — O(L) query.

## 4. Data Structure / Approach Justification
**Chosen:** insert every `w[j:]+'#'+w` with weight = index on each node.

- **vs two tries:** needs intersection; wrapped keys are simpler.

## 5. Logic Walkthrough
Build wrapped keys. Query `suff+'#'+pref`; return node weight or `-1`.

## 6. Dry Run
words=`["apple"]`; `f("a","e")` → **0**. `f("b","")` → **-1**.

## 7. Time & Space Complexity
Build **O(N·L²)**. Query **O(L)**. Space **O(N·L²)**. Why: L suffixes per word (section 4).

## 8. Trade-offs & Alternatives
Memory-heavy for long words; two-trie + weights is an alternate interview answer.

## 9. Common Mistakes / Edge Cases
Not updating weight on every path node; wrong query order; omitting `#` separator.

## 10. Interview Follow-ups / Variations
Return all matches; support updates.

## 11. Tags
`trie`, `design`, `prefix`, `suffix`, `leetcode-745`, `difficulty:hard`
