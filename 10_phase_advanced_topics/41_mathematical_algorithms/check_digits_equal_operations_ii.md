# Check If Digits Are Equal in String After Operations II

## 1. Problem Statement
[LeetCode 3463](https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-ii/) — repeatedly replace each adjacent pair `(s[i]+s[i+1]) % 10` until two digits remain; return whether they are equal. `n` up to `1e5` (simulation TLE).

- **Inputs:** digit string `s` (`n >= 2`).
- **Output:** bool.
- **Edges:** length 2; all zeros; large `n`.

## 2. Intuition
Each reduction is a Pascal/binomial convolution. Final left digit = `Σ C(n-2,i)·s[i] (mod 10)`; right = `Σ C(n-2,i)·s[i+1] (mod 10)`. Equal iff `Σ C(n-2,i)·(s[i]-s[i+1]) ≡ 0 (mod 10)`.

## 3. Brute Force → Optimal
- **Brute:** simulate O(N²) — too slow.
- **Optimal:** binomial coeffs mod 10 via Lucas on primes 2 and 5 + CRT lookup — O(N log n).

## 4. Data Structure / Approach Justification
**Chosen:** Lucas theorem for `C(n,k) mod 2` and `mod 5`, then CRT table to `mod 10`.

- **vs factor-count rolling product mod 2/5:** also O(N); Lucas is self-contained.
- **vs simulation:** fails constraints.

## 5. Logic Walkthrough
For each `i` in `[0, n-2]`, add `C(n-2,i) * (s[i]-s[i+1])` mod 10. Return whether total is 0.

## 6. Dry Run
`s = "3902"` → final digits equal → **true**.

## 7. Time & Space Complexity
Time **O(N log n)**. Space **O(1)**. Why: one pass; Lucas is O(log_p n) per coeff.

## 8. Trade-offs & Alternatives
Check congruence mod 2 and mod 5 separately (both zero ⇒ mod 10 zero) without materializing every `C % 10`.

## 9. Common Mistakes / Edge Cases
Computing `C % 10` as if 10 were prime; signed digit differences without normalizing mod 10.

## 10. Interview Follow-ups / Variations
Easy version (3461) allows simulation; generalize to mod `m` composite.

## 11. Tags
`math`, `combinatorics`, `lucas`, `leetcode-3463`, `difficulty:hard`
