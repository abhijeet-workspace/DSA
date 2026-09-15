# SAM Number of Distinct Substrings

## 1. Problem Statement
CP classic — count distinct substrings online with a suffix automaton: sum over states `(len[v] − len[link[v]])`.

- **Inputs:** string `s`.
- **Output:** distinct substring count.
- **Edges:** empty → 0; repeats.

## 2. Intuition
Each state represents an end-set of substrings; the link tree partitions new unique strings.

## 3. Brute Force → Optimal
- **Brute:** set of all substrings.
- **SAM:** O(N) build + O(|states|) sum.
- **SA formula:** also fine offline.

## 4. Data Structure / Approach Justification
**Chosen:** classic SAM extend + sum.

| Alternative | Note |
|-------------|------|
| SA + LCP | Offline |
| Trie of suffixes | O(N²) |

**Pedagogy:** SAM path-count = distinct substrings; pairs with SA LCP formula.

## 5. Logic Walkthrough
Extend each char; sum `len-link_len` over non-root states.

## 6. Dry Run
`aba` → 5.

## 7. Time & Space Complexity
Time **O(N log Σ)** with map (or O(N) array). Space **O(N)**.

## 8. Trade-offs & Alternatives
Pairs with `number_of_distinct_substrings_sa`.

## 9. Common Mistakes / Edge Cases
Including root in the sum; wrong link after clone.

## 10. Interview Follow-ups / Variations
Count occurrences of each substring.

## 11. Tags
`suffix-automaton`, `distinct-substrings`, `cp`, `difficulty:hard`
