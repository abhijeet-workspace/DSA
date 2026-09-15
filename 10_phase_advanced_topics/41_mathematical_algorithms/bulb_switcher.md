# Bulb Switcher

## 1. Problem Statement
[LeetCode 319](https://leetcode.com/problems/bulb-switcher/) — `n` bulbs start off; pass `i` toggles every `i`-th bulb. How many are on at the end?

- **Inputs:** `int n`.
- **Output:** count of bulbs that are on.
- **Valid answer:** number of perfect squares ≤ n.
- **Edges:** `n=0/1`; large n.

## 2. Intuition
Bulb `k` is toggled once per divisor. Odd toggle count ⟺ perfect square (divisors pair except square root).

## 3. Brute Force → Optimal
- **Brute:** simulate passes — O(N log N) / O(N²).
- **Optimal:** `floor(sqrt(n))`.

## 4. Data Structure / Approach Justification
**Chosen:** integer sqrt count.

- **vs sieve of toggles:** teaches the divisor insight less cleanly.

## 5. Logic Walkthrough
Return `floor(sqrt(n))` via Newton or binary search.

## 6. Dry Run
`n=3` → only bulb 1 on → **1**. `n=4` → bulbs 1,4 → **2**.

## 7. Time & Space Complexity
Time **O(log n)** for sqrt. Space **O(1)**.

## 8. Trade-offs & Alternatives
The math insight is the interview; coding sqrt is trivial after.

## 9. Common Mistakes / Edge Cases
Simulating for large n; floating sqrt off-by-one.

## 10. Interview Follow-ups / Variations
Bulb Switcher II/III/IV variants.

## 11. Tags
`math`, `number-theory`, `leetcode-319`, `difficulty:medium`
