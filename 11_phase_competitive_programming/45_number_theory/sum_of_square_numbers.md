# Sum of Square Numbers (LC 633)

## 1. Problem Statement
[LeetCode 633 — Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/): true iff `c = a² + b²` for nonnegative integers a,b.

- **Inputs:** nonnegative `c`.
- **Output:** bool.
- **Edges:** c=0 → true (0+0); primes 4k+3 to odd power cannot.

## 2. Intuition
Two-pointer on a=0..√c and b=√(c-a²), or Fermat theorem on prime factors of form 4k+3.

## 3. Brute Force → Optimal
- **Brute:** try all a,b ≤ √c — O(c).
- **Optimal:** two pointers O(√c) or factorization O(√c).

## 4. Data Structure / Approach Justification
**Chosen:** two-pointer left/right on squares.

**Pedagogy:** number-theory / sums of squares. Two-pointer appears elsewhere; here the math target is recognizing square pairs.

## 5. Logic Walkthrough
lo=0, hi=floor(√c). While lo≤hi: s=lo²+hi²; adjust lo/hi vs c.

## 6. Dry Run
`c=5` → 1+4 → **true**. `c=3` → **false**.

## 7. Time & Space Complexity
Time **O(√c)**, space **O(1)**.

## 8. Trade-offs & Alternatives
Prime-factor test: all 4k+3 primes even exponent.

## 9. Common Mistakes / Edge Cases
Overflow on lo*lo without long long; floating sqrt off-by-one.

## 10. Interview Follow-ups / Variations
Count representations r₂(n); Lagrange four-square.

## 11. Tags
`number-theory`, `two-pointers`, `leetcode-633`, `difficulty:medium`
