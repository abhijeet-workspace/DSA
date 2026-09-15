# Aho Online Stream Matcher

## 1. Problem Statement
Maintain an AC automaton and process an online stream of characters, emitting matches as soon as they complete.

- **Inputs:** patterns up front; then a stream of chars.
- **Output:** after each char, newly completed pattern ids (if any).
- **Edges:** matches spanning stream chunks; overlapping hits.

## 2. Intuition
AC state is a single integer — perfect for online scanners (virus filters, log watchers).

## 3. Brute Force → Optimal
- **Brute:** append to buffer and re-search.
- **Online AC:** O(1) amortized per char.

## 4. Data Structure / Approach Justification
**Chosen:** persistent automaton state `v` across `feed(ch)` calls.

| Alternative | Note |
|-------------|------|
| Restart KMP per pattern | Worse multi-pattern |
| Windowed re-scan | Extra work |

## 5. Logic Walkthrough
1. Build AC offline.
2. `feed`: transition; return outs at new node.
3. Keep `v` between calls.

## 6. Dry Run
Patterns `ab,bc`; stream `a,b,c` → after `b` hit `ab`; after `c` hit `bc`.

## 7. Time & Space Complexity
**O(1)** amortized per char after build.

## 8. Trade-offs & Alternatives
Patterns fixed after build; rebuild to add patterns.

## 9. Common Mistakes / Edge Cases
Resetting state each chunk; not reporting inherited outs.

## 10. Interview Follow-ups / Variations
Dynamic pattern inserts; byte alphabets.

## 11. Tags
`aho-corasick`, `streaming`, `online`, `lab`, `difficulty:hard`
