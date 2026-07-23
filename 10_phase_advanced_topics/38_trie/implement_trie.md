# Implement Trie

## Problem Statement
[LeetCode 208](https://leetcode.com/problems/implement-trie-prefix-tree/) — implement a prefix tree supporting `insert`, `search` (full word), and `startsWith`.

- **Inputs:** lowercase `a–z` words/prefixes.
- **Output:** bool for search / startsWith; insert is void.
- **Valid answer:** shared prefixes; `search` requires end-of-word flag.
- **Edges:** overlapping words (`app` / `apple`); search before insert; empty not given.

## Intuition
Each edge is a letter. A path from the root spells a string; an `isEnd` flag marks a complete word so prefixes are not false positives.

## Brute Force → Optimal
- **Brute:** store all words in a hash set — O(1) avg search, no prefix sharing / `startsWith` needs another structure.
- **Optimal:** 26-way trie — O(L) per op, shared prefix memory.

## Data Structure / Approach Justification
**Chosen:** `TrieNode` with `children[26]` and `isEnd`.

- **vs `unordered_map` children:** array is faster for fixed a–z.
- **vs hash set of words + prefix set:** more memory, no natural tree walk.

## Logic Walkthrough
`insert`: walk/create nodes per char, set `isEnd`. `search`: walk; fail on missing child; return `isEnd`. `startsWith`: same walk; return true if path exists.

## Dry Run
`insert("apple")`; `search("apple")` → true; `search("app")` → false; `startsWith("app")` → true; `insert("app")`; `search("app")` → true.

## Time & Space Complexity
Per op **O(L)**. Space **O(total chars)** across nodes. Why: one node edge per character inserted (section 4).

## Trade-offs & Alternatives
Array[26] wastes slots for sparse alphabets — use map/unordered_map then. Ternary search tree saves space for large alphabets.

## Common Mistakes / Edge Cases
Returning true on a prefix path without checking `isEnd` for `search`; not allocating a child before descending.

## Interview Follow-ups / Variations
Delete a word? Count words with a prefix? Path compression (radix tree)?

## Tags
`trie`, `prefix-tree`, `string`, `design`, `difficulty:medium`
