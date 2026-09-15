# Factorial Trailing Zeroes (LC 172)

## 1. Problem Statement
[LeetCode 172 — Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/): return the number of trailing zeroes in `n!`.

- **Inputs:** nonnegative `n`.
- **Output:** exponent of 10 in `n!` (= min of exponents of 2 and 5; 5s dominate).
- **Edges:** n < 5 → 0.

## 2. Intuition
Each trailing zero comes from a factor 10 = 2·5. There are always more 2s than 5s, so count floor(n/5)+floor(n/25)+…

## 3. Brute Force → Optimal
- **Brute:** compute n! then count zeros — overflow / too slow.
- **Optimal:** sum floor(n/5^k) — O(log n).

## 4. Data Structure / Approach Justification
**Chosen:** loop dividing by powers of 5.

**Pedagogy:** classic number-theory counting of prime factors in n!; not a DP/string problem.

## 5. Logic Walkthrough
ans = 0; while n: n/=5; ans+=n.

## 6. Dry Run
`n=25` → floor(25/5)+floor(25/25)=5+1=**6**.

## 7. Time & Space Complexity
Time **O(log₅ n)**, space **O(1)**.

## 8. Trade-offs & Alternatives
Same idea counts exponent of any prime p in n!.

## 9. Common Mistakes / Edge Cases
Using int overflow on huge n; forgetting higher powers 25,125,…

## 10. Interview Follow-ups / Variations
Trailing zeroes in n! in base b; remove K zeroes by dividing.

## 11. Tags
`number-theory`, `factorial`, `leetcode-172`, `difficulty:medium`
