# Letter Combinations of a Phone Number

## 1. Problem Statement
[LeetCode 17](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) — given digits `2–9`, return all letter strings the phone keypad could form.

- **Inputs:** `string digits` (empty or digits 2–9).
- **Output:** all combinations of length `|digits|`.
- **Valid answer:** any order; classic mapping (`2→abc`, …, `7→pqrs`, `9→wxyz`).
- **Edges:** empty input → `[]`; single digit; digits with 4 letters (7, 9).

## 2. Intuition
Each digit expands independently into its letter set. DFS builds one character per digit position until the path length equals `|digits|`.

## 3. Brute Force → Optimal
- **Brute:** nested loops only work for fixed length; generalizes poorly.
- **Optimal:** backtracking / BFS product over keypad letters — O(4^N) output-bound.

## 4. Data Structure / Approach Justification
**Chosen:** static keypad table + DFS append/pop per letter choice.

- **vs iterative BFS:** start with `[""]`, expand by digit — same asymptotics, no recursion depth.
- **vs recursion without backtracking buffer:** reallocating strings each step is fine but heavier.

## 5. Logic Walkthrough
Empty → return `{}`. Else at `index`, for each letter of `digits[index]`, push, recurse `index+1`, pop. When `index == n`, record `current`.

## 6. Dry Run
`digits="23"`:
- digit `2` → `a/b/c`, then `3` → `d/e/f`
- results: `ad ae af bd be bf cd ce cf` (**9** strings)

## 7. Time & Space Complexity
Time **O(4^N · N)** to build/output (worst digit has 4 letters). Space **O(N)** recursion (+ output). Why: Cartesian product over N digits (section 4).

## 8. Trade-offs & Alternatives
DFS is interview-clear. Iterative queue expansion avoids stack limits. Preallocated string of length N can reduce push/pop churn.

## 9. Common Mistakes / Edge Cases
Returning `[""]` for empty input; wrong keypad for 7/9; advancing digit index incorrectly; including 0/1 letters.

## 10. Interview Follow-ups / Variations
Word search / dictionary filter on combinations; count only; streaming generation.

## 11. Tags
`backtracking`, `string`, `keypad`, `leetcode-17`, `difficulty:medium`
