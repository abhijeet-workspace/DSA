# Modint Template

## 1. Problem Statement
Teaching-lab — lightweight `Mint` with +,-,* under `10^9+7`.

## 2. Intuition
Normalize into `[0,MOD)` and keep every op closed.

## 3. Brute Force → Optimal
- **Brute:** raw `ll` with ad-hoc `%`. **Optimal:** typed mint avoids missed mods.

## 4. Data Structure / Approach Justification
**Chosen:** small struct mint.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

## 5. Logic Walkthrough
Ctor mods; operators update `v` carefully for subtract.

## 6. Dry Run
`(MOD-1)+3 → 2`; `(MOD-1)*3 → MOD-3`.

## 7. Time & Space Complexity
**O(1)** per arithmetic op.

## 8. Trade-offs & Alternatives
Add `pow`/`inv` via binary exponent; Barrett reduction rarely needed.

## 9. Common Mistakes / Edge Cases
Negative ctor without `+MOD`; overflow before `%`.

## 10. Interview Follow-ups / Variations
NTTs need mint with primitive root MOD.

## 11. Tags
`modint`, `modular`, `template`, `difficulty:easy`
