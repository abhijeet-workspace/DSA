# Z-Algorithm vs Suffix Array

## 1. Problem Statement
Teaching lab — compute the Z-array of a string and contrast it with suffix-array LCP.

- **Inputs:** string `s`.
- **Output:** selected `z[i]` values.
- **Edges:** all equal; no self-matches.

## 2. Intuition
`z[i]` = LCP of `s` and `s[i..]`. SA LCP compares neighboring suffixes in lex order — different adjacency.

## 3. Brute Force → Optimal
- **Z:** O(N) for prefix-related matches (pattern search via `P+$+T`).
- **SA:** general substring toolkit.

## 4. Data Structure / Approach Justification
**Chosen:** classic Z-box algorithm.

| Alternative | Note |
|-------------|------|
| KMP prefix function | Related border structure |
| SA+LCP | Lex adjacency |

**Pedagogy:** Z-array answers prefix matches in linear time; SA needed for arbitrary substring order stats.

## 5. Logic Walkthrough
Maintain `[l,r]` match window; extend comparisons.

## 6. Dry Run
On `aabcaabxaaaz`, `z[4]=3`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Pick Z/KMP for single-pattern; SA/SAM for richer queries.

## 9. Common Mistakes / Edge Cases
Off-by-one in `r`; assuming `z[0]=n` required.

## 10. Interview Follow-ups / Variations
Manacher for palindromes (different again — not SA).

## 11. Tags
`z-algorithm`, `suffix-array`, `teaching`, `difficulty:easy`
