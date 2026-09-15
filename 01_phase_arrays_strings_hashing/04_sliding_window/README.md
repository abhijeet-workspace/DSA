# 04 — Sliding Window

Study-plan topic 8. Maintain a contiguous `[left, right]` **window** whose validity you update in amortized O(1) as the right end advances (and the left end may shrink). Fixed-size windows slide both ends together; variable windows expand/shrink under a monotone invariant.

**Prerequisite:** Topic 7 — Two Pointers (index pairs). Sliding window is the contiguous specialization.  
**Related:** Hashing for frequency windows; monotonic deque for window extrema (queues topic also covers LC 239).

Solve in this order (easy → hard):

| # | Difficulty | File | Problem |
|---:|---|---|---|
| 1 | Easy | [`maximum_sum_subarray`](./maximum_sum_subarray.md) | Max sum of size K (fixed-window drill) |
| 2 | Easy | [`max_average_subarray_i`](./max_average_subarray_i.md) | [LC 643](https://leetcode.com/problems/maximum-average-subarray-i/) |
| 3 | Easy | [`contains_duplicate_ii`](./contains_duplicate_ii.md) | [LC 219](https://leetcode.com/problems/contains-duplicate-ii/) |
| 4 | Medium | [`minimum_size_subarray_sum`](./minimum_size_subarray_sum.md) | [LC 209](https://leetcode.com/problems/minimum-size-subarray-sum/) |
| 5 | Medium | [`longest_substring_without_repeating`](./longest_substring_without_repeating.md) | [LC 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |
| 6 | Medium | [`fruit_into_baskets`](./fruit_into_baskets.md) | [LC 904](https://leetcode.com/problems/fruit-into-baskets/) |
| 7 | Medium | [`max_consecutive_ones_iii`](./max_consecutive_ones_iii.md) | [LC 1004](https://leetcode.com/problems/max-consecutive-ones-iii/) |
| 8 | Medium | [`longest_repeating_char_replacement`](./longest_repeating_char_replacement.md) | [LC 424](https://leetcode.com/problems/longest-repeating-character-replacement/) |
| 9 | Medium | [`permutation_in_string`](./permutation_in_string.md) | [LC 567](https://leetcode.com/problems/permutation-in-string/) |
| 10 | Medium | [`find_all_anagrams_in_a_string`](./find_all_anagrams_in_a_string.md) | [LC 438](https://leetcode.com/problems/find-all-anagrams-in-a-string/) |
| 11 | Medium | [`subarray_product_less_than_k`](./subarray_product_less_than_k.md) | [LC 713](https://leetcode.com/problems/subarray-product-less-than-k/) |
| 12 | Medium | [`number_of_substrings_containing_all_three`](./number_of_substrings_containing_all_three.md) | [LC 1358](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) |
| 13 | Hard | [`minimum_window_substring`](./minimum_window_substring.md) | [LC 76](https://leetcode.com/problems/minimum-window-substring/) |
| 14 | Hard | [`sliding_window_max`](./sliding_window_max.md) | [LC 239](https://leetcode.com/problems/sliding-window-maximum/) |
| 15 | Hard | [`substring_with_concatenation_of_all_words`](./substring_with_concatenation_of_all_words.md) | [LC 30](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) |

Each problem is a paired `{name}.cpp` + `{name}.md` (11-section teaching contract). Compile with `g++ -std=c++17`.
