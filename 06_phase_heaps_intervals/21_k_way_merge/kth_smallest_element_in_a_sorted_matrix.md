# Kth Smallest Element in a Sorted Matrix

## 1. Problem Statement
[LeetCode 378](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) — n×n matrix sorted in rows and columns; return the k-th smallest element.

- **Inputs:** `matrix`, `k`.
- **Output:** k-th smallest value.
- **Valid answer:** heap merge of rows or binary search on value.
- **Edges:** k=1; k=n²; duplicates.

## 2. Intuition
Treat each row as a sorted list; k-way merge with a min-heap until k pops.

## 3. Brute Force → Optimal
- **Brute:** flatten + sort — O(N² log N).
- **Heap:** O(K log N).
- **Binary search on value:** O(N log(max-min)).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of `{val,row,col}` seeded with column 0 of each row.

- **vs binary search:** often faster asymptotically for large N, small K prefers heap.

## 5. Logic Walkthrough
Seed heap with first of each row. Pop k times; after each pop push next in that row.

## 6. Dry Run
matrix 3×3, k=8 → **13**.

## 7. Time & Space Complexity
Time **O(K log N)**. Space **O(N)**. Why: heap size ≤ N (section 4).

## 8. Trade-offs & Alternatives
Teach both heap and value-binary-search answers in interviews.

## 9. Common Mistakes / Edge Cases
Seeding entire matrix; 0-index k; assuming strict increase.

## 10. Interview Follow-ups / Variations
Kth smallest sum of matrix rows (1439); multiplication table (668).

## 11. Tags
`heap`, `k-way-merge`, `binary-search`, `leetcode-378`, `difficulty:medium`
