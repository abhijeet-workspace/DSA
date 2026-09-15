# Mo Range Product Mod

## 1. Problem Statement
Teaching-lab — range **product mod prime** via Mo. Remove multiplies modular inverse.

**Skip note:** range GCD is *not* Mo-friendly (no O(1) remove); product-mod is the careful substitute for the suggested gcd/product idea.

## 2. Intuition
Under prime MOD, multiply is invertible so remove works.

## 3. Brute Force → Optimal
- Prefer prefix products `pref[r]/pref[l-1]`. Mo here is pedagogy only.

## 4. Data Structure / Approach Justification
**Chosen:** Mo product with inv remove — shows removable aggregator discipline.

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows). Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

## 5. Logic Walkthrough
add: prod*=a[i]; remove: prod*=inv(a[i]).

## 6. Dry Run
Matches brute products.

## 7. Time & Space Complexity
**O((N+Q)√N log MOD)** with inv, or O(1) if inv precomputed.

## 8. Trade-offs & Alternatives
**Pedagogy flag:** contest code should use prefix products, not Mo.

## 9. Common Mistakes / Edge Cases
Zero elements break inverse; must special-case zeros.

## 10. Interview Follow-ups / Variations
Range GCD with sparse table instead.

## 11. Tags
`mo-algorithm`, `modular`, `teaching-lab`, `difficulty:medium`
