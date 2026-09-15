# The K Weakest Rows in a Matrix

## 1. Problem Statement
[LeetCode 1337](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/) — binary matrix rows sorted (1s then 0s). Weakness = number of soldiers (1s); ties broken by smaller row index. Return the `k` weakest row indices in order.

- **Inputs:** `mat` (`m×n`), integer `k`.
- **Output:** `vector<int>` of length `k`.
- **Edges:** `k=1`; all rows equal strength; single row; all zeros / all ones.

## 2. Intuition
Each row’s strength is its soldier count; we need top-k *weakest* → maintain a size-`k` max-heap of `(soldiers, index)`.

## 3. Brute Force → Optimal
- **Brute:** compute all strengths, full sort — O(m n + m log m).
- **Optimal:** binary search per row for strength + size-k heap — O(m log n + m log k).

## 4. Data Structure / Approach Justification
**Chosen:** linear (or binary) count of 1s + max-heap of size `k`.

| Alternative | Why skip |
|-------------|---------|
| Full sort of all rows | Fine for small m; heap matches top-k topic |
| Sorting network / selection | Overkill for interview |

## 5. Logic Walkthrough
1. For each row `i`, count leading 1s as `soldiers`.
2. Push `(soldiers, i)`; if heap size > `k`, pop strongest.
3. Pop heap into answer from back → weakest-first order.

## 6. Dry Run
Rows strengths `[2,4,1,2,5]`, `k=3`: heap keeps rows 2,0,3 → output `[2,0,3]`.

## 7. Time & Space Complexity
- **Time:** O(m · n + m log k) with linear count (or O(m log n + m log k) with binary search)
- **Space:** O(k) for the heap

## 8. Trade-offs & Alternatives
Binary search on each row saves when `n` is large. Full sort is simpler if `m` is tiny.

## 9. Common Mistakes / Edge Cases
Wrong tie-break (index); counting trailing zeros; reverse heap polarity; unsorted output order.

## 10. Interview Follow-ups / Variations
Return strongest `k`; 2D “weakest columns”; online stream of rows.

## 11. Tags
`heap`, `top-k`, `matrix`, `binary-search`, `leetcode-1337`, `difficulty:easy`
