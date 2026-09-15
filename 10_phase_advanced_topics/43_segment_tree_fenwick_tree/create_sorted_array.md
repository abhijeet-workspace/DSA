# Create Sorted Array through Instructions

## 1. Problem Statement
[LeetCode 1649](https://leetcode.com/problems/create-sorted-array-through-instructions/) — insert instructions one-by-one into a sorted stream; cost is `min(#strictly less, #strictly greater)`; return total cost mod `10^9+7`.

- **Inputs:** `vector<int> instructions`.
- **Output:** total cost mod 1e9+7.
- **Valid answer:** exact modular sum.
- **Edges:** all equal; strictly increasing.

## 2. Intuition
Fenwick/segtree of frequencies: before inserting `x`, query count `< x` and `> x`.

## 3. Brute Force → Optimal
- **Brute:** maintain sorted vector — O(N²).
- **Optimal:** Fenwick on value domain — O(N log V).

## 4. Data Structure / Approach Justification
**Chosen:** Fenwick frequencies (values up to 1e5).

- **vs policy-based data / order-stat tree:** less portable.

## 5. Logic Walkthrough
For each x: `less=sum(x-1)`; `greater=i-sum(x)`; add min; `add(x,1)`.

## 6. Dry Run
`[1,5,6,2]` → costs 0+0+0+1 → **1**.

## 7. Time & Space Complexity
Time **O(N log V)**. Space **O(V)**.

## 8. Trade-offs & Alternatives
Dynamic segtree if V is huge/sparse.

## 9. Common Mistakes / Edge Cases
Off-by-one on less/greater; forgetting mod; counting equals as less.

## 10. Interview Follow-ups / Variations
Count smaller after self; reverse pairs.

## 11. Tags
`fenwick`, `counting`, `leetcode-1649`, `difficulty:hard`
