# Minimized Maximum of Products Distributed to Any Store

## Problem Statement
[LeetCode 2064](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) — `n` stores; each product type must be split across stores with at most `x` units per store and a store holds one type. Minimize x.

- **Inputs:** `n`, `quantities`.
- **Output:** `int` x.
- **Valid answer:** smallest x with `sum ceil(q/x) <= n`.
- **Edges:** n equals number of types (x = max q); lots of stores.

## Intuition
Same ceil packing as Koko: type q needs `ceil(q/x)` stores.

## Brute Force → Optimal
- **Brute:** try every x — O(max · M).
- **Optimal:** binary search — O(M log Max).

## Data Structure / Approach Justification
**Chosen:** search-on-answer with store budget n.

- **vs Koko:** hours budget vs store budget
- **vs ship packages:** no order constraint

## Logic Walkthrough
lo=1, hi=max(quantities). Feasible if total stores needed ≤ n.

## Dry Run
`n=6`, `[11,6]` → 3.

## Time & Space Complexity
Time **O(M log Max)**. Space **O(1)**. Why: M product types.

## Trade-offs & Alternatives
Drop-in Koko template.

## Common Mistakes / Edge Cases
Forgetting a store cannot mix types; d=0.

## Interview Follow-ups / Variations
Koko; smallest divisor.

## Tags
`binary-search`, `search-on-answer`, `leetcode-2064`, `difficulty:medium`
