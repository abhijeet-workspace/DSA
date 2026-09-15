# Count Primes (LC 204)

## 1. Problem Statement
[LeetCode 204 — Count Primes](https://leetcode.com/problems/count-primes/): count how many primes are strictly less than `n`.

- **Inputs:** integer `n` (0 ≤ n ≤ 5·10⁶ typical).
- **Output:** number of primes in `[2, n)`.
- **Valid answer:** exact count.
- **Edges:** n ≤ 2 → 0.

## 2. Intuition
Composites are multiples of primes ≤ √n. Sieve once, then scan the mark array.

## 3. Brute Force → Optimal
- **Brute:** trial-divide each k < n — O(n√n).
- **Optimal:** Eratosthenes then count — O(n log log n).

## 4. Data Structure / Approach Justification
**Chosen:** boolean sieve `is_prime[0..n-1]`.

**Pedagogy:** framed here as number-theory / sieve counting. A related sieve toolkit appears in `number_theory` in this folder and in mathematical-algorithms elsewhere; this file is the LC204 contest-shaped drill.

- **vs segmented sieve:** overkill when n fits memory.

## 5. Logic Walkthrough
Mark multiples of each prime p from p² up to n−1. Count remaining true flags from 2..n−1.

## 6. Dry Run
`n=10` → primes 2,3,5,7 → **4**. `n=0/1/2` → **0**.

## 7. Time & Space Complexity
Time **O(n log log n)**, space **O(n)**.

## 8. Trade-offs & Alternatives
For huge n with small windows use segmented sieve; for single primality use Miller–Rabin.

## 9. Common Mistakes / Edge Cases
Off-by-one at bound `n` (strictly less); treating 1 as prime; starting marks at 2p.

## 10. Interview Follow-ups / Variations
Count primes in [L,R]; SPF table; twin primes.

## 11. Tags
`number-theory`, `sieve`, `leetcode-204`, `difficulty:medium`
