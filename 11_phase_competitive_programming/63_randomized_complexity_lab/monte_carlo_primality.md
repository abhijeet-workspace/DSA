# Monte Carlo Primality (Fermat)

## 1. Problem Statement
Probabilistic primality test via random Fermat bases.

- **Inputs:** odd integer `n`, round count `K`.
- **Output:** “probably prime” or definite composite.
- **Valid answer:** primes always pass; most composites fail some base.
- **Edges:** `n<2`; evens; Carmichael numbers (Fermat liars).

## 2. Intuition
If `n` is prime, `a^(n-1) ≡ 1 (mod n)` for `a` not divisible by `n` (Fermat). Random bases catch many composites quickly.

## 3. Brute Force → Optimal
- **Brute:** trial division to √n.
- **Here:** K random Fermat tests — fast Monte Carlo (error on composites).

## 4. Data Structure / Approach Justification
**Chosen:** modular exponentiation + Fermat witnesses (teaching). Production prefers Miller–Rabin.

## 5. Logic Walkthrough
1. Handle tiny / even cases.
2. Pick random `a ∈ [2, n-2]`.
3. If `a^(n-1) ≢ 1 (mod n)` → composite; else after K rounds → probably prime.

## 6. Dry Run
`n=97`, `a=2` → `2^96 ≡ 1 (mod 97)` suggests prime. `n=91=7·13` usually fails some base.

## 7. Time & Space Complexity
About **O(K log³ n)** bit ops with naive mul (demo uses `__int128`). Space **O(1)**.

## 8. Trade-offs & Alternatives
Fast with small error probability. Miller–Rabin is stronger; AKS is deterministic poly but impractical.

## 9. Common Mistakes / Edge Cases
Treating Fermat-only as definitive; overflowing mul without wide product; Carmichael numbers.

## 10. Interview Follow-ups / Variations
Why Miller–Rabin beats plain Fermat? Deterministic MR bases for 64-bit.

## 11. Tags
`monte-carlo`, `primality`, `fermat`, `randomized`, `difficulty:medium`
