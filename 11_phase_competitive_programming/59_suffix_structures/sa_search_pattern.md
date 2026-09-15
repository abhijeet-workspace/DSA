# Suffix Array Pattern Search

## 1. Problem Statement
CP classic — after building SA of text `T`, test whether pattern `P` occurs via binary search on SA.

- **Inputs:** text, pattern.
- **Output:** yes/no occurrence.
- **Edges:** empty pattern; pattern longer than text.

## 2. Intuition
SA is lexicographically sorted suffixes; binary search compares `P` to `T[sa[mid]..]`.

## 3. Brute Force → Optimal
- **Brute:** `string::find`.
- **SA search:** O(|P| log |T|) after build.

## 4. Data Structure / Approach Justification
**Chosen:** doubling SA + binary search.

| Alternative | Note |
|-------------|------|
| KMP / Z | Linear single pattern |
| SAM | Online + multiple |

**Pedagogy:** binary search on SA for pattern occurrence; Z/KMP often simpler for single pattern.

## 5. Logic Walkthrough
Lower-bound style BS; verify equality at `lo`.

## 6. Dry Run
`banana` contains `ana`, not `band`.

## 7. Time & Space Complexity
Build **O(N log² N)**; query **O(M log N)**.

## 8. Trade-offs & Alternatives
LCP + RMQ speeds LCE but not required for existence.

## 9. Common Mistakes / Edge Cases
compare length limits; unsigned char ranks.

## 10. Interview Follow-ups / Variations
Report all occurrence positions (range of SA).

## 11. Tags
`suffix-array`, `pattern-matching`, `binary-search`, `cp`, `difficulty:medium`
