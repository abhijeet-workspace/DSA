# Subarray Sums Divisible by K

## Problem Statement
[LeetCode 974](https://leetcode.com/problems/subarray-sums-divisible-by-k/) — count the number of non-empty subarrays whose sum is divisible by `k`.

- **Input:** `nums`, integer `k`
- **Output:** count of subarrays with `sum % k == 0`
- **Edges:** negatives; zeros; single element divisible / not

## Intuition
`(prefix[j] - prefix[i]) % k == 0` ⇔ `prefix[j] % k == prefix[i] % k`. Count previous prefixes with the same remainder.

## Brute Force → Optimal
- **Brute:** all subarray sums — O(N²).
- **Optimal:** running prefix mod + frequency map — O(N).

## Data Structure / Approach Justification
`unordered_map<int,int>` of remainder → frequency. Seed `freq[0]=1` for subarrays starting at index 0.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested sum loops | Too slow for N≈3·10⁴ |
| Array of size k | Fine when k is moderate — same idea |

## Logic Walkthrough
1. `sum += x`; `rem = ((sum % k) + k) % k`.
2. Add `freq[rem]` to answer (all earlier same rem).
3. `++freq[rem]`.

## Dry Run
`[4,5,0,-2,-3,1]`, `k=5`: remainders evolve; total matching pairs → **7**.

## Time & Space Complexity
- **Time:** O(N)
- **Space:** O(min(N, k)) distinct remainders
- Why: one pass; at most k remainder keys.

## Trade-offs & Alternatives
Use `vector<int>(k)` when k is small. Same pattern as Continuous Subarray Sum but counting instead of existence with distance.

## Common Mistakes / Edge Cases
Negative `%` in C++ (`-2 % 5 == -2`); forgetting `freq[0]=1`; using floor division incorrectly.

## Interview Follow-ups / Variations
Subarray sum equals K (560); continuous subarray sum of length ≥ 2 (523).

## Tags
`prefix-sum`, `hash-map`, `modular-arithmetic`, `leetcode-974`, `medium`
