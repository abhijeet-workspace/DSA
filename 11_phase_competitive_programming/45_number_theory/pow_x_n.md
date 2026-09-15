# Pow(x, n) (LC 50)

## 1. Problem Statement
[LeetCode 50 — Pow(x, n)](https://leetcode.com/problems/powx-n/): compute `x` raised to integer power `n` (may be negative).

- **Inputs:** double `x`, long-range `n`.
- **Output:** `x^n` as double.
- **Edges:** n=0 → 1; negative n → reciprocal; INT_MIN exponent.

## 2. Intuition
Binary exponentiation: square the base and multiply when the current bit is set. For negative n, compute positive then invert.

## 3. Brute Force → Optimal
- **Brute:** multiply n times — O(|n|).
- **Optimal:** binary exp — O(log |n|).

## 4. Data Structure / Approach Justification
**Chosen:** iterative binary exponentiation with `long long` exponent.

**Pedagogy:** framed here for modular/number-theory powering habits (same skeleton as modpow). Also appears under arrays/strings fundamentals elsewhere as floating pow API practice — here the emphasis is binary-exp structure shared with CP modpow.

## 5. Logic Walkthrough
Take abs(n) as long long. While exp: if odd multiply ans*=x; x*=x; exp>>=1. If original n<0 return 1/ans.

## 6. Dry Run
`2^10` → **1024**. `2^-2` → **0.25**.

## 7. Time & Space Complexity
Time **O(log |n|)**, space **O(1)**.

## 8. Trade-offs & Alternatives
Recursive half-pow is fine; watch stack on huge |n| in theory only.

## 9. Common Mistakes / Edge Cases
Negating INT_MIN without long long; multiplying after shift incorrectly.

## 10. Interview Follow-ups / Variations
Modular pow; matrix pow; pow with large integer base.

## 11. Tags
`binary-exponentiation`, `math`, `leetcode-50`, `difficulty:medium`
