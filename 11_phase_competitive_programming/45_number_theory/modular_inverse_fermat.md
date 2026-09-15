# Modular Inverse via Fermat — Teaching Lab

## 1. Problem Statement
**Teaching lab:** compute modular inverse of `a` modulo prime `p` using Fermat: `a^{p-2} ≡ a^{-1} (mod p)` when p∤a.

- **Inputs:** a, prime modulus p.
- **Output:** inverse in `[0,p)` or report non-invertible.
- **Edges:** a≡0; composite mod (Fermat may fail).

## 2. Intuition
By Fermat's little theorem a^{p-1}≡1 ⇒ multiply both sides by a^{-1}.

## 3. Brute Force → Optimal
- **Brute:** try all x with a*x % p == 1.
- **Optimal:** binary exp a^{p-2} — O(log p).

## 4. Data Structure / Approach Justification
**Chosen:** iterative modpow.

**Pedagogy:** focused Fermat-inverse lab. The toolkit file `number_theory` also shows inverse; extGCD inverse (any coprime mod) is the general alternative taught alongside.

## 5. Logic Walkthrough
Reduce a mod p; if 0 fail; else power(a,p-2,p).

## 6. Dry Run
`a=3,p=11` → 4 because 3·4=12≡1.

## 7. Time & Space Complexity
Time **O(log p)**, space **O(1)**.

## 8. Trade-offs & Alternatives
Use extGCD when mod is composite but gcd(a,mod)=1.

## 9. Common Mistakes / Edge Cases
Using Fermat on composite moduli; negative a without normalize.

## 10. Interview Follow-ups / Variations
Batch inverses 1..n; inv of factorial for nCr.

## 11. Tags
`modular-inverse`, `fermat`, `teaching-lab`, `difficulty:easy`
