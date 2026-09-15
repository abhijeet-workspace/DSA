# Integer Break

## 1. Problem Statement
[LeetCode 343](https://leetcode.com/problems/integer-break/) — break integer `n` into the sum of `k ≥ 2` positive integers; maximize the product of those integers.

- **Inputs:** integer `n` (2 ≤ n ≤ 58 typically).
- **Output:** maximum product.
- **Edges:** `n=2` → 1; `n=3` → 2; prefer parts near 3.

## 2. Intuition
Optimal parts are mostly 3s (math: e is ideal; integers → 2 or 3, avoid 1 and prefer not many 4s as 2+2). DP: try every first cut.

## 3. Brute Force → Optimal
- **Brute:** all compositions — exponential.
- **Optimal:** O(n²) DP, or O(n) greedy by threes.

## 4. Data Structure / Approach Justification
**Chosen:** `dp[i]` = best product for breaking `i` (must break at least once for the original `n`).

| Alternative | Why skip |
|-------------|---------|
| Pure math / greedy 3s | Faster; less “1D DP chapter” |
| Recursion+memo | Same recurrence |

## 5. Logic Walkthrough
1. `dp[1]=1`.
2. For `i=2..n`, for `j=1..i-1`: `dp[i] = max(j*(i-j), j*dp[i-j])`.
3. Return `dp[n]` (forcing ≥1 cut via the `j*(i-j)` term).

## 6. Dry Run
`n=10`: 3+3+4 → 3·3·4=36 (or 3+3+2+2).

## 7. Time & Space Complexity
- **Time:** O(n²)
- **Space:** O(n)

## 8. Trade-offs & Alternatives
Greedy: use as many 3s as possible; if remainder 1, replace 3+1 by 2+2. Better for contests; DP teaches recurrence.

## 9. Common Mistakes / Edge Cases
Allowing unbroken `n` as answer; using leftover 1; `n=2,3` specials.

## 10. Interview Follow-ups / Variations
Integer break with exactly k parts; maximize sum under product constraint.

## 11. Tags
`1d-dp`, `math`, `leetcode-343`, `difficulty:medium`
