# Longest Common Substring via SA+LCP

## 1. Problem Statement
Find the length of the longest common substring of strings `A` and `B`.

- **Inputs:** strings `A`, `B`.
- **Output:** integer length of LCS (substring, not subsequence).
- **Valid answer:** any maximal length (multiple substrings may tie).
- **Edges:** no common chars; equal strings; one empty.

## 2. Intuition
Common substrings appear as neighboring suffixes from different sides after sorting. Concatenate `A + # + B`, build SA+LCP, take max LCP where adjacent SA entries come from different originals.

## 3. Brute Force → Optimal
- **Brute:** DP table O(|A||B|).
- **Optimal:** SA approach O(N log² N) with N=|A|+|B|.

## 4. Data Structure / Approach Justification
**Chosen:** SA+LCP on concatenated string with unique separators.

| Alternative | Note |
|-------------|------|
| Suffix automaton of A, walk B | Often faster constants |
| Binary search + rolling hash | Simpler code, hash risk |
| DP | Fine for small N |

## 5. Logic Walkthrough
1. Build `s = A + "#" + B + "$"`.
2. SA + Kasai LCP on `s`.
3. For each adjacent SA pair from different sides (`i < |A|` xor `j < |A|`), track max LCP.

## 6. Dry Run
`A=abac`, `B=bacc` → common `"bac"` length **3** (also `"ba"`, `"ac"`). Cross-side SA neighbors share that LCP.

## 7. Time & Space Complexity
Time **O(N log² N)**, space **O(N)**. Why: SA dominates; LCP scan is linear (section 4).

## 8. Trade-offs & Alternatives
Extends to k strings with more bookkeeping (which sides appear in an LCP range). SAM is often preferred in CP for LCS of two strings.

## 9. Common Mistakes / Edge Cases
Forgetting a unique separator (suffixes crossing the join); comparing same-side neighbors; off-by-one mid index.

## 10. Interview Follow-ups / Variations
Return the substring itself; LCS of k strings; longest repeated substring (same-side max LCP).

## 11. Tags
`suffix-array`, `lcp`, `lcs`, `string`, `cp`, `difficulty:hard`
