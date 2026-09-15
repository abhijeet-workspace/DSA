# Number of Distinct Substrings (SA)

## 1. Problem Statement
CP classic / related to [LeetCode 1698](https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/) (premium) — count distinct substrings of `s` via SA+LCP: `n(n+1)/2 − Σ LCP`.

- **Inputs:** string `s`.
- **Output:** count of distinct substrings.
- **Edges:** empty; all equal chars.

## 2. Intuition
Each suffix contributes `n-sa[i]` prefixes; subtract those already shared with previous suffix (`LCP`).

## 3. Brute Force → Optimal
- **Brute:** insert all O(N²) into set.
- **SA+LCP:** O(N log² N).
- **SAM:** O(N).

## 4. Data Structure / Approach Justification
**Chosen:** doubling SA + Kasai LCP.

| Alternative | Note |
|-------------|------|
| Suffix automaton | Linear, see `sam_number_distinct_substrings` |

**Pedagogy:** classic Σ (n−SA[i]−LCP[i−1]) identity; SAM gives same count online.

## 5. Logic Walkthrough
Build SA/LCP; return `n(n+1)/2 - sum LCP[i]`.

## 6. Dry Run
`aba` → 5; `aaa` → 3.

## 7. Time & Space Complexity
Time **O(N log² N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Same formula appears in many CP editorials.

## 9. Common Mistakes / Edge Cases
Including LCP[n-1] wrongly; empty string.

## 10. Interview Follow-ups / Variations
Count distinct of length k.

## 11. Tags
`suffix-array`, `lcp`, `distinct-substrings`, `cp`, `difficulty:medium`
