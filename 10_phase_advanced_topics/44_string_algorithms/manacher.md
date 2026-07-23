# Manacher's Algorithm

## Problem Statement
[LeetCode 5](https://leetcode.com/problems/longest-palindromic-substring/) — return a longest palindromic substring of `s`.

- **Inputs:** string `s`.
- **Output:** any longest palindromic substring.
- **Valid answer:** if ties, any max-length one (e.g. `"bab"` or `"aba"`).
- **Edges:** empty; single char; all identical; even-length center (`"cbbd"` → `"bb"`).

## Intuition
Expanding around every center is O(N²). Inside the current rightmost palindrome, the mirror center already gives a lower bound on the radius, so many expansions are skipped. Inserting `#` unifies odd/even centers.

## Brute Force → Optimal
- **Brute:** all substrings + palindrome check — O(N³) / expand centers O(N²).
- **DP:** `isPal[i][j]` — O(N²) time and space.
- **Optimal:** Manacher — O(N) time and space.

## Data Structure / Approach Justification
**Chosen:** transformed string `t` with `#`, radius array `P`, center `C` and right bound `R`.

- **vs expand-around-center:** simpler to code in interviews, slower asymptotically.
- **vs DP:** clearer recurrence, heavier memory.

## Logic Walkthrough
Build `t = #s0#s1#...#`. For each `i`, seed `P[i]` from mirror if `i < R`, then expand while chars match. Update `(C,R)` when the palindrome extends past `R`. Map best center back: `start = (centerIdx - maxLen) / 2`.

## Dry Run
`s="babad"` → candidates `"bab"` / `"aba"` (length 3).
`s="cbbd"` → `"bb"`.

## Time & Space Complexity
Time **O(N)**; space **O(N)** for `t` and `P`. Why: each expansion moves `R` right at most O(N) total (section 4).

## Trade-offs & Alternatives
Under interview time pressure, expand-around-center is usually enough. Use Manacher when N is large or the question demands linear time. Suffix structures are overkill for LPS alone.

## Common Mistakes / Edge Cases
Wrong index map from transformed to original; off-by-one when expanding; forgetting `#` so even palindromes break; empty input.

## Interview Follow-ups / Variations
Count all palindromic substrings from radii; longest palindromic subsequence (DP, different problem).

## Tags
`string`, `manacher`, `palindrome`, `leetcode-5`, `difficulty:hard`
