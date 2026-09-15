# Suffix Array O(N log² N)

## 1. Problem Statement
CP classic — build suffix array by prefix doubling with `std::sort` each round → O(N log² N).

- **Inputs:** string `s`.
- **Output:** `sa[i]` starting indices in lex order.
- **Edges:** length 1; identical characters.

## 2. Intuition
Sort by pairs `(rank[i], rank[i+k])` while doubling `k`.

## 3. Brute Force → Optimal
- **Brute:** sort suffixes O(N² log N).
- **Doubling:** O(N log² N).
- **DC3/SA-IS:** O(N) — skipped here as too long.

## 4. Data Structure / Approach Justification
**Chosen:** doubling + comparison sort.

| Alternative | Note |
|-------------|------|
| Radix per round | O(N log N) |
| DC3 | Linear, heavy |

**Pedagogy:** explicit O(N log² N) sort-of-pairs build; clarifies ranks before radix optimizations.

## 5. Logic Walkthrough
Init ranks; for k=1,2,4,… sort and densify ranks; stop when unique.

## 6. Dry Run
`banana` → `5 3 1 0 4 2` (suffixes a, ana, anana, banana, na, nana).

## 7. Time & Space Complexity
Time **O(N log² N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Same core as `suffix_array_build`; kept as a focused complexity lab.

## 9. Common Mistakes / Edge Cases
Sentinel ranks; not breaking early.

## 10. Interview Follow-ups / Variations
Add Kasai LCP in the same pass family.

## 11. Tags
`suffix-array`, `prefix-doubling`, `cp`, `difficulty:medium`
