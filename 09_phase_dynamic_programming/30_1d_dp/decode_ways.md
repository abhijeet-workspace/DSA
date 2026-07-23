# Decode Ways

## Problem Statement
[LeetCode 91](https://leetcode.com/problems/decode-ways/) — digits map `A=1..Z=26`; count ways to decode string `s`.

- **Inputs:** `string s` of digits.
- **Output:** number of valid decodings.
- **Valid answer:** 0 if impossible (e.g. leading zero).
- **Edges:** leading `'0'`; `"10"`, `"27"`; `"06"`.

## Intuition
At index `i`, add ways from single digit (if nonzero) and from two-digit `10..26`.

## Brute Force → Optimal
- **Brute:** recurse all partitions — exponential.
- **Optimal:** rolling DP — O(N)/O(1).

## Data Structure / Approach Justification
**Chosen:** two rolling ints for `dp[i-1]`, `dp[i-2]`.

- **vs `dp[n+1]` array:** clearer transitions.
- **vs memo recursion:** same asymptotics, more stack.

## Logic Walkthrough
Reject empty / leading zero. For each later char: add `prev1` if single valid; add `prev2` if two-digit in `[10,26]`.

## Dry Run
`"226"`:
- `'2'` → 1; `'22'` → 1+1=2; `'226'` → 2 (single 6) + 1 (26) = 3

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: constant work per index (section 4).

## Trade-offs & Alternatives
Full array helps visualize zeros. Careful handling of zeros is the hard part.

## Common Mistakes / Edge Cases
Treating `"06"` as valid; forgetting `'0'` cannot be a single digit; `"10"` / `"20"` edge.

## Interview Follow-ups / Variations
Decode Ways II with `'*'` (639).

## Tags
`1d-dp`, `string`, `leetcode-91`, `difficulty:medium`
