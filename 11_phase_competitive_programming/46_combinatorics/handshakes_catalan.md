# Handshakes That Don't Cross

## 1. Problem Statement
[LeetCode 1259](https://leetcode.com/problems/handshakes-that-dont-cross/) — 2n people on a circle; count non-crossing perfect handshake pairings mod 10^9+7 (Catalan).

## 2. Intuition
Classic Catalan: fix person 0 pairing with even-gap partners; product of sides.

## 3. Brute Force → Optimal
- **Brute:** all perfect matchings.
- **Optimal:** Catalan DP mod prime.

## 4. Data Structure / Approach Justification
**Chosen:** Catalan DP with mod.

- **Pedagogy:** Catalan in geometry/combinatorics clothing; same numbers as unique BSTs.

## 5. Logic Walkthrough
dp[0]=1; dp[n]=sum dp[i]*dp[n-1-i].

## 6. Dry Run
n=2 people pairs? numPeople=2 → 1; numPeople=4 → 2.

## 7. Time & Space Complexity
Time **O(n^2)**. Space **O(n)**.

## 8. Trade-offs & Alternatives
Formula with mod inverse for C(2n,n)/(n+1).

## 9. Common Mistakes / Edge Cases
Using n people not 2n.

## 10. Interview Follow-ups / Variations
Crossing allowed count.

## 11. Tags
`combinatorics`, `catalan`, `leetcode-1259`, `difficulty:hard`
