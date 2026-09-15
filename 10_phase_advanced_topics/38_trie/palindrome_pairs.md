# Palindrome Pairs

## 1. Problem Statement
[LeetCode 336](https://leetcode.com/problems/palindrome-pairs/) — given unique words, return all index pairs `(i, j)` such that `words[i] + words[j]` is a palindrome.

- **Inputs:** `vector<string> words` (distinct).
- **Output:** list of index pairs.
- **Valid answer:** any order of pairs.
- **Edges:** empty string; single-char; self-palindrome words; overlapping prefixes/suffixes.

## 2. Intuition
For each word, every split into `prefix|suffix` suggests a partner: if `prefix` is a palindrome, need `reverse(suffix)` before it; if `suffix` is a palindrome, need `reverse(prefix)` after it. A trie of reversed words makes partner lookups fast.

## 3. Brute Force → Optimal
- **Brute:** concatenate every ordered pair and check palindrome — O(N²·L).
- **Optimal:** reverse-word trie + per-word palindrome remainder checks — ~O(N·L²).

## 4. Data Structure / Approach Justification
**Chosen:** insert each reversed word into a trie storing its index; for each word walk the trie and test palindrome remainders.

- **vs hash of reverses:** hash works; trie shares prefixes of reverses.
- **vs Manacher on concatenations:** overkill for pair enumeration.

## 5. Logic Walkthrough
Insert reverse(word)→index. Walk trie by W's chars; when a word ends mid-walk, check remaining W is palindrome; at end of W, collect trie-descendant ends whose leftover path is a palindrome.

## 6. Dry Run
`["bat","tab","cat"]` → `(0,1)` and `(1,0)`. Empty `""` pairs with every palindrome word.

## 7. Time & Space Complexity
Time **O(N·L²)** typical. Space **O(N·L)** trie. Why: each word probes L positions with O(L) checks (section 4).

## 8. Trade-offs & Alternatives
Hash-map of reverses is shorter; trie shines when prefix queries matter. Empty-string cases need care either way.

## 9. Common Mistakes / Edge Cases
Pairing a word with itself; missing empty-string partner; forgetting both prefix-palindrome and suffix-palindrome cases.

## 10. Interview Follow-ups / Variations
Return concatenated strings; allow duplicates; count pairs only.

## 11. Tags
`trie`, `palindrome`, `string`, `leetcode-336`, `difficulty:hard`
