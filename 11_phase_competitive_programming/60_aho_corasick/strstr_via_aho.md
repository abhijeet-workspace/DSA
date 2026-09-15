# Implement strStr via Aho-Corasick (LC 28 overkill)

## 1. Problem Statement
Find the first index of `needle` in `haystack`, or `-1` if absent.

- **Inputs:** strings `haystack`, `needle` (lowercase ASCII for this lab).
- **Output:** first start index of a match, else `-1`.
- **Valid answer:** same as classic `strstr` / [LC 28](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/).
- **Edges:** empty needle → `0`; needle longer than haystack; multiple occurrences.
- **Note:** AC is pedagogical overkill for one pattern — KMP/Z/`find` are preferred.
- **Link:** [LC 28](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

## 2. Intuition
Build an AC automaton with a single pattern, scan the text once, record the first time the pattern output fires.

## 3. Brute Force → Optimal
- **Brute:** nested scan O(nm).
- **Better:** KMP/Z for one pattern.
- **Here:** AC still O(n+|Σ|) after build — useful only as a multi-pattern building block.

## 4. Data Structure / Approach Justification
**Chosen:** Aho-Corasick with one pattern id to show the same automaton API.

| Alternative | Note |
|-------------|------|
| `std::string::find` | Production default |
| KMP | Correct single-pattern teaching choice |
| Rabin–Karp | Rolling hash |

## 5. Logic Walkthrough
1. Insert `needle` as pattern 0.
2. `build` failure links.
3. Scan `haystack`; on first output hit at text position `i`, return `i - |needle| + 1`.

## 6. Dry Run
`haystack=sadbutsad`, `needle=sad` → first hit ends at index 2 → start **0**.

## 7. Time & Space Complexity
Build **O(|needle|·|Σ|)**, scan **O(|haystack|)**. Space **O(|needle|·|Σ|)**.

## 8. Trade-offs & Alternatives
Do not use AC in interviews for one needle unless discussing multi-pattern generalization.

## 9. Common Mistakes / Edge Cases
Off-by-one on start index; treating empty needle incorrectly; forgetting root self-loops.

## 10. Interview Follow-ups / Variations
Report all occurrences; switch to KMP; add many needles without rescanning text.

## 11. Tags
`aho-corasick`, `string`, `lc-28`, `overkill-demo`, `difficulty:easy`
