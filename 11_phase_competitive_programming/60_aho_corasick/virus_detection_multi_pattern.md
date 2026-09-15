# Virus Detection Multi-Pattern (Teaching)

## 1. Problem Statement
Teaching paraphrase of classic multi-pattern virus / signature scanning (contest-style I/O, **no invented contest ID**).

- **Statement:** You are given `n` lowercase virus signatures and one DNA string `t`. Report for each signature whether it occurs as a contiguous substring of `t`.
- **Input format (lab):** `n`; then `n` patterns; then one line `t`.
- **Output:** `n` lines `YES`/`NO`.
- **Constraints (lab):** `n ≤ 1000`, total pattern length ≤ 1e5, `|t| ≤ 1e5`, alphabet `a–z`.
- **Edges:** overlapping signatures; unused patterns; empty `t`.

## 2. Intuition
Dictionary of signatures + one scan ⇒ Aho-Corasick (or many KMP).

## 3. Brute Force → Optimal
- **Brute:** `find` each pattern in `t`.
- **AC:** linear in `|t| + Σ|p| + reports`.

## 4. Data Structure / Approach Justification
**Chosen:** AC with boolean seen flags per pattern id.

| Alternative | Note |
|-------------|------|
| Suffix automaton of `t` | Good if text fixed, patterns queried |
| Hashing | Probabilistic |

## 5. Logic Walkthrough
1. Read patterns; insert with ids; build.
2. Scan `t`; mark outs.
3. Print YES/NO per id.

## 6. Dry Run
Patterns `aba,ba`; `t=ababa` → YES YES.

## 7. Time & Space Complexity
**O(|t| + Σ|p| · |Σ|)**.

## 8. Trade-offs & Alternatives
Teaching I/O uses hardcoded sample equivalent to the stated format.

## 9. Common Mistakes / Edge Cases
Case sensitivity; not handling overlaps; wrong YES when only subsequence matches.

## 10. Interview Follow-ups / Variations
Count occurrences; online stream of DNA; alphabet size 4.

## 11. Tags
`aho-corasick`, `multi-pattern`, `teaching`, `difficulty:hard`
