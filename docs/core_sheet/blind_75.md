# Blind 75 — Core Drill Sheet

> **Not a starting curriculum.** Follow the primary study plan first:
> [`../study_plan.md`](../study_plan.md)
> (problem fundamentals → interview patterns → CP). Use Blind 75 only as a
> **post-fluency checklist** once those topics feel solid — not as day-one order.
>
> Older draft: [`../legacy_study_plan.md`](../legacy_study_plan.md) — prefer `study_plan.md`.

Must-do classic set mapped to in-repo C++17 solutions. Links are relative.
Prefer implementing from these files before opening LeetCode.

**Status:** Mapped in this repository (solutions + demos).

---

## 1. Arrays & Hashing
| # | Problem | Diff | File |
|---|---------|------|------|
| 1 | Two Sum | E | [two_sum.cpp](../../01_phase_arrays_strings_hashing/02_hash_maps_sets/two_sum.cpp) |
| 2 | Contains Duplicate | E | [contains_duplicate.cpp](../../01_phase_arrays_strings_hashing/02_hash_maps_sets/contains_duplicate.cpp) |
| 3 | Valid Anagram | E | [valid_anagram.cpp](../../01_phase_arrays_strings_hashing/02_hash_maps_sets/valid_anagram.cpp) |
| 4 | Group Anagrams | M | [group_anagrams.cpp](../../01_phase_arrays_strings_hashing/02_hash_maps_sets/group_anagrams.cpp) |
| 5 | Top K Frequent Elements | M | [top_k_frequent.cpp](../../01_phase_arrays_strings_hashing/02_hash_maps_sets/top_k_frequent.cpp) |
| 6 | Product of Array Except Self | M | [product_except_self.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/product_except_self.cpp) |
| 7 | Encode and Decode Strings | M | [encode_decode_strings.cpp](../../01_phase_arrays_strings_hashing/02_hash_maps_sets/encode_decode_strings.cpp) |
| 8 | Longest Consecutive Sequence | M | [longest_consecutive_sequence.cpp](../../01_phase_arrays_strings_hashing/02_hash_maps_sets/longest_consecutive_sequence.cpp) |

## 2. Two Pointers
| # | Problem | Diff | File |
|---|---------|------|------|
| 9 | Valid Palindrome | E | [valid_palindrome.cpp](../../01_phase_arrays_strings_hashing/03_two_pointers/valid_palindrome.cpp) |
| 10 | 3Sum | M | [three_sum.cpp](../../01_phase_arrays_strings_hashing/03_two_pointers/three_sum.cpp) |
| 11 | Container With Most Water | M | [container_with_most_water.cpp](../../01_phase_arrays_strings_hashing/03_two_pointers/container_with_most_water.cpp) |

## 3. Sliding Window
| # | Problem | Diff | File |
|---|---------|------|------|
| 12 | Best Time to Buy and Sell Stock | E | [best_time_to_buy_sell_stock.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/best_time_to_buy_sell_stock.cpp) |
| 13 | Longest Substring Without Repeating | M | [longest_substring_without_repeating.cpp](../../01_phase_arrays_strings_hashing/04_sliding_window/longest_substring_without_repeating.cpp) |
| 14 | Longest Repeating Character Replacement | M | [longest_repeating_char_replacement.cpp](../../01_phase_arrays_strings_hashing/04_sliding_window/longest_repeating_char_replacement.cpp) |
| 15 | Minimum Window Substring | H | [minimum_window_substring.cpp](../../01_phase_arrays_strings_hashing/04_sliding_window/minimum_window_substring.cpp) |

## 4. Stack
| # | Problem | Diff | File |
|---|---------|------|------|
| 16 | Valid Parentheses | E | [valid_parentheses.cpp](../../04_phase_stacks_queues/11_stacks/valid_parentheses.cpp) |

## 5. Binary Search
| # | Problem | Diff | File |
|---|---------|------|------|
| 17 | Find Minimum in Rotated Sorted Array | M | [find_minimum_rotated_sorted_array.cpp](../../02_phase_searching_sorting/07_binary_search/find_minimum_rotated_sorted_array.cpp) |
| 18 | Search in Rotated Sorted Array | M | [search_rotated_array.cpp](../../02_phase_searching_sorting/07_binary_search/search_rotated_array.cpp) |

## 6. Linked List
| # | Problem | Diff | File |
|---|---------|------|------|
| 19 | Reverse Linked List | E | [reverse_linked_list.cpp](../../03_phase_linked_lists/10_linked_list_manipulation/reverse_linked_list.cpp) |
| 20 | Linked List Cycle | E | [linked_list_cycle.cpp](../../03_phase_linked_lists/09_fast_and_slow_pointers/linked_list_cycle.cpp) |
| 21 | Merge Two Sorted Lists | E | [merge_two_sorted_lists.cpp](../../03_phase_linked_lists/10_linked_list_manipulation/merge_two_sorted_lists.cpp) |
| 22 | Merge K Sorted Lists | H | [k_way_merge.cpp](../../06_phase_heaps_intervals/21_k_way_merge/k_way_merge.cpp) |
| 23 | Remove Nth Node From End | M | [remove_nth_from_end.cpp](../../03_phase_linked_lists/10_linked_list_manipulation/remove_nth_from_end.cpp) |
| 24 | Reorder List | M | [reorder_list.cpp](../../03_phase_linked_lists/10_linked_list_manipulation/reorder_list.cpp) |

