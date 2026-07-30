# Boyer-Moore

## Problem Statement
Find all starting indices where pattern `pat` occurs in text `txt`, using the Boyer–Moore **bad-character** heuristic (good-suffix omitted for a teaching demo).

- **Inputs:** strings `txt` (N), `pat` (M).
- **Output:** 0-based start indices of matches.
- **Edges:** empty pattern; no match; overlapping matches; single character.

## Intuition
Compare from the **right** of the pattern. A mismatch lets you shift the pattern using where that text character last appears in the pattern, often skipping many positions.

## Brute Force → Optimal
- **Brute:** O(N·M) naive.
- **This demo:** bad-character shifts — average near O(N) on natural text; worst still O(N·M) without full BM.
- **Full Boyer–Moore:** bad-character + good-suffix → strong practical performance.

## Data Structure / Approach Justification
**Chosen:** bad-character table of size 256 (last index of each byte in `pat`).

- **vs KMP:** KMP is worst-case linear; BM often faster in practice on large alphabets.
- **vs Rabin–Karp:** BM avoids hashing; RK shines for multi-pattern / rolling hash pipelines.

## Logic Walkthrough
Build last-occurrence table. Align at `s`. Match right-to-left. On full match record `s` and shift. On mismatch at `j`, shift by `max(1, j - bad[txt[s+j]])`.

## Dry Run
`txt="ABAAABCD"`, `pat="ABC"`: mismatch shifts skip ahead → match at index **4**.

## Time & Space Complexity
Average ~**O(N)** on typical text; worst **O(N·M)** (bad-character only). Space **O(Σ)** for the table (256 here).

## Trade-offs & Alternatives
Interview default for guaranteed linear: KMP/Z. Use BM when discussing practical scanners / editors.

## Common Mistakes / Edge Cases
Forgetting `max(1, …)` (negative shift); not handling empty pattern; assuming full BM complexity with only bad-character.

## Interview Follow-ups / Variations
Good-suffix rule; Horspool; Sunday algorithm; multi-pattern (Aho–Corasick).

## Tags
`string`, `boyer-moore`, `pattern-matching`, `difficulty:medium`
