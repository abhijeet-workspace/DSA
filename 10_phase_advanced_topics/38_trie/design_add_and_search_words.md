# Design Add and Search Words

## Problem Statement
[LeetCode 211](https://leetcode.com/problems/design-add-and-search-words-data-structure/) — `addWord(word)`; `search(word)` where `.` matches any letter.

- **Inputs:** lowercase words; search patterns may contain `.`.
- **Output:** bool — whether any added word matches the pattern.
- **Valid answer:** exact length match; `.` expands to any a–z at that position.
- **Edges:** all dots; search before any add; length-1 words.

## Intuition
Store words in a trie. Exact letters follow one edge; on `.`, DFS-branch over all 26 children and succeed if any branch matches.

## Brute Force → Optimal
- **Brute:** keep a list of words; regex/scan each search — O(#words · L).
- **Optimal:** trie + DFS wildcard — practical under interview constraints.

## Data Structure / Approach Justification
**Chosen:** trie node `next[26]` + `end`, with recursive DFS for `.`.

- **vs length → word list:** simple for tiny sets; weak with many words/prefixes.
- **vs Aho-Corasick:** overkill for single-pattern wildcard search.

## Logic Walkthrough
`addWord`: insert like a normal trie. `search`: at index `i`, if `.` try all children; else follow one child; at end require `end`.

## Dry Run
Add `"bad"`, `"dad"`. `search("pad")` → false. `search(".ad")` → tries a…z then `"ad"` path → true. `search("b..")` → true.

## Time & Space Complexity
Add **O(L)**. Search **O(26^D · L)** worst with D dots. Space **O(total chars)**. Why: each `.` fans out (section 4).

## Trade-offs & Alternatives
Worst-case exponential in dots — usually few wildcards. Map by length can beat trie for very small dictionaries.

## Common Mistakes / Edge Cases
Treating `.` as literal; forgetting `end` at pattern end; null-child DFS without a guard.

## Interview Follow-ups / Variations
Support `*`? Delete words? Case-insensitive? Cap branching with pruning.

## Tags
`trie`, `dfs`, `backtracking`, `design`, `difficulty:medium`
