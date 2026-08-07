# Modular Arithmetic

## 1. Problem Statement
Foundations of modular arithmetic for DSA / CP:

1. Normalize negative residues into `[0, m)`
2. Modular add / sub / mul (overflow-safe mul for 64-bit demo via `__int128` when available, else careful)
3. Modular binary exponentiation
4. Modular inverse via Extended Euclid (when `gcd(a,m)=1`)

- **Input:** demo `a,b,m`
- **Output:** residues and inverse
- **Edges:** `m=1`; negative `a`; non-coprime inverse failure

## 2. Intuition
Congruences wrap every `m`. Powers reduce with binary exp under mod. Inverse `a⁻¹` satisfies `a·a⁻¹ ≡ 1 (mod m)` iff gcd=1.

## 3. Brute Force → Optimal
- Naive pow then mod: huge intermediates.
- Modpow: O(log exp).
- Inverse: trial O(m) vs ExtGcd O(log m) / Fermat when `m` prime.

## 4. Data Structure / Approach Justification
Iterative modpow + ExtGcd. Use `long long`; mul via `__int128` on platforms that support it (guarded).

| Alternative | When |
|-------------|------|
| Fermat `a^(m-2)` | Prime modulus only |
| CRT | Systems of congruences — CP phase |

## 5. Logic Walkthrough
1. `mod(a,m) = ((a%m)+m)%m`.
2. Modpow: same as binary exp with `% m` after ops.
3. ExtGcd → if `g==1`, inverse is `x mod m`.

## 6. Dry Run
`(7+8)%5=0`. `3^5 % 7 = 5`. Inverse of 3 mod 11 is 4 because `3*4=12≡1`.

## 7. Time & Space Complexity
Mod add/mul O(1); modpow O(log exp); inverse O(log m).

## 8. Trade-offs & Alternatives
Prefer Fermat for prime mods in contests; ExtGcd for general coprime mods.

## 9. Common Mistakes / Edge Cases
Negative mods in C++; multiplying before reducing; assuming inverse always exists.

## 10. Interview Follow-ups / Variations
`(a/b)%m` with inverse; Wilson’s theorem; CRT.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `modular-arithmetic`, `modpow`, `intermediate`

## 12. Next Steps
`07_series_and_sequences`. Deep dive: `modular_inverse`, `euler_totient`, `45_number_theory`.
