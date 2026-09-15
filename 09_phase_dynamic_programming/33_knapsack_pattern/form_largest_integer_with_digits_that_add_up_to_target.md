# Form Largest Integer With Digits That Add up to Target

## Problem Statement
[LeetCode 1449](https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/) — cost[i] = cost of digit i+1; form largest number whose digit costs sum to exactly `target` (unlimited digits). Return "0" if impossible.

- **Inputs:** `cost[9]`, `target`.
- **Output:** lexicographically largest number string.
- **Valid answer:** unbounded knapsack on cost with lex-max string.
- **Edges:** impossible; single digit.

## Intuition
DP best string for each cost; prefer longer then lex-greater.

## Brute Force → Optimal
- **Brute:** all compositions — exponential.
- **Optimal:** unbounded DP O(9·target·L).

## Data Structure / Approach Justification
**Chosen:** `dp[t]` best string paying exactly t.

- **vs digit greedy only:** need exact cost feasibility.

## Logic Walkthrough
For t, try append digit d if dp[t-cost[d]] valid; compare candidates.

## Dry Run
cost=[4,3,2,5,6,7,2,5,5], target=9 → 7772.

## Time & Space Complexity
Time **O(target·9·L)**. Space **O(target·L)**. Why: unbounded knapsack (section 4).

## Trade-offs & Alternatives
Store length + parents to rebuild and save memory.

## Common Mistakes / Edge Cases
Lex compare without length-first; using 0/1 once.

## Interview Follow-ups / Variations
Unbounded knapsack; Coin Change construction.

## Tags
`knapsack`, `unbounded`, `leetcode-1449`, `difficulty:hard`
