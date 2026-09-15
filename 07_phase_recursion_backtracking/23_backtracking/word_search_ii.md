# Word Search II

## 1. Problem Statement
[LeetCode 212](https://leetcode.com/problems/word-search-ii/) — given a board and a word list, return all words that can be formed by sequentially adjacent (4-dir) cells without reuse within a word.

- **Inputs:** `board`, `words`.
- **Output:** matched words (unique).
- **Valid answer:** any order; each word once.
- **Edges:** empty board; overlapping words; prefixes shared.

## 2. Intuition
Build a trie of words; DFS from each cell walking the trie. Mark cells visited; clear word at trie leaf to avoid duplicates.

## 3. Brute Force → Optimal
- **Brute:** run Word Search I per word — slow with shared prefixes.
- **Optimal:** one trie + board DFS prunes dead branches early.

## 4. Data Structure / Approach Justification
**Chosen:** trie + backtracking on grid.

- **vs hash set of words only:** weaker prefix prune.
- **vs Aho-Corasick:** heavier; trie is interview standard.

## 5. Logic Walkthrough
Insert all words. From each cell, DFS: follow edge, record if `node.word` set, mark `#`, explore 4 dirs, restore.

## 6. Dry Run
Board classic example finds `"oath"` and `"eat"`.

## 7. Time & Space Complexity
Time roughly **O(R·C·4^L)** pruned by trie. Space **O(total chars in words)**. Why: search from each start (section 4).

## 8. Trade-offs & Alternatives
Prune trie nodes with empty children after visit for speed. Parallel per-word DFS if few words.

## 9. Common Mistakes / Edge Cases
Not restoring board; not deduping found words; allowing diagonal moves.

## 10. Interview Follow-ups / Variations
Word Search I; Boggle; return paths not words.

## 11. Tags
`backtracking`, `trie`, `leetcode-212`, `difficulty:hard`
