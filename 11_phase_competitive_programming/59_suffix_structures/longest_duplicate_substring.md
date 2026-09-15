# Longest Duplicate Substring

## 1. Problem Statement
[LeetCode 1044](https://leetcode.com/problems/longest-duplicate-substring/) — longest substring that occurs ≥2 times (any if ties).

**Pedagogy vs SA:** binary search + Rabin–Karp is the usual LC solution; suffix array + LCP finds the same answer via `max LCP[i]`.

- **Inputs:** string `s`.
- **Output:** longest duplicated substring (or empty).
- **Edges:** all unique chars; whole string repeated.

## 2. Intuition
Monotone in length ⇒ binary search; rolling hash checks existence of duplicate of length mid.

## 3. Brute Force → Optimal
- **Brute:** all substrings set.
- **Hash+BS:** O(N log N) expected.
- **SA+LCP:** O(N log N) deterministic build.

## 4. Data Structure / Approach Justification
**Chosen:** binary search + Rabin–Karp with verify.

| Alternative | Note |
|-------------|------|
| Suffix array + max LCP | Preferred CP tool |
| SAM | Also finds longest repeat |

## 5. Logic Walkthrough
BS on len; maintain rolling hash map; strcmp on collisions.

## 6. Dry Run
`banana` → `ana`.

## 7. Time & Space Complexity
Time **O(N log N)** expected. Space **O(N)**.

## 8. Trade-offs & Alternatives
Use SA when you already build LCP for other queries.

## 9. Common Mistakes / Edge Cases
Hash collisions without verify; off-by-one length.

## 10. Interview Follow-ups / Variations
k-duplicate substring; online.

## 11. Tags
`leetcode-1044`, `rabin-karp`, `binary-search`, `suffix-pedagogy`, `difficulty:hard`
