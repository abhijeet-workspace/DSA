# Stars and Bars Demo

## 1. Problem Statement
**Teaching lab** — number of positive/non-negative integer solutions to x1+...+xk=n.

## 2. Intuition
Non-neg: C(n+k-1,k-1); positive: C(n-1,k-1).

## 3. Brute Force → Optimal
- **Brute:** nested loops.
- **Optimal:** binomial.

## 4. Data Structure / Approach Justification
**Chosen:** stars-and-bars closed form.

- **Pedagogy:** classic counting; appears inside DP knapsack counting with different framing.

## 5. Logic Walkthrough
Implement both formulas with safe binomial.

## 6. Dry Run
x1+x2+x3=5 non-neg → C(7,2)=21.

## 7. Time & Space Complexity
Time **O(k)** for binomial. Space **O(1)**.

## 8. Trade-offs & Alternatives
Upper bounds per variable → inclusion-exclusion.

## 9. Common Mistakes / Edge Cases
Mixing positive vs non-negative formulas.

## 10. Interview Follow-ups / Variations
Bounded variables IE.

## 11. Tags
`combinatorics`, `stars-and-bars`, `teaching-lab`, `difficulty:medium`
