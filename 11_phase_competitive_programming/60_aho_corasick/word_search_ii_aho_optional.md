# Word Search II — AC optional note (LC 212)

## 1. Problem Statement
Find all dictionary words that appear as paths in a board (4-direction).

- **Inputs:** `board` of letters, `words[]`.
- **Output:** list of words found on the board.
- **Valid answer:** [LC 212](https://leetcode.com/problems/word-search-ii/).
- **Edges:** reused cells forbidden in one path; overlapping words; empty board.
- **Note:** Standard solution is DFS + trie prune. Full Aho-Corasick is optional/unusual on a 2D grid; lab shows trie DFS (preferred) and comments when AC would not help.
- **Link:** [LC 212](https://leetcode.com/problems/word-search-ii/)

## 2. Intuition
Prefix pruning via a trie kills dead branches early. AC is built for linear text scanning, not grid DFS.

## 3. Brute Force → Optimal
- **Brute:** DFS from each cell for each word.
- **Better:** one trie of all words + DFS.
- **AC:** not a natural fit for branching grid walks.

## 4. Data Structure / Approach Justification
**Chosen:** insert words into a trie; DFS from each cell; prune missing edges; collect ends.

| Alternative | Note |
|-------------|------|
| Per-word DFS | Too slow with many words |
| AC automaton | Designed for 1D text streams |

## 5. Logic Walkthrough
1. Build trie of words.
2. From each cell, DFS with visited mask.
3. On trie end, push word; optional delete end to avoid duplicates.

## 6. Dry Run
Board `o a a n / e t a e / i h k r / i f l v`, words `{oath,pea,eat,rain}` → `oath`, `eat`.

## 7. Time & Space Complexity
**O(R·C·4^L)** worst with prune; space **O(total word chars)**.

## 8. Trade-offs & Alternatives
Trie DFS is the interview answer. Mention AC only to show you know when not to force it.

## 9. Common Mistakes / Edge Cases
Reusing cells; not backtracking visited; mutating trie incorrectly when removing found words.

## 10. Interview Follow-ups / Variations
Return first match only; larger alphabets; compare to AC on flattened rows (weak).

## 11. Tags
`trie`, `dfs`, `backtracking`, `lc-212`, `aho-note`, `difficulty:hard`
