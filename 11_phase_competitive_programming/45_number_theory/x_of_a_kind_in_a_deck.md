# X of a Kind in a Deck of Cards (LC 914)

## 1. Problem Statement
[LeetCode 914 — X of a Kind in a Deck of Cards](https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/): true iff we can split the deck into groups of size `X≥2` with equal values in each group.

- **Inputs:** `deck` multiset of card values.
- **Output:** bool.
- **Edges:** all unique → false; single value count≥2 → true.

## 2. Intuition
Group sizes must share a common divisor X≥2 → gcd of all frequencies must be ≥2.

## 3. Brute Force → Optimal
- **Brute:** try every X from 2..n.
- **Optimal:** frequency map + iterative gcd — O(n + U log).

## 4. Data Structure / Approach Justification
**Chosen:** hash/count map + `std::gcd`.

**Pedagogy:** gcd-of-frequencies pattern in number theory framing.

## 5. Logic Walkthrough
Count freqs. g=0; for each freq g=gcd(g,f). Return g≥2.

## 6. Dry Run
`[1,2,3,4,4,3,2,1]` freqs all 2 → gcd=2 → **true**.

## 7. Time & Space Complexity
Time **O(n)**, space **O(U)**.

## 8. Trade-offs & Alternatives
Same idea: split array into equal-sized identical-value groups.

## 9. Common Mistakes / Edge Cases
Returning true when gcd=1; empty deck.

## 10. Interview Follow-ups / Variations
GCD of subarray problems; fraction simplification batches.

## 11. Tags
`gcd`, `hash-map`, `leetcode-914`, `difficulty:easy`
