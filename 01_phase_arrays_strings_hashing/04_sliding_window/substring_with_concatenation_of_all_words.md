# Substring with Concatenation of All Words

## 1. Problem Statement
[LeetCode 30](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) — find all starting indices of substrings in `s` that are a concatenation of each word in `words` exactly once (order may vary). All words have equal length.

- **Input:** string `s`, vector of equal-length words
- **Output:** list of start indices
- **Valid answer:** every start where the next `|words|·wordLen` chars permute the multiset of words
- **Edges:** empty result; overlapping starts; duplicate words in `words`

**Prerequisite note:** Hard fixed-window sliding over chunks. Starts from two-pointer / anagram-window ideas (LC 438/567) but advances by `wordLen` and tracks word frequencies.

## 2. Intuition
Total span length is fixed: `totalLen = wordCount · wordLen`. Slide a window of that size, verifying the multiset of consecutive word-chunks equals `words`. Optimize by maintaining counts while sliding word-by-word for each alignment offset `0..wordLen−1`.

## 3. Brute Force → Optimal
- **Brute:** for each start, check all words used — O(N · M · L).
- **Optimal:** word-chunk sliding window per offset — O(N · L) with hash maps.

## 4. Data Structure / Approach Justification
`unordered_map<string,int>` for `need` and current `window`; `matched` count of satisfied word occurrences.

| Alternative | Why it loses here |
|-------------|-------------------|
| Check every start naively | Much larger constant |
| Trie of words | Useful, not required for LC constraints |

## 5. Logic Walkthrough
1. Build `need` from `words`.
2. For each offset in `[0, wordLen)`:
   - Slide `right` by `wordLen`; add chunk to `window`.
   - If excess of a word, advance `left` by words until valid.
   - When `matched == wordCount`, record `left` and advance once.
   - On unknown word, reset window.

## 6. Dry Run
`s=barfoothefoobarman`, `words=[foo,bar]` — matches at **0** (`barfoo`) and **9** (`foobar`).

## 7. Time & Space Complexity
- **Time:** O(N · wordLen) typical with hashing (substr cost)
- **Space:** O(|words|) for maps
- Why: each offset processes each aligned position roughly once.

## 8. Trade-offs & Alternatives
Naive per-start check is easier to write under time pressure; window version is the intended hard sliding-window drill.

## 9. Common Mistakes / Edge Cases
Ignoring duplicate words; resetting incorrectly on unknown chunks; forgetting multiple offsets (`s[1..]` misaligned to word boundaries).

## 10. Interview Follow-ups / Variations
Find all anagrams (438); minimum window substring (76); words of unequal length (much harder).

## 11. Tags
`sliding-window`, `hash-map`, `string`, `leetcode-30`, `hard`
