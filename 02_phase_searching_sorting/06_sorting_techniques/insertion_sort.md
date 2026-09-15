# Insertion Sort

## 1. Problem Statement
Classic algorithm — build a sorted prefix by inserting each next element into its correct position.

- **Inputs:** `vector<int> arr` (mutated in place).
- **Output:** `arr` sorted ascending.
- **Valid answer:** non-decreasing order.
- **Edges:** empty; one element; all equal; reverse sorted.

## 2. Intuition
Like sorting cards in hand: take `key = arr[i]`, shift larger left neighbors right, drop `key` in the hole.

## 3. Brute Force → Optimal
- **Brute:** for each `i`, scan left and shift — O(N²) worst.
- **Adaptive:** nearly sorted → O(N); used inside TimSort / introsort for tiny runs.

## 4. Data Structure / Approach Justification
**Chosen:** in-place shifting insertion (stable with `>` not `>=`).

- **vs shell sort:** gapped insertion speeds large arrays.
- **vs binary insertion:** fewer compares, same O(N²) moves.

## 5. Logic Walkthrough
For `i = 1..n-1`, save `key`, while `arr[j] > key` shift `arr[j]` right, then place `key` at `j+1`.

## 6. Dry Run
`[3,1,2]`:
- insert `1` → `[1,3,2]`
- insert `2` → `[1,2,3]`

## 7. Time & Space Complexity
Time **O(N²)** worst, **O(N)** best. Space **O(1)**. Why: each insertion may shift O(N) (section 4).

## 8. Trade-offs & Alternatives
Excellent for small / nearly sorted inputs; poor on large reverse-sorted data. Prefer `std::sort` for general N.

## 9. Common Mistakes / Edge Cases
Off-by-one when shifting (`j` vs `j+1`); using `>=` and breaking stability.

## 10. Interview Follow-ups / Variations
Why does `std::sort` switch to insertion on tiny partitions? Online insertion into a growing sorted stream.

## 11. Tags
`sorting`, `insertion-sort`, `adaptive`, `stable`, `difficulty:easy`
