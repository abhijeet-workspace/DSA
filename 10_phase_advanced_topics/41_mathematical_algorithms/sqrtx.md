# Sqrt(x)

## 1. Problem Statement
[LeetCode 69](https://leetcode.com/problems/sqrtx/) — return the floor of the non-negative square root of `x` (integer Newton / binary search framing).

- **Inputs:** non-negative `int x`.
- **Output:** `floor(sqrt(x))`.
- **Valid answer:** largest int `r` with `r*r ≤ x`.
- **Edges:** `0`, `1`, perfect squares, large near `INT_MAX`.

## 2. Intuition
Newton iteration `r = (r + x/r)/2` converges quickly to sqrt; stop when `r*r > x` then decrement.

## 3. Brute Force → Optimal
- **Brute:** linear scan i until i*i > x.
- **Binary search:** classic O(log x).
- **Newton:** fewer iterations in practice.

## 4. Data Structure / Approach Justification
**Chosen:** integer Newton for the math-topic framing (binary search version lives under searching).

- **vs floating sqrt + cast:** precision risk near boundaries.

## 5. Logic Walkthrough
Start `r=x`; while `r > x/r` set `r = (r + x/r)/2`; return `r`.

## 6. Dry Run
`x=8` → converges to **2**. `x=4` → **2**.

## 7. Time & Space Complexity
Time **O(log x)** iterations. Space **O(1)**.

## 8. Trade-offs & Alternatives
Binary search is easier to prove; Newton is faster constant factors.

## 9. Common Mistakes / Edge Cases
`r*r` overflow — compare `r > x/r` instead; returning ceil.

## 10. Interview Follow-ups / Variations
Nth root; Perfect Square check.

## 11. Tags
`math`, `newton`, `leetcode-69`, `difficulty:easy`
