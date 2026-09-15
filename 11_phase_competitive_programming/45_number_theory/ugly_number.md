# Ugly Number (LC 263)

## 1. Problem Statement
[LeetCode 263 — Ugly Number](https://leetcode.com/problems/ugly-number/): an ugly number's prime factors are only 2, 3, and/or 5. Decide if `n` is ugly.

- **Inputs:** int `n`.
- **Output:** bool.
- **Edges:** n≤0 → false; n=1 → true (empty product).

## 2. Intuition
Divide out all factors 2,3,5; leftover must be 1.

## 3. Brute Force → Optimal
- **Brute:** full factorization.
- **Optimal:** while-divisible by {2,3,5} — O(log n).

## 4. Data Structure / Approach Justification
**Chosen:** sequential divide loops.

**Pedagogy:** prime-factor restriction drill. `ugly_number_ii` (generation) may appear under heaps elsewhere; here LC263 is the recognition form.

## 5. Logic Walkthrough
If n≤0 false. While n%p==0 for p in {2,3,5}: n/=p. Return n==1.

## 6. Dry Run
`6=2·3` → true. `14=2·7` → false.

## 7. Time & Space Complexity
Time **O(log n)**, space **O(1)**.

## 8. Trade-offs & Alternatives
Same pattern for Hamming numbers / 7-smooth checks.

## 9. Common Mistakes / Edge Cases
Accepting n=0; forgetting n=1 is ugly.

## 10. Interview Follow-ups / Variations
Nth ugly number; super ugly with custom primes.

## 11. Tags
`number-theory`, `math`, `leetcode-263`, `difficulty:easy`
