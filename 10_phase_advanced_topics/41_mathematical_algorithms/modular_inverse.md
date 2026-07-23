# Modular Inverse

## Problem Statement
Find `x` such that `(a * x) % p == 1` when `p` is prime; also safe modular add/mul helpers.

- **Inputs:** `a`, prime modulus `p` (for inverse); values for `modAdd` / `modMul`.
- **Output:** modular inverse; modular sum/product.
- **Valid answer:** any `x` in `0..p-1` with `a*x ≡ 1 (mod p)`.
- **Edges:** `a≡0`; `gcd(a,mod)≠1` (no inverse); composite mod (Fermat invalid).

## Intuition
Fermat: `a^(p-1) ≡ 1 (mod p)` ⇒ `a * a^(p-2) ≡ 1`. Compute `a^(p-2)` via binary expo.

## Brute Force → Optimal
- **Brute:** try all `x` in `1..p-1` — O(p).
- **Optimal:** binary expo O(log p); ExtGcd for non-prime moduli.

## Data Structure / Approach Justification
**Chosen:** Fermat + `__int128` mul for wide products.

- **vs ExtGcd:** works for any coprime pair, not only primes.
- **vs precomputed inv[1..n]:** O(n) prep for many inverses.

## Logic Walkthrough
`modInverse(a,p) = fastPow(a, p-2, p)`. `modAdd` wraps once; `modMul` uses wide multiply then `%`.

## Dry Run
`a=3`, `p=7`: `3^5 = 243 ≡ 5 (mod 7)`, and `3*5=15≡1`.

## Time & Space Complexity
Time **O(log p)** inverse. Space **O(1)**. Why: binary expo on exponent `p-2` (section 4).

## Trade-offs & Alternatives
Fermat needs prime modulus. Use ExtGcd when modulus is composite but `gcd(a,m)=1`.

## Common Mistakes / Edge Cases
Applying Fermat with composite mod; omitting wide mul for `a*b`.

## Interview Follow-ups / Variations
Inverse factorial table for nCr; batch inverses; CRT.

## Tags
`math`, `modular-inverse`, `fermat`, `number-theory`, `difficulty:easy`