## 7. Trees
| # | Problem | Diff | File |
|---|---------|------|------|
| 25 | Maximum Depth of Binary Tree | E | [max_depth_binary_tree.cpp](../../05_phase_trees/14_binary_trees/max_depth_binary_tree.cpp) |
| 26 | Same Tree | E | [same_tree.cpp](../../05_phase_trees/14_binary_trees/same_tree.cpp) |
| 27 | Invert / Flip Binary Tree | E | [invert_tree.cpp](../../05_phase_trees/14_binary_trees/invert_tree.cpp) |
| 28 | Binary Tree Maximum Path Sum | H | [binary_tree_max_path_sum.cpp](../../05_phase_trees/15_tree_dfs_pattern/binary_tree_max_path_sum.cpp) |
| 29 | Binary Tree Level Order Traversal | M | [level_order_traversal.cpp](../../05_phase_trees/16_tree_bfs_pattern/level_order_traversal.cpp) |
| 30 | Serialize and Deserialize Binary Tree | H | [serialize_deserialize_binary_tree.cpp](../../05_phase_trees/14_binary_trees/serialize_deserialize_binary_tree.cpp) |
| 31 | Subtree of Another Tree | E | [subtree_of_another_tree.cpp](../../05_phase_trees/15_tree_dfs_pattern/subtree_of_another_tree.cpp) |
| 32 | Construct BT from Preorder & Inorder | M | [construct_binary_tree_preorder_inorder.cpp](../../05_phase_trees/15_tree_dfs_pattern/construct_binary_tree_preorder_inorder.cpp) |
| 33 | Validate Binary Search Tree | M | [validate_bst.cpp](../../05_phase_trees/17_binary_search_trees/validate_bst.cpp) |
| 34 | Kth Smallest Element in a BST | M | [kth_smallest_bst.cpp](../../05_phase_trees/17_binary_search_trees/kth_smallest_bst.cpp) |
| 35 | Lowest Common Ancestor of a BST | M | [lca_bst.cpp](../../05_phase_trees/17_binary_search_trees/lca_bst.cpp) |
| 36 | LCA of a Binary Tree | M | [lca_binary_tree.cpp](../../05_phase_trees/15_tree_dfs_pattern/lca_binary_tree.cpp) |

## 8. Tries
| # | Problem | Diff | File |
|---|---------|------|------|
| 37 | Implement Trie | M | [implement_trie.cpp](../../10_phase_advanced_topics/38_trie/implement_trie.cpp) |
| 38 | Design Add and Search Words | M | [design_add_and_search_words.cpp](../../10_phase_advanced_topics/38_trie/design_add_and_search_words.cpp) |
| 39 | Word Search II | H | [word_search_ii.cpp](../../10_phase_advanced_topics/38_trie/word_search_ii.cpp) |

## 9. Heap / Priority Queue
| # | Problem | Diff | File |
|---|---------|------|------|
| 40 | Find Median from Data Stream | H | [find_median_from_data_stream.cpp](../../06_phase_heaps_intervals/19_two_heaps/find_median_from_data_stream.cpp) |

## 10. Backtracking
| # | Problem | Diff | File |
|---|---------|------|------|
| 41 | Combination Sum | M | [combination_sum.cpp](../../07_phase_recursion_backtracking/22_subsets_pattern/combination_sum.cpp) |
| 42 | Word Search | M | [word_search.cpp](../../07_phase_recursion_backtracking/23_backtracking/word_search.cpp) |

## 11. Graphs
| # | Problem | Diff | File |
|---|---------|------|------|
| 43 | Number of Islands | M | [number_of_islands.cpp](../../08_phase_graphs/25_dfs_on_graphs/number_of_islands.cpp) |
| 44 | Clone Graph | M | [clone_graph.cpp](../../08_phase_graphs/25_dfs_on_graphs/clone_graph.cpp) |
| 45 | Pacific Atlantic Water Flow | M | [pacific_atlantic.cpp](../../08_phase_graphs/25_dfs_on_graphs/pacific_atlantic.cpp) |
| 46 | Course Schedule | M | [course_schedule.cpp](../../08_phase_graphs/27_topological_sort/course_schedule.cpp) |
| 47 | Course Schedule II | M | [course_schedule_ii.cpp](../../08_phase_graphs/27_topological_sort/course_schedule_ii.cpp) |
| 48 | Graph Valid Tree | M | [graph_valid_tree.cpp](../../08_phase_graphs/28_union_find/graph_valid_tree.cpp) |
| 49 | Number of Connected Components | M | [number_of_connected_components.cpp](../../08_phase_graphs/28_union_find/number_of_connected_components.cpp) |
| 50 | Alien Dictionary | H | [alien_dictionary.cpp](../../08_phase_graphs/27_topological_sort/alien_dictionary.cpp) |

