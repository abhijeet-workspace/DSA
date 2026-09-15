# 08 — Cyclic Sort

Study-plan topic 12. Place each value at its **home index**, then scan holes / duplicates. Extend to **cycle following** on index maps (rotate, nesting, couples).

**Prerequisite:** Topic 11 — Binary Search (and earlier array indexing).  
**Next:** Topic 13+ in searching/sorting / later phases.

Solve in this order (pattern → easy placement → cycle variants → hard):

| # | Difficulty | File | Problem |
|---:|---|---|---|
| 1 | Easy | [`cyclic_sort`](./cyclic_sort.md) | Cyclic Sort (pattern drill) |
| 2 | Easy | [`missing_number`](./missing_number.md) | [LC 268](https://leetcode.com/problems/missing-number/) |
| 3 | Easy | [`find_disappeared_numbers`](./find_disappeared_numbers.md) | [LC 448](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) |
| 4 | Easy | [`set_mismatch`](./set_mismatch.md) | [LC 645](https://leetcode.com/problems/set-mismatch/) |
| 5 | Medium | [`find_duplicate_number`](./find_duplicate_number.md) | [LC 287](https://leetcode.com/problems/find-the-duplicate-number/) |
| 6 | Medium | [`find_all_duplicates_in_an_array`](./find_all_duplicates_in_an_array.md) | [LC 442](https://leetcode.com/problems/find-all-duplicates-in-an-array/) |
| 7 | Medium | [`rotate_array`](./rotate_array.md) | [LC 189](https://leetcode.com/problems/rotate-array/) (cycle method) |
| 8 | Medium | [`array_nesting`](./array_nesting.md) | [LC 565](https://leetcode.com/problems/array-nesting/) |
| 9 | Medium | [`circular_array_loop`](./circular_array_loop.md) | [LC 457](https://leetcode.com/problems/circular-array-loop/) |
| 10 | Medium | [`max_chunks_to_make_sorted`](./max_chunks_to_make_sorted.md) | [LC 769](https://leetcode.com/problems/max-chunks-to-make-sorted/) |
| 11 | Medium | [`min_operations_reinitialize_permutation`](./min_operations_reinitialize_permutation.md) | [LC 1806](https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/) |
| 12 | Medium | [`wiggle_sort_ii`](./wiggle_sort_ii.md) | [LC 324](https://leetcode.com/problems/wiggle-sort-ii/) |
| 13 | Hard | [`first_missing_positive`](./first_missing_positive.md) | [LC 41](https://leetcode.com/problems/first-missing-positive/) |
| 14 | Hard | [`max_chunks_to_make_sorted_ii`](./max_chunks_to_make_sorted_ii.md) | [LC 768](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/) |
| 15 | Hard | [`couples_holding_hands`](./couples_holding_hands.md) | [LC 765](https://leetcode.com/problems/couples-holding-hands/) |

Notes:
- `find_all_duplicates_in_an_array` and `first_missing_positive` also appear in fundamentals topic 1 with different framing; this folder teaches **cyclic-sort / cycle-following**.
- `rotate_array` in fundamentals uses reverse; here we use **cycle decomposition**.

Each problem is a paired `{name}.cpp` + `{name}.md` (11-section teaching contract). Compile with `g++ -std=c++17`.
