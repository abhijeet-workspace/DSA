# Counting Bits

## Problem Statement
[LeetCode 338](https://leetcode.com/problems/counting-bits/) — for each `i` in `[0,n]`, return the number of `1` bits in `i`.

- **Inputs:** non-negative `n`.
- **Output:** `vector` of size `n+1`.
- **Valid answer:** Hamming weights for each index.
- **Edges:** `n=0`; powers of two.

## Intuition
`dp[i] = dp[i>>1] + (i&1)` — right shift drops the LSB; LSB contributes 0 or 1 ones.

## Brute Force → Optimal
- **Brute:** popcount each `i` — O(N log N).
- **Optimal:** linear DP recurrence — O(N).

## Data Structure / Approach Justification
**Chosen:** `vector<int> dp(n+1)`.

- **vs `dp[i]=dp[i&(i-1)]+1`:** also O(N); Kernighan-style.
- **vs builtin per i:** fine but hides the recurrence interview point.

## Logic Walkthrough
`dp[0]=0`. For `i=1..n`, set from half plus LSB.

## Dry Run
`n=5` → `[0,1,1,2,1,2]`.

## Time & Space Complexity
Time **O(N)**. Space **O(N)** for the answer. Why: each value from a smaller index (section 4).

## Trade-offs & Alternatives
Both O(N) DP forms are interview-acceptable. Streaming without O(N) memory needs online popcount.

## Common Mistakes / Edge Cases
Sizing array `n` instead of `n+1`; off-by-one in the loop.

## Interview Follow-ups / Variations
Streaming version; count bits in a range `[L,R]`.

## Tags
`bit-manipulation`, `dp`, `difficulty:easy`
