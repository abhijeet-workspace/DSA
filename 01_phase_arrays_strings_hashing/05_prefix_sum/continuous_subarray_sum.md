# Continuous Subarray Sum

## Problem Statement
[LeetCode 523](https://leetcode.com/problems/continuous-subarray-sum/) — return true if there exists a contiguous subarray of length **at least 2** whose sum is a multiple of `k`.

- **Input:** `nums`, `k` (k ≥ 1 on LC)
- **Output:** boolean
- **Edges:** zeros (0 is multiple of k); length-1 only; large nums with modular wrap

## Intuition
Same remainder of prefix sums mod k means the between-sum is divisible by k. Require the earlier index to be at least 2 positions before the current index.

## Brute Force → Optimal
- **Brute:** check all subarrays of length ≥ 2 — O(N²).
- **Optimal:** prefix mod + first-index map — O(N).

## Data Structure / Approach Justification
Map remainder → earliest index; seed `0 → -1`. Only store the first occurrence so longer spans remain possible.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested sums | TLE on large N |
| Store last index only | May miss a valid earlier span (usually still OK if you check distance carefully; first is safer) |

## Logic Walkthrough
1. Accumulate `sum`; `rem = sum % k` (normalize if needed).
2. If `rem` seen and `i - first[rem] >= 2` → true.
3. Else if unseen, record `first[rem] = i`.

## Dry Run
`[23,2,4,6,7]`, `k=6`: after `23,2,4` sum=29, rem=5; earlier rem 5 at after 23 alone? Actually after 23 rem=5 (index 0); after 23+2+4=29 rem=5 (index 2) → distance 2 → **true** (`[2,4]` sum 6).

## Time & Space Complexity
- **Time:** O(N)
- **Space:** O(min(N, k))
- Why: one pass over prefixes.

## Trade-offs & Alternatives
Special-case `k==1` (any length ≥ 2 works). Counting zeros: two consecutive zeros form a valid multiple.

## Common Mistakes / Edge Cases
Accepting length-1 multiples; overwriting first index; `sum % k` with negatives; treating single `0` as valid when length must be ≥ 2.

## Interview Follow-ups / Variations
Subarray sums divisible by K (974); check product multiple; length exactly L.

## Tags
`prefix-sum`, `hash-map`, `modular-arithmetic`, `leetcode-523`, `medium`
