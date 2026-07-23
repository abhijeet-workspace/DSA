# Interleaving String

## Problem Statement
[LeetCode 97](https://leetcode.com/problems/interleaving-string/) — return whether `s3` is an interleaving of `s1` and `s2` (relative order of each preserved).

- **Inputs:** strings `s1`, `s2`, `s3`.
- **Output:** boolean.
- **Valid answer:** every char of `s3` comes from `s1` or `s2` in order; lengths add up.
- **Edges:** empty `s1` or `s2`; length mismatch; shared prefixes forcing branches.

## Intuition
Boolean DP on how many chars taken from each string: take next from `s1` or `s2` if it matches `s3[i+j-1]`.

## Brute Force → Optimal
- **Brute:** DFS take-from-s1 / take-from-s2 — exponential without memo.
- **Optimal:** 1D rolling boolean DP — O(MN) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** `dp[j]` for fixed `i` = whether `s1[:i]` and `s2[:j]` form `s3[:i+j]`.

- **vs 2D bool grid:** same transitions, more memory.
- **vs two-pointer greedy:** fails when both strings offer the same next char.

## Logic Walkthrough
Reject if lengths differ. Init row with `s2` vs `s3`. For each `i`, update `dp[0]` from `s1`, then `dp[j] = (dp[j]∧s1 match) ∨ (dp[j-1]∧s2 match)`.

## Dry Run
`s1=aab`, `s2=axy`, `s3=aaxaby`: consume `aa` from `s1`/`s2` mix then finish → **true**.

## Time & Space Complexity
Time **O(MN)**. Space **O(N)**. Why: each `(i,j)` state once; compress rows (section 4).

## Trade-offs & Alternatives
Full 2D easier to explain. Memoized DFS same asymptotics.

## Common Mistakes / Edge Cases
Skipping length check; overwriting `dp[j]` before reading for `from_s1`; treating as concatenation only.

## Interview Follow-ups / Variations
Count number of interleavings; 3-string interleave; reconstruct one split.

## Tags
`string-dp`, `2d-dp`, `interleaving`, `leetcode-97`, `difficulty:medium`
