# Guess Number Higher or Lower

## Problem Statement
[LeetCode 374](https://leetcode.com/problems/guess-number-higher-or-lower/) — number `pick` in `[1, n]`; `guess(num)` returns -1 (too high), 1 (too low), or 0 (correct).

- **Inputs:** `int n`; hidden pick via API.
- **Output:** `int` the pick.
- **Valid answer:** the unique number with `guess == 0`.
- **Edges:** `n = 1`; pick at bounds.

## Intuition
Classic binary search on a monotone API instead of an array.

## Brute Force → Optimal
- **Brute:** linear guesses — O(N).
- **Optimal:** binary search — O(log N).

## Data Structure / Approach Justification
**Chosen:** standard `lo/hi` with overflow-safe mid.

- **vs ternary search:** more guesses in the worst case
- **vs linear:** too many API calls

## Logic Walkthrough
`mid = lo + (hi-lo)/2`. Shrink by `guess` sign.

## Dry Run
`n=10`, pick=6 → mid path lands on 6.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: halving `[1,n]`.

## Trade-offs & Alternatives
Same skeleton as 704; only the comparison source changes.

## Common Mistakes / Edge Cases
`(lo+hi)/2` overflow; swapping -1/1 meaning.

## Interview Follow-ups / Variations
First bad version (278); guess number II (375, DP).

## Tags
`binary-search`, `interactive`, `leetcode-374`, `difficulty:easy`
