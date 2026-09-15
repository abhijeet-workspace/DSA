# Find the Kth Smallest Sum of a Matrix With Sorted Rows

## 1. Problem Statement
[LeetCode 1439](https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/) — m×n matrix with each row sorted; pick one from each row; return k-th smallest possible sum.

- **Inputs:** `mat`, `k`.
- **Output:** k-th smallest sum.
- **Valid answer:** iteratively keep k best partial sums while merging next row.
- **Edges:** m=1; k=1; wide rows.

## 2. Intuition
Start with sums {0}. For each row, form all extensions of current ≤k candidates, keep the k smallest via a heap.

## 3. Brute Force → Optimal
- **Brute:** all products of choices — exponential.
- **Optimal:** row-by-row k-best — O(m · (k·n) log (k·n)).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of candidate sums per row layer.

- **vs Dijkstra on index tuple:** also valid k-way style.

## 5. Logic Walkthrough
prev=[0]. For each row: push all prev[i]+row[j]; extract k smallest into prev. Answer prev[k-1].

## 6. Dry Run
`[[1,3,11],[2,4,6]]`, k=5 → **7**.

## 7. Time & Space Complexity
Time **O(m · kn log(kn))**. Space **O(kn)**. Why: bounded frontier per row (section 4).

## 8. Trade-offs & Alternatives
Simpler than full multi-index Dijkstra; enough for constraints.

## 9. Common Mistakes / Edge Cases
Keeping all sums; 0-based k; assuming columns sorted (only rows are).

## 10. Interview Follow-ups / Variations
Kth smallest in sorted matrix (378); find k pairs.

## 11. Tags
`heap`, `k-way-merge`, `leetcode-1439`, `difficulty:hard`
