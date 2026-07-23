# Regular Expression Matching

## Problem Statement
[LeetCode 10](https://leetcode.com/problems/regular-expression-matching/) — match entire string `s` against pattern `p` supporting `.` (any char) and `*` (zero or more of preceding element).

- **Inputs:** strings `s`, `p`.
- **Output:** boolean (full match, not partial).
- **Valid answer:** classic regex semantics for `.` and `*` only.
- **Edges:** empty `s` with `a*`; consecutive `*`; leading `*`; `.` alone.

## Intuition
DP on prefixes: `*` branches into “use zero of prev token” vs “consume one more matching char and stay on `*`”.

## Brute Force → Optimal
- **Brute:** backtracking on each `*` expansion — exponential worst case.
- **Optimal:** 2D boolean DP — O(MN) time and space.

## Data Structure / Approach Justification
**Chosen:** `dp[i][j]` = whether `s[:i]` matches `p[:j]`.

- **vs recursive with memo:** same asymptotics; table makes `*` zero/more cases explicit.
- **vs NFA simulation:** correct but heavier for interview coding.

## Logic Walkthrough
`dp[0][0]=true`; empty `s` with `x*` patterns via `dp[0][j]=dp[0][j-2]`. Char/`.` → diagonal. `*` → `dp[i][j-2]` or (if prev token matches) `dp[i-1][j]`.

## Dry Run
`s=aa`, `p=a*`: `*` consumes both `a`s via repeated `dp[i-1][j]` → **true**.

## Time & Space Complexity
Time **O(MN)**. Space **O(MN)**. Why: every prefix pair of `s` and `p` (section 4).

## Trade-offs & Alternatives
1D rolling possible with care for `j-2`. Wildcard Matching (44) uses `?`/`*` differently — don’t mix transitions.

## Common Mistakes / Edge Cases
Treating `*` as “any sequence” without preceding atom; forgetting zero-occurrence; partial match instead of full; `p` starting with `*`.

## Interview Follow-ups / Variations
Wildcard Matching (44); implement `+` / `?`; compile pattern to NFA.

## Tags
`string-dp`, `2d-dp`, `regex`, `leetcode-10`, `difficulty:hard`
