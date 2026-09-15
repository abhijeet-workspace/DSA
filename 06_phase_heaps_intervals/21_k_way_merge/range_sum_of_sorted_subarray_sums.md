# Range Sum of Sorted Subarray Sums

## 1. Problem Statement
[LeetCode 1508](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/) — form all contiguous subarray sums, sort them, return sum of values from index `left` to `right` (1-based) mod 1e9+7.

- **Inputs:** `nums`, `n`, `left`, `right`.
- **Output:** range sum over sorted subarray-sums.
- **Valid answer:** generate O(N²) sums (N≤1000) or heap k-way of row starts.
- **Edges:** left=right; full range; single element array.

## 2. Intuition
Constraints allow generating all subarray sums then sorting. Heap/k-way can extract only up to `right` smallest sums when N is larger.

## 3. Brute Force → Optimal
- **Brute:** all sums + sort — O(N² log N) OK for N≤1000.
- **Heap:** repeatedly expand subarray starts — k-way flavored.

## 4. Data Structure / Approach Justification
**Chosen:** generate + sort (clear under constraints).

- **Adjacent:** mention min-heap of (sum, i, j) for larger N.

## 5. Logic Walkthrough
For each start i, accumulate to j; push sums; sort; add indices [left-1, right-1].

## 6. Dry Run
`[1,2,3,4]`, left=1,right=5 → sorted sums first five sum to **13**.

## 7. Time & Space Complexity
Time **O(N² log N)**. Space **O(N²)**. Why: all subarray sums (section 4).

## 8. Trade-offs & Alternatives
For teaching, note the heap extraction alternative connecting to k-way merge.

## 9. Common Mistakes / Edge Cases
0-based left/right; forgetting mod; non-contiguous subsets.

## 10. Interview Follow-ups / Variations
Kth smallest pair distance; find k pairs.

## 11. Tags
`sorting`, `prefix-sum`, `k-way-merge-adjacent`, `leetcode-1508`, `difficulty:medium`
