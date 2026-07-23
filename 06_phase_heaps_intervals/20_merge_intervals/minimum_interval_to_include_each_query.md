# Minimum Interval to Include Each Query

## Problem Statement
[LeetCode 1851](https://leetcode.com/problems/minimum-interval-to-include-each-query/) — for each query `x`, return the length of the smallest interval that covers `x`, or `-1` if none.

- **Inputs:** `intervals` as `[left, right]` (inclusive), `queries` as integers.
- **Output:** `vector<int>` answers in original query order.
- **Valid answer:** min `(right - left + 1)` among intervals with `left ≤ x ≤ right`.
- **Edges:** no covering interval; point intervals; queries outside all ranges.

## Intuition
Process queries in sorted order. Add all intervals whose left ≤ current query into a min-heap keyed by length; drop intervals whose right < query. Heap top is the smallest covering length.

## Brute Force → Optimal
- **Brute:** for each query scan all intervals — O(Q·N).
- **Optimal:** sort intervals + queries, sweep with min-heap — O((N+Q) log N).

## Data Structure / Approach Justification
**Chosen:** sort both; min-heap of `{length, right}`; answer by original index.

- **vs segment tree / sparse table on compressed coords:** heavier to code; same interview complexity class.
- **vs per-query binary search on sorted intervals:** harder to get min length without extra structures.

## Logic Walkthrough
Sort intervals by left; sort `(query, idx)`. For each query `x`: push all intervals with `L ≤ x`; pop while `R < x`; if heap non-empty, `ans[idx] = top.length`.

## Dry Run
`intervals=[[1,4],[2,4],[3,6],[4,4]]`, `queries=[2,3,4,5]`:
- `x=2`: candidates lengths 4,3 → ans 3
- `x=3`: add `[3,6]` len 4 → min 3
- `x=4`: add `[4,4]` len 1 → min 1
- `x=5`: drop expired; `[3,6]` remains → 4

## Time & Space Complexity
Time **O((N+Q) log N)**. Space **O(N+Q)**. Why: each interval/query enters/leaves heap once after sorts (section 4).

## Trade-offs & Alternatives
Offline sorted sweep needs all queries up front. Online queries favor trees over compressed coordinates.

## Common Mistakes / Edge Cases
Off-by-one on inclusive length `R-L+1`; not restoring answer order; leaving expired intervals in the heap.

## Interview Follow-ups / Variations
Online queries? Only count covering intervals? Range minimum offline with Mo’s / fenwick?

## Tags
`intervals`, `heap`, `offline-queries`, `leetcode-1851`, `difficulty:hard`
