# Beautiful Arrangement

## 1. Problem Statement
[LeetCode 526](https://leetcode.com/problems/beautiful-arrangement/) — count permutations `P` of `1..n` such that for every position `i` (1-indexed), `P[i] % i == 0` or `i % P[i] == 0`.

- **Inputs:** `int n` (≤15).
- **Output:** count of beautiful arrangements.
- **Valid answer:** integer count.
- **Edges:** `n=1`; larger n exponential.

## 2. Intuition
Place numbers position-by-position; only try unused `x` that satisfy the divisibility check with current `pos`.

## 3. Brute Force → Optimal
- **Brute:** all n! perms then filter.
- **Optimal:** backtracking with constraint prune + optional bit DP.

## 4. Data Structure / Approach Justification
**Chosen:** DFS over positions with `used[]`.

- **vs swap-based permute:** similar; used-array is clear.
- **vs DP on bitmasks:** faster for n=15.

## 5. Logic Walkthrough
At `pos`, for each unused `x` valid for `pos`, mark used, recurse `pos+1`, unmark. `pos>n` → count++.

## 6. Dry Run
`n=2`: `[1,2]` and `[2,1]` both valid → **2**.

## 7. Time & Space Complexity
Time **O(n!)** pruned. Space **O(n)**. Why: permutation search (section 4).

## 8. Trade-offs & Alternatives
Bitmask DP `dp[mask]` counting ways to fill next position.

## 9. Common Mistakes / Edge Cases
0-index vs 1-index positions; forgetting to unmark; checking wrong modulo direction.

## 10. Interview Follow-ups / Variations
Construct one arrangement; beautiful subsets; matching with gcd constraints.

## 11. Tags
`backtracking`, `permutations`, `leetcode-526`, `difficulty:medium`
