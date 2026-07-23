# Aho-Corasick First Match Positions

## 1. Problem Statement
For each pattern, find the starting index of its first occurrence in text, or `-1`.

- **Inputs:** patterns with ids, text `t`.
- **Output:** `ans[id]` = leftmost start, or `-1`.
- **Valid answer:** leftmost starts only.
- **Edges:** pattern longer than text; overlapping patterns; missing patterns.

## 2. Intuition
Scan once with AC. When a pattern id fires at end index `i`, start = `i - |p| + 1`. Keep the first time only.

## 3. Brute Force → Optimal
- **Brute:** `string::find` per pattern.
- **Optimal:** one AC pass over the text.

## 4. Data Structure / Approach Justification
**Chosen:** AC with `outs` lists + stored pattern lengths.

| Alternative | Note |
|-------------|------|
| KMP each | Simpler if few patterns |
| Regex engines | Overkill / opaque |

## 5. Logic Walkthrough
1. Insert patterns; store `plen[id]`.
2. Build failure links; inherit outs from link.
3. On each text index `i`, for unset ids in `outs`, set `i - plen + 1`.

## 6. Dry Run
Patterns `ab`,`ba`, text `abab` → starts `0` and `1`.

## 7. Time & Space Complexity
Time **O(|t| + Σ|p| + reports)**, space **O(Σ|p|)**. Why: single automaton scan (section 4).

## 8. Trade-offs & Alternatives
Useful for highlighting / first-hit APIs. Collecting all positions needs vectors per id.

## 9. Common Mistakes / Edge Cases
Recording end index instead of start; not inheriting linked outs; 1-based vs 0-based confusion.

## 10. Interview Follow-ups / Variations
All match positions; last match; streaming with partial resets.

## 11. Tags
`aho-corasick`, `positions`, `string`, `cp`, `difficulty:hard`
