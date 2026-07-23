# Median of Two Sorted Arrays

## Problem Statement
[LeetCode 4](https://leetcode.com/problems/median-of-two-sorted-arrays/) — two sorted arrays; return median in O(log(min(m,n))) time.

- **Inputs:** `vector<int> a`, `vector<int> b`.
- **Output:** `double` median.
- **Valid answer:** middle value (odd total) or average of two middles (even).
- **Edges:** one array empty; highly uneven lengths; negatives.

## Intuition
Binary-partition the shorter array so left parts have `half = (m+n+1)/2` elements and max(left) ≤ min(right).

## Brute Force → Optimal
- **Brute:** merge then pick middle — O(m+n) time/space.
- **Optimal:** partition BS on shorter — O(log(min(m,n))).

## Data Structure / Approach Justification
**Chosen:** ensure `a` is shorter; search cut `i` with `j = half - i`; sentinels `INT_MIN`/`INT_MAX`.

- **vs merge:** simpler but fails the log-time constraint.
- **vs k-th element recursion:** related; partition is standard LC answer.

## Logic Walkthrough
If `aL <= bR && bL <= aR`, partitions correct → odd: `max(aL,bL)`; even: average with `min(aR,bR)`. If `aL > bR`, shrink `i`; else grow `i`.

## Dry Run
`a=[1,3]`, `b=[2]`:
- half=2; valid cut yields median `2`

## Time & Space Complexity
Time **O(log(min(m,n)))**. Space **O(1)**. Why: BS over shorter length (section 4).

## Trade-offs & Alternatives
Merge is fine if log constraint is dropped. Watch overflow on average — use `double`.

## Common Mistakes / Edge Cases
Not swapping to shorter array; wrong `half`; off-by-one on empty left/right sides.

## Interview Follow-ups / Variations
k-th in two sorted arrays; median of data stream (heaps).

## Tags
`binary-search`, `partition`, `hard`, `difficulty:hard`
