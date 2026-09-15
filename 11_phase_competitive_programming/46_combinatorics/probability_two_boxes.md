# Probability of Two Boxes Having Same Number of Distinct Balls

## 1. Problem Statement
[LeetCode 1467](https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/) — simplified teaching: for small balls arrays compute probability via multinomial enumeration.

## 2. Intuition
Total ways = multinomial; favorable when distinct counts equal.

## 3. Brute Force → Optimal
- **Brute:** all distributions.
- **Optimal:** DFS over color splits with combinatorics weights.

## 4. Data Structure / Approach Justification
**Chosen:** DFS + binomial coefficients for each color split.

- **Pedagogy:** multinomial probabilities; heavy combinatorics interview rare but good CP counting.

## 5. Logic Walkthrough
DFS colors; for taking k of color in box1, weight C(cnt,k); track distinct deltas.

## 6. Dry Run
balls=[1,1] → probability 1.0.

## 7. Time & Space Complexity
Exponential in colors; OK for tiny LC constraints.

## 8. Trade-offs & Alternatives
Monte Carlo estimate.

## 9. Common Mistakes / Edge Cases
Precision; not using double carefully.

## 10. Interview Follow-ups / Variations
Expected distinct counts.

## 11. Tags
`combinatorics`, `probability`, `leetcode-1467`, `difficulty:hard`
