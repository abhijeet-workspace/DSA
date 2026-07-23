# Trie Advanced

## Problem Statement
Demonstrate two advanced trie uses: (1) [LeetCode 421](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) max XOR of a pair via a binary trie; (2) Aho-Corasick skeleton for multi-pattern matching.

- **Inputs:** integer array; or multiple lowercase patterns.
- **Output:** max pairwise XOR; built failure-link automaton.
- **Valid answer:** any pair maximizing `a ^ b`; AC reports pattern ids at nodes.
- **Edges:** single element; identical numbers; overlapping patterns (`he`/`she`).

## Intuition
XOR is maximized by preferring the opposite bit at each MSB→LSB step. Aho-Corasick adds failure links so the search automaton can jump to the longest proper suffix that is a prefix.

## Brute Force → Optimal
- **Brute XOR:** try all pairs — O(N²).
- **Optimal XOR:** insert all numbers in a 32-bit trie; query best partner — O(32N).
- **Brute multi-match:** run KMP per pattern — O(patterns · text).
- **AC:** one automaton — linear in text + pattern size.

## Data Structure / Approach Justification
**Chosen:** binary trie `children[2]`; AC as indexed `vector<Node>` with fail links.

- **vs hash set of numbers:** cannot greedily choose opposite bits.
- **vs separate KMP:** AC shares work across patterns.

## Logic Walkthrough
XOR: insert bits MSB-first; query tries opposite bit each level. AC: insert patterns; BFS set fail links; merge match lists from fail targets.

## Dry Run
`nums={3,10,5,25,2,8}` → max XOR `5^25=28`. AC inserts `he,she,his,hers` then builds fails.

## Time & Space Complexity
XOR insert/query **O(32)** each → **O(N)** total. AC build **O(Σ|pattern|)**. Space **O(states · alphabet)**. Why: fixed bit depth / linear automaton (section 4).

## Trade-offs & Alternatives
XOR trie needs all numbers first (or online insert+query). AC is heavier than a plain trie but required for streaming multi-match.

## Common Mistakes / Edge Cases
Querying an empty XOR trie; wrong bit order (LSB first); forgetting to merge fail matches in AC.

## Interview Follow-ups / Variations
Max XOR with a range constraint; AC search over a text; compressed binary trie.

## Tags
`trie`, `xor`, `aho-corasick`, `bit-trie`, `difficulty:hard`
