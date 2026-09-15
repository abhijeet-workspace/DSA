# MITM n≤40 Subset-Sum Teaching Lab

## 1. Problem Statement
Precise teaching statement (no invented contest ID): You are given `n` (1≤n≤40) integers `|a_i|≤1e9` and a target `T`. Decide if some subset sums to `T`. Time limit assumes ~2^20 work is fine, 2^40 is not.

- **Inputs:** n, array, T.
- **Output:** YES/NO.
- **Edges:** n odd split; T=0; overflow use 64-bit.

## 2. Intuition
Canonical CP MITM template for n≤40.

## 3. Brute Force → Optimal
- **2^n fail.**
- **Split n/2.**

## 4. Data Structure / Approach Justification
**Chosen:** bitmask enum + sort + binary_search.

| Alternative | Note |
|-------------|------|
| DP | Impossible for large sums |

## 5. Logic Walkthrough
Same as `meet_in_the_middle` with explicit n≤40 framing and YES/NO I/O.

## 6. Dry Run
n=6, a as classic sample, T=9 → YES.

## 7. Time & Space Complexity
**O(2^(n/2) · n)**.

## 8. Trade-offs & Alternatives
Template to memorize.

## 9. Common Mistakes / Edge Cases
32-bit sums; forgetting empty.

## 10. Interview Follow-ups / Variations
Count; lexicographically smallest mask.

## 11. Tags
`meet-in-the-middle`, `n40`, `teaching`, `difficulty:hard`
