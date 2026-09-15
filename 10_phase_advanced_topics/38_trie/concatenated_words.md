# Concatenated Words

## 1. Problem Statement
[LeetCode 472](https://leetcode.com/problems/concatenated-words/) — return all words that are concatenations of at least two shorter words from the list.

- **Inputs:** `vector<string> words` (unique).
- **Output:** list of concatenated words.
- **Valid answer:** any order.
- **Edges:** empty list; deep concatenations; missing intermediate pieces.

## 2. Intuition
A word is concatenated if it word-breaks into ≥2 dictionary words. A trie plus memoized DFS detects that.

## 3. Brute Force → Optimal
- **Brute:** recursive splits against a set.
- **Optimal:** trie + memoized DFS requiring ≥2 pieces.

## 4. Data Structure / Approach Justification
**Chosen:** insert all words; DFS with `parts` counter and memo.

- **vs DP word-break + hash set:** also correct; trie shares prefix checks.

## 5. Logic Walkthrough
For each word, DFS from index 0; on word-end mid-string, recurse with `parts+1`; success at end with `parts≥2`.

## 6. Dry Run
`["cat","cats","catsdogcats","dog",...]` → `catsdogcats`, `dogcatsdog`, `ratcatdogcat`.

## 7. Time & Space Complexity
Roughly **O(total·L²)** with memo. Space **O(total)** trie + memo. Why: classic word-break cost (section 4).

## 8. Trade-offs & Alternatives
Hash-set word-break is fine; trie helps with heavy prefix sharing.

## 9. Common Mistakes / Edge Cases
Counting the word as using itself alone; missing memo; requiring exactly 2 parts.

## 10. Interview Follow-ups / Variations
Minimum parts; return one segmentation.

## 11. Tags
`trie`, `dfs`, `word-break`, `leetcode-472`, `difficulty:hard`
