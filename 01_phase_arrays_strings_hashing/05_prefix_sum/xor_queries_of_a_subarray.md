# XOR Queries of a Subarray

## Problem Statement
[LeetCode 1310](https://leetcode.com/problems/xor-queries-of-a-subarray/) — for each query `[left, right]`, return XOR of `arr[left…right]`.

- **Input:** `arr`, `queries` of inclusive index pairs
- **Output:** vector of XOR answers in query order
- **Edges:** single-element range; full array; many queries

## Intuition
XOR is associative and its own inverse: `xor(L..R) = pref[R+1] ^ pref[L]` where `pref[i] = arr[0]^…^arr[i-1]`.

## Brute Force → Optimal
- **Brute:** XOR each query range from scratch — O(N·Q).
- **Optimal:** build prefix XOR once — O(N + Q).

## Data Structure / Approach Justification
1D prefix XOR array of size `n+1` with `pref[0]=0`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Per-query scan | Too slow when Q and N are both large |
| Sparse table | Overkill; XOR is invertible so prefix suffices |

## Logic Walkthrough
1. `pref[i+1] = pref[i] ^ arr[i]`.
2. For query `[L,R]`, answer `pref[R+1] ^ pref[L]`.

## Dry Run
`arr=[1,3,4,8]`, pref=`[0,1,2,6,14]`. Query `[0,1]` → `2^0=2`; `[1,2]` → `6^1=7`; `[0,3]` → `14`; `[3,3]` → `8`.

## Time & Space Complexity
- **Time:** O(N + Q)
- **Space:** O(N) for prefix (+ O(Q) for answers)
- Why: one build pass; O(1) per query.

## Trade-offs & Alternatives
Same pattern as range sum with prefix sums. For updates online, use a Fenwick/segment tree with XOR.

## Common Mistakes / Edge Cases
Off-by-one on inclusive `R` (`pref[R]` vs `pref[R+1]`); using `+` instead of `^`; mutating `arr` in place without a separate pref.

## Interview Follow-ups / Variations
Range sum queries; XOR of subarrays count; updates with Fenwick.

## Tags
`prefix-xor`, `bit-manipulation`, `range-query`, `leetcode-1310`, `medium`
