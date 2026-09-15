# Flatten 2D Vector

## 1. Problem Statement
[LeetCode 251](https://leetcode.com/problems/flatten-2d-vector/) — implement iterator over `vector<vector<int>>` in row-major order, skipping empty inner vectors.

- **Inputs:** 2D vector.
- **Output:** `next` / `hasNext` sequence.
- **Valid answer:** two indices (row, col) with skip logic.
- **Edges:** empty rows; trailing empties; fully empty.

## 2. Intuition
Maintain (r,c); after each read advance and skip empty rows.

## 3. Brute Force → Optimal
- **Brute:** flatten to 1D upfront.
- **Optimal:** O(1) amortized with lazy skip.

## 4. Data Structure / Approach Justification
**Chosen:** two indices into the structure.

- **Adjacent** multi-pointer / k-list iteration practice.

## 5. Logic Walkthrough
advanceToNext skips empty. next returns data[r][c++] then advance.

## 6. Dry Run
`{{1,2},{},{3},{4,5}}` → `1 2 3 4 5`.

## 7. Time & Space Complexity
Time **O(1)** amortized per next (total skip O(total cells + rows)). Space **O(1)**.

## 8. Trade-offs & Alternatives
Iterator design warm-up before heap k-way.

## 9. Common Mistakes / Edge Cases
Not skipping empties in hasNext; dangling pointer if vec is temporary.

## 10. Interview Follow-ups / Variations
Zigzag Iterator; Merge k lists.

## 11. Tags
`design`, `two-pointers`, `k-way-merge-adjacent`, `leetcode-251`, `difficulty:medium`
