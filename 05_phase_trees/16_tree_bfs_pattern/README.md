# 16 — Tree BFS Pattern

Level-order / queue patterns: per-level aggregates, views, and neighbor wiring.

**Prerequisite:** Binary tree basics (14).  
**Related:** Tree DFS (15); graph BFS.

Solve in this order (easy → hard):

| # | Difficulty | File | Problem |
|---:|---|---|---|
| 1 | Easy | [`min_depth`](./min_depth.md) | [LC 111](https://leetcode.com/problems/minimum-depth-of-binary-tree/) |
| 2 | Easy | [`average_of_levels`](./average_of_levels.md) | [LC 637](https://leetcode.com/problems/average-of-levels-in-binary-tree/) |
| 3 | Easy | [`cousins_in_binary_tree`](./cousins_in_binary_tree.md) | [LC 993](https://leetcode.com/problems/cousins-in-binary-tree/) |
| 4 | Medium | [`level_order_traversal`](./level_order_traversal.md) | [LC 102](https://leetcode.com/problems/binary-tree-level-order-traversal/) |
| 5 | Medium | [`binary_tree_level_order_traversal_ii`](./binary_tree_level_order_traversal_ii.md) | [LC 107](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) |
| 6 | Medium | [`zigzag_traversal`](./zigzag_traversal.md) | [LC 103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) |
| 7 | Medium | [`right_side_view`](./right_side_view.md) | [LC 199](https://leetcode.com/problems/binary-tree-right-side-view/) |
| 8 | Medium | [`populating_next_right_pointers`](./populating_next_right_pointers.md) | [LC 116](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) |
| 9 | Medium | [`largest_values_in_each_tree_row`](./largest_values_in_each_tree_row.md) | [LC 515](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) |
| 10 | Medium | [`find_bottom_left_tree_value`](./find_bottom_left_tree_value.md) | [LC 513](https://leetcode.com/problems/find-bottom-left-tree-value/) |
| 11 | Medium | [`deepest_leaves_sum`](./deepest_leaves_sum.md) | [LC 1302](https://leetcode.com/problems/deepest-leaves-sum/) |
| 12 | Medium | [`maximum_level_sum`](./maximum_level_sum.md) | [LC 1161](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/) |
| 13 | Medium | [`even_odd_tree`](./even_odd_tree.md) | [LC 1609](https://leetcode.com/problems/even-odd-tree/) |
| 14 | Medium | [`count_good_nodes`](./count_good_nodes.md) | [LC 1448](https://leetcode.com/problems/count-good-nodes-in-binary-tree/) |
| 15 | Hard | [`vertical_order_traversal`](./vertical_order_traversal.md) | [LC 987](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/) |

Each problem is a paired `{name}.cpp` + `{name}.md` (11-section teaching contract). Compile with `g++ -std=c++17`.
