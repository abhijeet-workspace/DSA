# 51 — Mo's Algorithm

Offline range queries via block-sorted windows. Prefer Fenwick/SegTree/prefix when the aggregator is prefix-friendly; use Mo for distinct/mode/mex-style maintenance.

Paired `{name}.cpp` + `{name}.md` (11-section teaching contract). Compile with `g++ -std=c++17`.

| # | File | Note |
|---:|---|---|
| 1 | [`mos_range_sum`](./mos_range_sum.md) | sum window |
| 2 | [`mos_range_distinct`](./mos_range_distinct.md) | distinct count |
| 3 | [`mos_frequency_of_k`](./mos_frequency_of_k.md) | freq of k |
| 4 | [`mos_range_xor`](./mos_range_xor.md) | XOR (prefer prefix) |
| 5 | [`mos_add_remove_parity`](./mos_add_remove_parity.md) | odd frequencies |
| 6 | [`mos_sum_of_distinct`](./mos_sum_of_distinct.md) | sum of uniques |
| 7 | [`mos_count_pairs_equal`](./mos_count_pairs_equal.md) | equal pairs |
| 8 | [`mos_range_mex`](./mos_range_mex.md) | range mex |
| 9 | [`mos_range_mode`](./mos_range_mode.md) | range mode |
| 10 | [`mos_range_product_mod`](./mos_range_product_mod.md) | product mod |
| 11 | [`mos_range_inversions_small`](./mos_range_inversions_small.md) | range inversions |
| 12 | [`mos_hilbert_order_demo`](./mos_hilbert_order_demo.md) | Hilbert order |
| 13 | [`mos_block_size_tuning_lab`](./mos_block_size_tuning_lab.md) | block tuning |
| 14 | [`mos_with_updates_offline`](./mos_with_updates_offline.md) | time Mo |
| 15 | [`mo_on_trees_path_demo`](./mo_on_trees_path_demo.md) | tree path lab |

