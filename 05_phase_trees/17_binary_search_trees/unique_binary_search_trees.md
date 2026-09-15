# Unique Binary Search Trees

## 1. Problem Statement
[LeetCode 96](https://leetcode.com/problems/unique-binary-search-trees/) — count structurally unique BSTs that store values `1..n`.

- **Inputs:** `int n`.
- **Output:** `int` count (Catalan number G_n).
- **Valid answer:** G_n = Σ G_i G_{n-1-i}.
- **Edges:** n=1 → 1; n=3 → 5.

## 2. Intuition
Pick root `i`; left has `i-1` nodes (values smaller), right has `n-i`; multiply ways and sum over roots.

## 3. Brute Force → Optimal
- **Brute:** recurse with memo — OK.
- **Optimal:** DP Catalan — O(N²).

## 4. Data Structure / Approach Justification
**Chosen:** `dp[0]=1`; `dp[k]=Σ dp[i]*dp[k-1-i]`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Generate all trees | Overkill for count |
| Closed Catalan formula | Needs big integers / precision care |

## 5. Logic Walkthrough
Fill `dp` from 1..n using previous lengths.

## 6. Dry Run
n=3: roots 1|2|3 → 1*2 + 1*1 + 2*1 = 5.

## 7. Time & Space Complexity
- **Time:** O(N²)
- **Space:** O(N)
- Why: classic Catalan DP.

## 8. Trade-offs & Alternatives
LC 95 asks to generate trees; here only count.

## 9. Common Mistakes / Edge Cases
`dp[0]` not 1; off-by-one in split; overflow for large n (use long).

## 10. Interview Follow-ups / Variations
Unique BSTs II (95); Catalan applications.

## 11. Tags
`bst`, `dp`, `catalan`, `leetcode-96`, `difficulty:medium`
