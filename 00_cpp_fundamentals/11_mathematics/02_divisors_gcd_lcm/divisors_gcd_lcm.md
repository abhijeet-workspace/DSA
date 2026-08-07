# Divisors, GCD & LCM

## 1. Problem Statement
Solve classic divisibility problems:

1. Count and list all divisors of `n` in O(√n)
2. Euclidean GCD
3. LCM via `a / gcd * b` (divide first)

- **Input:** demo integers in `main`
- **Output:** divisor list / count, gcd, lcm
- **Edges:** `n=1`; `gcd(a,0)=|a|`; LCM overflow

## 2. Intuition
Divisors come in pairs `(d, n/d)`. Euclid: `gcd(a,b)=gcd(b,a%b)`. LCM is the smallest common multiple — use gcd to avoid scanning.

## 3. Brute Force → Optimal
- Divisors: trial to `n` → O(n); pair walk to √n → O(√n).
- GCD: trial divisors → O(min(a,b)); Euclid → O(log min).
- LCM: check multiples → slow; formula with gcd → O(log).

## 4. Data Structure / Approach Justification
Recursive Euclid + vector for divisors (sorted optionally).

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `std::gcd` (C++17) | Prefer in production; reimplement to learn |
| Binary GCD (Stein) | Avoids `%`; same class of complexity |

## 5. Logic Walkthrough
1. For `i=1..√n`, if `n%i==0` record `i` and `n/i` (if distinct).
2. Recurse Euclid until remainder 0.
3. `lcm = a / gcd(a,b) * b`.

## 6. Dry Run
`n=12` divisors: 1,2,3,4,6,12. `gcd(48,18)=6`. `lcm(4,6)=12`.

## 7. Time & Space Complexity
- Divisors: O(√n) time, O(d(n)) space
- GCD / LCM: O(log min(a,b)) time, O(log) recursion (or O(1) iterative)

## 8. Trade-offs & Alternatives
Sort divisors if order matters. For many queries on same `n`, precompute SPF (later sections / advanced phase).

## 9. Common Mistakes / Edge Cases
- Forgetting to add `n/i` when listing divisors
- `lcm = a*b/gcd` overflowing before divide
- Negative inputs without absolute values

## 10. Interview Follow-ups / Variations
Count divisors from prime factorization; GCD of an array; Extended Euclid → modular inverse.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `gcd`, `lcm`, `divisors`, `beginner`

## 12. Next Steps
`03_prime_checking_factors`. Extended Euclid / CRT: `41_mathematical_algorithms`, `45_number_theory`.
