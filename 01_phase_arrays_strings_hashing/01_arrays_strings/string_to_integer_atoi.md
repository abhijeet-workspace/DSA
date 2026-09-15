# String to Integer (atoi)

## Problem Statement
[LeetCode 8](https://leetcode.com/problems/string-to-integer-atoi/) — implement `atoi`: ignore leading spaces, optional sign, read digits, clamp to 32-bit int range.

- **Inputs:** string `s`.
- **Output:** parsed `int` (clamped to `[INT_MIN, INT_MAX]`).
- **Valid answer:** stop at first non-digit after the number; empty/invalid → 0.
- **Edges:** only spaces; overflow; leading zeros; `+`/`-` alone.

## Intuition
Finite-state parse: skip spaces → optional sign → accumulate digits with overflow checks before multiplying.

## Brute Force → Optimal
- **Brute:** regex / `stoll` with try-catch — hides edge cases.
- **Optimal:** one left-to-right scan with `long long` clamp — O(N).

## Data Structure / Approach Justification
**Chosen:** index scan + `long long` accumulator.

- **vs `stoi`:** undefined on overflow / non-conforming inputs.
- **vs DFA table:** clearer for interview narration.

## Logic Walkthrough
Skip spaces; read sign; while digit, `val = val*10 + d`, clamp if beyond 32-bit; return `sign * val`.

## Dry Run
`"   -42"` → skip spaces, sign=-1, digits 4,2 → `-42`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: single pass, constant extra memory.

## Trade-offs & Alternatives
`long long` simplifies clamp vs checking before multiply with only `int`.

## Common Mistakes / Edge Cases
Not clamping mid-parse; treating trailing junk as error; multiple signs.

## Interview Follow-ups / Variations
Reverse Integer (7); valid number (65).

## Tags
`string`, `parsing`, `overflow`, `leetcode-8`, `difficulty:medium`
