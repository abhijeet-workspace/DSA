# Longest Word in Dictionary

## 1. Problem Statement
[LeetCode 720](https://leetcode.com/problems/longest-word-in-dictionary/) — longest word buildable one character at a time by other dictionary words; ties → lexicographically smallest.

- **Inputs:** `vector<string> words`.
- **Output:** winning word or `""`.
- **Valid answer:** unique under the tie-break.
- **Edges:** all length-1; missing intermediate prefixes.

## 2. Intuition
Every prefix of a valid word must also be in the dictionary. Trie DFS only descends through end-marked nodes.

## 3. Brute Force → Optimal
- **Brute:** sort; check all prefixes in a set.
- **Optimal:** trie walk through `isEnd` chain.

## 4. Data Structure / Approach Justification
**Chosen:** insert all; DFS children `a→z` only if child `end`.

- **vs sort + set:** same asymptotics; trie makes the chain explicit.

## 5. Logic Walkthrough
DFS from root; track best by length then lex.

## 6. Dry Run
`["w","wo","wor","worl","world"]` → **`world`**.

## 7. Time & Space Complexity
Time **O(total)**. Space **O(total)**. Why: each edge once (section 4).

## 8. Trade-offs & Alternatives
Sort by length and insert when `word[:-1]` exists is a short alternative.

## 9. Common Mistakes / Edge Cases
Descending through non-end nodes; wrong lex tie-break.

## 10. Interview Follow-ups / Variations
Return all valid words; allow k missing prefixes.

## 11. Tags
`trie`, `dfs`, `string`, `leetcode-720`, `difficulty:medium`
