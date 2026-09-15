# Manacher vs Suffix Array (Note)

## 1. Problem Statement
Teaching lab — Manacher finds the longest palindromic substring in O(N). **Not** a suffix-array problem; included to prevent tool mix-ups in the suffix folder.

- **Inputs:** string `s`.
- **Output:** one longest palindromic substring.
- **Edges:** single char; whole string palindrome.

## 2. Intuition
Odd/even palindromes unified via separators; expand using mirror radius inside the right frontier.

## 3. Brute Force → Optimal
- **Brute:** expand all centers O(N²).
- **Manacher:** O(N).
- **SA:** wrong primary tool for palindromes.

## 4. Data Structure / Approach Justification
**Chosen:** Manacher with `#` separators.

| Alternative | Note |
|-------------|------|
| DP boolean table | O(N²) |
| SA / hashing | Possible but unnatural |

**Pedagogy:** contrast Manacher (palindromes) vs SA (lex order / LCP); pick tool by query type.

## 5. Logic Walkthrough
Build transformed string; maintain center/right; track max radius.

## 6. Dry Run
`babad` → `bab` or `aba`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Use SA for repeats/LCS; Manacher for palindromes.

## 9. Common Mistakes / Edge Cases
Forgetting sentinels `^/$`; off-by-one substr.

## 10. Interview Follow-ups / Variations
Count palindromic substrings.

## 11. Tags
`manacher`, `palindrome`, `teaching`, `difficulty:medium`
