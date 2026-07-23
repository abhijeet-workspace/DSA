# Suffix Array + Kasai LCP

## 1. Problem Statement
Build the suffix array (SA) and LCP array for a string `s`.

- **Inputs:** string `s` of length `N`.
- **Output:** `SA[i]` = starting index of the `i`-th lexicographically smallest suffix; `LCP[i]` = longest common prefix of suffixes `SA[i]` and `SA[i+1]` (convention may leave `LCP[N-1]=0`).
- **Valid answer:** any correct SA/LCP for `s`.
- **Edges:** empty / length 1; all equal characters; already-sorted suffixes.

## 2. Intuition
Prefix-doubling sorts suffixes by pairs of ranks `(rank[i], rank[i+k])` while doubling `k`. Kasai walks suffixes in text order using `invSA` so consecutive LCPs reuse `k-1` work.

## 3. Brute Force → Optimal
- **Brute:** sort all suffixes with `strcmp` — O(N² log N).
- **Optimal:** doubling SA O(N log² N) (or O(N log N) with radix) + Kasai LCP O(N).

## 4. Data Structure / Approach Justification
**Chosen:** rank arrays + `std::sort` doubling; inverse SA for Kasai.

| Alternative | Why not default |
|-------------|-----------------|
| DC3 / SA-IS | Linear but heavier to code/teach |
| Suffix automaton | Better for distinct-substring counts |
| Rolling hash + sort | Extra collision care |

## 5. Logic Walkthrough
1. Init `rank[i]=s[i]`, `sa = 0..n-1`.
2. For `k=1,2,4,...`: sort by `(rank[i], rank[i+k])`, recompute dense ranks; stop when ranks are unique.
3. Kasai: for `i` in text order, compare suffix `i` with neighbor `sa[inv[i]+1]`, store LCP, then `k--`.

## 6. Dry Run
`s=banana` → suffixes sorted start with `a`, `ana`, `anana`, `banana`, `na`, `nana`. First SA entry is index of `a`. Neighbor LCPs capture shared prefixes like `ana`/`anana`.

## 7. Time & Space Complexity
- **Time:** O(N log² N) SA + O(N) LCP.
- **Space:** O(N) for `sa`, `rank`, `lcp`.
Why: log rounds of sorting pairs; Kasai total matches O(N) (section 4).

## 8. Trade-offs & Alternatives
Doubling is interview-friendly. Use SA-IS when N is huge and constants matter. LCP + sparse table gives LCE queries.

## 9. Common Mistakes / Edge Cases
Off-by-one between 0-based SA and LCP slots; forgetting sentinel / empty rank `-1` for `i+k≥n`; not breaking when ranks become unique.

## 10. Interview Follow-ups / Variations
Range-min on LCP for LCE; distinct substrings via `N(N+1)/2 - sum LCP`; SA for pattern matching.

## 11. Tags
`suffix-array`, `lcp`, `kasai`, `string`, `cp`, `difficulty:hard`