## 12. Dynamic Programming
| # | Problem | Diff | File |
|---|---------|------|------|
| 51 | Climbing Stairs | E | [climbing_stairs.cpp](../../09_phase_dynamic_programming/30_1d_dp/climbing_stairs.cpp) |
| 52 | House Robber | M | [house_robber.cpp](../../09_phase_dynamic_programming/30_1d_dp/house_robber.cpp) |
| 53 | House Robber II | M | [house_robber_ii.cpp](../../09_phase_dynamic_programming/30_1d_dp/house_robber_ii.cpp) |
| 54 | Longest Increasing Subsequence | M | [lis.cpp](../../09_phase_dynamic_programming/34_longest_sequence_pattern/lis.cpp) |
| 55 | Longest Common Subsequence | M | [lcs.cpp](../../09_phase_dynamic_programming/31_2d_dp/lcs.cpp) |
| 56 | Word Break | M | [word_break.cpp](../../09_phase_dynamic_programming/30_1d_dp/word_break.cpp) |
| 57 | Combination Sum (DP view) | M | [combination_sum.cpp](../../07_phase_recursion_backtracking/22_subsets_pattern/combination_sum.cpp) |
| 58 | House Robber / Coin Change family | M | [coin_change.cpp](../../09_phase_dynamic_programming/30_1d_dp/coin_change.cpp) |
| 59 | Maximum Product Subarray | M | [maximum_product_subarray.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/maximum_product_subarray.cpp) |
| 60 | Maximum Subarray (Kadane) | M | [maximum_subarray.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/maximum_subarray.cpp) |
| 61 | Decode Ways | M | [decode_ways.cpp](../../09_phase_dynamic_programming/30_1d_dp/decode_ways.cpp) |
| 62 | Unique Paths | M | [unique_paths.cpp](../../09_phase_dynamic_programming/32_grid_dp/unique_paths.cpp) |
| 63 | Jump Game | M | [jump_game.cpp](../../09_phase_dynamic_programming/30_1d_dp/jump_game.cpp) |

## 13. Intervals
| # | Problem | Diff | File |
|---|---------|------|------|
| 64 | Insert Interval | M | [insert_interval.cpp](../../06_phase_heaps_intervals/20_merge_intervals/insert_interval.cpp) |
| 65 | Merge Intervals | M | [merge_intervals.cpp](../../06_phase_heaps_intervals/20_merge_intervals/merge_intervals.cpp) |
| 66 | Non-overlapping Intervals | M | [non_overlapping_intervals.cpp](../../06_phase_heaps_intervals/20_merge_intervals/non_overlapping_intervals.cpp) |
| 67 | Meeting Rooms | E | [meeting_rooms.cpp](../../06_phase_heaps_intervals/20_merge_intervals/meeting_rooms.cpp) |
| 68 | Meeting Rooms II | M | [meeting_rooms_ii.cpp](../../06_phase_heaps_intervals/20_merge_intervals/meeting_rooms_ii.cpp) |

## 14. Matrix
| # | Problem | Diff | File |
|---|---------|------|------|
| 69 | Set Matrix Zeroes | M | [set_matrix_zeroes.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/set_matrix_zeroes.cpp) |
| 70 | Spiral Matrix | M | [spiral_matrix.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/spiral_matrix.cpp) |
| 71 | Rotate Image | M | [rotate_image.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/rotate_image.cpp) |
| 72 | Word Search | M | [word_search.cpp](../../07_phase_recursion_backtracking/23_backtracking/word_search.cpp) |

## 15. Bit Manipulation
| # | Problem | Diff | File |
|---|---------|------|------|
| 73 | Number of 1 Bits | E | [number_of_1_bits.cpp](../../10_phase_advanced_topics/40_bit_manipulation/number_of_1_bits.cpp) |
| 74 | Counting Bits | E | [counting_bits.cpp](../../10_phase_advanced_topics/40_bit_manipulation/counting_bits.cpp) |
| 75 | Reverse Bits | E | [reverse_bits.cpp](../../10_phase_advanced_topics/40_bit_manipulation/reverse_bits.cpp) |
| — | Sum of Two Integers | M | [sum_of_two_integers.cpp](../../10_phase_advanced_topics/40_bit_manipulation/sum_of_two_integers.cpp) |
| — | Missing Number | E | [missing_number.cpp](../../02_phase_searching_sorting/08_cyclic_sort/missing_number.cpp) |

## Also commonly bundled
| Problem | File |
|---------|------|
| Longest Palindromic Substring | [longest_palindromic_substring.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/longest_palindromic_substring.cpp) |
| Palindromic Substrings | [palindromic_substrings.cpp](../../01_phase_arrays_strings_hashing/01_arrays_strings/palindromic_substrings.cpp) |
| Partition Equal Subset Sum | [partition_equal_subset_sum.cpp](../../09_phase_dynamic_programming/33_knapsack_pattern/partition_equal_subset_sum.cpp) |

## How to use
1. Solve in order within each section.
2. Timebox 20–30 minutes, then read the repo solution.
3. Re-solve from scratch after 48 hours (spaced repetition).
