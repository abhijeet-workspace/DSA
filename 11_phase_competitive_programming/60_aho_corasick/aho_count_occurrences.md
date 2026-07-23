# Aho-Corasick Count Occurrences

## 1. Problem Statement
Count the total number of pattern occurrences in text (overlapping allowed).

- **Inputs:** dictionary of patterns, text `t`.
- **Output:** total hit count across all patterns and positions.
- **Valid answer:** exact overlapping count.
- **Edges:** self-overlapping patterns (`aa` in `aaa`); duplicate inserts.

## 2. Intuition
Same AC automaton; store `outCnt` = patterns ending here + link’s count. Each text step adds `outCnt` of the current state.

## 3. Brute Force → Optimal
- **Brute:** KMP count per pattern.
- **Optimal:** AC O(|t| + build); reporting volume absorbed into counts.

## 4. Data Structure / Approach Justification
**Chosen:** AC with aggregated `outCnt` instead of listing ids (faster when only totals matter).

| Alternative | Note |
|-------------|------|
| List all outs | Needed for per-pattern reports |
| SAM | Different construction |

## 5. Logic Walkthrough
1. Insert patterns; bump `outCnt` at terminals.
2. BFS: `outCnt[v] += outCnt[link[v]]`; fill missing transitions.
3. Scan text; `ans += outCnt[v]` each step.

## 6. Dry Run
Patterns `a`,`aa`, text `aaa`: positions yield 1+2+2 = **5** (`a`×3 + `aa`×2).

## 7. Time & Space Complexity
Time **O(|t| + Σ|p|)**, space **O(Σ|p|)**. Why: counts folded into nodes; no per-hit list walk (section 4).

## 8. Trade-offs & Alternatives
Reporting every occurrence explicitly can dominate time if the answer is huge — counting aggregates avoids that.

## 9. Common Mistakes / Edge Cases
Adding link counts twice; forgetting overlaps; inserting the same pattern twice without intending multiplicity.

## 10. Interview Follow-ups / Variations
Per-pattern counts; list starting indices; weighted patterns.

## 11. Tags
`aho-corasick`, `counting`, `string`, `cp`, `difficulty:hard`
