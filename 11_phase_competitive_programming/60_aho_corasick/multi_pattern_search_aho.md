# Multi-Pattern Search with Aho-Corasick

## 1. Problem Statement
Teaching lab: given patterns and one text, list every (pattern id, end position) match.

- **Inputs:** `patterns[]`, text `t` (lowercase).
- **Output:** pairs `(id, endIndex)` for each occurrence (overlapping allowed).
- **Edges:** nested patterns (`he`/`she`); empty text; unused patterns.
- **I/O (lab):** hardcoded samples; print matches sorted by end then id.

## 2. Intuition
One automaton scan reports all pattern hits via output lists inherited through failure links.

## 3. Brute Force → Optimal
- **Brute:** KMP per pattern.
- **AC:** one pass O(|t| + total pattern length + hits).

## 4. Data Structure / Approach Justification
**Chosen:** classic AC with `outs` vectors copied along fail links.

| Alternative | Note |
|-------------|------|
| Suffix array of text | Different tradeoffs |
| Multiple KMP | Fine for few patterns |

## 5. Logic Walkthrough
1. Insert patterns with ids.
2. BFS build links + inherit outs.
3. Scan text; emit each out id at current index.

## 6. Dry Run
Patterns `he,she`; text `ushers` → `(0,4),(1,4)` for end indices of `he`/`she`.

## 7. Time & Space Complexity
Build **O(Σ|p|·|Σ|)**, match **O(|t| + hits)**.

## 8. Trade-offs & Alternatives
Output-link chains save memory vs copying full outs.

## 9. Common Mistakes / Edge Cases
Missing inherited outputs; not allowing overlaps.

## 10. Interview Follow-ups / Variations
Count only; first match positions; streaming.

## 11. Tags
`aho-corasick`, `multi-pattern`, `lab`, `difficulty:hard`
