# Regular Expression Matching

## Problem Statement
[LeetCode 10](https://leetcode.com/problems/regular-expression-matching/) — full-string match with `.` (any char) and `*` (zero or more of preceding).

- **Inputs:** `s`, pattern `p`.
- **Output:** bool.
- **Valid answer:** entire string must match.
- **Edges:** empty s; `a*`; consecutive stars (valid with letter); `.*`.

## Intuition
DP `dp[i][j]` = s[:i] matches p[:j]. `*` branches: drop `x*` or consume one matching char.

## Brute Force → Optimal
- **Brute:** recursion with backtracking — exponential.
- **Optimal:** 2D DP — O(mn).

## Data Structure / Approach Justification
**Chosen:** boolean DP table.

- **vs memoized recursion:** same complexity, DP is explicit.

## Logic Walkthrough
Init empty matches empty and zero-or-more prefixes. Transition on literal/`.` or `*` zero/more.

## Dry Run
`aab` vs `c*a*b`: `c*` empty, `a*` takes aa, `b` matches.

## Time & Space Complexity
Time **O(mn)**. Space **O(mn)** (can roll to O(n)).

## Trade-offs & Alternatives
NFA simulation; rolling arrays for space.

## Common Mistakes / Edge Cases
Treating `*` as wildcard (that's LC 44); partial matches.

## Interview Follow-ups / Variations
Wildcard Matching (44); regex engines.

## Tags
`dp`, `string`, `regex`, `leetcode-10`, `difficulty:hard`
