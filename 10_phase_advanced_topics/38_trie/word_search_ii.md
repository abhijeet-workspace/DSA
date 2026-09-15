# Word Search II

## 1. Problem Statement
[LeetCode 212](https://leetcode.com/problems/word-search-ii/) — find all dictionary words formable on a board (4-dir, no cell reuse).

- **Inputs:** `board` of letters; list of words.
- **Output:** list of words found (any order).
- **Valid answer:** each word once even if multiple paths exist.
- **Edges:** empty board; duplicate words; overlapping matches.

## 2. Intuition
Insert all words into a trie. DFS from every cell following trie edges; shared prefixes prune board paths that cannot match any remaining word.

## 3. Brute Force → Optimal
- **Brute:** run Word Search I per word — repeats work on shared prefixes.
- **Optimal:** one trie + board DFS; clear stored word at leaf to dedupe.

## 4. Data Structure / Approach Justification
**Chosen:** trie with `word` string at terminal; board cell marked `#` during DFS.

- **vs per-word DFS:** worse when many words share prefixes.
- **vs Aho-Corasick on paths:** advanced; usually unnecessary in interviews.

## 5. Logic Walkthrough
Build trie. From each `(r,c)`, descend if child exists; on terminal push word and clear it; mark cell, recurse 4 dirs, restore cell.

## 6. Dry Run
Board forms `"oath"` and `"eat"`; `"pea"`/`"rain"` fail. Output includes `eat`, `oath`.

## 7. Time & Space Complexity
Worst **O(M·N·4·3^(L−1))** board walks. Space **O(W)** trie for W words. Why: trie prunes but branching remains (section 4).

## 8. Trade-offs & Alternatives
Optional: delete empty trie branches after finding a word. Per-word search is simpler for tiny dictionaries.

## 9. Common Mistakes / Edge Cases
Forgetting to restore the board cell; not deduping found words; allowing diagonal moves.

## 10. Interview Follow-ups / Variations
Return counts only? Huge dictionary → prune trie nodes; Unicode boards.

## 11. Tags
`trie`, `backtracking`, `dfs`, `matrix`, `difficulty:hard`
