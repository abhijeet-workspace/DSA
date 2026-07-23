# KMP Algorithm

## Problem Statement
Find all starting indices where pattern `pat` occurs in text `txt` in linear time.

- **Inputs:** strings `txt` (length N), `pat` (length M).
- **Output:** 0-based start indices of matches (overlapping allowed).
- **Valid answer:** all occurrences; empty list if none.
- **Edges:** empty pattern; `N < M`; overlapping matches (`"AA"` in `"AAAA"`); single char.

## Intuition
Naive matching rechecks characters after a mismatch. The LPS array remembers how much of the pattern is still a valid prefix after a fail, so the text pointer never rewinds.

## Brute Force → Optimal
- **Brute:** try every start, compare up to M chars — O(N·M).
- **Optimal:** KMP — O(N + M) preprocess + search.

## Data Structure / Approach Justification
**Chosen:** LPS `vector<int>` of size M, then two-pointer scan of text/pattern.

- **vs Rabin–Karp:** KMP worst-case linear; RK average linear, worst O(NM) with collisions.
- **vs Z-algorithm:** similar asymptotics; Z builds one array on `pat$text`.

## Logic Walkthrough
Build LPS: while matching, grow `len`; on fail set `len = lps[len-1]` or write 0. Search: advance on match; on full match record `i-j` and set `j = lps[j-1]`; on mismatch jump `j` via LPS or advance `i`.

## Dry Run
`pat="AA"`, `txt="AAAAAA"`:
- LPS ≈ `[0,1]`
- Matches at **0,1,2,3,4** (overlapping)

`pat="TEST"`, `txt="THIS IS A TEST TEXT"` → match at **10**.

## Time & Space Complexity
Time **O(N + M)**; space **O(M)** for LPS. Why: each `i`/`len` advances at most N+M times (section 4).

## Trade-offs & Alternatives
KMP is the classic interview linear matcher. Prefer Z when you want occurrence listing via concat; prefer RK for multiple patterns with rolling hashes / plagiarism-style pipelines.

## Common Mistakes / Edge Cases
Off-by-one on `lps[j-1]`; forgetting overlap after a match; not handling `m==0`; confusing LPS definition (proper prefix — not whole string).

## Interview Follow-ups / Variations
Count occurrences only; shortest superstring / border theory; KMP automaton; pattern with wildcards.

## Tags
`string`, `kmp`, `lps`, `pattern-matching`, `difficulty:medium`
