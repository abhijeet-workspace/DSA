# Perfect Number (LC 507)

## 1. Problem Statement
[LeetCode 507 — Perfect Number](https://leetcode.com/problems/perfect-number/): a perfect number equals the sum of its proper divisors (exclude itself).

- **Inputs:** int `num`.
- **Output:** bool.
- **Edges:** num≤1 → false.

## 2. Intuition
Sum divisors in O(√n) by pairing factors i and num/i; subtract num at the end.

## 3. Brute Force → Optimal
- **Brute:** check all i < num.
- **Optimal:** loop to √num — O(√n).

## 4. Data Structure / Approach Justification
**Chosen:** factor-pair accumulation.

**Pedagogy:** divisor-sum / σ(n) number-theory drill.

## 5. Logic Walkthrough
sum=1 for num>1; for i=2..√num if divides add i and num/i (avoid double √).

## 6. Dry Run
`28` → 1+2+4+7+14=28 → **true**.

## 7. Time & Space Complexity
Time **O(√n)**, space **O(1)**.

## 8. Trade-offs & Alternatives
Euclid–Euler even perfect form 2^{p-1}(2^p−1) for Mersenne prime.

## 9. Common Mistakes / Edge Cases
Including num itself; double-counting sqrt for squares.

## 10. Interview Follow-ups / Variations
Abundant/deficient classification; sum of divisors sieve.

## 11. Tags
`number-theory`, `divisors`, `leetcode-507`, `difficulty:easy`
