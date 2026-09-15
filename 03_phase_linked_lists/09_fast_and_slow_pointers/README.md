# 09 — Fast & Slow Pointers

Study-plan topic 13. Floyd cycle detection, middle-finding, and related two-pointer walks on lists (and cycle-shaped sequences).

**Prerequisite:** Linked-list basics / manipulation patterns.  
**Related:** Cyclic sort (array-index Floyd for duplicates); two pointers on arrays/strings.

Solve in this order (easy → hard / pattern build-up):

| # | Difficulty | File | Problem |
|---:|---|---|---|
| 1 | Easy | [`linked_list_cycle`](./linked_list_cycle.md) | [LC 141](https://leetcode.com/problems/linked-list-cycle/) |
| 2 | Easy | [`middle_of_linked_list`](./middle_of_linked_list.md) | [LC 876](https://leetcode.com/problems/middle-of-the-linked-list/) |
| 3 | Easy | [`happy_number`](./happy_number.md) | [LC 202](https://leetcode.com/problems/happy-number/) |
| 4 | Easy | [`palindrome_linked_list`](./palindrome_linked_list.md) | [LC 234](https://leetcode.com/problems/palindrome-linked-list/) |
| 5 | Easy | [`intersection_of_two_linked_lists`](./intersection_of_two_linked_lists.md) | [LC 160](https://leetcode.com/problems/intersection-of-two-linked-lists/) |
| 6 | Medium | [`linked_list_cycle_ii`](./linked_list_cycle_ii.md) | [LC 142](https://leetcode.com/problems/linked-list-cycle-ii/) |
| 7 | Medium | [`remove_nth_node_from_end`](./remove_nth_node_from_end.md) | [LC 19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) |
| 8 | Medium | [`delete_middle_node`](./delete_middle_node.md) | [LC 2095](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) |
| 9 | Medium | [`swap_nodes_in_pairs`](./swap_nodes_in_pairs.md) | [LC 24](https://leetcode.com/problems/swap-nodes-in-pairs/) |
| 10 | Medium | [`odd_even_linked_list`](./odd_even_linked_list.md) | [LC 328](https://leetcode.com/problems/odd-even-linked-list/) |
| 11 | Medium | [`rotate_list`](./rotate_list.md) | [LC 61](https://leetcode.com/problems/rotate-list/) |
| 12 | Medium | [`reorder_list`](./reorder_list.md) | [LC 143](https://leetcode.com/problems/reorder-list/) |
| 13 | Medium | [`remove_duplicates_from_sorted_list_ii`](./remove_duplicates_from_sorted_list_ii.md) | [LC 82](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) |
| 14 | Medium | [`circular_array_loop`](./circular_array_loop.md) | [LC 457](https://leetcode.com/problems/circular-array-loop/) |
| 15 | Medium | [`sort_list`](./sort_list.md) | [LC 148](https://leetcode.com/problems/sort-list/) |

Skipped elsewhere: [`find_duplicate_number`](../../02_phase_searching_sorting/08_cyclic_sort/find_duplicate_number.md) (LC 287) lives under cyclic sort.

Each problem is a paired `{name}.cpp` + `{name}.md` (11-section teaching contract). Compile with `g++ -std=c++17`.
