# Ugly Number II

## 1. Problem Statement
[LeetCode 264](https://leetcode.com/problems/ugly-number-ii/) — an ugly number’s prime factors are only 2, 3, and/or 5. Return the `n`th ugly number (1-indexed; `1` is ugly).

- **Inputs:** integer `n` (1 ≤ n ≤ 1690 typically).
- **Output:** the nth ugly number.
- **Edges:** `n=1` → 1; duplicates like 6=2·3=3·2.

## 2. Intuition
Every ugly number is some earlier ugly ×2, ×3, or ×5. Merge three increasing sequences like a k-way merge / heap without duplicates.

## 3. Brute Force → Optimal
- **Brute:** check each integer for ugly — too slow for large n.
- **Optimal:** DP with three indices — O(n).

## 4. Data Structure / Approach Justification
**Chosen:** array `ugly[0..n-1]` + pointers `i2,i3,i5`.

| Alternative | Why skip |
|-------------|---------|
| Min-heap of candidates | Classic; needs set for dedup; similar idea |
| Factorization scan | Too slow |

Heap version belongs in top-k / merge chapter; three-pointer DP is the standard interview answer.

## 5. Logic Walkthrough
1. `ugly[0]=1`; `i2=i3=i5=0`.
2. For each next slot: take `min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)`.
3. Advance every pointer whose product equals the chosen next (dedup).
4. Return `ugly[n-1]`.

## 6. Dry Run
`n=10`: sequence `1,2,3,4,5,6,8,9,10,12` → **12**.

## 7. Time & Space Complexity
- **Time:** O(n)
- **Space:** O(n)

## 8. Trade-offs & Alternatives
Priority queue + set is clearer “merge” framing but heavier constants and code.

## 9. Common Mistakes / Edge Cases
Using `else if` so only one pointer advances (misses duplicates); int overflow on products; off-by-one for 1-indexed n.

## 10. Interview Follow-ups / Variations
Super ugly numbers (LC 313); nth number divisible only by given primes.

## 11. Tags
`heap`, `dp`, `math`, `three-pointers`, `leetcode-264`, `difficulty:medium`
