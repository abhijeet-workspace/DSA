# Maximum Product After K Increments

## 1. Problem Statement
[LeetCode 2233](https://leetcode.com/problems/maximum-product-after-k-increments/) — perform exactly `k` increments (+1) on any elements; maximize product of array; mod 1e9+7.

- **Inputs:** `nums`, `k`.
- **Output:** max product mod 1e9+7.
- **Valid answer:** always bump current minimum.
- **Edges:** zeros; k large; single element.

## 2. Intuition
For a fixed sum, product is maximized when values are balanced — repeatedly increment the smallest element.

## 3. Brute Force → Optimal
- **Brute:** try distributions — too many.
- **Optimal:** min-heap, k times — O((N+K) log N).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap.

- **vs sorting each time:** slower.
- **Adjacent practice:** single-heap greedy in the two-heaps topic.

## 5. Logic Walkthrough
Heapify nums. k times: pop min, push min+1. Multiply all with mod.

## 6. Dry Run
`[0,4]`, k=5 → become like `[3,4]` or `[2,5]` etc.; product **20**.

## 7. Time & Space Complexity
Time **O((N+K) log N)**. Space **O(N)**. Why: k heap ops (section 4).

## 8. Trade-offs & Alternatives
For huge k, binary search on final min value is faster; heap is interview-clear.

## 9. Common Mistakes / Edge Cases
Max-heap instead of min; overflowing before mod; skipping zeros.

## 10. Interview Follow-ups / Variations
Remove Stones to Minimize Total; Maximal Score After K Operations.

## 11. Tags
`heap`, `greedy`, `leetcode-2233`, `difficulty:medium`
