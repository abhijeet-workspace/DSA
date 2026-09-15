# SAM First Occurrence

## 1. Problem Statement
Teaching / CP — find the first starting index of pattern `P` in text via SAM, using `firstPos` end positions on states.

- **Inputs:** text built into SAM, pattern.
- **Output:** first start index or `-1`.
- **Edges:** missing pattern; pattern = full text.

## 2. Intuition
Walk `P` in the automaton; state's `firstPos` is an end index of the matched string class; start = `firstPos-|P|+1`.

## 3. Brute Force → Optimal
- **Brute:** `find`.
- **SAM:** O(|P|) after O(|T|) build.

## 4. Data Structure / Approach Justification
**Chosen:** SAM with `firstPos` on create (clone inherits).

| Alternative | Note |
|-------------|------|
| SA binary search | Also O(|P| log |T|) |
| KMP | Linear single pattern |

**Pedagogy:** SAM endpos links give first occurrence; contrasts SA binary search.

## 5. Logic Walkthrough
Extend with positions; walk pattern; convert end→start.

## 6. Dry Run
`banana`: `ana`→1, `nana`→2, `band`→-1.

## 7. Time & Space Complexity
Build **O(N log Σ)**; query **O(|P|)**.

## 8. Trade-offs & Alternatives
Useful when many patterns share one text automaton.

## 9. Common Mistakes / Edge Cases
Updating `firstPos` on clone incorrectly; off-by-one start.

## 10. Interview Follow-ups / Variations
All occurrence ends via endpos sets.

## 11. Tags
`suffix-automaton`, `pattern-matching`, `cp`, `difficulty:hard`
