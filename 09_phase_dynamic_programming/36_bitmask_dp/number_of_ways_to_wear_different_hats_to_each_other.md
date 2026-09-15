# Number of Ways to Wear Different Hats to Each Other

## Problem Statement
[LeetCode 1434](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/) — n people each like some hats (1..40); assign distinct hats; count ways mod 1e9+7.

- **Inputs:** `hats` list per person.
- **Output:** ways mod 10^9+7.
- **Valid answer:** injections from people to hats.
- **Edges:** n=1; impossible.

## Intuition
DP over hats: for each hat, assign to one unused person or skip; mask = people assigned.

## Brute Force → Optimal
- **Brute:** assign per person.
- **Optimal:** O(40*n*2^n) hat-centric DP.

## Data Structure / Approach Justification
**Chosen:** dp[mask] ways; iterate hats.

## Logic Walkthrough
People as bits (n<=10); hats up to 40.

## Dry Run
Sample -> **1**.

## Time & Space Complexity
Time **O(H*n*2^n)**. Space **O(2^n)**. Why: people mask (section 4).

## Trade-offs & Alternatives
Hat-centric beats person-centric when H>n.

## Common Mistakes / Edge Cases
Reusing hats.

## Interview Follow-ups / Variations
Assignment bitmask DP.

## Tags
`bitmask-dp`, `leetcode-1434`, `difficulty:hard`
