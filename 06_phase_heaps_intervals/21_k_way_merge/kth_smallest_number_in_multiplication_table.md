# Kth Smallest Number in Multiplication Table

## 1. Problem Statement
[LeetCode 668](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) — m×n multiplication table (`i*j`); return the k-th smallest number in it.

- **Inputs:** `m`, `n`, `k`.
- **Output:** k-th smallest value.
- **Valid answer:** binary search on value + O(m) count.
- **Edges:** k=1; k=m*n; m=1.

## 2. Intuition
Rows are sorted. Count of values ≤ x is sum over rows of min(n, x/i). Binary search x.

## 3. Brute Force → Optimal
- **Brute:** generate all + heap — memory heavy.
- **Optimal:** binary search — O(m log (mn)).

## 4. Data Structure / Approach Justification
**Chosen:** binary search on answer.

- **Adjacent** to matrix k-th (378); heap k-way would need care with duplicates.

## 5. Logic Walkthrough
lo=1, hi=m*n. If count(mid)≥k then hi=mid else lo=mid+1.

## 6. Dry Run
m=n=3, k=5 → table values … → **3**.

## 7. Time & Space Complexity
Time **O(m log (mn))**. Space **O(1)**. Why: log range × row counts (section 4).

## 8. Trade-offs & Alternatives
Prefer BS over materializing; teaches k-th without building structure.

## 9. Common Mistakes / Edge Cases
Wrong count formula; 0-based; overflow m*n (use care if huge — here fits int constraints).

## 10. Interview Follow-ups / Variations
Kth smallest in sorted matrix; kth pair distance.

## 11. Tags
`binary-search`, `k-way-merge-adjacent`, `math`, `leetcode-668`, `difficulty:hard`
