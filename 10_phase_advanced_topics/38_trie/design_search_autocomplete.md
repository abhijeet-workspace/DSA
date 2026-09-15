# Design Search Autocomplete System

## Problem Statement
[LeetCode 642](https://leetcode.com/problems/design-search-autocomplete-system/) — autocomplete from historical sentences; each `input(c)` returns top-3 hottest matches for current prefix; `#` stores sentence and resets.

- **Inputs:** initial sentences + times; stream of chars.
- **Output:** up to 3 sentences (hot desc, then lex).
- **Valid answer:** ASCII including spaces; `#` ends entry.
- **Edges:** no matches; ties; new sentence.

## Intuition
Trie where each node stores hot map of sentences through it; query top-3 at current node.

## Brute Force → Optimal
- **Brute:** scan all sentences each keystroke — O(N·L).
- **Optimal:** trie with hot maps — O(L + K log K) per key for K candidates at node.

## Data Structure / Approach Justification
**Chosen:** trie + per-node sentence frequency map.

- **vs store only terminals + DFS collect:** more work per query.

## Logic Walkthrough
`input`: append char, walk child; return top3 hot; on `#` increment sentence and reset.

## Dry Run
Type `i` → hottest among sentences starting with i.

## Time & Space Complexity
Build **O(Σ L)**. Query **O(L + K log K)**. Space **O(Σ L²)** worst with maps along path.

## Trade-offs & Alternatives
Keep only top-3 at each node to save memory (harder updates).

## Common Mistakes / Edge Cases
Not resetting on `#`; wrong tie-break; dead node after mismatch still accepting.

## Interview Follow-ups / Variations
Prefix search; search suggestions system (1268).

## Tags
`trie`, `design`, `heap`, `leetcode-642`, `difficulty:hard`
