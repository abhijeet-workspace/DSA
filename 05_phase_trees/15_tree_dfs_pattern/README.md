# 15 — Tree DFS Pattern

Depth-first tree DP/path problems: postorder aggregates, path constraints, and construct/flatten patterns.

**Prerequisite:** Binary tree basics (14).  
**Related:** Tree BFS (16); DP on trees.

Solve in this order (easy → hard):

| # | Difficulty | File | Problem |
|---:|---|---|---|
| 1 | Easy | [`path_sum`](./path_sum.md) | [LC 112](https://leetcode.com/problems/path-sum/) |
| 2 | Easy | [`subtree_of_another_tree`](./subtree_of_another_tree.md) | [LC 572](https://leetcode.com/problems/subtree-of-another-tree/) |
| 3 | Medium | [`path_sum_ii`](./path_sum_ii.md) | [LC 113](https://leetcode.com/problems/path-sum-ii/) |
| 4 | Medium | [`path_sum_iii`](./path_sum_iii.md) | [LC 437](https://leetcode.com/problems/path-sum-iii/) |
| 5 | Medium | [`diameter_binary_tree`](./diameter_binary_tree.md) | [LC 543](https://leetcode.com/problems/diameter-of-binary-tree/) |
| 6 | Medium | [`longest_univalue_path`](./longest_univalue_path.md) | [LC 687](https://leetcode.com/problems/longest-univalue-path/) |
| 7 | Medium | [`house_robber_iii`](./house_robber_iii.md) | [LC 337](https://leetcode.com/problems/house-robber-iii/) |
| 8 | Medium | [`distribute_coins_in_binary_tree`](./distribute_coins_in_binary_tree.md) | [LC 979](https://leetcode.com/problems/distribute-coins-in-binary-tree/) |
| 9 | Medium | [`binary_tree_pruning`](./binary_tree_pruning.md) | [LC 814](https://leetcode.com/problems/binary-tree-pruning/) |
| 10 | Medium | [`maximum_binary_tree`](./maximum_binary_tree.md) | [LC 654](https://leetcode.com/problems/maximum-binary-tree/) |
| 11 | Medium | [`flatten_binary_tree_to_linked_list`](./flatten_binary_tree_to_linked_list.md) | [LC 114](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) |
| 12 | Medium | [`construct_binary_tree_preorder_inorder`](./construct_binary_tree_preorder_inorder.md) | [LC 105](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) |
| 13 | Medium | [`lca_binary_tree`](./lca_binary_tree.md) | [LC 236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) |
| 14 | Medium | [`all_nodes_distance_k`](./all_nodes_distance_k.md) | [LC 863](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) |
| 15 | Hard | [`binary_tree_max_path_sum`](./binary_tree_max_path_sum.md) | [LC 124](https://leetcode.com/problems/binary-tree-maximum-path-sum/) |

Each problem is a paired `{name}.cpp` + `{name}.md` (11-section teaching contract). Compile with `g++ -std=c++17`.
