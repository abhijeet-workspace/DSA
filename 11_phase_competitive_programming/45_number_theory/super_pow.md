# Super Pow (LC 372)

## 1. Problem Statement
[LeetCode 372 — Super Pow](https://leetcode.com/problems/super-pow/): compute `a^b mod 1337` where `b` is given as a digit array (huge exponent).

- **Inputs:** int `a`, `vector<int> b` digits MSB-first.
- **Output:** `a^b % 1337`.
- **Edges:** a may exceed 1337; b can be long.

## 2. Intuition
1337=7·191. Process exponent digit-by-digit: if current = `a^prefix`, next digit d → `(current^10 * a^d) mod 1337`.

## 3. Brute Force → Optimal
- **Brute:** build full integer b — impossible for large length.
- **Optimal:** digit DP-style powering with modpow — O(|b| log 10).

## 4. Data Structure / Approach Justification
**Chosen:** helper `modPow(x,k)` and fold over digits.

**Pedagogy:** number-theory modular powering with huge exponents (Euler/φ optional). Not the same as LC50 float pow.

## 5. Logic Walkthrough
ans=1; for each digit d: ans = modPow(ans,10) * modPow(a,d) % 1337.

## 6. Dry Run
`a=2, b=[3]` → 8. `a=2, b=[1,0]` → 1024 % 1337 = **1024**.

## 7. Time & Space Complexity
Time **O(|b| log MOD)** roughly, space **O(1)**.

## 8. Trade-offs & Alternatives
Can use Euler φ(1337)=φ(7)φ(191)=6·190=1140 to reduce exponent when gcd(a,1337)=1.

## 9. Common Mistakes / Edge Cases
Forgetting mod on intermediate multiplies; treating b as int.

## 10. Interview Follow-ups / Variations
CRT split mod 7 and 191; general a^b mod m for composite m.

## 11. Tags
`modular-arithmetic`, `binary-exponentiation`, `leetcode-372`, `difficulty:medium`
