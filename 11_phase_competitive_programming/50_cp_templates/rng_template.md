# RNG Template

## 1. Problem Statement
Teaching-lab — splitmix64-style generator for stress tests / custom hash salts.

## 2. Intuition
Fast, high-quality 64-bit mixing; seed from clock or fixed for repro.

## 3. Brute Force → Optimal
- **Brute:** `rand()`. **Optimal:** 64-bit mix RNG.

## 4. Data Structure / Approach Justification
**Chosen:** splitmix64 increment + mix.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

## 5. Logic Walkthrough
`next` advances state; `uniform` maps to `[l,r]`.

## 6. Dry Run
Seeded uniforms on singleton ranges; two next() differ.

## 7. Time & Space Complexity
**O(1)** per random.

## 8. Trade-offs & Alternatives
`mt19937_64` also fine; avoid `rand()%n` bias for contests needing fairness.

## 9. Common Mistakes / Edge Cases
Using RNG for crypto; modulo bias on large ranges (OK for stress).

## 10. Interview Follow-ups / Variations
Shuffle helper; random graphs.

## 11. Tags
`rng`, `splitmix64`, `template`, `difficulty:easy`
