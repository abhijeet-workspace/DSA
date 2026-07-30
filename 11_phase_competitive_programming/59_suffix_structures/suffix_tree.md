# Suffix Tree

## Problem Statement
Build a tree of **all suffixes** of a text so that pattern existence queries run in time proportional to pattern length.

- **Inputs:** text `T` (length N), pattern `P` (length M).
- **Output:** whether `P` occurs in `T`.
- **Edges:** empty pattern; pattern longer than text; repeated suffixes (`"banana"`).

## Intuition
Every substring is a prefix of some suffix. If you store all suffixes in a trie (edge-compressed in a true suffix tree), walking `P` character-by-character answers “is this a substring?”.

## Brute Force → Optimal
- **Brute:** scan text for pattern O((N-M+1)·M) or build this demo trie O(N²).
- **True suffix tree (Ukkonen):** O(N) build, O(M) search — advanced; this folder also has suffix arrays / automata for CP practice.

## Data Structure / Approach Justification
**Chosen:** explicit trie of all suffixes (clear teaching model, O(N²) space/time).

- **vs Suffix Array:** array + binary search is O(N log N) build, O(M log N) search; less pointer-heavy.
- **vs Suffix Automaton:** often preferred in CP for substring queries.

## Logic Walkthrough
For each `i`, insert `T[i..]`. To query, walk from the root along `P`; fail if an edge is missing.

## Dry Run
`T="banana"`: suffixes include `ana`, `nan`, `a`, … → `contains("ana")` **yes**, `contains("band")` **no**.

## Time & Space Complexity
This demo: build **O(N²)**, query **O(M)**, space **O(N²)** worst. Ukkonen: build **O(N)**, query **O(M)**.

## Trade-offs & Alternatives
Use suffix array / SAM in contests. Use a real compressed suffix tree when teaching Ukkonen / edge compression.

## Common Mistakes / Edge Cases
Forgetting empty pattern; memory blow-up on long texts with this O(N²) build; confusing trie-of-suffixes with compressed suffix tree.

## Interview Follow-ups / Variations
Ukkonen’s algorithm; longest repeated substring; suffix array + LCP; Aho–Corasick for multi-pattern.

## Tags
`suffix-tree`, `string`, `pattern-matching`, `difficulty:hard`
