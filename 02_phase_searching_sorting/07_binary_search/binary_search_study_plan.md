# LeetCode Binary Search Study Plan

Official plan: [Binary Search](https://leetcode.com/studyplan/binary-search/) — **8 patterns, 42 problems**.

Teaching solutions live in this folder as `{name}.cpp` + `{name}.md`. Premium APIs are simulated in `main()`.

Groups 1–6 match the GraphQL catalog exactly (32 problems). Groups 7–8 did not return question lists from the public API (empty `questions` despite `questionNum` 8 and 2); those 10 titles are the standard search-on-answer + DP+BS set that completes a 42-problem binary-search curriculum (875 already existed here).

| Group | Problem | File |
|---|---|---|
| Search In Array | 704 Binary Search | `binary_search_classic` |
| Search In Array | 35 Search Insert Position | `search_insert_position` |
| Search In Array | 744 Smallest Letter Greater Than Target | `find_smallest_letter_greater_than_target` |
| Search In Array | 1351 Count Negatives in Sorted Matrix | `count_negative_numbers_sorted_matrix` |
| Search In Array | 34 First and Last Position | `find_first_last_position` |
| Search In Array | 436 Find Right Interval | `find_right_interval` |
| Search In Array | 981 Time Based Key-Value Store | `time_based_key_value_store` |
| Search In Array | 1146 Snapshot Array | `snapshot_array` |
| Rotated Array | 33 Search in Rotated Sorted Array | `search_rotated_array` |
| Rotated Array | 153 Find Minimum in Rotated Sorted Array | `find_minimum_rotated_sorted_array` |
| Rotated Array | 154 Find Minimum in Rotated Sorted Array II | `find_minimum_rotated_sorted_array_ii` |
| Standard Search | 374 Guess Number Higher or Lower | `guess_number_higher_or_lower` |
| Standard Search | 278 First Bad Version | `first_bad_version` |
| Standard Search | 74 Search a 2D Matrix | `search_2d_matrix` |
| Standard Search | 702 Sorted Array of Unknown Size (premium) | `search_sorted_array_unknown_size` |
| Standard Search | 1533 Index of the Large Integer (premium) | `find_index_of_large_integer` |
| Math | 367 Valid Perfect Square | `valid_perfect_square` |
| Math | 69 Sqrt(x) | `sqrtx` |
| Math | 441 Arranging Coins | `arranging_coins` |
| Tricky Invariant | 1539 Kth Missing Positive Number | `kth_missing_positive_number` |
| Tricky Invariant | 275 H-Index II | `h_index_ii` |
| Tricky Invariant | 540 Single Element in a Sorted Array | `single_element_in_sorted_array` |
| Tricky Invariant | 852 Peak Index in a Mountain Array | `peak_index_in_mountain_array` |
| Tricky Invariant | 658 Find K Closest Elements | `find_k_closest_elements` |
| Tricky Invariant | 4 Median of Two Sorted Arrays | `median_of_two_sorted_arrays` |
| As A Tool | 1099 Two Sum Less Than K (premium) | `two_sum_less_than_k` |
| As A Tool | 611 Valid Triangle Number | `valid_triangle_number` |
| As A Tool | 2300 Successful Pairs of Spells and Potions | `successful_pairs_of_spells_and_potions` |
| As A Tool | 1498 Subsequences Sum Condition | `num_subseq_satisfy_sum_condition` |
| As A Tool | 528 Random Pick with Weight | `random_pick_with_weight` |
| As A Tool | 300 LIS (patience / binary search) | `longest_increasing_subsequence_bs` |
| As A Tool | 354 Russian Doll Envelopes | `russian_doll_envelopes` |
| On Solution Space | 875 Koko Eating Bananas | `koko_eating_bananas` |
| On Solution Space | 1011 Capacity To Ship Packages | `capacity_to_ship_packages` |
| On Solution Space | 1482 Days to Make m Bouquets | `min_days_to_make_m_bouquets` |
| On Solution Space | 1283 Smallest Divisor Given a Threshold | `smallest_divisor_given_threshold` |
| On Solution Space | 410 Split Array Largest Sum | `split_array_largest_sum` |
| On Solution Space | 774 Minimize Max Distance to Gas Station (premium) | `minimize_max_distance_to_gas_station` |
| On Solution Space | 1231 Divide Chocolate (premium) | `divide_chocolate` |
| On Solution Space | 2064 Minimized Maximum of Products | `minimized_maximum_of_products` |
| With Dynamic Programming | 1235 Maximum Profit in Job Scheduling | `maximum_profit_in_job_scheduling` |
| With Dynamic Programming | 1751 Maximum Number of Events II | `max_number_of_events_attended_ii` |

## How to run

```bash
g++ -std=c++17 -Wall -Wextra -O2 path/to/file.cpp -o /tmp/demo && /tmp/demo
```
